/*
��ʾ������������ࡣ�������������Ǻ�����õġ�Ҳ������������õġ�Ĭ����������õġ�


*/
#ifndef VxDisplayToolBar_H
#define VxDisplayToolBar_H

#include <QWidget>
#include <vector>
using namespace std;

enum ToolBarDir
{
	ToolBarDir_V = 0,
	ToolBarDir_H,
};


class CVxDisplayToolBar : public QWidget
{
	Q_OBJECT

public:
	CVxDisplayToolBar(QWidget *parent = 0);
	~CVxDisplayToolBar();

public:
	void SetBtnW( int iW);
	void SetBtnH( int iH);
	void SetBtnWH(int iW, int iH);
	void SetBtnGap( int iGap);

	void SetDir(int iDir);
	int  GetDir();

	void SetCurNo( int iCurNo);
	int  GetAllLength();//��ȡ���߹������ĳ��ȣ��߶ȣ���


protected:

	virtual void mousePressEvent(QMouseEvent * pEvent);
	virtual void paintEvent(QPaintEvent * pEvent);

signals:
	void CurNo(int);

private:

	int m_iDir;  //�������ķ��÷��ɣ�ˮƽ/��ֱ��

	int m_iBtnW;
	int m_iBtnH;
	int m_iBtnG;//ÿ����ť֮��Ŀ�϶
	int m_iCurNo;//��ǰ�ĸ���ť������	

	//������ͼƬ��
	QPixmap*  m_pBig;
	QPixmap*  m_pSmall;
	QPixmap*  m_pMove;
	QPixmap*  m_pAreaSelect;
	QPixmap*  m_pShipCenter;
	QPixmap*  m_pMark;
	QPixmap*  m_pCompute;

	vector<QPixmap*> m_vecPics;
	
};

#endif // VxDisplayToolBar_H
