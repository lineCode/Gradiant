#include "startmenu.h"


using namespace Qt;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow* welcomeWindow = new MainWindow();
    //welcomeWindow->show();

    StartMenu* welcomeWindow = new StartMenu();
    welcomeWindow->show();

    return a.exec();
}
