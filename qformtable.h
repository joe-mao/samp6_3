#ifndef QFORMTABLE_H
#define QFORMTABLE_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QItemSelectionModel>
#include "qwdialogsize.h"
#include "qwdialogheaders.h"





#define FixedColumnCount 6 //文件固定6列

namespace Ui {
class QFormTable;
}

class QFormTable : public QMainWindow
{
    Q_OBJECT

private:
    QLabel * LabCurFile;//当前文件
    QLabel * LabCellPos;//当前单元格行列号
    QLabel * LabCellText;//当前单元格内容
    QStandardItemModel * theModel;//数据模型
    QItemSelectionModel * theSelection;//选择模型
    void iniModelFromStringList(QStringList & aFileContent);//从StringList初始化数据模型
    QWDialogHeaders * dlgSetHeaders = nullptr;


protected:
    virtual void closeEvent(QCloseEvent * event);

private slots:
    //当前选择单元格发生变化
    void on_currentChanged(const QModelIndex & current, const QModelIndex & previous);

    void on_actTab_SetSize_triggered();

    void on_actTab_SetHeader_triggered();


    void on_tableView_clicked(const QModelIndex &index);

public:
    explicit QFormTable(QWidget *parent = nullptr);
    ~QFormTable();

public slots:
    void setACellText(int row, int column, QString text);
    void setActLocateEnable(bool enable);//使能actTab_Locate
public:
    void setDlgLocateNull();

signals:
    void cellIndexChanged(int rowNo, int colNo);//当前单元格发生变化

private:
    Ui::QFormTable *ui;
};

#endif // QFORMTABLE_H_H
