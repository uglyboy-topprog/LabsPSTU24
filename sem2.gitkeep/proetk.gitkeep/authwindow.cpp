#include "authwindow.h"
#include "loginwindow.h"
#include "registrationwindow.h"
#include "mainwindow.h"

AuthWindow::AuthWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Authentication");
    resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *loginBtn = new QPushButton("Вход", this);
    QPushButton *registerBtn = new QPushButton("Регистрация", this);

    layout->addWidget(loginBtn);
    layout->addWidget(registerBtn);

    connect(loginBtn, &QPushButton::clicked, this, &AuthWindow::showLogin);
    connect(registerBtn, &QPushButton::clicked, this, &AuthWindow::showRegistration);
}

AuthWindow::~AuthWindow()
{
    delete loginWindow;
    delete registrationWindow;
    delete mainWindow;
}

void AuthWindow::showLogin()
{
    if (!loginWindow) {
        loginWindow = new LoginWindow();
        connect(loginWindow, &LoginWindow::authenticated, this, &AuthWindow::showLanguageWindow);
    }
    loginWindow->show();
}

void AuthWindow::showRegistration()
{
    if (!registrationWindow) {
        registrationWindow = new RegistrationWindow();
    }
    registrationWindow->show();
}

void AuthWindow::showLanguageWindow()
{
    this->hide();

    if (!mainWindow) {
        mainWindow = new MainWindow();
    }
    mainWindow->showLanguageSelection();
}
