#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QStringList>
#include <QTextCodec>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Автоматизация научного перевода");
    setMinimumSize(600, 400);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *inputLabel = new QLabel("Введите текст на английском:");
    inputTextEdit = new QTextEdit(this);
    translateButton = new QPushButton("Перевести и объяснить");
    clearButton = new QPushButton("Очистить");
    QLabel *outputLabel = new QLabel("Перевод и объяснения:");
    outputTextEdit = new QTextEdit(this);
    outputTextEdit->setReadOnly(true);

    layout->addWidget(inputLabel);
    layout->addWidget(inputTextEdit);
    layout->addWidget(translateButton);
    layout->addWidget(clearButton);
    layout->addWidget(outputLabel);
    layout->addWidget(outputTextEdit);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    translateProcess = new QProcess(this);
    explainProcess = new QProcess(this);

    translateProcess->setProcessChannelMode(QProcess::MergedChannels);
    explainProcess->setProcessChannelMode(QProcess::MergedChannels);

    connect(translateButton, &QPushButton::clicked, this, &MainWindow::translateAndExplain);
    connect(clearButton, &QPushButton::clicked, this, [this]() {
        inputTextEdit->clear();
        outputTextEdit->clear();
    });

    setStyleSheet(
            "MainWindow {"
            "    background-color: #FAFAFA;"
            "}"
            "QLabel {"
            "    font-family: 'Arial';"
            "    font-size: 16px;"
            "    color: #333333;"
            "    font-weight: bold;"
            "}"
            "QTextEdit {"
            "    background-color: #FFFFFF;"
            "    border: 1px solid #CCCCCC;"
            "    border-radius: 10px;"
            "    padding: 10px;"
            "    font-family: 'Arial';"
            "    font-size: 14px;"
            "    box-shadow: 0 2px 4px rgba(0,0,0,0.1);"
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
            "QPushButton#clearButton {"
            "    background-color: #F44336;"
            "}"
            "QPushButton#clearButton:hover {"
            "    background-color: #E53935;"
            "}"
            "QPushButton#clearButton:pressed {"
            "    background-color: #D32F2F;"
            "}"
        );

    qDebug() << "MainWindow создан";
}

MainWindow::~MainWindow() {
    delete translateProcess;
    delete explainProcess;
}

void MainWindow::translateAndExplain() {
    currentInputText = inputTextEdit->toPlainText();
    if (currentInputText.isEmpty()) {
        outputTextEdit->setText("Пожалуйста, введите текст.");
        return;
    }

    QStringList translateArgs;
    translateArgs << "translator.py" << currentInputText;
    qDebug() << "Запуск перевода с аргументами:" << translateArgs;
    translateProcess->start("py", translateArgs);
    if (!translateProcess->waitForStarted()) {
        qDebug() << "Не удалось запустить процесс перевода!";
        outputTextEdit->setText("Ошибка: Не удалось запустить процесс перевода.");
        return;
    }
    translateProcess->waitForFinished();
    QByteArray translatedOutput = translateProcess->readAllStandardOutput();
    QString translatedText = QString::fromUtf8(translatedOutput).trimmed();
    QString errorText = translateProcess->readAllStandardError().trimmed();
    qDebug() << "Вывод перевода:" << translatedText;
    qDebug() << "Ошибка перевода:" << errorText;
    if (translateProcess->exitCode() != 0) {
        translatedText = "Ошибка перевода: " + errorText;
    }

    QStringList explainArgs;
    explainArgs << "explain_terms.py" << translatedText;
    qDebug() << "Запуск объяснения с аргументами:" << explainArgs;
    explainProcess->start("py", explainArgs);
    if (!explainProcess->waitForStarted()) {
        qDebug() << "Не удалось запустить процесс объяснения!";
        outputTextEdit->setText("Ошибка: Не удалось запустить процесс объяснения.");
        return;
    }
    explainProcess->waitForFinished();
    QByteArray explainOutput = explainProcess->readAllStandardOutput();
    QString explanations = QString::fromUtf8(explainOutput).trimmed();
    errorText = explainProcess->readAllStandardError().trimmed();
    qDebug() << "Вывод объяснений:" << explanations;
    qDebug() << "Ошибка объяснений:" << errorText;
    if (explainProcess->exitCode() != 0) {
        explanations = "Ошибка анализа терминов: " + errorText;
    }

    outputTextEdit->setText("Перевод на русский: " + translatedText + "\n\nОбъяснения терминов:\n" + explanations);
}
