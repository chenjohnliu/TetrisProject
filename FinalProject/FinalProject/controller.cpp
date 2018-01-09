#include "controller.h"
#include "model.h"


Controller::Controller(Model *model)
{
    gameModel = model;

    timer=new QTimer();
	secondTimer = new QTimer();

    startGame();
    //userHasInput(start);
}

void Controller::startGame()
{
    gameModel->setState(Model::idle);//~~~~~~~~~~~~~~~~~~~~~~
    gameModel->setBlock();
}

void Controller::play()
{
	gameModel->setState(Model::playing);
	if (!gameModel->gameOver())
	{

		gameModel->createBlock();
		gameModel->setState(Model::playing);
	}
	gameModel->setState(Model::playing);

	connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));

	timer->start(gameModel->getInterval());

	connect(secondTimer, SIGNAL(timeout()), this, SLOT(countTime()));

	secondTimer->start(1000);
}

int Controller::getPlayStat()
{
    return playStat;
}

void Controller::restart()
{
	//playStat = 0;
	gameModel->cleanAll();
	gameModel->init();
	//gameModel->setState(Model::idle);

	timer->stop();
	secondTimer->stop();
	gameModel->second = 0;
	gameModel->minute = 0;
	gameModel->changeScore(0);
	if (!gameModel->gameOver())
	{
		gameModel->createBlock();
	}
	gameModel->setState(Model::playing);

	timer->start(gameModel->getInterval());
	secondTimer->start(1000);
}
void Controller::userHasInput(inputInformation input)
{
    Model::State theState = gameModel->getState();
    if (theState == Model::playing)
    {
        if (gameModel->level != gameModel->originalLevel)
        {
            timer->start(gameModel->getInterval());
            gameModel->originalLevel = gameModel->level;
        }

        switch (input)
        {
        case left:
            gameModel->move("LEFT");
			gameModel->setState(Model::playing);
			
            break;
        case right:
            gameModel->move("RIGHT");
			gameModel->setState(Model::playing);
            break;
        case drop:
            gameModel->move("FALL");
			gameModel->setState(Model::playing);
            gameModel->shiftRow();
			if (gameModel->getShiftCount() >= gameModel->getLevelInterval())
			{
				gameModel->changeLevel(++gameModel->level);
				timer->start(gameModel->getInterval());
			}
			if (!gameModel->gameOver())
			{
				gameModel->createBlock();
				gameModel->setState(Model::playing);
			}
            else
                gameModel->setState(Model::idle);
            break;
        case rotate:
            gameModel->move("ROTATE");
			gameModel->setState(Model::playing);
            break;
        case pause:
            timer->stop();
			secondTimer->stop();
            gameModel->setState(Model::pause);
            break;
        case down:
			if (gameModel->canMove())
			{
				gameModel->move("DOWN");
				gameModel->setState(Model::playing);
			}
            else
            {
                gameModel->shiftRow();
				if (gameModel->getShiftCount() >= gameModel->getLevelInterval())
				{
                    gameModel->changeLevel(++gameModel->level);
                    timer->start(gameModel->getInterval());
				}
				if (!gameModel->gameOver())
				{
					gameModel->createBlock();
					gameModel->setState(Model::playing);
				}
                else
                {
                    gameModel->setState(Model::idle);
                    playStat = 0;
                }
                //gameModel->createBlock();
            }
            break;
        default:
            cout << "ERROR:playing+start";
        }
    }
	else if (theState == Model::idle)
	{
		secondTimer->stop();
		if (input == start)
		{
			playStat = 1;
			play();
			//gameModel->setState(Model::playing);
		}
		else
		{
			cout << "ERROR:idle state+ !start";
		}
	}
    else if (theState == Model::pause)
    {
        if (input == resume)
        {
            timer->start();
			secondTimer->start();
            gameModel->setState(Model::playing);
        }
        else
        {
            cout << "ERROR:pause state+ !resume";
        }
    }
    else
    {
        cout << "I don't know why we got here";
    }
}

void Controller::MySlot()
{
	userHasInput(down);
	
	/*int choose = rand() % 4;
	if(choose == 0) userHasInput(down);
	else if(choose == 1) userHasInput(left);
	else if (choose == 2) userHasInput(right);
	else userHasInput(drop);*/


	/*userHasInput(down);
	int choose = rand() % 5;
	if (choose == 0) userHasInput(down);
	else if (choose == 1) userHasInput(left);
	else if (choose == 2) userHasInput(right);
	else if (choose == 3|| choose == 4) userHasInput(rotate);*/
	//else userHasInput(drop);

	/*rotate有問題, 顯示藍色代阜贍個點的值為2*/

}

void Controller::countTime()
{
	if (gameModel->getState() != pause)
	{
		if (gameModel->second >= 60)
		{
			gameModel->minute += 1;
			gameModel->second = 0;
		}
		else
		{
			gameModel->second += 1;
		}

		gameModel->secondChanged();
	}
}
