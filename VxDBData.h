#pragma once

#include <qlist>
// ��ͼ��Ϣ  

struct CVxSailMapInfo
{
	QString id;				//ͼ��
	QString name;			//ͼ��
	QString scale;			//������
	QString baselatitude;	//��׼γ��
	QString	style;			//ͶӰ��ʽ
	QString position1;		//λ��1
	QString position2;		//λ��2
};
typedef QList<CVxSailMapInfo> CVxSailMapInfos;

// �ƻ�����  
struct CVxPlanRoute
{
	QString id;				//���
	QString name;			//������
	QString startposition;	//���λ��
	QString endposition;		//�յ�λ��
	QString sections;		//������
	QString type;			//����
	QString sumbittime;		//�ύʱ��
};
typedef QList<CVxPlanRoute> CVxPlanRoutes;

// ������Ϣ  
struct CVxRouteInfo
{
	QString id;				//���
	QString longitude;		//����
	QString latitude;		//γ��
	QString speed;			//����
	QString direction;		//��λ
	QString distance;		//����
	QString totaldistance;	//�ܾ���
	QString warning;		//ƫ������
	QString time;			//ʱ��
	QString totaltime;		//��ʱ��
};

// ���м�¼
struct CVxRouteRecord
{
	QString time;					//ʱ��
	QString latitude;				//γ��
	QString longitude;				//����
	QString	course;					//����
	QString speed;					//����
	QString	compoundcourse;			//������
	QString	groundspeed;			//����
	QString	flowdirection;			//����
	QString	flowrate;				//����
	QString	winddirection;			//����
};
typedef QList<CVxRouteRecord> CVxRouteRecords;


// ������Ϣ
struct CVxWarnningRecrod
{
	QString desc;			//��������
	QString time;			//����ʱ��
	QString duration;		//����ʱ��
};