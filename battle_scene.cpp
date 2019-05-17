#include "battle_scene.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "enemy.h"
#include "player.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMessageBox>

battle_scene::battle_scene(string player_name)
{
    QFont newFont("Courier", 20, QFont::Bold, false);
    QApplication::setFont(newFont);

    battle_stage = 1;

    if (battle_stage == 1)
    {
         enemy = new Enemy(nullptr, "enemy_calculus");
    }
    else if (battle_stage == 2)
    {
         enemy = new Enemy(nullptr, "enemy_python");
    }
    else if (battle_stage == 3)
    {
         enemy = new Enemy(nullptr, "enemy_cpp");
    }
//    enemy = new Enemy(nullptr);
    player = new Player(nullptr,player_name);

    //create a scene
    scene =  new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);
    scene->setBackgroundBrush(QBrush(QImage(":/images/images/battlebg1.png")));

    // Button to get to the page where player wins.
    QPushButton * fast_forward = new QPushButton(">>");
    fast_forward->move(500,50);
    fast_forward->setFixedHeight(40);
    fast_forward->setFixedWidth(50);
    fast_forward->setStyleSheet("width: 200px");
    scene->addWidget(fast_forward);

    // Skip button: goes straight to the navigation scene
    connect(fast_forward, &QPushButton::clicked, [this](){
        emit battle_won(4);
    }
    );

    //set up player health
    player_health = new QGraphicsTextItem();
    player_health->setPlainText(QString("Player Health: ") + QString::number(player->health));
    player_health->setDefaultTextColor(Qt::white);

    // Set up text box to display actions
    action = new QGraphicsTextItem();
    action->setPlainText(QString("You have entered the \nbattle room. Press Y to attack. "));
    action->setDefaultTextColor(Qt::white);

    //set up enemy health
    enemy_health = new QGraphicsTextItem();
    enemy_health->setPlainText(QString("Enemy Health: ") + QString::number(player->health));
    enemy_health->setDefaultTextColor(Qt::red);


    //create an item to put into the scene
    player->setPos(100,195);
    enemy->setPos(800,195);

    //create battle dialog part
    study_1 = new a_study();
    group_2 = new b_group();
    overnight_3 = new c_overnight();
    run_4 = new d_run();

    //set position of the dialog
    study_1->setPos(790,600);
    group_2->setPos(790,640);
    overnight_3->setPos(790,680);
    run_4->setPos(790,720);
    player_health->setPos(50,80);
    enemy_health->setPos(775,80);
    action->setPos(50,600);

    //add item to the scene
    scene->addItem(player);
    scene->addItem(enemy);
    scene->addItem(study_1);
    scene->addItem(group_2);
    scene->addItem(overnight_3);
    scene->addItem(run_4);
    scene->addItem(player_health);
    scene->addItem(enemy_health);
    scene->addItem(action);

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


    connect(this, SIGNAL(player_hit()), player, SLOT(start_animation()));
    connect(this, SIGNAL(enemy_hit()), enemy, SLOT(start_animation()));
}

void battle_scene::up(int a) // Selecting the attack modes
{
    if(a == 1){
        study_1->setDefaultTextColor(Qt::white);
        run_4->setDefaultTextColor(Qt::yellow);
        run_4->setFocus();
    }else if(a == 2){
        group_2->setDefaultTextColor(Qt::white);
        study_1->setDefaultTextColor(Qt::yellow);
        study_1->setFocus();
    }else if(a == 3){
        overnight_3->setDefaultTextColor(Qt::white);
        group_2->setDefaultTextColor(Qt::yellow);
        group_2->setFocus();
    }else if(a == 4){
        run_4->setDefaultTextColor(Qt::white);
        overnight_3->setDefaultTextColor(Qt::yellow);
        overnight_3->setFocus();
    }
}

void battle_scene::down(int a)
{
    if(a == 1){
        study_1->setDefaultTextColor(Qt::white);
        group_2->setDefaultTextColor(Qt::yellow);
        group_2->setFocus();
    }else if(a == 2){
        group_2->setDefaultTextColor(Qt::white);
        overnight_3->setDefaultTextColor(Qt::yellow);
        overnight_3->setFocus();
    }else if(a == 3){
        overnight_3->setDefaultTextColor(Qt::white);
        run_4->setDefaultTextColor(Qt::yellow);
        run_4->setFocus();
    }else if(a == 4){
        run_4->setDefaultTextColor(Qt::white);
        study_1->setDefaultTextColor(Qt::yellow);
        study_1->setFocus();
    }
}

void battle_scene::yes(int a)
{
    float hit_probability = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    if(a == 1) //  study attack
    {
        // Player attacking enemy, 5.85
        if (hit_probability <= 0.9){
            int damage_amount = rand() % 6 + 4; // random int 4-7
            enemy->health = std::max(0, enemy->health - damage_amount); // Health can't go negative
            enemy_health->setPlainText(QString("Enemy Health: ") + QString::number(enemy->health));

            // Dialog box showing the action
            QMessageBox::information(
                this,
                tr("Dungeon and Studies"),
                tr("Enemy is is hit!") );

            emit enemy_hit();
        }
        else // If the attack is missed
        {
            // Dialog box showing the action
            QMessageBox::critical(
                this,
                tr("Dungeon and Studies"),
                tr("You MISSED!") );
        }

        // Enemy attacking player
        int enemy_attack_damage_amount = rand() % 6 + 5; // random int 5-15
        player->health = std::max(0, player->health - enemy_attack_damage_amount); // Health can't go negative
        player_health->setPlainText(QString("Player Health: ") + QString::number(player->health));

        // Dialog box showing the action
        QMessageBox::information(
            this,
            tr("Dungeon and Studies"),
            tr("Player is hit!") );

        emit player_hit();

    }
    else if(a == 2) //  group study attack
    {
        // Player attacking enemy, 10.5
        if (hit_probability <= 0.75){
            int damage_amount = rand() % 9 + 10; // random int 5-9
            enemy->health = std::max(0, enemy->health - damage_amount); // Health can't go negative
            enemy_health->setPlainText(QString("Enemy Health: ") + QString::number(enemy->health));

            // Dialog box showing the action
            QMessageBox::information(
                this,
                tr("Dungeon and Studies"),
                tr("Enemy is is hit!") );

            emit enemy_hit();
        }
        else // If the attack is missed
        {
            // Dialog box showing the action
            QMessageBox::critical(
                this,
                tr("Dungeon and Studies"),
                tr("You MISSED!") );
        }

        // Enemy attacking player
        int enemy_attack_damage_amount = rand() % 6 + 5; // random int 5-15
        player->health = std::max(0, player->health - enemy_attack_damage_amount); // Health can't go negative
        player_health->setPlainText(QString("Player Health: ") + QString::number(player->health));

        // Dialog box showing the action
        QMessageBox::information(
            this,
            tr("Dungeon and Studies"),
            tr("Player is hit!") );

        emit player_hit();
    }
    else if(a == 3) //  overnight study attack, 5
    {
        // Player attacking enemy
        if (hit_probability <= 0.5){
            int damage_amount = rand() % 20 + 1; // random int 1-19
            enemy->health = std::max(0, enemy->health - damage_amount); // Health can't go negative
            enemy_health->setPlainText(QString("Enemy Health: ") + QString::number(enemy->health));

            // Dialog box showing the action
            QMessageBox::information(
                this,
                tr("Dungeon and Studies"),
                tr("Enemy is is hit!") );

            emit enemy_hit();
        }
        else // If the attack is missed
        {
            // Dialog box showing the action
            QMessageBox::critical(
                this,
                tr("Dungeon and Studies"),
                tr("You MISSED!") );
        }

        // Enemy attacking player
        int enemy_attack_damage_amount = rand() % 6 + 5; // random int 5-15
        player->health = std::max(0, player->health - enemy_attack_damage_amount); // Health can't go negative
        player_health->setPlainText(QString("Player Health: ") + QString::number(player->health));

        // Dialog box showing the action
        QMessageBox::information(
            this,
            tr("Dungeon and Studies"),
            tr("Player is hit!") );

        emit player_hit();
    }
    else if(a == 4) //  run , have to add arithmethic function and battle finish function at the end
    {
        // Player attacking enemy
        if (hit_probability <= 0.1){
            int damage_amount = 100;
            enemy->health = std::max(0, enemy->health - damage_amount); // Health can't go negative
            enemy_health->setPlainText(QString("Enemy Health: ") + QString::number(enemy->health));

            // Dialog box showing the action
            QMessageBox::information(
                this,
                tr("Dungeon and Studies"),
                tr("Enemy died directly!") );

            emit battle_ran();
        }
        else // If the attack is missed
        {
            // Dialog box showing the action
            QMessageBox::critical(
                this,
                tr("Dungeon and Studies"),
                tr("You are TRAPPED bro!") );

            // Enemy attacking player
            int enemy_attack_damage_amount = rand() % 6 + 5; // random int 5-15
            player->health = std::max(0, player->health - enemy_attack_damage_amount); // Health can't go negative
            player_health->setPlainText(QString("Player Health: ") + QString::number(player->health));

            // Dialog box showing the action
            QMessageBox::information(
                this,
                tr("Dungeon and Studies"),
                tr("Player is hit!") );

            emit player_hit();
        }
    }

    if (player->health <= 0 or enemy->health <= 0)
    {
        battle_finish();
    }
}

void battle_scene::battle_finish()
{
    if(enemy->health <= 0)       // when player won
    {
        player->health = 100;       //health recovery
        scene->removeItem(enemy_health);    //remove existing enemy
        scene->removeItem(enemy);
        delete enemy_health;
        delete enemy;

        if (battle_stage == 1)
        {
            battle_stage ++;
            add_new_enemy("enemy_python");  //append next enemy
        }
        else if(battle_stage == 2)
        {
            battle_stage ++;
            add_new_enemy("enemy_cpp");
        }

        // If three levels of battle are won, go to game_over scene
        if(battle_stage == 3)
        {
            battle_stage ++;
        }

        QMessageBox::information(
                    this,
                    tr("Dungeon and Studies"),
                    tr("You won the round!"));

        emit battle_won(battle_stage);
    }
    else if(player->health <= 0) // when player lost
    {
        emit battle_lost();
    }
    else // when player successfully ran
    {
        player->health = 100;
        emit battle_ran();
    }
}

void battle_scene::add_new_enemy(string enemy_name)     //delete previous enemy and add next enemy
{
    enemy = new Enemy(nullptr, enemy_name);
    enemy_health = new QGraphicsTextItem();
    enemy_health->setPlainText(QString("Enemy Health: ") + QString::number(enemy->health));
    enemy_health->setDefaultTextColor(Qt::red);
    enemy->setPos(800,195);
    enemy_health->setPos(775,80);
    scene->addItem(enemy);
    scene->addItem(enemy_health);
}




























