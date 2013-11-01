#include "stdafx.h"
#include "VxShipNavigation.h"
#include <QtGui/QApplication>



#include "VxDataDefine.h"


#include "VxDBUi.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
	InitDegreeStr();

	//CVxShipNavigation w;
	//w.setGeometry(100,100,500,600);
	//w.show();


	//TestDBControl testDBControl;

	CVxSeaChartView view;
	view.show();
	view.resize(1000, 570);


	//CVxPlanRoutesView planRoutesView;
	//planRoutesView.show();
	//planRoutesView.resize(1000, 570);


	//CVxSailRecordsView sailRecordsView;
	//sailRecordsView.show();
	//sailRecordsView.resize(1000, 570);


	return a.exec();
}
