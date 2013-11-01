#ifndef VXDBCONTORL_H
#define VXDBCONTORL_H

#include <QObject>
#include "VxDBData.h"
/* ��Ҫ���ĸ���, ��ͼ��, ���߱�, ���߼�¼��, ���߱�����, 
*  �����Ƕ����ݿ����Ҫ�����ӿ�
*/

class VxDBContoller 
{
public:
	VxDBContoller();

	bool InitDBEnvironment(); // ��ʼ�����ݿ⻷��

	void SetDBFullPath(QString dbFullPath);
	/*
	* ��ȡ��ͼ��ϸ��Ϣ
	*/
	bool QuerySailMaps(CVxSailMapInfos &sailMapInfos); //��ͼװ��-��ȡ	
	bool InsertSailMap(const CVxSailMapInfo &sailMapInfo); //��ͼװ��-����	
	bool DeleteSailMap(QString id); //��ͼװ��-ɾ��	
	bool UpdateSailMap(const CVxSailMapInfo &sailMapInfo); //��ͼװ��-�޸�

	/*
	* ͨ����ͼ�Ż�ȡ���ߵ���ϸ��Ϣ
	*/
	bool QueryPlanRoutes(CVxPlanRoutes &planRoutes); //������Ϣ-��ȡ
	bool InsertPlanRoute(const CVxPlanRoute &planRoute);	//������Ϣ-����
	bool DeletePlanRoute(QString id);	//������Ϣ-ɾ��
	bool UpdatePlanRoute(const CVxPlanRoute &planRoute);	//������Ϣ-�޸�
	//bool QuerySailInfo(CVxPlanRoutes &planRoutes); //������Ϣ-��ȡ
	//bool InsertSailInfo(const CVxPlanRoute &planRoute);	//������Ϣ-����
	//bool DeleteSailInfo(QString id);	//������Ϣ-ɾ��
	//bool UpdateSailInfo(const CVxPlanRoute &planRoute);	//������Ϣ-�޸�


	/*
	* ��ȡ���м�¼��Ϣ
	*/
	bool QuerySailRecords(CVxRouteRecords &routeRecords);		//���м�¼��Ϣ-��ȡ
	bool InsertSailRecord(const CVxRouteRecord &routeRecord);	//���м�¼��Ϣ-����
	bool DeleteSailRecord(QString time);						//���м�¼��Ϣ-ɾ��


	/*
	* ���б�����Ϣ
	*/
	bool QuerySailWarningRecords(); //���б�����Ϣ-��ȡ
	bool InsertSailWarningRecord();	//���б�����Ϣ-����
	bool DeleteSailWarningRecord();	//���б�����Ϣ-ɾ��

	/*
	* �û�����
	*/
	void QueryUserPassword();	//�û�����-��ȡ
	void UpdataUserPassword();	//�û�����-�޸�


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
