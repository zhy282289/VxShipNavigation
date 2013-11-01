#include "stdafx.h"
#include "VxShipNavigation.h"
#include "VxDisplayArea.h"

CVxShipNavigation::CVxShipNavigation(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	m_pDisplayArea = new CVxDisplayArea(this);
}

CVxShipNavigation::~CVxShipNavigation()
{

}
void CVxShipNavigation::resizeEvent(QResizeEvent* pEvent)
{
	int iW = width();
	int iH = height();

	m_pDisplayArea->setGeometry(0, 0, iW, iH);
}