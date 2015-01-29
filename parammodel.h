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

#ifndef PARAMMODEL_H
#define PARAMMODEL_H

#include <QObject>
#include <QStringListModel>
#include <QJsonDocument>
class ParamModel : public QStringListModel
{
    Q_OBJECT
public:
    ParamModel(QObject * parent = 0);
    ~ParamModel();

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void setAlphabetic(bool active);
    void setHeaders(const QStringList& list);



protected:
    QString sectionToAlpha(int section) const;
    bool mIsAlphabetic;
    QStringList mHeaders;
    QString mTitle;
};

#endif // PARAMMODEL_H
