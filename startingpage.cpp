#include "startingpage.h"
#include "ui_startingpage.h"
#include "game.h"
#include<QApplication>
#include<QPixmap>

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
    hide();
    game = new Game();
}

