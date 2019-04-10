#include "battle_scene.h"

#include<QGraphicsScene>
#include<QGraphicsSceneMouseEvent>

battle_scene::battle_scene(Player *player, Enemy *enemy)
{

    //create a scene
    scene =  new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);
    scene->setBackgroundBrush(QBrush(QImage(":/images/images/bg.png")));

    //set up player health
    player_health = new QGraphicsTextItem();
    player_health->setPlainText(QString("Player Health: ") + QString::number(player->health));
    player_health->setFont(QFont("times",25));
    player_health->setDefaultTextColor(Qt::green);

    //set up enemy health
    enemy_health = new QGraphicsTextItem();
    enemy_health->setPlainText(QString("Enemy Health: ") + QString::number(player->health));
    enemy_health->setFont(QFont("times",25));
    enemy_health->setDefaultTextColor(Qt::red);


    //create an item to put into the scene
    player->setPos(100,300);
    enemy->setPos(800,300);

    //create battle dialog part
    study_1 = new a_study();
    group_2 = new b_group();
    overnight_3 = new c_overnight();
    run_4 = new d_run();


    //set position of the dialog
    study_1->setPos(800,600);
    group_2->setPos(800,640);
    overnight_3->setPos(800,680);
    run_4->setPos(800,720);
    player_health->setPos(100,20);
    enemy_health->setPos(750,20);

    //add item to the scene
    scene->addItem(player);
    scene->addItem(enemy);
    scene->addItem(study_1);
    scene->addItem(group_2);
    scene->addItem(overnight_3);
    scene->addItem(run_4);
    scene->addItem(player_health);
    scene->addItem(enemy_health);


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);
    setScene(scene);


    //when down is pressed
    connect(study_1,&a_study::down,this,&battle_scene::down);
    connect(group_2,&b_group::down,this,&battle_scene::down);
    connect(overnight_3,&c_overnight::down,this,&battle_scene::down);
    connect(run_4,&d_run::down,this,&battle_scene::down);

    //when up is pressed
    connect(study_1,&a_study::up,this,&battle_scene::up);
    connect(group_2,&b_group::up,this,&battle_scene::up);
    connect(overnight_3,&c_overnight::up,this,&battle_scene::up);
    connect(run_4,&d_run::up,this,&battle_scene::up);

    //when 'y'(yes) is pressed
    connect(study_1,&a_study::yes,this,&battle_scene::yes);
    connect(group_2,&b_group::yes,this,&battle_scene::yes);
    connect(overnight_3,&c_overnight::yes,this,&battle_scene::yes);
    connect(run_4,&d_run::yes,this,&battle_scene::yes);


}

void battle_scene::up(int a)
{
    if(a == 1){
        study_1->setDefaultTextColor(Qt::black);
        run_4->setDefaultTextColor(Qt::yellow);
        run_4->setFocus();
    }else if(a == 2){
        group_2->setDefaultTextColor(Qt::black);
        study_1->setDefaultTextColor(Qt::yellow);
        study_1->setFocus();
    }else if(a == 3){
        overnight_3->setDefaultTextColor(Qt::black);
        group_2->setDefaultTextColor(Qt::yellow);
        group_2->setFocus();
    }else if(a == 4){
        run_4->setDefaultTextColor(Qt::black);
        overnight_3->setDefaultTextColor(Qt::yellow);
        overnight_3->setFocus();
    }
}

void battle_scene::down(int a)
{
    if(a == 1){
        study_1->setDefaultTextColor(Qt::black);
        group_2->setDefaultTextColor(Qt::yellow);
        group_2->setFocus();
    }else if(a == 2){
        group_2->setDefaultTextColor(Qt::black);
        overnight_3->setDefaultTextColor(Qt::yellow);
        overnight_3->setFocus();
    }else if(a == 3){
        overnight_3->setDefaultTextColor(Qt::black);
        run_4->setDefaultTextColor(Qt::yellow);
        run_4->setFocus();
    }else if(a == 4){
        run_4->setDefaultTextColor(Qt::black);
        study_1->setDefaultTextColor(Qt::yellow);
        study_1->setFocus();
    }
}

void battle_scene::yes(int a)
{
    if(a == 1){
    }else if(a == 2){

    }else if(a == 3){

    }else if(a == 4){

    }
}
