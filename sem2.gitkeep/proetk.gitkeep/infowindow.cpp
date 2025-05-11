#include "infowindow.h"
#include <QVBoxLayout>
#include <QDebug>

InfoWindow::InfoWindow(const QString &language, int difficulty, QWidget *parent) : QWidget(parent) {
    setWindowTitle("Информация об уровне");
    setMinimumSize(300, 200);
    setGeometry(150, 150, 300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);
    infoLabel = new QLabel(this);
    layout->addWidget(infoLabel);

    // Устанавливаем текст через switch
    if (language == "ru") {
        switch (difficulty) {
            case 1: infoLabel->setText("Ур 1"); break;
            case 2: infoLabel->setText("Ур 2"); break;
            case 3: infoLabel->setText("Ур 3"); break;
            case 4: infoLabel->setText("Ур 4"); break;
            case 5: infoLabel->setText("Ур 5"); break;
        }
    } else if (language == "en") {
        switch (difficulty) {
            case 1: infoLabel->setText("Level 1"); break;
            case 2: infoLabel->setText("Level 2"); break;
            case 3: infoLabel->setText("Level 3"); break;
            case 4: infoLabel->setText("Level 4"); break;
            case 5: infoLabel->setText("Level 5"); break;
        }
    } else if (language == "bn") {
        switch (difficulty) {
            case 1: infoLabel->setText("স্তর ১"); break;
            case 2: infoLabel->setText("স্তর ২"); break;
            case 3: infoLabel->setText("স্তর ৩"); break;
            case 4: infoLabel->setText("স্তর ৪"); break;
            case 5: infoLabel->setText("স্তর ৫"); break;
        }
    }

    qDebug() << "InfoWindow инициализирован с текстом:" << infoLabel->text();
}

void InfoWindow::setInfoText(const QString &text) {
    infoLabel->setText(text);
    qDebug() << "InfoWindow текст обновлён на:" << text;
}
