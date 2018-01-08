#ifndef CONTROLLER_H
#define CONTROLLER_H


#include<string>
#include<ctime>
#include<Qtimer.h>
#include<QtCore>
#include<QDebug>
#include <QLabel>
#include <QString>
class Model;

class Controller : public QObject
{
    Q_OBJECT

public:
    enum inputInformation { left, right, drop, rotate, down, start, resume ,pause};
    Controller() {};
    Controller(Model* model);
    void userHasInput(inputInformation input);
    void startGame();
    void play();
    int getPlayStat();
    void restart();

public slots:
    void MySlot();
	void countTime();

private:
    //int getTime();
    Model *gameModel;
    //view gameView;
    QTimer *timer;
	QTimer *secondTimer;

    int playStat = 0;   // playStat = 0 -> not playing, playStat = 1 -> playing
};

#endif // CONTROLLER_H
