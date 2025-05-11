#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include "difficultywindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Main Window");
    setMinimumSize(200, 150);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    infoLabel = new QLabel("Выберите язык: Русский, English, বাংলা", centralWidget);
    languageChoice = new QComboBox(centralWidget);
    languageChoice->addItem("Русский", "ru");
    languageChoice->addItem("English", "en");
    languageChoice->addItem("বাংলা", "bn");

    QPushButton *okButton = new QPushButton("OK", centralWidget);
    QPushButton *cancelButton = new QPushButton("Назад", centralWidget);

    layout->addWidget(infoLabel);
    layout->addWidget(languageChoice);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    connect(okButton, &QPushButton::clicked, this, [this]() {
        handleLanguageChoice(languageChoice->currentData().toString());
    });
    connect(cancelButton, &QPushButton::clicked, this, [this]() {
        qDebug() << "Cancel нажата, возвращаемся к AuthWindow";
        this->hide();
    });

    qDebug() << "MainWindow создан";
}

void MainWindow::showLanguageSelection() {
    qDebug() << "Показываем выбор языка";
    this->show();
    this->raise();
    this->activateWindow();
    qDebug() << "MainWindow видимость после show:" << isVisible();
}

void MainWindow::handleLanguageChoice(const QString &language) {
    qDebug() << "Выбран язык:" << language;
    if (language == "ru") {
        infoLabel->setText("Вы выбрали русский язык");
    } else if (language == "en") {
        infoLabel->setText("You selected English");
    } else if (language == "bn") {
        infoLabel->setText("আপনি বাংলা ভাষা নির্বাচন করেছেন");
    }

    if (!difficultyWindow) {
        difficultyWindow = new DifficultyWindow(language, this, nullptr);
    }
    difficultyWindow->show();
    difficultyWindow->raise();
    difficultyWindow->activateWindow();
}
