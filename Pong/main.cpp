#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <paddle1class.h>
#include <pongball.h>
#include <paddle2class.h>
#include <playerscore.h>
#include <computerscore.h>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    paddle1class *paddle1 = new paddle1class();                                        //create paddle1
    Paddle2Class *paddle2 = new Paddle2Class();                                        //create paddle2
    PongBall *ball = new PongBall(paddle1, paddle2);                                   //create ball
    paddle2->getBallPointer(ball);                                                     //get pointer of ball

    QGraphicsScene *scene = new QGraphicsScene();                                      //create scene pointer to new obj
    scene->setSceneRect(0,0,800,600);                                                  //set scene 800 x 600

    paddle1->setPos(paddle1->x(),(scene->height()/2)-(paddle1->rect().height())/2);    //set position of paddle1 to middle of left side
    paddle1->setFlag(QGraphicsItem::ItemIsFocusable);                                  //make paddle1 focusable [setting flag]
    paddle1->setFocus();                                                               //make paddle1 focused

    ball->setPos(scene->width()/2-(ball->rect().width()/2),                            //set ball position at center of screen
                 scene->height()/2-(ball->rect().height()/2) );

    paddle2->setPos(800-paddle2->rect().width(),(scene->height()/2)-(paddle2->rect().height())/2);

    playerscore *pscore = new playerscore();                                            //create scoreboard object - player + computer
    computerscore *cscore = new computerscore();
    ball->getPointerToScore(pscore, cscore);

    QMediaPlayer *media = new QMediaPlayer();                                          //for background music
    media->setMedia(QUrl("qrc:/music/bgsound.mp3"));
    media->play();

    scene->addItem(paddle1);                                                           //add paddle1 to scene
    scene->addItem(ball);                                                              //add ball to scene
    scene->addItem(paddle2);                                                           //add paddle2 to scene
    scene->addItem(pscore);                                                            //add player score to scene
    scene->addItem(cscore);                                                            //add computer score to scene

    QGraphicsView *view = new QGraphicsView();                                         //create view
    view->setScene(scene);                                                             //insert scene into view
    view->setFixedSize(800,600);                                                       //set size of view (800x600)
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                        //remove horizontal scroll bars from view
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                          //remove vertical scroll bars from view
    view->show();                                                                      //show view

    return a.exec();
}
