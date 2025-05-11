#include "authwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

AuthWindow::AuthWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Окно авторизации");
    setMinimumSize(200, 120);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Добро пожаловать!", this);
    titleLabel->setAlignment(Qt::AlignCenter); // Центрируем текст
    loginButton = new QPushButton("Вход", this);
    registrationButton = new QPushButton("Регистрация", this);

    layout->addWidget(titleLabel);
    layout->addWidget(loginButton);
    layout->addWidget(registrationButton);

    setLayout(layout);
    adjustSize();

    connect(loginButton, &QPushButton::clicked, this, &AuthWindow::showLoginWindow);
    connect(registrationButton, &QPushButton::clicked, this, &AuthWindow::showRegistrationWindow);

    qDebug() << "AuthWindow создан";
}

void AuthWindow::showLoginWindow() {
    qDebug() << "Открываем окно входа";
    if (!loginWindow) {
        qDebug() << "Создаём LoginWindow";
        loginWindow = new LoginWindow(nullptr);
        qDebug() << "LoginWindow создан успешно";
    }
    loginWindow->show();
    loginWindow->raise();
    loginWindow->activateWindow();
    qDebug() << "LoginWindow отображено:" << loginWindow->isVisible();
}

void AuthWindow::showRegistrationWindow() {
    qDebug() << "Открываем окно регистрации";
    if (!registrationWindow) {
        qDebug() << "Создаём RegistrationWindow";
        registrationWindow = new RegistrationWindow(nullptr);
        qDebug() << "RegistrationWindow создан успешно";
    }
    registrationWindow->show();
    registrationWindow->raise();
    registrationWindow->activateWindow();
    qDebug() << "RegistrationWindow отображено:" << registrationWindow->isVisible();
}
