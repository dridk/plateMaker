#ifndef PARAMWIDGET_H
#define PARAMWIDGET_H

#include <QDockWidget>
#include <QListView>
#include <QStringListModel>

class ParamWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit ParamWidget(QWidget *parent = 0);
    ~ParamWidget();

     QStringList stringList() const;
     QListView *view() ;

public slots:
    void paste();
    void copy();
    void setStringList(const QStringList& list);


private:
    QListView * mView;
    QStringListModel * mModel;
};

#endif // PARAMWIDGET_H
