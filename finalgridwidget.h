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

#ifndef FINALGRIDWIDGET_H
#define FINALGRIDWIDGET_H

#include <QWidget>
#include <QTableView>
class FinalGridWidget : public QTableView
{
    Q_OBJECT
public:
    explicit FinalGridWidget(QWidget *parent = 0);
    ~FinalGridWidget();

signals:

public slots:
};

#endif // FINALGRIDWIDGET_H
