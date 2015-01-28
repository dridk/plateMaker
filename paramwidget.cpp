#include "paramwidget.h"
#include <QClipboard>
#include <QDebug>
#include <QAction>
#include <QApplication>
#include <QHeaderView>
ParamWidget::ParamWidget(QWidget *parent) : QTableView(parent)
{
    mModel = new ParamModel;
    setModel(mModel);

    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setDefaultSectionSize(20);
    setAlternatingRowColors(true);

    horizontalHeader()->hide();



    QAction  * pasteAction = new QAction("Paste",this);
    QAction  * copyAction = new QAction("Copy",this);
    QAction  * cutAction = new QAction("Cut",this);
    QAction  * delAction = new QAction("del",this);
    QAction  * insertAction = new QAction("Insert",this);

    connect(pasteAction,SIGNAL(triggered()),this,SLOT(paste()));
    connect(copyAction,SIGNAL(triggered()),this,SLOT(copy()));
    connect(cutAction,SIGNAL(triggered()),this,SLOT(cut()));
    connect(delAction,SIGNAL(triggered()),this,SLOT(clear()));
    connect(insertAction,SIGNAL(triggered()),this,SLOT(insert()));

    addAction(insertAction);
    addAction(pasteAction);
    addAction(copyAction);
    addAction(cutAction);


}

ParamWidget::~ParamWidget()
{

}

QStringList ParamWidget::stringList() const
{
    return mModel->stringList();


}

void ParamWidget::setAlphabetic(bool active)
{
    mModel->setAlphabetic(active);

}


void ParamWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->matches(QKeySequence::Copy))
        copy();

    if (event->matches(QKeySequence::Paste))
        paste();

    if (event->matches(QKeySequence::Cut))
        cut();

    if (event->matches(QKeySequence::Delete))
        clear();

    if (event->key() == Qt::Key_Insert)
        insert();
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
    foreach (QModelIndex index, selectionModel()->selectedRows()){

        QString txt = index.data().toString();
        list.append(txt);
    }
    qApp->clipboard()->setText(list.join("\n"));


}

void ParamWidget::cut()
{
    copy();
    clear();
}

void ParamWidget::clear()
{
    QList<int> ids;
    QStringList list = mModel->stringList();
    foreach (QModelIndex index, selectionModel()->selectedRows()){
        ids.append(index.row());
    }

    qSort(ids.begin(), ids.end(), qGreater<int>());

    foreach (int id, ids){
       list.removeAt(id);
        qDebug()<<id;
    }


    mModel->setStringList(list);

}

void ParamWidget::insert()
{

    QStringList list = mModel->stringList();
    list.append("<value>");
    mModel->setStringList(list);



}

void ParamWidget::setData(const QStringList &list, const QStringList &headers)
{
    mModel->setStringList(list);
    mModel->setHeaders(headers);

}



