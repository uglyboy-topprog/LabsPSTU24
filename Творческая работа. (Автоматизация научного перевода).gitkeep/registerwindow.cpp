#include "registerwindow.h"
#include <QCryptographicHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Регистрация");
    setMinimumSize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameLabel = new QLabel("Логин:");
    passwordLabel = new QLabel("Пароль:");
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    registerButton = new QPushButton("Зарегистрировать");

    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    setLayout(layout);

    connect(registerButton, &QPushButton::clicked, this, &RegisterWindow::handleRegister);

    setStyleSheet(
            "RegisterWindow {"
            "    background-color: #FFFFFF;"
            "}"
            "QLabel {"
            "    font-family: 'Arial';"
            "    font-size: 14px;"
            "    color: #333333;"
            "}"
            "QLineEdit {"
            "    background-color: #F5F5F5;"
            "    border: 1px solid #CCCCCC;"
            "    border-radius: 8px;"
            "    padding: 8px;"
            "    font-family: 'Arial';"
            "    font-size: 14px;"
            "    box-shadow: 0 2px 4px rgba(0,0,0,0.1);"
            "}"
            "QLineEdit:focus {"
            "    border: 1px solid #0288D1;"
            "    background-color: #E3F2FD;"
            "}"
            "QPushButton {"
            "    background-color: #4CAF50;"
            "    color: white;"
            "    font-family: 'Arial';"
            "    font-size: 14px;"
            "    font-weight: bold;"
            "    padding: 10px;"
            "    border-radius: 8px;"
            "    border: none;"
            "    box-shadow: 0 4px 8px rgba(0,0,0,0.2);"
            "}"
            "QPushButton:hover {"
            "    background-color: #45A049;"
            "    box-shadow: 0 6px 12px rgba(0,0,0,0.3);"
            "}"
            "QPushButton:pressed {"
            "    background-color: #388E3C;"
            "    box-shadow: 0 2px 4px rgba(0,0,0,0.1);"
            "}"
        );

    qDebug() << "RegisterWindow создан";
}

RegisterWindow::~RegisterWindow() {
}

void RegisterWindow::handleRegister() {
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text().trimmed();
    qDebug() << "Регистрация с логином:" << username << "(длина:" << username.length() << ")";
    qDebug() << "Регистрация с паролем:" << password << "(длина:" << password.length() << ")";
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Логин и пароль не могут быть пустыми!");
        qDebug() << "Ошибка: пустые поля";
        return;
    }
    QFile file("users.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull() && doc.isObject() && doc.object().contains(username)) {
            QMessageBox::warning(this, "Ошибка", "Пользователь уже существует!");
            qDebug() << "Ошибка: пользователь существует";
            return;
        }
    }
    saveUser(username, password);
    QMessageBox::information(this, "Успех", "Регистрация прошла успешно!");
    qDebug() << "Регистрация успешна";
    accept(); // Закрываем окно после успешной регистрации
}

void RegisterWindow::saveUser(const QString &username, const QString &password) {
    QFile file("users.json");
    QJsonObject users;
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull() && doc.isObject()) {
            users = doc.object();
        }
    }

    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(password.toUtf8());
    QString hashedPassword = QString(hash.result().toHex());
    qDebug() << "Хешированный пароль:" << hashedPassword;

    users[username] = hashedPassword;
    QJsonDocument doc(users);
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.close();
    qDebug() << "Сохранён пользователь:" << username << "с паролем" << hashedPassword;
}
