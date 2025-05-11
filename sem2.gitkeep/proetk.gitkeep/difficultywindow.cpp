#include "difficultywindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QMap>
#include "mainwindow.h" // Подключаем здесь, а не в .h

DifficultyWindow::DifficultyWindow(const QString &language, MainWindow *mainWindow, QWidget *parent)
    : QWidget(parent), language(language), mainWindow(mainWindow) {
    setWindowTitle("Выбор уровня сложности");
    setMinimumSize(300, 200);
    setGeometry(100, 100, 300, 200);

    qDebug() << "Инициализация DifficultyWindow";

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel(this);

    if (language == "ru") {
        titleLabel->setText("Выберите уровень сложности:");
    } else if (language == "en") {
        titleLabel->setText("Select difficulty level:");
    } else if (language == "bn") {
        titleLabel->setText("কঠিনতা স্তর নির্বাচন করুন:");
    }

    layout->addWidget(titleLabel);

    for (int i = 0; i < 5; ++i) {
        buttons[i] = new QPushButton(QString::number(i + 1), this);
        layout->addWidget(buttons[i]);
        connect(buttons[i], &QPushButton::clicked, this, [this, i]() {
            handleDifficultySelection(i + 1);
        });
    }

    backButton = new QPushButton("Назад", this);
    layout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &DifficultyWindow::handleBack);

    qDebug() << "DifficultyWindow полностью настроен";
}

void DifficultyWindow::handleDifficultySelection(int difficulty) {
    qDebug() << "Выбран уровень сложности:" << difficulty;

    QMap<QString, QMap<int, QString>> infoTexts;
    infoTexts["ru"][1] = "Ур 1 - Лёгкий уровень";
    infoTexts["ru"][2] = "Ур 2 - Средний уровень";
    infoTexts["ru"][3] = "Ур 3 - Сложный уровень";
    infoTexts["ru"][4] = "Ур 4 - Очень сложный уровень";
    infoTexts["ru"][5] = "Ур 5 - Экстремальный уровень";

    infoTexts["en"][1] = "Level 1 - Easy";
    infoTexts["en"][2] = "Level 2 - Medium";
    infoTexts["en"][3] = "Level 3 - Hard";
    infoTexts["en"][4] = "Level 4 - Very Hard";
    infoTexts["en"][5] = "Level 5 - Extreme";

    infoTexts["bn"][1] = "স্তর ১ - সহজ";
    infoTexts["bn"][2] = "স্তর ২ - মাঝারি";
    infoTexts["bn"][3] = "স্তর ৩ - কঠিন";
    infoTexts["bn"][4] = "স্তর ৪ - খুব কঠিন";
    infoTexts["bn"][5] = "স্তর ৫ - এক্সট্রিম";

    if (language == "ru") {
        infoTexts["ru"][1] = "Ур 1 - Новый лёгкий уровень";
    }

    delete infoWindow;
    infoWindow = new InfoWindow(language, difficulty, nullptr);
    infoWindow->setInfoText(infoTexts[language][difficulty]);
    infoWindow->show();
    infoWindow->raise();
    infoWindow->activateWindow();

    qDebug() << "InfoWindow открыт с текстом:" << infoTexts[language][difficulty];
}

void DifficultyWindow::handleBack() {
    qDebug() << "Нажата кнопка 'Назад'";
    this->hide();
    if (mainWindow) {
        mainWindow->show();
        mainWindow->raise();
        mainWindow->activateWindow();
    }
}
