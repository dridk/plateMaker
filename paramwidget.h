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

#ifndef PARAMWIDGET_H
#define PARAMWIDGET_H

#include <QDockWidget>
#include <QListView>
#include <QTableView>
#include <QStringListModel>
#include <QKeyEvent>
#include "parammodel.h"

class ParamWidget : public QTableView
{
    Q_OBJECT
public:
    explicit ParamWidget(QWidget *parent = 0);
    ~ParamWidget();

     QStringList stringList() const;
     void setAlphabetic(bool active);




public slots:
    void paste();
    void copy();
    void cut();
    void remove();
    void insert();

    void setData(const QStringList& list, const QStringList& headers = QStringList());



private:
    ParamModel * mModel;
};

#endif // PARAMWIDGET_H
