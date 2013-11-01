#pragma once

#include <qlist>
// 海图信息  

struct CVxSailMapInfo
{
	QString id;				//图号
	QString name;			//图名
	QString scale;			//比例尺
	QString baselatitude;	//基准纬度
	QString	style;			//投影方式
	QString position1;		//位置1
	QString position2;		//位置2
};
typedef QList<CVxSailMapInfo> CVxSailMapInfos;

// 计划航线  
struct CVxPlanRoute
{
	QString id;				//序号
	QString name;			//航线名
	QString startposition;	//起点位置
	QString endposition;		//终点位置
	QString sections;		//航段数
	QString type;			//类型
	QString sumbittime;		//提交时间
};
typedef QList<CVxPlanRoute> CVxPlanRoutes;

// 航线信息  
struct CVxRouteInfo
{
	QString id;				//序号
	QString longitude;		//经度
	QString latitude;		//纬度
	QString speed;			//航速
	QString direction;		//方位
	QString distance;		//距离
	QString totaldistance;	//总距离
	QString warning;		//偏航报警
	QString time;			//时间
	QString totaltime;		//总时间
};

// 航行记录
struct CVxRouteRecord
{
	QString time;					//时间
	QString latitude;				//纬度
	QString longitude;				//经度
	QString	course;					//航向
	QString speed;					//航速
	QString	compoundcourse;			//航迹向
	QString	groundspeed;			//地速
	QString	flowdirection;			//流向
	QString	flowrate;				//流速
	QString	winddirection;			//风向
};
typedef QList<CVxRouteRecord> CVxRouteRecords;


// 报警信息
struct CVxWarnningRecrod
{
	QString desc;			//报警内容
	QString time;			//报警时间
	QString duration;		//持续时间
};