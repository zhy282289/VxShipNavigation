#include "StdAfx.h"
#include "VxDisplayArea.h"

#include "VxDisplayToolBar.h"
#include "VxDataDefine.h"



CVxDisplayArea::CVxDisplayArea(QWidget *parent)
	: QWidget(parent)
{
	setFocusPolicy(Qt::ClickFocus);

	m_iRow = m_iCol = 5;
	m_iSubAreaH = 100;

	m_iMouseType = -1;
	m_pToolBar = new CVxDisplayToolBar(this);
	connect(m_pToolBar, SIGNAL(CurNo(int)), this, SLOT(MouseType(int)) );
}

CVxDisplayArea::~CVxDisplayArea()
{

}

void CVxDisplayArea::SetRow(int iRow)
{
	m_iRow = iRow;
	update();
}
void CVxDisplayArea::SetCol(int iCol)
{
	m_iCol = iCol;
	update();
}
void CVxDisplayArea::SetRowCol( int iRow, int iCol)
{
	m_iRow = iRow;
	m_iCol = iCol;
	update();
}
int CVxDisplayArea::GetRow()
{
	return m_iRow;
}
int CVxDisplayArea::GetCol()
{
	return m_iCol;
}
void CVxDisplayArea::MouseType(int iType)
{
	m_iMouseType = iType;
}

void CVxDisplayArea::mousePressEvent(QMouseEvent * pEvent)
{

}

void CVxDisplayArea:: mouseDoubleClickEvent ( QMouseEvent* pEvent )
{
	//在副显示区域、则弹出航行态势监控画面
}
void CVxDisplayArea::mouseMoveEvent(QMouseEvent * pEevent)
{

}

void CVxDisplayArea::paintEvent(QPaintEvent * pEvent)
{
	QPainter painter(this);
	int iW = width();
	int iH = height();

	//绘制一个粗线条的外框
	painter.save();
	QPen pen;
	pen.setWidth(3.0);
	painter.setPen(pen);
	QRect rc = rect();
	painter.drawRect(rc);
	painter.restore();

	//绘制主显示区域网格划分
	DrawGrid(painter, iW, iH - m_iSubAreaH);


}
void  CVxDisplayArea::DrawGrid(QPainter& painter,int iW, int iH)
{
	float fW = 1.0 * iW/m_iCol;
	float fH = 1.0 * iH/(m_iRow + 1);

	//画竖直线。
	float fStartX = 0;
	for ( int i = 0; i < m_iCol; i ++ )
	{
		QPoint topPoint(fStartX, 0);
		QPoint bottomPoint(fStartX,iH);
		painter.drawLine(topPoint,bottomPoint);

		QString strDegree = QString("E ") + QString::number(120)+ GetDegreeStr() + QString::number(15.001) + GetMinuteStr();
		painter.drawText(fStartX + 5, 15, strDegree);

		fStartX += fW;
	}

	//画竖直线。
	float fStartY = 0;
	for ( int i = 0; i < m_iRow + 1 + 1; i ++ )//多画最底下一条和副显示区域之间的横线。
	{
		QPoint LeftPoint(0, fStartY);
		QPoint RightPoint(iW,fStartY);
		painter.drawLine(LeftPoint,RightPoint);

		if ( i < m_iRow)
		{
			QString strDegree = QString("N ") + QString::number(120)+ GetDegreeStr() + QString::number(15.001) + GetMinuteStr();
			painter.drawText( 5, fStartY + fH - 10, strDegree);
		}

		fStartY += fH;
	}
}
void CVxDisplayArea::resizeEvent(QResizeEvent* pEvent)
{
	int iW = width();
	int iH = height();

	//工具栏有多长。
	int iToolBarLen = m_pToolBar->GetAllLength();
	int iToolBarDir = m_pToolBar->GetDir();
	
	if (ToolBarDir_V == iToolBarDir)
	{
		int iToolBarW = 50;
		int iPosX = iW - 20 - iToolBarW; //
		int iPosY = 0.5 * (iH - iToolBarLen);
		m_pToolBar->setGeometry(iPosX, iPosY,iToolBarW, iToolBarLen);
	}
	else
	{

	}
	update();
}

void CVxDisplayArea::keyPressEvent( QKeyEvent* pEvent )
{
	int iKey = pEvent->key();
	if (Qt::Key_Escape == iKey)
	{
		m_iMouseType = -1;
		m_pToolBar->SetCurNo(m_iMouseType);
	}

	update();
}