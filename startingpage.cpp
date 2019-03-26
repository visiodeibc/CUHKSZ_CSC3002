#include "startingpage.h"
#include "ui_startingpage.h"
#include "Game.h"
#include<QApplication>

Game * game;

StartingPage::StartingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartingPage)
{
    ui->setupUi(this);
}

StartingPage::~StartingPage()
{
    delete ui;
}

void StartingPage::on_pushButton_clicked()
{
    delete ui;
    //hide();
    game = new Game();
    game->show();
   //   delete ui;
}
