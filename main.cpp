#include <QApplication>
#include <game.h>
#include <gameui.h>

game *myGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //displaying the game ui to the player
    gameUi *gameui = new gameUi();
    gameui->show();


    return a.exec();
}
