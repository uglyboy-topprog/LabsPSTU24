#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QDebug> // Добавили для qDebug()


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Main Window");
    resize(300, 200);
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);
    setupLanguagePage();
    setupDifficultyPage();
    setupContentPage(0);  // Передаем 0 в качестве значения по умолчанию
}

void MainWindow::showLanguageSelection() {
    stackedWidget->setCurrentIndex(0);
    show();
}

void MainWindow::setupLanguagePage() {
    QWidget *page = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(page);
    QStringList languages = {"Английский", "Китайский", "Испанский"};
    for (const QString &lang : languages) {
        QPushButton *button = new QPushButton(lang, page);
        connect(button, &QPushButton::clicked, this, [this, lang]() {
            onLanguageSelected(lang);
        });
        layout->addWidget(button);
    }
    stackedWidget->addWidget(page);
}

void MainWindow::setupDifficultyPage() {
    QWidget *page = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(page);

    for (int i = 1; i <= 5; ++i) {
        QPushButton *button = new QPushButton(QString::number(i), this);
        connect(button, &QPushButton::clicked, this, [this, i]() {
            onButtonClicked(i); // Передаём корректный buttonId (1, 2, 3, 4, 5)
        });
        layout->addWidget(button);
    }

    stackedWidget->addWidget(page);
}

void MainWindow::onButtonClicked(int buttonId) {
    qDebug() << "Button clicked:" << buttonId; // Для отладки
    setupContentPage(buttonId);
    stackedWidget->setCurrentIndex(2); // Переключаем на страницу с контентом
}


void MainWindow::setupContentPage(int buttonId) {
    QWidget *page = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(page);
    QListWidget *list = new QListWidget(page);

    QStringList items;
    switch (buttonId) {
        case 1:
            items << "Item A" << "Item B" << "Item C";
            break;
        case 2:
            items << "Item X" << "Item Y" << "Item Z";
            break;
        case 3:
            items << "Item 3A" << "Item 3B" << "Item 3C";
            break;
        case 4:
            items << "Item 4X" << "Item 4Y" << "Item 4Z";
            break;
        case 5:
            items << "Item 5A" << "Item 5B" << "Item 5C";
            break;
        default:
            items << "Default 1" << "Default 2" << "Default 3";
            break;
    }

    list->addItems(items);
    layout->addWidget(list);
    stackedWidget->addWidget(page);
}

void MainWindow::onLanguageSelected(const QString &lang) {
    Q_UNUSED(lang);
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::onDifficultySelected(int level) {
    Q_UNUSED(level);
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::showDifficultySelection() {
    stackedWidget->setCurrentIndex(1);
}


