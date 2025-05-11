#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>

class DifficultyWindow; // Предварительное объявление вместо #include "difficultywindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    void showLanguageSelection();

private slots:
    void handleLanguageChoice(const QString &language);

private:
    QLabel *infoLabel;
    QComboBox *languageChoice;
    DifficultyWindow *difficultyWindow = nullptr;
};

#endif // MAINWINDOW_H
