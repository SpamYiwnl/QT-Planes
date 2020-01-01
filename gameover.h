#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

namespace Ui {
class gameOver;
}

class gameOver : public QWidget
{
    Q_OBJECT

public:
    explicit gameOver(QWidget *parent = 0);
    ~gameOver();

    int Score;

private slots:
    void on_pBtnPlayAgain_clicked();

    void on_pBtnQuit_clicked();

private:
    Ui::gameOver *ui;
};

#endif // GAMEOVER_H
