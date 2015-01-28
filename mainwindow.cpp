#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mViewResult = new ParamWidget;
    mViewA= new ParamWidget;
    mViewB= new ParamWidget;

    mTabWidget = new QTabWidget;
    mRegEdit = new QLineEdit;

    mTabWidget->addTab(mViewResult,mViewResult->windowIcon(), "Results");

    QDockWidget * dockWidgetA = new QDockWidget("List A");
    QDockWidget * dockWidgetB = new QDockWidget("List B");;

    dockWidgetA->setWidget(mViewA);
    dockWidgetB->setWidget(mViewB);


    dockWidgetA->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dockWidgetB->setFeatures(QDockWidget::NoDockWidgetFeatures);



    addDockWidget(Qt::LeftDockWidgetArea, dockWidgetA);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidgetB);




    ui->mainToolBar->addWidget(mRegEdit);

    connect(ui->actionOrganize,SIGNAL(triggered()),this,SLOT(organize()));
    connect(ui->actionAbout_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(showAbout()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(load()));

    setCentralWidget(mTabWidget);

    resize(800,600);


    QStringList tempA;
    QStringList tempB;

    tempA<<"A"<<"B"<<"C";
    tempB<<"1"<<"2"<<"3"<<"4"<<"5"<<"6";

    mViewA->setData(tempA);
    mViewB->setData(tempB);

    mRegEdit->setText("PKD{{A}}_ULTIME{{B}}");

    mViewA->setWindowTitle("Key A");
    mViewB->setWindowTitle("Key B");

    mViewA->setAlphabetic(true);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::organize()
{
    QStringList list;
    QStringList headers;
    QString pattern = mRegEdit->text();
    int sectionA= 0, sectionB = 0;

    foreach (QString a, mViewA->stringList()) {

        sectionB = 0;

        foreach (QString b, mViewB->stringList())
        {
            QString tmp = pattern;
            QString txt = tmp.replace("{{A}}", a);
            txt = txt.replace("{{B}}",b);
            list.append(txt);

            QString headerA = mViewA->model()->headerData(sectionA, Qt::Vertical).toString();
            QString headerB = mViewB->model()->headerData(sectionB, Qt::Vertical).toString();

            headers.append(QString("%1%2").arg(headerA).arg(headerB));
            sectionB++;


        }

        sectionA++;


    }


    mViewResult->setData(list,headers);






}

void MainWindow::showAbout()
{
    QMessageBox box(this);

    box.setWindowTitle("About");
    box.setTextFormat(Qt::RichText);
    box.setText("<b>PlateMaker </b>GPL3<br/>sacha@labsquare.org<br/>Code source avaible on <a href='https://github.com/dridk/plateMaker'>Github</a>");





    box.exec();










}

void MainWindow::save()
{

    QString filename = QFileDialog::getSaveFileName(this,"open file","", tr("Plate maker(*.json)"));

    QFile file(filename);

    if (file.open(QIODevice::WriteOnly)){
        QJsonDocument doc ;
        QJsonObject root;
        root.insert("reg", mRegEdit->text());
        root.insert("listA", QJsonArray::fromStringList(mViewA->stringList()));
        root.insert("listB", QJsonArray::fromStringList(mViewB->stringList()));
        doc.setObject(root);
        file.write(doc.toJson());
        file.close();
    }


}

void MainWindow::load()
{
    QString filename = QFileDialog::getOpenFileName(this,"open file","", tr("Plate maker(*.json)"));

    QFile file(filename);

    if (file.open(QIODevice::ReadOnly)){
        QJsonDocument doc  = QJsonDocument::fromJson(file.readAll());

        mRegEdit->setText(doc.object().value("reg").toString());

        QStringList a, b;
        foreach (QVariant item, doc.object().value("listA").toArray().toVariantList() )
            a.append(item.toString());

        foreach (QVariant item, doc.object().value("listB").toArray().toVariantList() )
            b.append(item.toString());


        mViewA->setData(a);
        mViewB->setData(b);
        file.close();

        organize();
    }
}
