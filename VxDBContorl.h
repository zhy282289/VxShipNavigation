#ifndef VXDBCONTORL_H
#define VXDBCONTORL_H

#include <QObject>
#include "VxDBData.h"
/* 主要有四个表, 海图表, 航线表, 航线记录表, 航线报警表, 
*  下面是对数据库的主要操作接口
*/

class VxDBContoller 
{
public:
	VxDBContoller();

	bool InitDBEnvironment(); // 初始化数据库环境

	void SetDBFullPath(QString dbFullPath);
	/*
	* 获取海图详细信息
	*/
	bool QuerySailMaps(CVxSailMapInfos &sailMapInfos); //海图装订-读取	
	bool InsertSailMap(const CVxSailMapInfo &sailMapInfo); //海图装订-插入	
	bool DeleteSailMap(QString id); //海图装订-删除	
	bool UpdateSailMap(const CVxSailMapInfo &sailMapInfo); //海图装订-修改

	/*
	* 通过海图号获取航线的详细信息
	*/
	bool QueryPlanRoutes(CVxPlanRoutes &planRoutes); //航线信息-读取
	bool InsertPlanRoute(const CVxPlanRoute &planRoute);	//航线信息-插入
	bool DeletePlanRoute(QString id);	//航线信息-删除
	bool UpdatePlanRoute(const CVxPlanRoute &planRoute);	//航线信息-修改
	//bool QuerySailInfo(CVxPlanRoutes &planRoutes); //航线信息-读取
	//bool InsertSailInfo(const CVxPlanRoute &planRoute);	//航线信息-插入
	//bool DeleteSailInfo(QString id);	//航线信息-删除
	//bool UpdateSailInfo(const CVxPlanRoute &planRoute);	//航线信息-修改


	/*
	* 获取航行记录信息
	*/
	bool QuerySailRecords(CVxRouteRecords &routeRecords);		//航行记录信息-读取
	bool InsertSailRecord(const CVxRouteRecord &routeRecord);	//航行记录信息-插入
	bool DeleteSailRecord(QString time);						//航行记录信息-删除


	/*
	* 航行报警信息
	*/
	bool QuerySailWarningRecords(); //航行报警信息-读取
	bool InsertSailWarningRecord();	//航行报警信息-插入
	bool DeleteSailWarningRecord();	//航行报警信息-删除

	/*
	* 用户密码
	*/
	void QueryUserPassword();	//用户密码-读取
	void UpdataUserPassword();	//用户密码-修改


private:


private:
	QString			m_dbPath;
	QString			m_tbSailMapInfo;
	QString			m_tbPlanRoute;
	QString			m_tbRouteInfo;
	QString			m_tbRouteRecord;
	QString			m_tbWarnningRecord;
};



VxDBContoller*	GetDBController();
void			ReleaseDBController();


class TestDBControl
{
public:
	TestDBControl();
};
#endif // VXDBCONTORL_H
