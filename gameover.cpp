#include "gameover.h"
#include "ui_gameover.h"
#include <game.h>

extern game *myGame;

gameOver::gameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameOver)
{
    //When the game is over getting its score and passing it to the label(Score) in the ui
    ui->setupUi(this);
    Score = myGame->myScore->getScore();
    ui->score->setText(QString::number(Score));
}

gameOver::~gameOver()
{
    delete ui;
}

void gameOver::on_pBtnPlayAgain_clicked()
{
    //If play again is clicked clearing the scene and creating a new game object
//    hide();
    myGame->myScene->clear();
    myGame = new game();
    myGame->show();
}

void gameOver::on_pBtnQuit_clicked()
{
    //If quit is clicked closing the game
    close();
}
