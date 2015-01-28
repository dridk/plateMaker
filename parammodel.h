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
