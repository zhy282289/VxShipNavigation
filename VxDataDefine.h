/*
���ݽṹ�����ļ�


*/


#ifndef VXDATADEFINE_H
#define VXDATADEFINE_H

#include <QString>

class CVxPositionInt
{
	int  m_iDegree;//��
	int  m_iMinute;//��
	int  m_iSecond;//��
};

class CVxPositionFloat
{
	int   m_iDegree;//��
	float m_iMinute;//�� 
};


void  InitDegreeStr();
const QString&  GetDegreeStr();
const QString&  GetMinuteStr();
const QString&  GetSecondStr();


#endif // VXDATADEFINE_H


