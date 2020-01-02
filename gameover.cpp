#include "gameover.h"
#include "ui_gameover.h"
#include <game.h>

extern game *myGame;

gameOver::gameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameOver)
{
    //if player loses taking the score and passing it to the label(Score) in the ui
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
    //after play again button is pressed creating a new game ui
    hide();
    myGame->myScene->clear();
    myGame = new game();
    myGame->show();
}

void gameOver::on_pBtnQuit_clicked()
{
    //quit button
    close();
}
