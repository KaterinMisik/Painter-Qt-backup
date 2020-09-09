#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QPushButton>
#include "recttodraw.h"
#include <QObject>
namespace Ui {
class ToolBar;
}

class ToolBar : public QWidget
{
    Q_OBJECT
    QList<RectToDraw> rects, circles;
    QRectF creatorRect, creatorRectangle, new_creatorRectangle;

public:
    explicit ToolBar(QWidget *parent = nullptr);
    ~ToolBar();
    bool isRectanglingEnabled();
    bool isCheckboxingEnabled();
    bool isrectanglingEnabled();
    bool isCircleEnabled();
    bool isTriangleEnabled();

    void setTopLeft(const QPointF point);
    void setBottomRight(const QPointF point);
    bool isSaveBoxEnabled();

    bool isUploadEnabled();
signals:
    void regionSelected(const QRect &);
    void dataReady(const QStringList& data);
    void dataReady1(const QStringList& data);
    void savepoints();
private:
    QRect currentRegion;
private slots:

    void on_pushButton_clicked();




    void on_pushButton_2_clicked();

private:
    Ui::ToolBar *ui;
};

#endif // TOOLBAR_H
