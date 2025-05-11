#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel> 
#include "mainwindow.h"

class AuthWindow;

class LoginWindow : public QWidget {
    Q_OBJECT
public:
    LoginWindow(AuthWindow *parent = nullptr);

private slots:
    void handleLogin();
    void closeWindows();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QLabel *errorLabel; 
    MainWindow *mainWindow = nullptr;
    AuthWindow *authWindow;
};

#endif // LOGINWINDOW_H
