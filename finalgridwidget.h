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
