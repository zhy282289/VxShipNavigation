
#include "StdAfx.h"

#include "VxDataDefine.h"


QString strDegree;
QString strMinute;
QString strSecond;

void  InitDegreeStr()
{
	strDegree = QString("¡ã");
	strMinute = QString("¡ä");
	strSecond = QString("¡å");
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
