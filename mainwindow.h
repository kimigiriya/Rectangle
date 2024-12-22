#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "rectanglewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void saveRectangle();
    void loadRectangle();

private:
    Ui::MainWindow *ui;
    RectangleWidget *rectangleWidget;
    QPushButton *saveButton;
    QPushButton *loadButton;
};
#endif // MAINWINDOW_H
