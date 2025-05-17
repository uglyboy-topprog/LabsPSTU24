#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QProcess>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void translateAndExplain();

private:
    QTextEdit *inputTextEdit;
    QTextEdit *outputTextEdit;
    QPushButton *translateButton;
    QPushButton *clearButton;
    QProcess *translateProcess;
    QProcess *explainProcess;
    QString currentInputText;
};

#endif // MAINWINDOW_H
