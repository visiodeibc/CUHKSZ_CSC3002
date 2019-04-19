#include "startingpage.h"
#include "ui_startingpage.h"
#include "game.h"

#include <QApplication>
#include <QPixmap>

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

string player = "cool";

void StartingPage::on_radioButton1_clicked()
{
    player = "smart";
}

void StartingPage::on_radioButton2_clicked()
{
    player = "cool";
}

void StartingPage::on_radioButton3_clicked()
{
    player = "lazy";
}

void StartingPage::on_pushButton_clicked()
{
    this->hide();
    game = new Game(nullptr, player);
}

