
#pragma once




class CVxDBLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	CVxDBLineEdit(QWidget *parent = NULL);
};




class IDLineEditDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	IDLineEditDelegate(QWidget *parent = 0) ;


	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void CloseEditAndNextItem(QWidget *editor);
	void CloseEdit(QWidget *editor);

signals:
	void Finish(int row, QWidget *editor,QString id);

public slots:
	void commitAndCloseEditor();


};

class NameLineEditDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	NameLineEditDelegate(QWidget *parent = NULL);
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void CloseEditAndNextItem(QWidget *editor);
	void CloseEdit(QWidget *editor);

signals:
	void Finish(int row, QWidget *editor,QString id);

public slots:
	void commitAndCloseEditor();
};