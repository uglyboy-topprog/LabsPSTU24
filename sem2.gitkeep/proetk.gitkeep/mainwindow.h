#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTranslator>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void showLanguageSelection();
    void showDifficultySelection();
    void showContentList();

private slots:
    void onLanguageSelected(const QString &lang);
    void onDifficultySelected(int level);
    void onButtonClicked(int buttonId);

private:
    void setupLanguagePage();
    void setupDifficultyPage();
    void setupContentPage(int difficultyLevel); // Изменили аргумент
    QStackedWidget *stackedWidget;
    QTranslator *translator;
    QString username;
    QWidget *contentPage;
    QListWidget *listWidget;
    //Ui::MainWindow *ui; // Удали эту строку!
};
#endif // MAINWINDOW_H
