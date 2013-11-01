#include "stdafx.h"
#include "VxDBUi.h"


const int BTN_WIDTH = 72;
const int BTN_HEIGHT = 24;


CVxSeaChartView::CVxSeaChartView( QWidget *parent /*= NULL*/ )
	:QWidget(parent)
{
	setWindowTitle("��ͼװ��");
	setMinimumSize(550, 350);
	m_seaChartTableView = new CVxSeaChartTableView(this);

	m_okBtn = new CVxButton("ȷ��", this);
	m_cancelBtn = new CVxButton("ȡ��", this);

	connect(m_okBtn, SIGNAL(clicked()), this, SLOT(SlotOkBtn()));
	connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(SlotCancelBtn()));

	//InitView();

}

CVxSeaChartView::~CVxSeaChartView()
{

}

void CVxSeaChartView::SlotOkBtn()
{
	m_seaChartTableView->OkBtn();
}

void CVxSeaChartView::SlotCancelBtn()
{

}

void CVxSeaChartView::resizeEvent( QResizeEvent *event )
{
	const int margin = 10;
	int w = this->rect().width();
	int h = this->rect().height();
	int left = margin;
	int top = margin;
	int bottomh = 70;

	m_seaChartTableView->setGeometry(margin, margin, w - 2*margin, h - bottomh);
	left = w / 2 - BTN_WIDTH - BTN_WIDTH / 2;
	top = m_seaChartTableView->geometry().bottom() + 2*margin;
	m_okBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = w / 2 + BTN_WIDTH / 2;
	m_cancelBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
}





//////////////////////////////////////////////////////////////////////////
CVxBaseTableWidget::CVxBaseTableWidget( QWidget *parent /*= NULL*/ )
	: QTableWidget(parent)
{
	verticalHeader()->hide();
	horizontalHeader()->setStretchLastSection(true);

	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setWordWrap(true);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setStyleSheet("CVxBaseTableWidget::item{height: 15px; selection-background-color: rgb(0,220,250);}");
}

CVxBaseTableWidget::~CVxBaseTableWidget()
{

}



//////////////////////////////////////////////////////////////////////////
CVxSeaChartTableView::CVxSeaChartTableView( QWidget *parent /*= NULL*/ )
	: CVxBaseTableWidget(parent)
{

	//setEditTriggers(QAbstractItemView::NoEditTriggers);

	setColumnCount(COLUMN_COUNT);
	setRowCount(ROW_COUNT);

	
	QTableWidgetItem *newItem = new QTableWidgetItem();
	Qt::ItemFlags flags = newItem->flags() | Qt::ItemIsEditable;
	const int row = 0;
	newItem->setFlags(flags);
	this->setItem(row, ID, newItem);
	newItem = new QTableWidgetItem();
	newItem->setFlags(flags);
	this->setItem(row, NAME, newItem);
	newItem = new QTableWidgetItem();
	newItem->setFlags(flags);
	this->setItem(row, SCALE, newItem);
	newItem->setFlags(flags);
	newItem = new QTableWidgetItem();
	this->setItem(row, BASELATITUDE, newItem);
	newItem->setFlags(flags);
	newItem = new QTableWidgetItem();
	newItem->setFlags(flags);
	this->setItem(row, STYLE, newItem);
	newItem = new QTableWidgetItem();
	newItem->setFlags(flags);
	this->setItem(row, POSITION1, newItem);
	newItem = new QTableWidgetItem();
	newItem->setFlags(flags);
	this->setItem(row, POSITION2, newItem);


	QStringList headers;
	headers << "ͼ��" << "ͼ��" << "������" << "��׼γ��" << "ͶӰ��ʽ" << "λ��1" << "λ��2";
	setHorizontalHeaderLabels(headers);

	m_idDelegate = new IDLineEditDelegate(this);
	connect(m_idDelegate, SIGNAL(Finish(int,QWidget*,QString)), this, SLOT(SlotDelegateFinish(int,QWidget*,QString)));
	setItemDelegateForColumn(ID, m_idDelegate);

	m_nameDelegate = new NameLineEditDelegate(this);
	connect(m_nameDelegate, SIGNAL(Finish(int,QWidget*,QString)), this, SLOT(SlotDelegateFinish(int,QWidget*,QString)));
	setItemDelegateForColumn(NAME, m_nameDelegate);


	InitView();
}

CVxSeaChartTableView::~CVxSeaChartTableView()
{

}

void CVxSeaChartTableView::AddRow( const CVxSailMapInfo &info )
{
	Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;

	int row = this->rowCount();
	this->insertRow(row);
	QTableWidgetItem *newItem = new QTableWidgetItem(info.id);
	newItem->setFlags(flags);
	this->setItem(row, ID, newItem);
	newItem = new QTableWidgetItem(info.name);
	newItem->setFlags(flags);
	this->setItem(row, NAME, newItem);
	newItem = new QTableWidgetItem(info.scale);
	newItem->setFlags(flags);
	this->setItem(row, SCALE, newItem);
	newItem = new QTableWidgetItem(info.baselatitude);
	newItem->setFlags(flags);
	this->setItem(row, BASELATITUDE, newItem);
	newItem = new QTableWidgetItem(info.style);
	newItem->setFlags(flags);
	this->setItem(row, STYLE, newItem);
	newItem = new QTableWidgetItem(info.position1);
	newItem->setFlags(flags);
	this->setItem(row, POSITION1, newItem);
	newItem = new QTableWidgetItem(info.position2);
	newItem->setFlags(flags);
	this->setItem(row, POSITION2, newItem);

}


void CVxSeaChartTableView::InsertRow( int row, const CVxSailMapInfo &info )
{
	Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	this->insertRow(row);
	QTableWidgetItem *newItem = new QTableWidgetItem(info.id);
	newItem->setFlags(flags);
	this->setItem(row, ID, newItem);
	newItem = new QTableWidgetItem(info.name);
	newItem->setFlags(flags);
	this->setItem(row, NAME, newItem);
	newItem = new QTableWidgetItem(info.scale);
	newItem->setFlags(flags);
	this->setItem(row, SCALE, newItem);
	newItem = new QTableWidgetItem(info.baselatitude);
	newItem->setFlags(flags);
	this->setItem(row, BASELATITUDE, newItem);
	newItem = new QTableWidgetItem(info.style);
	newItem->setFlags(flags);
	this->setItem(row, STYLE, newItem);
	newItem = new QTableWidgetItem(info.position1);
	newItem->setFlags(flags);
	this->setItem(row, POSITION1, newItem);
	newItem = new QTableWidgetItem(info.position2);
	newItem->setFlags(flags);
	this->setItem(row, POSITION2, newItem);
}



void CVxSeaChartTableView::ModifyRow(const CVxSailMapInfo &info )
{
	int row = FindRow(info.id);
	if (row != -1)
	{
		item(row, ID)->setText(info.id);
		item(row, NAME)->setText(info.name);
		item(row, SCALE)->setText(info.scale);
		item(row, BASELATITUDE)->setText(info.baselatitude);
		item(row, STYLE)->setText(info.style);
		item(row, POSITION1)->setText(info.position1);
		item(row, POSITION2)->setText(info.position2);
	}

}

void CVxSeaChartTableView::SlotDelegateFinish(int row, QWidget *editor, QString id )
{
	CVxSailMapInfo info;


	switch (row)
	{
	case ID:
		{
			m_hasSailMapInfo = GetSailMapInfo(id, info);
			const int row = 0;
			item(row, NAME)->setText(info.name);
			item(row, SCALE)->setText(info.scale);
			item(row, BASELATITUDE)->setText(info.baselatitude);
			item(row, STYLE)->setText(info.style);
			item(row, POSITION1)->setText(info.position1);
			item(row, POSITION2)->setText(info.position2);
			if (m_hasSailMapInfo)
			{
				m_idDelegate->CloseEdit(editor);
			}
			else
			{
				m_idDelegate->CloseEditAndNextItem(editor);
			}
		}
		break;
	case NAME:
		{
			m_idDelegate->CloseEditAndNextItem(editor);
		}
		break;
	default:
		;
	}

}

void CVxSeaChartTableView::InitView()
{
	GetDBController()->QuerySailMaps(m_sailMapInfos);
	for (int i = 0; i < m_sailMapInfos.size(); i++)
	{
		CVxSailMapInfo &sailMapInfo = m_sailMapInfos[i];
		AddRow(sailMapInfo);
	}
}

bool CVxSeaChartTableView::GetSailMapInfo( const QString &id, CVxSailMapInfo &info )
{
	for (int i = 0; i < m_sailMapInfos.size(); ++i)
	{
		CVxSailMapInfo &sialMapIfo = m_sailMapInfos[i];
		if (sialMapIfo.id == id)
		{
			info = sialMapIfo;
			return true;
		}
	}

	return false;
}

void CVxSeaChartTableView::OkBtn()
{
	CVxSailMapInfo sailMapInfo;
	const int row = 0;
	sailMapInfo.id = item(row, ID)->text();
	sailMapInfo.name = item(row, NAME)->text();
	sailMapInfo.scale = item(row, SCALE)->text();
	sailMapInfo.baselatitude = item(row, BASELATITUDE)->text();
	sailMapInfo.style = item(row, STYLE)->text();
	sailMapInfo.position1 = item(row, POSITION1)->text();
	sailMapInfo.position2 = item(row, POSITION2)->text();
	
	if (m_hasSailMapInfo)
	{
		GetDBController()->UpdateSailMap(sailMapInfo);

		// ���½���
		ModifyRow(sailMapInfo);
	}
	else
	{
		GetDBController()->InsertSailMap(sailMapInfo);

		// ���½���
		AddRow(sailMapInfo);
	}
}

int CVxSeaChartTableView::FindRow( const QString id )
{
	int row = rowCount();
	for (int i = 1; i < row; ++i)
	{
		QTableWidgetItem *item = this->item(i, ID);
		if (item->text() == id)
		{
			return i;
		}
	}
	return -1;
}



//////////////////////////////////////////////////////////////////////////
CVxButton::CVxButton( QWidget *parent /*= NULL*/ )
	: QPushButton(parent)
{

}

CVxButton::CVxButton( const QString & text, QWidget * parent /*= 0*/ )
	: QPushButton(text, parent)
{

}


//////////////////////////////////////////////////////////////////////////
CVxPlanRoutesTableView::CVxPlanRoutesTableView( QWidget *parent /*= NULL*/ )
	: CVxBaseTableWidget(parent)
{
	setColumnCount(COLUMN_COUNT);
	setRowCount(ROW_COUNT);

	QStringList headers;
	headers << "���" << "������" << "���λ��" << "�յ�λ��" << "������" << "����" << "�ύʱ��";
	setHorizontalHeaderLabels(headers);
}

CVxPlanRoutesTableView::~CVxPlanRoutesTableView()
{

}

void CVxPlanRoutesTableView::AddRow( const CVxPlanRoute &info )
{
	int row = this->rowCount();
	this->insertRow(row);
	QTableWidgetItem *newItem = new QTableWidgetItem(info.id);
	this->setItem(row, ID, newItem);
	newItem = new QTableWidgetItem(info.name);
	this->setItem(row, NAME, newItem);
	newItem = new QTableWidgetItem(info.startposition);
	this->setItem(row, STARTPOSITION, newItem);
	newItem = new QTableWidgetItem(info.endposition);
	this->setItem(row, ENDPOSITION, newItem);
	newItem = new QTableWidgetItem(info.sections);
	this->setItem(row, SECTIONS, newItem);
	newItem = new QTableWidgetItem(info.type);
	this->setItem(row, TYPE, newItem);
	newItem = new QTableWidgetItem(info.sumbittime);
	this->setItem(row, SUMBITTIME, newItem);
}

CVxPlanRoutesView::CVxPlanRoutesView( QWidget *parent /*= NULL*/ )
	: QWidget(parent)
{
	setWindowTitle("�ƻ�����");
	setMinimumSize(550, 350);
	m_planRoutesTableView = new CVxPlanRoutesTableView(this);

	m_lookupBtn = new CVxButton("�鿴", this);
	m_newBtn = new CVxButton("�½�", this);
	m_setCurBtn = new CVxButton("��Ϊ��ǰ", this);
	m_returnBtn = new CVxButton("����", this);
	m_sendBtn = new CVxButton("����", this);
	m_deleteBtn = new CVxButton("ɾ��", this);
	m_cancelBtn = new CVxButton("ȡ��", this);


	connect(m_lookupBtn, SIGNAL(clicked()), this, SLOT(SlotLookupBtn()));
	connect(m_newBtn, SIGNAL(clicked()), this, SLOT(SlotNewBtn()));
	connect(m_setCurBtn, SIGNAL(clicked()), this, SLOT(SlotSetCurBtn()));
	connect(m_returnBtn, SIGNAL(clicked()), this, SLOT(SlotReturnBtn()));
	connect(m_sendBtn, SIGNAL(clicked()), this, SLOT(SlotSendBtn()));
	connect(m_deleteBtn, SIGNAL(clicked()), this, SLOT(SlotDeleteBtn()));
	connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(SlotCancelBtn()));
	

	InitView();
}

CVxPlanRoutesView::~CVxPlanRoutesView()
{

}

void CVxPlanRoutesView::resizeEvent( QResizeEvent *event )
{
	const int margin = 10;
	int w = this->rect().width();
	int h = this->rect().height();
	int left = margin;
	int top = margin;
	int bottomh = 70;

	m_planRoutesTableView->setGeometry(left, top, w-2*margin, h-bottomh);
	top = m_planRoutesTableView->geometry().bottom() + 2*margin;

	int totalbtnw = 7 * BTN_WIDTH + 6 * margin;
	left = (w - totalbtnw) / 2;
	m_lookupBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_lookupBtn->geometry().right() + margin;
	m_newBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_newBtn->geometry().right() + margin;
	m_setCurBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_setCurBtn->geometry().right() + margin;
	m_returnBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_returnBtn->geometry().right() + margin;
	m_sendBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_sendBtn->geometry().right() + margin;
	m_deleteBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_deleteBtn->geometry().right() + margin;
	m_cancelBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);

}


void CVxPlanRoutesView::InitView()
{
	GetDBController()->QueryPlanRoutes(m_planRoutes);
	for (int i = 0; i < m_planRoutes.size(); i++)
	{
		CVxPlanRoute &planRoute = m_planRoutes[i];
		m_planRoutesTableView->AddRow(planRoute);
	}
}


void CVxPlanRoutesView::SlotLookupBtn()
{
	CVxLookupPlanRouteView lookupPlanRouteView(this);

	lookupPlanRouteView.exec();
}

void CVxPlanRoutesView::SlotNewBtn()
{
	CVxCreatePlanRouteView createPlanRouteView(this);
	createPlanRouteView.exec();
}

void CVxPlanRoutesView::SlotSetCurBtn()
{

}

void CVxPlanRoutesView::SlotReturnBtn()
{

}

void CVxPlanRoutesView::SlotSendBtn()
{

}

void CVxPlanRoutesView::SlotDeleteBtn()
{

}

void CVxPlanRoutesView::SlotCancelBtn()
{

}


//////////////////////////////////////////////////////////////////////////
CVxPlanRouteInfoTableView::CVxPlanRouteInfoTableView( QWidget *parent /*= NULL*/ )
	: CVxBaseTableWidget(parent)
{
	setColumnCount(COLUMN_COUNT);
	setRowCount(ROW_COUNT);

	QStringList headers;
	headers << "���" << "����" << "γ��" << "����" << "��λ" << "����" << "�ܾ���" << "ƫ������" << "ʱ��" << "��ʱ��";
	setHorizontalHeaderLabels(headers);
}

CVxPlanRouteInfoTableView::~CVxPlanRouteInfoTableView()
{

}

void CVxPlanRouteInfoTableView::AddRow( const CVxPlanRoute &info )
{
	//int row = this->rowCount();
	//this->insertRow(row);
	//QTableWidgetItem *newItem = new QTableWidgetItem(info.id);
	//this->setItem(row, ID, newItem);
	//newItem = new QTableWidgetItem(info.name);
	//this->setItem(row, NAME, newItem);
	//newItem = new QTableWidgetItem(info.startposition);
	//this->setItem(row, STARTPOSITION, newItem);
	//newItem = new QTableWidgetItem(info.endposition);
	//this->setItem(row, ENDPOSITION, newItem);
	//newItem = new QTableWidgetItem(info.sections);
	//this->setItem(row, SECTIONS, newItem);
	//newItem = new QTableWidgetItem(info.type);
	//this->setItem(row, TYPE, newItem);
	//newItem = new QTableWidgetItem(info.sumbittime);
	//this->setItem(row, SUMBITTIME, newItem);
}

//////////////////////////////////////////////////////////////////////////
CVxLookupPlanRouteView::CVxLookupPlanRouteView( QWidget *parent /*= NULL*/ )
	: QDialog(parent)
{
	setWindowTitle("������Ϣ(�鿴)");
	setMinimumSize(550, 350);
	resize(1000, 570);
	m_planRouteInfoTableView = new CVxPlanRouteInfoTableView(this);

	m_lbRouteName = new CVxLabel("������:", this);
	m_ledRouteName = new CVxLineEdit(this);

	m_setCurBtn = new CVxButton("��Ϊ��ǰ", this);
	m_retRouteBtn = new CVxButton("����", this);
	m_modifyBtn = new CVxButton("�޸�", this);
	m_returnBtn = new CVxButton("����", this);

	connect(m_setCurBtn, SIGNAL(clicked()), this, SLOT(SlotSetCurBtn()));
	connect(m_retRouteBtn, SIGNAL(clicked()), this, SLOT(SlotRetRouteBtn()));
	connect(m_modifyBtn, SIGNAL(clicked()), this, SLOT(SlotModifyBtn()));
	connect(m_returnBtn, SIGNAL(clicked()), this, SLOT(SlotReturnBtn()));

	//InitView();
}



CVxLookupPlanRouteView::~CVxLookupPlanRouteView()
{

}

void CVxLookupPlanRouteView::resizeEvent( QResizeEvent *event )
{
	const int margin = 10;
	int w = this->rect().width();
	int h = this->rect().height();
	int left = margin;
	int top = margin;
	int bottomh = 70;

	m_lbRouteName->setGeometry(left, top, 50, BTN_HEIGHT);
	left = m_lbRouteName->geometry().right() + 2;
	m_ledRouteName->setGeometry(left, top, 120, BTN_HEIGHT);

	left = margin;
	top = m_ledRouteName->geometry().bottom() + 2;

	m_planRouteInfoTableView->setGeometry(left, top, w-2*margin, h-bottomh-BTN_HEIGHT);
	top = m_planRouteInfoTableView->geometry().bottom() + 2*margin;

	int totalbtnw = 4 * BTN_WIDTH + 3 * margin;
	left = (w - totalbtnw) / 2;
	m_setCurBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_setCurBtn->geometry().right() + margin;
	m_retRouteBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_retRouteBtn->geometry().right() + margin;
	m_modifyBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_modifyBtn->geometry().right() + margin;
	m_returnBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
}

void CVxLookupPlanRouteView::SlotSetCurBtn()
{

}

void CVxLookupPlanRouteView::SlotRetRouteBtn()
{

}

void CVxLookupPlanRouteView::SlotModifyBtn()
{
	CVxModifyPlanRouteView modifyPlanRouteView(this);
	modifyPlanRouteView.exec();
}

void CVxLookupPlanRouteView::SlotReturnBtn()
{

}

//////////////////////////////////////////////////////////////////////////
CVxLabel::CVxLabel( QWidget *parent /*= NULL*/ )
	: QLabel(parent)
{

}

CVxLabel::CVxLabel( const QString & text, QWidget * parent /*= 0*/, Qt::WindowFlags f /*= 0*/ )
	: QLabel(text, parent, f)
{

}

CVxLineEdit::CVxLineEdit( QWidget * parent /*= 0*/ )
	: QLineEdit(parent)
{

}

CVxLineEdit::CVxLineEdit( const QString & contents, QWidget * parent /*= 0*/ )
	: QLineEdit(contents, parent)
{

}

//////////////////////////////////////////////////////////////////////////
CVxCreatePlanRouteView::CVxCreatePlanRouteView( QWidget *parent /*= NULL*/ )
	: QDialog(parent)
{
	setWindowTitle("������Ϣ(�½�)");
	setMinimumSize(550, 350);
	resize(1000, 570);

	m_planRouteInfoTableView = new CVxPlanRouteInfoTableView(this);

	m_lbRouteName = new CVxLabel("������:", this);
	m_ledRouteName = new CVxLineEdit(this);

	m_saveBtn = new CVxButton("����", this);
	m_clearBtn = new CVxButton("���", this);
	m_cancelBtn = new CVxButton("ȡ��", this);


	connect(m_saveBtn, SIGNAL(clicked()), this, SLOT(SlotSaveBtn()));
	connect(m_clearBtn, SIGNAL(clicked()), this, SLOT(SlotClearBtn()));
	connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(SlotCancelBtn()));

}

CVxCreatePlanRouteView::~CVxCreatePlanRouteView()
{

}

void CVxCreatePlanRouteView::resizeEvent( QResizeEvent *event )
{
	const int margin = 10;
	int w = this->rect().width();
	int h = this->rect().height();
	int left = margin;
	int top = margin;
	int bottomh = 70;

	m_lbRouteName->setGeometry(left, top, 50, BTN_HEIGHT);
	left = m_lbRouteName->geometry().right() + 2;
	m_ledRouteName->setGeometry(left, top, 120, BTN_HEIGHT);

	left = margin;
	top = m_ledRouteName->geometry().bottom() + 2;

	m_planRouteInfoTableView->setGeometry(left, top, w-2*margin, h-bottomh-BTN_HEIGHT);
	top = m_planRouteInfoTableView->geometry().bottom() + 2*margin;

	int totalbtnw = 3 * BTN_WIDTH + 2 * margin;
	left = (w - totalbtnw) / 2;
	m_saveBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_saveBtn->geometry().right() + margin;
	m_clearBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_clearBtn->geometry().right() + margin;
	m_cancelBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
}

void CVxCreatePlanRouteView::SlotSaveBtn()
{

}

void CVxCreatePlanRouteView::SlotClearBtn()
{

}

void CVxCreatePlanRouteView::SlotCancelBtn()
{

}

//////////////////////////////////////////////////////////////////////////
CVxModifyPlanRouteView::CVxModifyPlanRouteView( QWidget *parent /*= NULL*/ )
	: QDialog(parent)
{
	setWindowTitle("������Ϣ(�޸�)");
	setMinimumSize(550, 350);
	resize(1000, 570);
	m_planRouteInfoTableView = new CVxPlanRouteInfoTableView(this);

	m_lbRouteName = new CVxLabel("������:", this);
	m_ledRouteName = new CVxLineEdit(this);

	m_saveBtn = new CVxButton("����", this);
	m_cancelBtn = new CVxButton("ȡ��", this);


	connect(m_saveBtn, SIGNAL(clicked()), this, SLOT(SlotSaveBtn()));
	connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(SlotCancelBtn()));

}

CVxModifyPlanRouteView::~CVxModifyPlanRouteView()
{

}

void CVxModifyPlanRouteView::resizeEvent( QResizeEvent *event )
{
	const int margin = 10;
	int w = this->rect().width();
	int h = this->rect().height();
	int left = margin;
	int top = margin;
	int bottomh = 70;

	m_lbRouteName->setGeometry(left, top, 50, BTN_HEIGHT);
	left = m_lbRouteName->geometry().right() + 2;
	m_ledRouteName->setGeometry(left, top, 120, BTN_HEIGHT);

	left = margin;
	top = m_ledRouteName->geometry().bottom() + 2;

	m_planRouteInfoTableView->setGeometry(left, top, w-2*margin, h-bottomh-BTN_HEIGHT);
	top = m_planRouteInfoTableView->geometry().bottom() + 2*margin;

	int totalbtnw = 2 * BTN_WIDTH + 1 * margin;
	left = (w - totalbtnw) / 2;
	m_saveBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_saveBtn->geometry().right() + margin;
	m_cancelBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);

}

void CVxModifyPlanRouteView::SlotSaveBtn()
{

}

void CVxModifyPlanRouteView::SlotCancelBtn()
{

}


//////////////////////////////////////////////////////////////////////////
CVxSailRecordsTableView::CVxSailRecordsTableView( QWidget *parent /*= NULL*/ )
	: CVxBaseTableWidget(parent)
{
	setColumnCount(COLUMN_COUNT);
	setRowCount(ROW_COUNT);

	QStringList headers;
	headers << "ʱ��" << "γ��" << "����" << "����" << "����" << "������" << "����" << "����" << "����" << "����";
	setHorizontalHeaderLabels(headers);
}

CVxSailRecordsTableView::~CVxSailRecordsTableView()
{

}

void CVxSailRecordsTableView::AddRow( const CVxRouteRecord &info )
{
	int row = this->rowCount();
	this->insertRow(row);
	QTableWidgetItem *newItem = new QTableWidgetItem(info.time);
	this->setItem(row, TIME, newItem);
	newItem = new QTableWidgetItem(info.latitude);
	this->setItem(row, LATITUDE, newItem);
	newItem = new QTableWidgetItem(info.longitude);
	this->setItem(row, LONGITUDE, newItem);
	newItem = new QTableWidgetItem(info.course);
	this->setItem(row, COURSE, newItem);
	newItem = new QTableWidgetItem(info.speed);
	this->setItem(row, SPEED, newItem);
	newItem = new QTableWidgetItem(info.compoundcourse);
	this->setItem(row, COMPOUNDCOURSE, newItem);
	newItem = new QTableWidgetItem(info.groundspeed);
	this->setItem(row, GROUNDSPEED, newItem);
	newItem = new QTableWidgetItem(info.flowdirection);
	this->setItem(row, FLOWDIRECTION, newItem);
	newItem = new QTableWidgetItem(info.flowrate);
	this->setItem(row, FLOWRATE, newItem);
	newItem = new QTableWidgetItem(info.winddirection);
	this->setItem(row, WINDDIRECTION, newItem);
}

//////////////////////////////////////////////////////////////////////////



CVxSailRecordsView::CVxSailRecordsView( QWidget *parent /*= NULL*/ )
	: QDialog(parent)
{
	setWindowTitle("���м�¼");
	setMinimumSize(550, 350);
	resize(1000, 570);

	m_sailRecordsTableView = new CVxSailRecordsTableView(this);


	m_firstPageBtn = new CVxButton("��ҳ", this);
	m_prePageBtn = new CVxButton("��һҳ", this);
	m_nextPageBtn = new CVxButton("��һҳ", this);
	m_lastPageBtn = new CVxButton("βҳ", this);
	m_gotoPageBtn = new CVxButton("ת��", this);
	m_cancelBtn = new CVxButton("ȡ��", this);

	connect(m_firstPageBtn, SIGNAL(clicked()), this, SLOT(SlotFirstPageBtn()));
	connect(m_prePageBtn, SIGNAL(clicked()), this, SLOT(SlotPrePageBtn()));
	connect(m_nextPageBtn, SIGNAL(clicked()), this, SLOT(SlotNextPageBtn()));
	connect(m_lastPageBtn, SIGNAL(clicked()), this, SLOT(SlotLastPageBtn()));
	connect(m_gotoPageBtn, SIGNAL(clicked()), this, SLOT(SlotGotoPageBtn()));
	connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(SlotCancelBtn()));


	InitView();
}

CVxSailRecordsView::~CVxSailRecordsView()
{

}

void CVxSailRecordsView::resizeEvent( QResizeEvent *event )
{
	const int margin = 10;
	int w = this->rect().width();
	int h = this->rect().height();
	int left = margin;
	int top = margin;
	int bottomh = 50;

	m_sailRecordsTableView->setGeometry(left, top, w-2*margin, h-bottomh);
	top = m_sailRecordsTableView->geometry().bottom() + margin;

	int totalbtnw = 6 * BTN_WIDTH + 5 * margin;
	left = (w - totalbtnw) / 2;
	m_firstPageBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_firstPageBtn->geometry().right() + margin;
	m_prePageBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_prePageBtn->geometry().right() + margin;
	m_nextPageBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_nextPageBtn->geometry().right() + margin;
	m_lastPageBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_lastPageBtn->geometry().right() + margin;
	m_gotoPageBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);
	left = m_gotoPageBtn->geometry().right() + margin;
	m_cancelBtn->setGeometry(left, top, BTN_WIDTH, BTN_HEIGHT);


}

void CVxSailRecordsView::SlotFirstPageBtn()
{

}

void CVxSailRecordsView::SlotPrePageBtn()
{

}

void CVxSailRecordsView::SlotNextPageBtn()
{

}

void CVxSailRecordsView::SlotLastPageBtn()
{

}

void CVxSailRecordsView::SlotGotoPageBtn()
{

}

void CVxSailRecordsView::SlotCancelBtn()
{

}

void CVxSailRecordsView::InitView()
{
	GetDBController()->QuerySailRecords(m_routeRecords);
	for (int i = 0; i < m_routeRecords.size(); i++)
	{
		CVxRouteRecord &routeRecord = m_routeRecords[i];
		m_sailRecordsTableView->AddRow(routeRecord);
	}
}
