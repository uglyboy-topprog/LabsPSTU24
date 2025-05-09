#include "registrationwindow.h"
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardPaths>

RegistrationWindow::RegistrationWindow(QWidget *parent) : QWidget(parent)
{
    usernameLabel = new QLabel("Имя:", this);
    passwordLabel = new QLabel("Пароль:", this);
    emailLabel = new QLabel("Почта:", this);
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    registerButton = new QPushButton("Регистрация", this);

    passwordEdit->setEchoMode(QLineEdit::Password);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(emailLabel);
    layout->addWidget(emailEdit);
    layout->addWidget(registerButton);

    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::registerUser);
}

void RegistrationWindow::registerUser()
{
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text().trimmed();
    QString email = emailEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Error", "Пожалуйста, заполните все поля");
        return;
    }

    // Регулярное выражение для проверки email
        QRegularExpression re("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        QRegularExpressionMatch match = re.match(email);

        if (!match.hasMatch()) {
            QMessageBox::warning(this, "Error", "Некорректный email");
            return;
        }

        // Сохранение в файл
        QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "data.txt";
            QFile file(filePath);

            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream stream(&file);
                stream << "Username: " << username << "\n";
                stream << "Password: " << password << "\n";
                stream << "Email: " << email << "\n\n";
                file.close();

                // Сообщение об успехе (с указанием пути):
                QMessageBox::information(this, "Успех", "Данные сохранены в:\n" + filePath);
            } else {
                QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл!");
            }

    close();
}



