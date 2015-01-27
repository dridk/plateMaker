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

    connect(pasteAction,SIGNAL(triggered()),this,SLOT(paste()));
    connect(copyAction,SIGNAL(triggered()),this,SLOT(copy()));

    mView->addAction(pasteAction);
    mView->addAction(copyAction);


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

void ParamWidget::setStringList(const QStringList &list)
{
    mModel->setStringList(list);



}

