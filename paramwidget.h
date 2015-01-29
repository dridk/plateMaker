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



     virtual void keyPressEvent(QKeyEvent*event);

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
