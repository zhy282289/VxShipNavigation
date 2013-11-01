#pragma once

#include "VxDBDelegateUi.h"

// 所有图表的基类
class CVxBaseTableWidget : public QTableWidget
{
	Q_OBJECT
public:
	CVxBaseTableWidget(QWidget *parent = NULL);
	~CVxBaseTableWidget();

protected:



private:

};


class CVxButton;
class CVxLabel;
class CVxLineEdit;

class CVxSeaChartTableView;

// 海图信息窗口
class CVxSeaChartView : public QWidget
{
	Q_OBJECT
public:
	CVxSeaChartView(QWidget *parent = NULL);
	~CVxSeaChartView();

protected:
	void		resizeEvent(QResizeEvent *event);

private slots:
	void		SlotOkBtn();
	void		SlotCancelBtn();

private:

private:
	CVxSeaChartTableView		*m_seaChartTableView;
	CVxButton					*m_okBtn;
	CVxButton					*m_cancelBtn;

	//CVxSailMapInfos				m_sailMapInfos;
private:

};


// 海图信息表
class CVxSeaChartTableView : public CVxBaseTableWidget
{

	enum {ID, NAME, SCALE, BASELATITUDE, STYLE, POSITION1, POSITION2};
	enum {COLUMN_COUNT = 7, ROW_COUNT = 1};
	Q_OBJECT
public:
	CVxSeaChartTableView(QWidget *parent = NULL);
	~CVxSeaChartTableView();

	void	AddRow(const CVxSailMapInfo &info);
	void	InsertRow(int row, const CVxSailMapInfo &info);
	void	ModifyRow(const CVxSailMapInfo &info);
	void	OkBtn();

protected:
	void	InitView();
	bool	GetSailMapInfo(const QString &id, CVxSailMapInfo &info);
	int		FindRow(const QString id);
private slots:
	void	SlotDelegateFinish(int row, QWidget *editor, QString id);

private:

	CVxSailMapInfos				m_sailMapInfos;

	IDLineEditDelegate			*m_idDelegate;
	NameLineEditDelegate		*m_nameDelegate;

	bool						m_hasSailMapInfo;
};

class CVxPlanRoutesTableView;
// 计划航线窗口
class CVxPlanRoutesView : public QWidget
{
	Q_OBJECT
public:
	CVxPlanRoutesView(QWidget *parent = NULL);
	~CVxPlanRoutesView();

protected:
	void		resizeEvent(QResizeEvent *event);

private slots:
	void		SlotLookupBtn();
	void		SlotNewBtn();
	void		SlotSetCurBtn();
	void		SlotReturnBtn();
	void		SlotSendBtn();
	void		SlotDeleteBtn();
	void		SlotCancelBtn();


private:
	void		InitView();


private:
	CVxPlanRoutesTableView		*m_planRoutesTableView;
	CVxButton					*m_lookupBtn;
	CVxButton					*m_newBtn;
	CVxButton					*m_setCurBtn;
	CVxButton					*m_returnBtn;
	CVxButton					*m_sendBtn;
	CVxButton					*m_deleteBtn;
	CVxButton					*m_cancelBtn;

	CVxPlanRoutes				m_planRoutes;
};

// 计划航线表
class CVxPlanRoutesTableView : public CVxBaseTableWidget
{

	enum {ID, NAME, STARTPOSITION, ENDPOSITION, SECTIONS, TYPE, SUMBITTIME};
	enum {COLUMN_COUNT = 7, ROW_COUNT = 0};
	Q_OBJECT
public:
	CVxPlanRoutesTableView(QWidget *parent = NULL);
	~CVxPlanRoutesTableView();

	void	AddRow(const CVxPlanRoute &info);
protected:



private:
};


class CVxPlanRouteInfoTableView;
// 查看计划航线信息窗口
class CVxLookupPlanRouteView : public QDialog
{
	Q_OBJECT
public:
	CVxLookupPlanRouteView(QWidget *parent = NULL);
	~CVxLookupPlanRouteView();

protected:
	void		resizeEvent(QResizeEvent *event);

private slots:
	void		SlotSetCurBtn();
	void		SlotRetRouteBtn();
	void		SlotModifyBtn();
	void		SlotReturnBtn();
	//void		SlotSendBtn();
	//void		SlotDeleteBtn();
	//void		SlotCancelBtn();


private:
	//void		InitView();


private:
	CVxPlanRouteInfoTableView		*m_planRouteInfoTableView;

	CVxLabel					*m_lbRouteName;
	CVxLineEdit					*m_ledRouteName;

	CVxButton					*m_setCurBtn;
	CVxButton					*m_retRouteBtn;
	CVxButton					*m_modifyBtn;
	CVxButton					*m_returnBtn;


	//CVxPlanRoutes				m_planRoutes;
};

// 修改计划航线信息窗口
class CVxModifyPlanRouteView : public QDialog
{
	Q_OBJECT
public:
	CVxModifyPlanRouteView(QWidget *parent = NULL);
	~CVxModifyPlanRouteView();

protected:
	void		resizeEvent(QResizeEvent *event);

private slots:
	void		SlotSaveBtn();
	void		SlotCancelBtn();

private:
	//void		InitView();


private:
	CVxPlanRouteInfoTableView		*m_planRouteInfoTableView;

	CVxLabel					*m_lbRouteName;
	CVxLineEdit					*m_ledRouteName;

	CVxButton					*m_saveBtn;
	CVxButton					*m_cancelBtn;


};



// 新建计划航线信息窗口
class CVxCreatePlanRouteView : public QDialog
{
	Q_OBJECT
public:
	CVxCreatePlanRouteView(QWidget *parent = NULL);
	~CVxCreatePlanRouteView();

protected:
	void		resizeEvent(QResizeEvent *event);

private slots:
	void		SlotSaveBtn();
	void		SlotClearBtn();
	void		SlotCancelBtn();
	//void		SlotReturnBtn();
	//void		SlotSendBtn();
	//void		SlotDeleteBtn();
	//void		SlotCancelBtn();


private:
	//void		InitView();


private:
	CVxPlanRouteInfoTableView		*m_planRouteInfoTableView;

	CVxLabel					*m_lbRouteName;
	CVxLineEdit					*m_ledRouteName;

	CVxButton					*m_saveBtn;
	CVxButton					*m_clearBtn;
	CVxButton					*m_cancelBtn;


	//CVxPlanRoutes				m_planRoutes;
};



// 计划航线信息表
class CVxPlanRouteInfoTableView : public CVxBaseTableWidget
{
	enum {ID, LONGITUDE, LATITUDE, SPEED, DIRECTION, DISTANCE, TOTALDISTANCE, WARNNING, TIME, TOTALTIME};
	enum {COLUMN_COUNT = 10, ROW_COUNT = 0};
	Q_OBJECT
public:
	CVxPlanRouteInfoTableView(QWidget *parent = NULL);
	~CVxPlanRouteInfoTableView();


	void	AddRow(const CVxPlanRoute &info);
protected:



private:
};


class CVxSailRecordsTableView;
// 航行记录窗口
class CVxSailRecordsView : public QDialog
{
	Q_OBJECT
public:
	CVxSailRecordsView(QWidget *parent = NULL);
	~CVxSailRecordsView();

protected:
	void		resizeEvent(QResizeEvent *event);

private slots:
	void		SlotFirstPageBtn();
	void		SlotPrePageBtn();
	void		SlotNextPageBtn();
	void		SlotLastPageBtn();
	void		SlotGotoPageBtn();
	void		SlotCancelBtn();


private:
	void		InitView();


private:
	CVxSailRecordsTableView		*m_sailRecordsTableView;


	CVxButton					*m_firstPageBtn;
	CVxButton					*m_prePageBtn;
	CVxButton					*m_nextPageBtn;
	CVxButton					*m_lastPageBtn;
	CVxButton					*m_gotoPageBtn;
	CVxButton					*m_cancelBtn;

	CVxRouteRecords				m_routeRecords;
};



// 航行记录表
class CVxSailRecordsTableView : public CVxBaseTableWidget
{
	enum {TIME, LATITUDE, LONGITUDE, COURSE, SPEED, COMPOUNDCOURSE, GROUNDSPEED, FLOWDIRECTION, FLOWRATE, WINDDIRECTION};
	enum {COLUMN_COUNT = 10, ROW_COUNT = 0};
	Q_OBJECT
public:
	CVxSailRecordsTableView(QWidget *parent = NULL);
	~CVxSailRecordsTableView();


	void	AddRow(const CVxRouteRecord &info);
protected:
	


private:
};


class CVxButton : public QPushButton
{
	Q_OBJECT
public:
	CVxButton(QWidget *parent = NULL);
	CVxButton(const QString & text, QWidget * parent = 0);
};


class CVxLabel : public QLabel
{
	Q_OBJECT
public:
	CVxLabel(QWidget *parent = NULL);
	CVxLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0);

};

class CVxLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	CVxLineEdit(QWidget * parent = 0);
	CVxLineEdit(const QString & contents, QWidget * parent = 0);
};