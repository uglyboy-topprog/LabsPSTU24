#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class ItemWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWindow(int buttonId, QWidget *parent = nullptr); // Передаем ID кнопки
    void updateItems(int buttonId); // Обновляем список в зависимости от ID

private:
    QVBoxLayout *layout;
};

#endif // ITEMWINDOW_H
