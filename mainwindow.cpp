#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mPatientWidget = new ParamWidget;
    mValueWidget= new ParamWidget;
    mResultWidget = new ParamWidget;
    mTabWidget = new QTabWidget;
    mRegEdit = new QLineEdit;

    mTabWidget->addTab(mResultWidget,mResultWidget->windowIcon(), "Results");

    addDockWidget(Qt::LeftDockWidgetArea, mPatientWidget);
    addDockWidget(Qt::LeftDockWidgetArea, mValueWidget);


    ui->mainToolBar->addWidget(mRegEdit);

    connect(ui->actionOrganize,SIGNAL(triggered()),this,SLOT(organize()));
    connect(ui->actionAbout_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(showAbout()));

    setCentralWidget(mTabWidget);

    resize(800,600);


    QStringList tempA;
    QStringList tempB;

    tempA<<"A"<<"B"<<"C";
    tempB<<"1"<<"2"<<"3"<<"4"<<"5"<<"6";

    mPatientWidget->setStringList(tempA);
    mValueWidget->setStringList(tempB);

    mRegEdit->setText("PKD{{A}}_ULTIME{{B}}");

    mPatientWidget->setWindowTitle("Key A");
    mValueWidget->setWindowTitle("Key B");




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::organize()
{
    QStringList list;
    QString pattern = mRegEdit->text();

    foreach (QString a, mPatientWidget->stringList()) {


        foreach (QString b, mValueWidget->stringList())
        {
            QString tmp = pattern;
            QString txt = tmp.replace("{{A}}", a);
            txt = txt.replace("{{B}}",b);
            list.append(txt);
        }



    }


    mResultWidget->setStringList(list);







}

void MainWindow::showAbout()
{
    QMessageBox box(this);

    box.setWindowTitle("About");
    box.setTextFormat(Qt::RichText);
    box.setText("<b>PlateMaker </b>GPL3<br/>sacha@labsquare.org<br/>Code source avaible on <a href='https://github.com/dridk/plateMaker'>Github</a>");





    box.exec();










}
