#include <QApplication>
#include <game.h>
#include <gameui.h>

game *myGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creating a game ui and showing  it to the user at start
    gameUi *gameui = new gameUi();
    gameui->show();


    return a.exec();
}
