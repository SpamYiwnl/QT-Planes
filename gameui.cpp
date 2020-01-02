#include "gameui.h"
#include "ui_gameui.h"
#include <game.h>

extern game *myGame;

gameUi::gameUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameUi)
{
    ui->setupUi(this);
}

gameUi::~gameUi()
{
    delete ui;
}

void gameUi::on_pBtnPlay_clicked()
{
    //creating a new game on play button click
    hide();
    myGame = new game();
    myGame->show();
}

void gameUi::on_pBtnQuit_clicked()
{
    //quit
    close();
}
