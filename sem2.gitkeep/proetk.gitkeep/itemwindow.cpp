#include "itemwindow.h"

ItemWindow::ItemWindow(int buttonId, QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    updateItems(buttonId); // Инициализируем список
}

void ItemWindow::updateItems(int buttonId)
{
    // Очищаем предыдущие элементы
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Добавляем новые элементы в зависимости от buttonId
    QStringList items;
    switch (buttonId) {
        case 1:
            items <<"Item A" << "Item B" << "Item C";
            break;
        }

    for (const QString &item : qAsConst(items)) {
        QLabel *label = new QLabel(item, this);
        layout->addWidget(label);
    }
}
