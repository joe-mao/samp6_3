#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include "qformdoc.h"
#include "qformtable.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->tabWidget->setVisible(false);

    this->ui->tabWidget->clear();//清除所有页面（刚开始i有两个空页面）
    this->ui->tabWidget->setTabsClosable(true);//Page有关闭按钮，可被关闭
    this->setCentralWidget(this->ui->tabWidget);
    this->setWindowState(Qt::WindowMaximized);//窗口最大化显示
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制窗口背景图片
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0, ui->mainToolBar->height(), this->width(), this->height()-ui->mainToolBar->height()-ui->statusBar->height(), QPixmap(":/image/image/back.jpg"));
//    qDebug()<<"this->height:"<<this->height();//1017
//    qDebug()<<"this->width:"<<this->width();//1920
//    qDebug()<<"mainToolBar->height:"<<this->ui->mainToolBar->height();//12
//    qDebug()<<"statusBar->height:"<<this->ui->statusBar->height();//22

}

void MainWindow::on_actWidgetInsite_triggered()
{
    //创建QFormDoc窗体，并在tabWidget中显示
    QFormDoc * formDoc = new QFormDoc(this);
    formDoc->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除
    int cur = this->ui->tabWidget->addTab(formDoc, QString::asprintf("Doc %d", this->ui->tabWidget->count()));
    this->ui->tabWidget->setCurrentIndex(cur);
    this->ui->tabWidget->setVisible(true);
}

void MainWindow::on_actWidget_triggered()
{
    //QFormDoc * formDoc = new QFormDoc();
    QFormDoc * formDoc = new QFormDoc(this);
    formDoc->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除
    formDoc->setWindowTitle("基于QWidget的窗体,无父窗口,关闭时删除");
    formDoc->setWindowFlag(Qt::Window, true);
    formDoc->setWindowOpacity(0.9);
    //formDoc->setWindowModality(Qt::WindowModal);
    formDoc->show();//在单独的窗口中显示
}

void MainWindow::on_actWindowInsite_triggered()
{
    QFormTable * formTable = new QFormTable(this);
    formTable->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除
    int cur = this->ui->tabWidget->addTab(formTable, QString::asprintf("Table %d", this->ui->tabWidget->count()));
   this->ui->tabWidget->setCurrentIndex(cur);
    this->ui->tabWidget->setVisible(true);
}



void MainWindow::on_actWindow_triggered()
{
    QFormTable * formTable = new QFormTable(this);
    formTable->setAttribute(Qt::WA_DeleteOnClose);
    formTable->setWindowTitle("基于QMainWindow的窗口，指定父窗口，关闭时删除");
    formTable->show();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    //关闭Tab
    if(index < 0){
        return;
    }
    QWidget * aForm = this->ui->tabWidget->widget(index);
    aForm->close();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    bool en = this->ui->tabWidget->count() > 0;//再无分页
    this->ui->tabWidget->setVisible(en);
}
