/*
显示界面操作工具类。工具栏、可以是横向放置的、也可以是纵向放置的。默认是纵向放置的。


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
	int  GetAllLength();//获取工具工具栏的长度（高度）。


protected:

	virtual void mousePressEvent(QMouseEvent * pEvent);
	virtual void paintEvent(QPaintEvent * pEvent);

signals:
	void CurNo(int);

private:

	int m_iDir;  //工具栏的放置放松（水平/竖直）

	int m_iBtnW;
	int m_iBtnH;
	int m_iBtnG;//每个按钮之间的空隙
	int m_iCurNo;//当前哪个按钮被按下	

	//工具栏图片。
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
