
#include "StdAfx.h"

#include "VxDataDefine.h"


QString strDegree;
QString strMinute;
QString strSecond;

void  InitDegreeStr()
{
	strDegree = QString("��");
	strMinute = QString("��");
	strSecond = QString("��");
}
const QString&  GetDegreeStr()
{
	return strDegree;
}
const QString&  GetMinuteStr()
{
	return strMinute;
}
const QString&  GetSecondStr()
{
	return strSecond;
}
