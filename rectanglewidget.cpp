#include "rectanglewidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QTextStream>


RectangleWidget::RectangleWidget(QWidget *parent)
    : QWidget(parent)
{
    rectPos = QPoint(100, 100); // Начальная позиция прямоугольника

}

RectangleWidget::~RectangleWidget()
{
}

void RectangleWidget::saveToFile(const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << rectPos.x() << " " << rectPos.y();
        file.close();
    } else {
        qDebug() << "Ошибка открытия файла для сохранения";
    }
}


void RectangleWidget::loadFromFile(const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        int x, y;
        in >> x >> y;
        if (in.status() == QTextStream::Ok) { // Проверка статуса потока
            rectPos = QPoint(x,y);
            update();
        } else {
            qDebug() << "Ошибка загрузки файла";
        }
        file.close();
    } else {
        qDebug() << "Ошибка открытия файла для загрузки";
    }
}

// Перерисовка прямоугольника в место нажатия
void RectangleWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        rectPos = event->pos() - QPoint(rectSize / 2, rectSize / 2);
        update();
    }
}

void RectangleWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawRect(rectPos.x(), rectPos.y(), rectSize, rectSize);
}
