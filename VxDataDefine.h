/*
数据结构定义文件


*/


#ifndef VXDATADEFINE_H
#define VXDATADEFINE_H

#include <QString>

class CVxPositionInt
{
	int  m_iDegree;//度
	int  m_iMinute;//分
	int  m_iSecond;//秒
};

class CVxPositionFloat
{
	int   m_iDegree;//度
	float m_iMinute;//分 
};


void  InitDegreeStr();
const QString&  GetDegreeStr();
const QString&  GetMinuteStr();
const QString&  GetSecondStr();


#endif // VXDATADEFINE_H


