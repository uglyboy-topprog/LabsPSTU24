#include "registrationwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include "authwindow.h"

RegistrationWindow::RegistrationWindow(AuthWindow *parent) : QWidget(parent), authWindow(parent) {
    setWindowTitle("Регистрация");
    setMinimumSize(200, 120);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Введите данные для регистрации", this);
    titleLabel->setAlignment(Qt::AlignCenter); // Центрируем текст
    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Имя пользователя");
    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);
    registerButton = new QPushButton("Зарегистрироваться", this);

    layout->addWidget(titleLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    setLayout(layout);
    adjustSize();

    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::handleRegistration);

    qDebug() << "RegistrationWindow создан";
}

void RegistrationWindow::handleRegistration() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    qDebug() << "Попытка регистрации с именем:" << username << "и паролем:" << password;

    if (!username.isEmpty() && !password.isEmpty()) {
        QFile file("users.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << username << ":" << password << "\n";
            file.close();
            qDebug() << "Пользователь сохранён в users.txt";
        } else {
            qDebug() << "Не удалось открыть файл для записи";
        }

        qDebug() << "Регистрация успешна";
        if (!mainWindow) {
            mainWindow = new MainWindow(nullptr);
            mainWindow->setAttribute(Qt::WA_QuitOnClose, true);
        }
        mainWindow->show();
        mainWindow->raise();
        mainWindow->activateWindow();
        qDebug() << "MainWindow видимость:" << mainWindow->isVisible();
        QTimer::singleShot(100, this, SLOT(closeWindows()));
    } else {
        qDebug() << "Пожалуйста, заполните все поля";
    }
}

void RegistrationWindow::closeWindows() {
    qDebug() << "Закрываем окна";
    this->close();
    if (authWindow) {
        authWindow->hide();
    }
}
