#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QString>

class InfoWindow : public QWidget {
    Q_OBJECT
public:
    InfoWindow(const QString &language, int difficulty, QWidget *parent = nullptr);
    void setInfoText(const QString &text); // Публичный метод для изменения текста

private:
    QLabel *infoLabel;
};

#endif // INFOWINDOW_H
