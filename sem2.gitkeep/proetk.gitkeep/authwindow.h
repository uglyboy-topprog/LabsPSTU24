#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "registrationwindow.h"
#include "loginwindow.h"
#include "mainwindow.h"

class AuthWindow : public QWidget {
    Q_OBJECT
public:
    AuthWindow(QWidget *parent = nullptr);

private slots:
    void showLoginWindow();
    void showRegistrationWindow();

private:
    QPushButton *loginButton;
    QPushButton *registrationButton;
    RegistrationWindow *registrationWindow = nullptr;
    LoginWindow *loginWindow = nullptr;
    MainWindow *mainWindow = nullptr; // Добавляем указатель
};

#endif // AUTHWINDOW_H
