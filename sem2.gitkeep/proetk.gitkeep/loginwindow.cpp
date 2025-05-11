#include "loginwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include "authwindow.h"
#include "mainwindow.h"

LoginWindow::LoginWindow(AuthWindow *parent) : QWidget(parent), authWindow(parent) {
    qDebug() << "Инициализация LoginWindow";

    setWindowTitle("Вход");
    setMinimumSize(200, 120);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Введите данные для входа", this);
    titleLabel->setAlignment(Qt::AlignCenter); // Центрируем текст
    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Имя пользователя");
    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Войти", this);
    errorLabel = new QLabel("", this);
    errorLabel->setStyleSheet("color: red;");
    errorLabel->setAlignment(Qt::AlignCenter); // Центрируем текст ошибки
    errorLabel->hide();

    layout->addWidget(titleLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(errorLabel);
    layout->addWidget(loginButton);

    setLayout(layout);
    adjustSize();

    bool connectionResult = connect(loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
    qDebug() << "Подключение сигнала:" << (connectionResult ? "Успешно" : "Не удалось");
    qDebug() << "LoginWindow виден:" << isVisible();
    qDebug() << "LoginButton доступен:" << loginButton->isEnabled();
    qDebug() << "LoginButton виден:" << loginButton->isVisible();
    qDebug() << "Layout установлен:" << (layout->parent() == this);
    qDebug() << "LoginWindow размер:" << size();

    qDebug() << "LoginWindow создан";
}

void LoginWindow::handleLogin() {
    qDebug() << "Кнопка 'Войти' нажата";
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    qDebug() << "Попытка входа с именем:" << username << "и паролем:" << password;

    bool loginSuccess = false;

    QFile file("users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(":");
            if (parts.size() == 2) {
                QString storedUsername = parts[0];
                QString storedPassword = parts[1];
                if (username == storedUsername && password == storedPassword) {
                    loginSuccess = true;
                    break;
                }
            }
        }
        file.close();
    } else {
        qDebug() << "Не удалось открыть файл для чтения";
    }

    if (loginSuccess) {
        qDebug() << "Успешный вход";
        errorLabel->hide();
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
        qDebug() << "Неверное имя пользователя или пароль";
        errorLabel->setText("Неверное имя пользователя или пароль");
        errorLabel->show();
        adjustSize();
    }
}

void LoginWindow::closeWindows() {
    qDebug() << "Закрываем окна";
    this->close();
    if (authWindow) {
        authWindow->hide();
    }
}
