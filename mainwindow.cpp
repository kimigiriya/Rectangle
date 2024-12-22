#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QHBoxLayout>
#include <QDebug>
#include <QStyle>
#include <QStyleFactory>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rectangleWidget = new RectangleWidget(this);

    saveButton = new QPushButton("Сохранить", this);
    loadButton = new QPushButton("Загрузить", this);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveRectangle);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadRectangle);

    // Кастомизация кнопок с помощью CSS
    saveButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   text-align: center;"
        "   text-decoration: none;"
        "   display: inline-block;"
        "   font-size: 16px;"
        "   margin: 4px 2px;"
        "   cursor: pointer;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #367C39;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #29622C;"
        "}"
        );


    loadButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #008CBA;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   text-align: center;"
        "   text-decoration: none;"
        "   display: inline-block;"
        "   font-size: 16px;"
        "   margin: 4px 2px;"
        "   cursor: pointer;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #00688B;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #004F6B;"
        "}"
        );

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(rectangleWidget);
    mainLayout->addLayout(layout);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveRectangle() {
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить прямоугольник", "", "Text Files (*.txt)");
    if(!fileName.isEmpty()) {
        rectangleWidget->saveToFile(fileName);
    }
}

void MainWindow::loadRectangle() {
    QString fileName = QFileDialog::getOpenFileName(this, "Загрузить прямоугольник", "", "Text Files (*.txt)");
    if(!fileName.isEmpty()) {
        rectangleWidget->loadFromFile(fileName);
    }
}
