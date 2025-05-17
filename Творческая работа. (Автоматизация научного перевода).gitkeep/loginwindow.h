#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "registerwindow.h"

class LoginWindow : public QDialog {
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    bool isLoggedIn() const { return loggedIn; }

private slots:
    void handleLogin();
    void handleRegister();

private:
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    bool loggedIn;

    void loadUsers();
    bool checkLogin(const QString &username, const QString &password);
};

#endif // LOGINWINDOW_H
