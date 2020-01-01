#ifndef GAMEUI_H
#define GAMEUI_H

#include <QWidget>

namespace Ui {
class gameUi;
}

class gameUi : public QWidget
{
    Q_OBJECT

public:
    explicit gameUi(QWidget *parent = 0);
    ~gameUi();

private slots:
    void on_pBtnPlay_clicked();

    void on_pBtnQuit_clicked();

private:
    Ui::gameUi *ui;
};

#endif // GAMEUI_H
