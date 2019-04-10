#include<QApplication>
#include "startingpage.h"

int game_stage = 0;

int main(int argc, char *argv[]){
    QApplication a(argc,argv);

    StartingPage StartingPage;
    StartingPage.show();

    return a.exec();
}
