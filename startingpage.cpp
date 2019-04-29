#include "startingpage.h"
#include "ui_startingpage.h"
#include "game.h"

#include <QApplication>
#include <QPixmap>
#include <QMediaPlayer>

#include "prologue.h"

#include "game.h"
#include "player.h"
#include "battle_scene.h"
#include "startingpage.h"


StartingPage::StartingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartingPage)
{
    ui->setupUi(this);

    // Play background music
    music_sp = new QMediaPlayer();
    music_sp->setMedia(QUrl("qrc:/soundtracks/soundtracks/start_game.mp3"));
    music_sp->play();
}

StartingPage::~StartingPage()
{
    delete ui;
}

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
    music_sp->stop();

    // Show the prologue screen first, before proceeding to game
    prologue = new Prologue(player);
    prologue->show();
}

