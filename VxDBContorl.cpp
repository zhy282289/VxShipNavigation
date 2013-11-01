#include "stdafx.h"
#include "vxdbcontorl.h"

#include <qtsql/qtsql>


VxDBContoller::VxDBContoller()
{
	m_dbPath = "./VxShipNavigation.db";

	m_tbSailMapInfo = "SailMapInfoTable";
	m_tbPlanRoute = "PlanRouteTable";
	m_tbRouteInfo = "RouteInfoTable";
	m_tbRouteRecord = "RouteRecord";
	m_tbWarnningRecord = "WarningRecordTable";

	InitDBEnvironment();
}

bool VxDBContoller::InitDBEnvironment()
{
	//QApplication::addLibraryPath("D:\\Qt\\Qt4.8.1_win32\\plugins\\");
	//QStringList driverList = QSqlDatabase::drivers();

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(m_dbPath);
	if (!db.open())
	{
		return false;
	}

	bool binit = true;
	QSqlQuery query;
	QStringList tables = db.tables();
	if (!tables.contains(m_tbSailMapInfo))
	{
		if (!query.exec(QString("CREATE TABLE %1 (id TEXT NOT NULL PRIMARY KEY, name TEXT, scale TEXT, baselatitude TEXT,style TEXT, position1 TEXT, position2 TEXT)").arg(m_tbSailMapInfo)))
		{
			binit = false;
			qDebug() << m_tbSailMapInfo << " TABLE CREATE FAIL: " << db.lastError().text();
		}
	}

	if (!tables.contains(m_tbPlanRoute))
	{
		if (!query.exec(QString("CREATE TABLE %1 (id TEXT NOT NULL PRIMARY KEY, name TEXT, startposition TEXT,endposition TEXT, sections TEXT, type TEXT, sumbittime TEXT )").arg(m_tbPlanRoute)))
		{
			binit = false;
			qDebug() <<m_tbPlanRoute <<  "TABLE CREATE FAIL: " << db.lastError().text();
		}
	}

	//if (!tables.contains(m_tbRouteInfo))
	//{
	//	if (!query.exec(QString("CREATE TABLE %1 (id, name , age)").arg(m_tbRouteInfo)))
	//	{
	//		binit = false;
	//		qDebug() << "CREATE FAIL: " << db.lastError().text();
	//	}
	//}

	if (!tables.contains(m_tbRouteRecord))
	{
		if (!query.exec(QString("CREATE TABLE %1 (time TEXT NOT NULL, latitude TEXT, longitude TEXT,course TEXT, speed TEXT, compoundcourse TEXT, groundspeed TEXT, flowdirection TEXT, flowrate TEXT, winddirection TEXT)").arg(m_tbRouteRecord)))
		{
			binit = false;
			qDebug() <<m_tbRouteRecord << "TABLE CREATE FAIL: " << db.lastError().text();
		}
	}

	//if (!tables.contains(m_tbWarnningRecord))
	//{
	//	if (!query.exec(QString("CREATE TABLE %1 (id, name , age)").arg(m_tbWarnningRecord)))
	//	{
	//		binit = false;
	//		qDebug() << "CREATE FAIL: " << db.lastError().text();
	//	}
	//}

	return binit;
}

bool VxDBContoller::QuerySailMaps( CVxSailMapInfos &sailMapInfos )
{
	QSqlQuery query;
	query.exec(QString("SELECT * FROM %1").arg(m_tbSailMapInfo));
	CVxSailMapInfo sailMapInfo;
	while (query.next())
	{
		sailMapInfo.id = query.value(0).toString();
		sailMapInfo.name = query.value(1).toString();
		sailMapInfo.scale = query.value(2).toString();
		sailMapInfo.baselatitude = query.value(3).toString();
		sailMapInfo.style = query.value(4).toString();
		sailMapInfo.position1 = query.value(5).toString();
		sailMapInfo.position2 = query.value(6).toString();
		sailMapInfos.push_back(sailMapInfo);
	}
	query.finish();

	return true;
}

bool VxDBContoller::InsertSailMap( const CVxSailMapInfo &sailMapInfo )
{
	QSqlQuery query;
	QString querycmd = QString("INSERT INTO %1 (id, name, scale, baselatitude,style, position1, position2) "
		"VALUES (:id, :name, :scale, :baselatitude, :style, :position1, :position2)").arg(m_tbSailMapInfo);
	query.prepare(querycmd);
	query.bindValue(0, sailMapInfo.id);
	query.bindValue(1, sailMapInfo.name);
	query.bindValue(2, sailMapInfo.scale);
	query.bindValue(3, sailMapInfo.baselatitude);
	query.bindValue(4, sailMapInfo.style);
	query.bindValue(5, sailMapInfo.position1);
	query.bindValue(6, sailMapInfo.position2);
	bool ret = query.exec();
	query.finish();
	if (!ret)
		qDebug() << query.lastError().text();
	return ret;
}

bool VxDBContoller::DeleteSailMap( QString id )
{
	QSqlQuery query;
	bool ret = query.exec(QString("DELETE FROM %1 WHERE id=\"%2\"").arg(m_tbSailMapInfo, id)); // 需要增加''才行

	if (!ret)
		qDebug() << query.lastError().text();
	return ret;
}

bool VxDBContoller::UpdateSailMap( const CVxSailMapInfo &sailMapInfo )
{
	QSqlQuery query;
	QString querycmd = QString("UPDATE %1 SET name=\"%2\", scale=\"%3\", baselatitude=\"%4\", style=\"%5\", position1=\"%6\", position2=\"%7\" "
		"WHERE id=\"%8\"").arg(m_tbSailMapInfo, sailMapInfo.name, sailMapInfo.scale, sailMapInfo.baselatitude, 
		sailMapInfo.style,sailMapInfo.position1, sailMapInfo.position2, sailMapInfo.id);

	bool ret = query.exec(querycmd); // 需要增加''才行
	if (!ret)
		qDebug() << query.lastError().text();
	return ret;
}

void VxDBContoller::SetDBFullPath( QString dbFullPath )
{
	m_dbPath = dbFullPath;
}

bool VxDBContoller::QueryPlanRoutes( CVxPlanRoutes &planRoutes )
{
	QSqlQuery query;
	query.exec(QString("SELECT * FROM %1").arg(m_tbPlanRoute));
	CVxPlanRoute planRoute;
	while (query.next())
	{
		planRoute.id = query.value(0).toString();
		planRoute.name = query.value(1).toString();
		planRoute.startposition = query.value(2).toString();
		planRoute.endposition = query.value(3).toString();
		planRoute.sections = query.value(4).toString();
		planRoute.type = query.value(5).toString();
		planRoute.sumbittime = query.value(6).toString();
		planRoutes.push_back(planRoute);
	}
	query.finish();
	return true;
}

bool VxDBContoller::InsertPlanRoute( const CVxPlanRoute &planRoute )
{

	QSqlQuery query;
	QString querycmd = QString("INSERT INTO %1 (id, name, startposition,endposition, sections, type, sumbittime) "
		"VALUES (:id, :name, :startposition, :endposition, :sections, :type, :sumbittime)").arg(m_tbPlanRoute);
	query.prepare(querycmd);
	query.bindValue(0, planRoute.id);
	query.bindValue(1, planRoute.name);
	query.bindValue(2, planRoute.startposition);
	query.bindValue(3, planRoute.endposition);
	query.bindValue(4, planRoute.sections);
	query.bindValue(5, planRoute.type);
	query.bindValue(6, planRoute.sumbittime);
	bool ret = query.exec();
	query.finish();

	if (!ret)
		qDebug() << query.lastError().text();
	return ret;
}

bool VxDBContoller::DeletePlanRoute( QString id )
{
	QSqlQuery query;
	bool ret = query.exec(QString("DELETE FROM %1 WHERE id=\"%2\"").arg(m_tbPlanRoute, id)); 
	if (!ret)
		qDebug() << query.lastError().text();

	return ret;
}

bool VxDBContoller::UpdatePlanRoute( const CVxPlanRoute &planRoute )
{
	QSqlQuery query;
	QString querycmd = QString("UPDATE %1 SET name=\"%2\", startposition=\"%3\", endposition=\"%4\", sections=\"%5\", type=\"%6\", sumbittime=\"%7\" "
		"WHERE id=\"%8\"").arg(m_tbPlanRoute, planRoute.name, planRoute.startposition, planRoute.endposition, 
		planRoute.sections,planRoute.type, planRoute.sumbittime, planRoute.id);

	bool ret = query.exec(querycmd); // 需要增加''才行
	
	if (!ret)
		qDebug() << query.lastError().text();

	return ret;
}

bool VxDBContoller::QuerySailRecords( CVxRouteRecords &routeRecords )
{
	QSqlQuery query;
	query.exec(QString("SELECT * FROM %1").arg(m_tbRouteRecord));
	CVxRouteRecord routeRecord;
	while (query.next())
	{
		routeRecord.time = query.value(0).toString();
		routeRecord.latitude = query.value(1).toString();
		routeRecord.longitude = query.value(2).toString();
		routeRecord.course = query.value(3).toString();
		routeRecord.speed = query.value(4).toString();
		routeRecord.compoundcourse = query.value(5).toString();
		routeRecord.groundspeed = query.value(6).toString();
		routeRecord.flowdirection = query.value(7).toString();
		routeRecord.flowrate = query.value(8).toString();
		routeRecord.winddirection = query.value(9).toString();
		routeRecords.push_back(routeRecord);
	}
	query.finish();
	return true;
}

bool VxDBContoller::InsertSailRecord( const CVxRouteRecord &routeRecord )
{
	QSqlQuery query;
	QString querycmd = QString("INSERT INTO %1 (time, latitude, longitude,course, speed, compoundcourse, groundspeed, flowdirection, flowrate, winddirection) "
		"VALUES (:time, :latitude, :longitude, :course, :speed, :compoundcourse, :groundspeed, :flowdirection, :flowrate, :winddirection)").arg(m_tbRouteRecord);
	query.prepare(querycmd);
	query.bindValue(0, routeRecord.time);
	query.bindValue(1, routeRecord.latitude);
	query.bindValue(2, routeRecord.longitude);
	query.bindValue(3, routeRecord.course);
	query.bindValue(4, routeRecord.speed);
	query.bindValue(5, routeRecord.compoundcourse);
	query.bindValue(6, routeRecord.groundspeed);
	query.bindValue(7, routeRecord.flowdirection);
	query.bindValue(8, routeRecord.flowrate);
	query.bindValue(9, routeRecord.winddirection);
	bool ret = query.exec();
	query.finish();

	if (!ret)
		qDebug() << query.lastError().text();
	return ret;
}


VxDBContoller		*g_DBController = NULL;
VxDBContoller* GetDBController()
{
	if (g_DBController == NULL)
	{
		g_DBController = new VxDBContoller;
	}
	return g_DBController;
}

void ReleaseDBController()
{
	if (g_DBController)
	{
		delete g_DBController;
	}
}

TestDBControl::TestDBControl()
{
	CVxSailMapInfos	sailMapInfos;
	CVxSailMapInfo sailMapInfo;	
	for (int i = 0;i < 10; ++i)
	{
		sailMapInfo.id = QString::number(i);
		sailMapInfo.name = "天津到大连港";
		sailMapInfo.scale = "1：100,000";
		sailMapInfo.baselatitude = "N30°00.00'";
		sailMapInfo.style = "墨卡托";
		sailMapInfo.position1 = "N30°00.00' E120°00.00'";
		sailMapInfo.position2 = "N30°00.00' E120°00.00'";
		GetDBController()->InsertSailMap(sailMapInfo);
	}
	GetDBController()->QuerySailMaps(sailMapInfos);

	sailMapInfo.id = QString::number(1);
	sailMapInfo.name = "天津到大连港1111111111111";
	GetDBController()->UpdateSailMap(sailMapInfo);
	sailMapInfos.clear();
	GetDBController()->QuerySailMaps(sailMapInfos);
	sailMapInfos.clear();
	GetDBController()->DeleteSailMap("0");
	GetDBController()->QuerySailMaps(sailMapInfos);


	CVxPlanRoutes planRoutes;
	CVxPlanRoute planRoute;

	for (int i = 0;i < 10; ++i)
	{
		planRoute.id = QString::number(i);
		planRoute.name = "chuganghangxian1";
		planRoute.startposition = "N30°15.000’E120°15.000'";
		planRoute.endposition = "N30°15.000’E120°15.000'";
		planRoute.sections = "15";
		planRoute.type = "BH";
		planRoute.sumbittime = "2013-8-27  18:00:00";
		GetDBController()->InsertPlanRoute(planRoute);
	}
	GetDBController()->QueryPlanRoutes(planRoutes);

	planRoute.id = QString::number(1);
	planRoute.name = "chuganghangxian1234444444444";
	GetDBController()->UpdatePlanRoute(planRoute);
	planRoutes.clear();
	GetDBController()->QueryPlanRoutes(planRoutes);
	planRoutes.clear();
	GetDBController()->DeletePlanRoute("0");
	GetDBController()->QueryPlanRoutes(planRoutes);


	// 航行记录
	CVxRouteRecords routeRecords;
	CVxRouteRecord routeRecord;

	for (int i = 0;i < 10; ++i)
	{
		routeRecord.time = "2013-08-07 08:00:00";
		routeRecord.latitude = "N30°15.000’";
		routeRecord.longitude = "E120°15.000'";
		routeRecord.course = "090°.0";
		routeRecord.speed = "18.5kn";
		routeRecord.compoundcourse = "090°.0";
		routeRecord.groundspeed = "18.5kn";
		routeRecord.flowdirection = "090°.0";
		routeRecord.flowrate = "02.2kn";
		routeRecord.winddirection = "090°.0";

		GetDBController()->InsertSailRecord(routeRecord);
	}
	GetDBController()->QuerySailRecords(routeRecords);
}
