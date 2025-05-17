#include "welcomewindow.h"
#include <QPixmap>
#include <QDebug>
#include "mainwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Welcome");
    setMinimumSize(400, 600);

    QVBoxLayout *layout = new QVBoxLayout(this);

    // Загружаем изображение котика как фон
    backgroundLabel = new QLabel(this);
    QPixmap pixmap("cat.jpg");
    if (pixmap.isNull()) {
        qDebug() << "Ошибка: не удалось загрузить изображение cat.jpg";
        backgroundLabel->setText("Изображение не найдено!");
    } else {
        backgroundLabel->setPixmap(pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
    backgroundLabel->setAlignment(Qt::AlignCenter);

    welcomeButton = new QPushButton("Welcome", this);

    layout->addWidget(backgroundLabel, 1);
    layout->addWidget(welcomeButton, 0, Qt::AlignHCenter);

    setLayout(layout);

    connect(welcomeButton, &QPushButton::clicked, this, &WelcomeWindow::onWelcomeClicked);

    // Применяем стиль
    setStyleSheet(
        "WelcomeWindow {"
        "    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #E0F7FA, stop:1 #B2EBF2);"
        "}"
        "QPushButton {"
        "    background-color: #0288D1;"
        "    color: white;"
        "    font-family: 'Arial';"
        "    font-size: 18px;"
        "    font-weight: bold;"
        "    padding: 12px 24px;"
        "    border-radius: 10px;"
        "    border: none;"
        "    box-shadow: 0 4px 8px rgba(0,0,0,0.2);"
        "}"
        "QPushButton:hover {"
        "    background-color: #0277BD;"
        "    box-shadow: 0 6px 12px rgba(0,0,0,0.3);"
        "}"
        "QPushButton:pressed {"
        "    background-color: #01579B;"
        "    box-shadow: 0 2px 4px rgba(0,0,0,0.1);"
        "}"
    );

    qDebug() << "WelcomeWindow создан";
}

WelcomeWindow::~WelcomeWindow() {
}

void WelcomeWindow::onWelcomeClicked() {
    qDebug() << "onWelcomeClicked вызван";
    welcomeButton->setEnabled(false);
    LoginWindow loginWindow(this);
    hide();
    if (loginWindow.exec() == QDialog::Accepted) {
        qDebug() << "Вход успешен, открываем MainWindow";
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        connect(mainWindow, &MainWindow::destroyed, this, &WelcomeWindow::close);
    } else {
        qDebug() << "Вход не удался, возвращаемся к WelcomeWindow";
        show();
        welcomeButton->setEnabled(true);
    }
}
