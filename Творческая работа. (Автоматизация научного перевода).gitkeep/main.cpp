#include "welcomewindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    WelcomeWindow welcome;
    welcome.show();
    return app.exec();
}
