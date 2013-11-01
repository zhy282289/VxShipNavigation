
#include "stdafx.h"
#include "VxDBDelegateUi.h"

CVxDBLineEdit::CVxDBLineEdit( QWidget *parent /*= NULL*/ )
	: QLineEdit(parent)
{
	setStyleSheet("CVxDBLineEdit{border: 1px solid gray;}");
}


//////////////////////////////////////////////////////////////////////////

IDLineEditDelegate::IDLineEditDelegate( QWidget *parent /*= 0*/ )
	: QStyledItemDelegate(parent)
{

}


QWidget * IDLineEditDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	CVxDBLineEdit *editor = new CVxDBLineEdit(parent);
	editor->setValidator(new QIntValidator(0, 100000, editor));
	editor->setStyleSheet("CVxLineEdit{border: 1px solid red;}");
	connect(editor, SIGNAL(editingFinished()), this, SLOT(commitAndCloseEditor()));
	return editor;
}

void IDLineEditDelegate::setEditorData( QWidget *editor, const QModelIndex &index ) const
{
	QString text = index.data().toString();
	((CVxDBLineEdit*)editor)->setText(text);
}

void IDLineEditDelegate::setModelData( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
	QString text = ((CVxDBLineEdit*)editor)->text();
	model->setData(index, text);
}

void IDLineEditDelegate::commitAndCloseEditor()
{
	CVxDBLineEdit *editor = (CVxDBLineEdit*)sender();
	emit commitData(editor);
	emit Finish(0, editor, editor->text());

}

void IDLineEditDelegate::CloseEditAndNextItem(QWidget *editor)
{
	emit closeEditor(editor, QAbstractItemDelegate::EditNextItem);
}

void IDLineEditDelegate::CloseEdit(QWidget *editor)
{
	emit closeEditor(editor);
}




//////////////////////////////////////////////////////////////////////////

NameLineEditDelegate::NameLineEditDelegate( QWidget *parent /*= NULL*/ )
	: QStyledItemDelegate(parent)
{

}

QWidget * NameLineEditDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	CVxDBLineEdit *editor = new CVxDBLineEdit(parent);
	connect(editor, SIGNAL(editingFinished()), this, SLOT(commitAndCloseEditor()));
	return editor;
}

void NameLineEditDelegate::setEditorData( QWidget *editor, const QModelIndex &index ) const
{
	QString text = index.data().toString();
	((CVxDBLineEdit*)editor)->setText(text);
}

void NameLineEditDelegate::setModelData( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
	QString text = ((CVxDBLineEdit*)editor)->text();
	model->setData(index, text);
}

void NameLineEditDelegate::commitAndCloseEditor()
{
	CVxDBLineEdit *editor = (CVxDBLineEdit*)sender();
	emit commitData(editor);
	emit Finish(1, editor, editor->text());

}

void NameLineEditDelegate::CloseEditAndNextItem(QWidget *editor)
{
	emit closeEditor(editor, QAbstractItemDelegate::EditNextItem);
}

void NameLineEditDelegate::CloseEdit(QWidget *editor)
{
	emit closeEditor(editor);
}
