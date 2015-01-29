#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTabWidget>
#include "finalgridwidget.h"
#include "paramwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void organize();
    void showAbout();
    void save();
    void load();
    void paste();
    void copy();
    void cut();
    void remove();
    void insert();
    void selectAll();

protected:
    ParamWidget * focusWidget();


private:
    Ui::MainWindow *ui;
    ParamWidget* mViewResult;
    ParamWidget* mViewB;
    ParamWidget * mViewA;
    QLineEdit * mRegEdit;

};

#endif // MAINWINDOW_H
