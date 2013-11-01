/*
航行态势显示区域

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
	void MouseType(int iType);//获取工具栏、当然选择的是什么工具。

protected:
	virtual void mousePressEvent(QMouseEvent* pEvent);
	virtual void mouseDoubleClickEvent ( QMouseEvent* pEvent ); 
	virtual void mouseMoveEvent(QMouseEvent* pEevent);
	virtual void paintEvent(QPaintEvent* pEvent);
	virtual void resizeEvent(QResizeEvent* pEvent);

	virtual void keyPressEvent ( QKeyEvent* pEvent );

private:
	void  DrawGrid(QPainter& painter,int iW, int iH);//绘制网格分隔。
private:

	int m_iMouseType;	//鼠标的操作类型，由工具栏按钮控制

	int m_iRow;//主显示区域有多少行、列。
	int m_iCol;
	int m_iSubAreaH;//副显示区域高度。

	CVxPositionFloat m_MinE,m_MaxE;
	CVxPositionFloat m_MinN,m_MaxN;
	CVxPositionFloat m_ShipPos;
	vector<CVxPositionFloat>m_vecShopPos;//舰的历史数据。


	CVxDisplayToolBar*  m_pToolBar; //工具栏  
};

#endif // VxDisplayArea_H
