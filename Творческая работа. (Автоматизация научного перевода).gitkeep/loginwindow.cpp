#include "loginwindow.h"
#include <QCryptographicHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>
#include <QDir> // Добавляем этот заголовок

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent), loggedIn(false) {
    setWindowTitle("Вход");
    setMinimumSize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameLabel = new QLabel("Логин:");
    passwordLabel = new QLabel("Пароль:");
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Вход");
    registerButton = new QPushButton("Регистрация");

    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);
    layout->addWidget(registerButton);

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::handleRegister);

    setStyleSheet(
            "LoginWindow {"
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
            "    background-color: #0288D1;"
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
            "    background-color: #0277BD;"
            "    box-shadow: 0 6px 12px rgba(0,0,0,0.3);"
            "}"
            "QPushButton:pressed {"
            "    background-color: #01579B;"
            "    box-shadow: 0 2px 4px rgba(0,0,0,0.1);"
            "}"
            "QPushButton#registerButton {"
            "    background-color: #4CAF50;"
            "}"
            "QPushButton#registerButton:hover {"
            "    background-color: #45A049;"
            "}"
            "QPushButton#registerButton:pressed {"
            "    background-color: #388E3C;"
            "}"
        );

        loadUsers();
        qDebug() << "LoginWindow создан";

}

LoginWindow::~LoginWindow() {
}

void LoginWindow::handleLogin() {
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text().trimmed();
    qDebug() << "Попытка входа с логином:" << username;
    if (checkLogin(username, password)) {
        loggedIn = true;
        accept();
        qDebug() << "Вход успешен";
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль!");
        qDebug() << "Вход неуспешен";
        usernameEdit->clear();
        passwordEdit->clear();
    }
}

void LoginWindow::handleRegister() {
    RegisterWindow registerWindow(this);
    registerWindow.exec();
    qDebug() << "Окно регистрации закрыто";
    loadUsers();
}

void LoginWindow::loadUsers() {
    QFile file("users.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull() && doc.isObject()) {
            qDebug() << "Пользователи загружены:" << doc.toJson();
        } else {
            qDebug() << "Файл users.json повреждён или пуст";
        }
    } else {
        if (file.open(QIODevice::WriteOnly)) {
            file.close();
            qDebug() << "Создан пустой users.json в" << QDir::currentPath();
        } else {
            qDebug() << "Ошибка создания users.json:" << file.errorString();
        }
    }
}

bool LoginWindow::checkLogin(const QString &username, const QString &password) {
    QFile file("users.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull() && doc.isObject()) {
            QJsonObject users = doc.object();
            qDebug() << "Проверка логина:" << username << "в" << users;
            if (users.contains(username)) {
                QCryptographicHash hash(QCryptographicHash::Md5);
                hash.addData(password.toUtf8());
                QString hashedPassword = QString(hash.result().toHex());
                qDebug() << "Хеш введённого пароля:" << hashedPassword << "Хеш в файле:" << users[username].toString();
                return users[username].toString() == hashedPassword;
            }
        }
    }
    qDebug() << "Логин не найден или файл пуст";
    return false;
}
