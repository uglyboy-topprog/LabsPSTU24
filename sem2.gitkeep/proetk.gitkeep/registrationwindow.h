#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class RegistrationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RegistrationWindow(QWidget *parent = nullptr);

public:
    void saveUserData( const QString &username,const QString &password, const QString &email);

private slots:
    void registerUser();

private:
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *emailLabel;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *emailEdit;
    QPushButton *registerButton;
};

#endif // REGISTRATIONWINDOW_H
