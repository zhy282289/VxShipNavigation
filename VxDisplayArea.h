/*
����̬����ʾ����

*/
#ifndef VxDisplayArea_H
#define VxDisplayArea_H

#include <QWidget>
#include <vector>
using namespace std;

#include "VxDataDefine.h"

class CVxDisplayToolBar;

class CVxDisplayArea : public QWidget
{
	Q_OBJECT

public:
	CVxDisplayArea(QWidget *parent = 0);
	~CVxDisplayArea();

	void SetRow(int iRow);
	void SetCol(int iCol);
	void SetRowCol( int iRow, int iCol);
	int GetRow();
	int GetCol();

public slots:
	void MouseType(int iType);//��ȡ����������Ȼѡ�����ʲô���ߡ�

protected:
	virtual void mousePressEvent(QMouseEvent* pEvent);
	virtual void mouseDoubleClickEvent ( QMouseEvent* pEvent ); 
	virtual void mouseMoveEvent(QMouseEvent* pEevent);
	virtual void paintEvent(QPaintEvent* pEvent);
	virtual void resizeEvent(QResizeEvent* pEvent);

	virtual void keyPressEvent ( QKeyEvent* pEvent );

private:
	void  DrawGrid(QPainter& painter,int iW, int iH);//��������ָ���
private:

	int m_iMouseType;	//���Ĳ������ͣ��ɹ�������ť����

	int m_iRow;//����ʾ�����ж����С��С�
	int m_iCol;
	int m_iSubAreaH;//����ʾ����߶ȡ�

	CVxPositionFloat m_MinE,m_MaxE;
	CVxPositionFloat m_MinN,m_MaxN;
	CVxPositionFloat m_ShipPos;
	vector<CVxPositionFloat>m_vecShopPos;//������ʷ���ݡ�


	CVxDisplayToolBar*  m_pToolBar; //������  
};

#endif // VxDisplayArea_H
