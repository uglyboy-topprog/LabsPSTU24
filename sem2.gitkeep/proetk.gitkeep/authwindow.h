#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class LoginWindow;
class RegistrationWindow;
class MainWindow;

class AuthWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

private slots:
    void showLogin();
    void showRegistration();
    void showLanguageWindow();

private:
    LoginWindow *loginWindow = nullptr;
    RegistrationWindow *registrationWindow = nullptr;
    MainWindow *mainWindow = nullptr;
};

#endif // AUTHWINDOW_H
