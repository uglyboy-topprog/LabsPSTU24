#include "loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent)
{
    usernameLabel = new QLabel("Имя:", this);
    passwordLabel = new QLabel("Пароль:", this);
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    loginButton = new QPushButton("Войти", this);

    passwordEdit->setEchoMode(QLineEdit::Password);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::loginUser);
}

void LoginWindow::loginUser()
{
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите имя пользователя и пароль");
        return;
    }

    emit authenticated();
    close();
}
