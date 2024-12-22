#ifndef RECTANGLEWIDGET_H
#define RECTANGLEWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QFile>

class RectangleWidget : public QWidget
{
    Q_OBJECT

public:
    RectangleWidget(QWidget *parent = nullptr);
    ~RectangleWidget() override;

    QPoint getRectanglePosition() const { return rectPos; }
    void setRectanglePosition(const QPoint& pos) { rectPos = pos; update(); }

    void saveToFile(const QString& filename);
    void loadFromFile(const QString& filename);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint rectPos; // Позиция верхнего левого угла прямоугольника
    int rectSize = 50; // Размер прямоугольника
};

#endif // RECTANGLEWIDGET_H
