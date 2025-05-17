#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "loginwindow.h"

class WelcomeWindow : public QDialog {
    Q_OBJECT

public:
    WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

private slots:
    void onWelcomeClicked();

private:
    QPushButton *welcomeButton;
    QLabel *backgroundLabel;
};

#endif // WELCOMEWINDOW_H
