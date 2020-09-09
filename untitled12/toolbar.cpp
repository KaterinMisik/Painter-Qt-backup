#include "toolbar.h"
#include "ui_toolbar.h"
#include <QPushButton>
#include <qimagewidget.h>
#include <QObject>
#include <QToolButton>
#include <QDebug>
ToolBar::ToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBar)
{
    ui->setupUi(this);


    connect(ui->pushButton, &QPushButton::clicked, this, &ToolBar::on_pushButton_clicked);

}



ToolBar::~ToolBar()
{
    delete ui;
}

void ToolBar::on_pushButton_clicked()
{

    QVector<QPoint> p1, p2;
    QFile file("C:/Users/kamil/Desktop/data.txt");
    QStringList lineList;
    if(file.open(QIODevice::ReadOnly | QFile::Text)){

        QTextStream  in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            lineList.append(line);
        }
        emit(dataReady(lineList));
        file.close();
     //   qDebug()<<lineList;

      //  int i = 0; i < lineList.size(); ++i;
      //  qDebug()<<lineList.size();
      //  QStringList<int> lineList = new QStringList<int>();
      //  int count = list.Count;

    }
}




bool ToolBar::isSaveBoxEnabled(void)

{
  return ui->saveControl->isChecked();
}




bool ToolBar::isrectanglingEnabled(void)

{
    return ui->RectangleControl->isChecked();
}



bool ToolBar::isCircleEnabled(void)


{
    return ui->circleControl->isChecked();
}



bool ToolBar::isTriangleEnabled(void)

{
    return ui->TriangleControl->isChecked();
}




void ToolBar::on_pushButton_2_clicked()
{

    QVector<QPointF> points;
   // QLineF lines[3];
    QFile file("C:/Users/kamil/Desktop/triangledata.txt");
    QStringList lineList;
    if(file.open(QIODevice::ReadOnly | QFile::Text)){

        QTextStream  in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            lineList.append(line);
        }
        emit(dataReady1(lineList));
        file.close();
        qDebug()<<lineList;

      //  int i = 0; i < lineList.size(); ++i;
      //  qDebug()<<lineList.size();
      //  QStringList<int> lineList = new QStringList<int>();
      //  int count = list.Count;
}
}
