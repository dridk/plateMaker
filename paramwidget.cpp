/* PlateMaker
Copyright (C) 2015 www.labsquare.org
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.*/

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


void ParamWidget::paste()
{

    QString txt = qApp->clipboard()->text();
    QStringList list = mModel->stringList();

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
    remove();
}

void ParamWidget::remove()
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



