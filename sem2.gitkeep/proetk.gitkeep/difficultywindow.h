#ifndef DIFFICULTYWINDOW_H
#define DIFFICULTYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "infowindow.h"

class MainWindow; // Предварительное объявление вместо #include "mainwindow.h"

class DifficultyWindow : public QWidget {
    Q_OBJECT
public:
    DifficultyWindow(const QString &language, MainWindow *mainWindow, QWidget *parent = nullptr);

private slots:
    void handleDifficultySelection(int difficulty);
    void handleBack();

private:
    QString language;
    QPushButton *buttons[5];
    InfoWindow *infoWindow = nullptr;
    MainWindow *mainWindow;
    QPushButton *backButton;
};

#endif // DIFFICULTYWINDOW_H
