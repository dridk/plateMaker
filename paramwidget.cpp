#include "paramwidget.h"
#include <QClipboard>
#include <QDebug>
#include <QAction>
#include <QApplication>
ParamWidget::ParamWidget(QWidget *parent) : QDockWidget(parent)
{
    mView = new QListView;
    mModel = new QStringListModel;

    mView->setModel(mModel);

    setWidget(mView);
    setFeatures(QDockWidget::NoDockWidgetFeatures);

    mView->setSelectionBehavior(QAbstractItemView::SelectRows);
    mView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    mView->setContextMenuPolicy(Qt::ActionsContextMenu);




    QAction  * pasteAction = new QAction("Paste",this);
    QAction  * copyAction = new QAction("Copy",this);
    QAction  * cutAction = new QAction("Cut",this);

    connect(pasteAction,SIGNAL(triggered()),this,SLOT(paste()));
    connect(copyAction,SIGNAL(triggered()),this,SLOT(copy()));
    connect(cutAction,SIGNAL(triggered()),this,SLOT(cut()));

    mView->addAction(pasteAction);
    mView->addAction(copyAction);
    mView->addAction(cutAction);


}

ParamWidget::~ParamWidget()
{

}

QStringList ParamWidget::stringList() const
{
    return mModel->stringList();

}

QListView *ParamWidget::view()
{
    return mView;
}

void ParamWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->matches(QKeySequence::Copy))
        copy();

    if (event->matches(QKeySequence::Paste))
        paste();

    if (event->matches(QKeySequence::Cut))
        cut();
}

void ParamWidget::paste()
{

    QString txt = qApp->clipboard()->text();
    QStringList list;

    foreach (QString item, txt.split("\n")) {
        if (!item.isEmpty())
            list.append(item);
    }

    mModel->setStringList(list);


}

void ParamWidget::copy()
{

    QStringList list;
    foreach (QModelIndex index, mView->selectionModel()->selectedRows()){

        QString txt = index.data().toString();
        list.append(txt);
    }


    qApp->clipboard()->setText(list.join("\n"));


}

void ParamWidget::cut()
{

    copy();
    QStringList list = mModel->stringList();

    foreach (QModelIndex index, mView->selectionModel()->selectedRows()){

       list.removeAll(index.data().toString());
    }

    mModel->setStringList(list);


}

void ParamWidget::setStringList(const QStringList &list)
{
    mModel->setStringList(list);



}

