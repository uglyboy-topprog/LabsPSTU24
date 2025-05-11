#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "mainwindow.h"

class AuthWindow;

class RegistrationWindow : public QWidget {
    Q_OBJECT
public:
    RegistrationWindow(AuthWindow *parent = nullptr);

private slots:
    void handleRegistration();
    void closeWindows(); // Убедимся, что этот слот объявлен

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *registerButton;
    MainWindow *mainWindow = nullptr;
    AuthWindow *authWindow;
};

#endif // REGISTRATIONWINDOW_H
