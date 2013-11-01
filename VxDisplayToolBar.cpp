#include "StdAfx.h"
#include "VxDisplayToolBar.h"

CVxDisplayToolBar::CVxDisplayToolBar(QWidget *parent)
	: QWidget(parent)
{
	m_iDir = ToolBarDir_V;

	m_iBtnW = 40;
	m_iBtnH = 40;
	m_iBtnG = 5; 
	m_iCurNo = -1; 
	m_pBig = new QPixmap(tr(":/CVxDisplayToolBar/Resources/big.png"));
	m_pSmall = new QPixmap(tr(":/CVxDisplayToolBar/Resources/small.png"));
	m_pMove = new QPixmap(tr(":/CVxDisplayToolBar/Resources/move.png"));
	m_pAreaSelect = new QPixmap(tr(":/CVxDisplayToolBar/Resources/areaSelect.png"));
	m_pShipCenter = new QPixmap(tr(":/CVxDisplayToolBar/Resources/shipCenter.png"));
	m_pMark = new QPixmap(tr(":/CVxDisplayToolBar/Resources/mark.png"));
	m_pCompute = new QPixmap(tr(":/CVxDisplayToolBar/Resources/compute.png"));

	m_vecPics.push_back(m_pBig);
	m_vecPics.push_back(m_pSmall);
	m_vecPics.push_back(m_pMove);
	m_vecPics.push_back(m_pAreaSelect);
	m_vecPics.push_back(m_pShipCenter);
	m_vecPics.push_back(m_pMark);
	m_vecPics.push_back(m_pCompute);
}

CVxDisplayToolBar::~CVxDisplayToolBar()
{

}

void CVxDisplayToolBar::SetBtnW( int iW)
{
	m_iBtnW = iW;
	update();
}
void CVxDisplayToolBar::SetBtnH( int iH)
{
	m_iBtnH = iH;
	update();
}
void CVxDisplayToolBar::SetBtnWH(int iW, int iH)
{
	m_iBtnW = iW;
	m_iBtnH = iH;
	update();
}
void CVxDisplayToolBar::SetBtnGap( int iGap)
{
	m_iBtnG = iGap;
	update();
}
void CVxDisplayToolBar::SetDir(int iDir)
{
	m_iDir = iDir;
	update();
}
int  CVxDisplayToolBar::GetDir()
{
	return m_iDir;
}

void CVxDisplayToolBar::SetCurNo( int iCurNo)
{
	m_iCurNo = iCurNo;
	update();
}
int CVxDisplayToolBar::GetAllLength()
{
	int iPicCnt = m_vecPics.size();
	if ( ToolBarDir_H == m_iDir)
	{
		return iPicCnt * m_iBtnW + (iPicCnt + 1) *m_iBtnG;
	}
	else
	{
		return iPicCnt * m_iBtnH + (iPicCnt + 1) *m_iBtnG;
	}

}
void CVxDisplayToolBar::mousePressEvent(QMouseEvent * pEvent)
{
	int iW = width();
	int iH = height();
	QPoint qMousePos = pEvent->pos();
	m_iCurNo = -1;

	if (ToolBarDir_H == m_iDir)//横向排列工具栏的
	{

	}
	else//纵向排列工具栏的
	{
		//竖直向下、图片在工具栏的中央,计算每个图片的矩形。
		int iStartX = 0.5 * (iW - m_iBtnW);
		int iStartY = m_iBtnG;

	
		int iPicCnt = m_vecPics.size();
		for ( int i = 0; i < iPicCnt; i ++)
		{
			QRect rc(iStartX, iStartY, m_iBtnW,m_iBtnH);

			if (rc.contains(qMousePos))
			{
				m_iCurNo = i;
				break;
			}
			iStartY += (m_iBtnH + m_iBtnG);
		}
	}
	emit CurNo(m_iCurNo);

	update();
}


void CVxDisplayToolBar::paintEvent(QPaintEvent * pEvent)
{
	QPainter paiter(this);
	
	int iW = width();
	int iH = height();

	//绘制工具栏外框
	paiter.drawRect(QRect(0,0,iW -1,iH -1));

	if (ToolBarDir_H == m_iDir)//横向排列工具栏的
	{
		
	}
	else//纵向排列工具栏的
	{
		//竖直向下、图片在工具栏的中央。
		int iStartX = 0.5 * (iW - m_iBtnW);
		int iStartY = m_iBtnG;

		int iPicCnt = m_vecPics.size();
		for ( int i = 0; i < iPicCnt; i ++)
		{
			paiter.drawPixmap(iStartX, iStartY, m_iBtnW,m_iBtnH,*(m_vecPics[i]));
			if (m_iCurNo == i) //当前工具被选中、给其添加一个外框。
			{
				QRect rc(iStartX - 1, iStartY -1, m_iBtnW + 1, m_iBtnH + 1);
				paiter.drawRect(rc);
			}

			iStartY += (m_iBtnH + m_iBtnG);
		}
	}
}