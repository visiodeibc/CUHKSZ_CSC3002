#include "startingpage.h"
#include "ui_startingpage.h"
#include "game.h"

#include <QApplication>
#include <QPixmap>

// To play the soundtrack
#include <QMediaPlayer>

Game * game;

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

    //Stop background music
    music_sp->stop();
}

