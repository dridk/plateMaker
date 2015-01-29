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


#include "parammodel.h"
#include <QDebug>
#include <QtMath>
ParamModel::ParamModel(QObject * parent)
    :QStringListModel(parent)
{

    mIsAlphabetic = false;

}

ParamModel::~ParamModel()
{
}

QVariant ParamModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical) {
        return mHeaders.value(section, mIsAlphabetic ? sectionToAlpha(section) : QString::number(section));
    }


    if ( orientation == Qt::Horizontal){
        return objectName();
    }
    return QVariant();
}

void ParamModel::setAlphabetic(bool active)
{
    mIsAlphabetic = active;
    emit layoutChanged();
}

void ParamModel::setHeaders(const QStringList &list)
{
    mHeaders = list;
    emit layoutChanged();
}


QString ParamModel::sectionToAlpha(int section) const
{
    QString result;
    int size = 26;
    int number = section;

    if (section == 0)
        result.append("A");

    while (number > 0)
    {
        int bit = number % size;
        number = number / size;
        result.prepend(QChar(65+bit));
    }


    return result;


}

