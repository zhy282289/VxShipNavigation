/*


*/


#ifndef VXSHIPNAVIGATION_H
#define VXSHIPNAVIGATION_H

#include <QtGui/QWidget>

class CVxDisplayArea;



class CVxShipNavigation : public QWidget
{
	Q_OBJECT

public:
	CVxShipNavigation(QWidget *parent = 0, Qt::WFlags flags = 0/*Qt::FramelessWindowHint*/);
	~CVxShipNavigation();

protected:
	virtual void resizeEvent(QResizeEvent* pEvent);

private:

	CVxDisplayArea*  m_pDisplayArea;	
};

#endif // VXSHIPNAVIGATION_H
