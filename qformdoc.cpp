#include "qformdoc.h"
#include "ui_qformdoc.h"
#include <QToolBar>
#include <QMessageBox>
#include <QVBoxLayout>


QFormDoc::QFormDoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFormDoc)
{
    ui->setupUi(this);
    QToolBar * locToolBar = new QToolBar("文档", this);//创建工具栏
    locToolBar->addAction(this->ui->actOpen);
    locToolBar->addAction(this->ui->actFont);
    locToolBar->addSeparator();
    locToolBar->addAction(this->ui->actCut);
    locToolBar->addAction(this->ui->actCopy);
    locToolBar->addAction(this->ui->actPaste);
    locToolBar->addAction(this->ui->actUndo);
    locToolBar->addAction(this->ui->actRedo);
    locToolBar->addSeparator();
    locToolBar->addAction(this->ui->actClose);
    locToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QVBoxLayout * myLayout = new QVBoxLayout();
    //设置工具栏和编辑器上下布局
    myLayout->addWidget(locToolBar);
    myLayout->addWidget(this->ui->plainTextEdit);
    myLayout->setContentsMargins(2, 2, 2, 2);//减小边框的宽度
    myLayout->setSpacing(2);
    this->setLayout(myLayout);//设置布局

}

QFormDoc::~QFormDoc()
{
    QMessageBox::information(this, "消息", "FormTable窗口被删除和释放");



    delete ui;

}
