#include "view.h"
#include "externaldialog.h"
#include <QWidget>
#include <QtCore>
#include <QLabel>
#include <QString>

view::view(QWidget *parent)
    : QMainWindow(parent)
{
    myModel = new Model(this);
    myController = new Controller(myModel);
    ui.setupUi(this);
	ui.label_3->setText(QString::number(myModel->minute) + "m" + QString::number(myModel->second) + "s");
    
    
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(changeIcon()));
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(showSetting()));
    connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(restart()));
	//connect(ui.label_3, SIGNAL(1), this, SLOT(printSecond()));
    QPixmap cancelButton(":/view/cancel.png");
    QIcon Icon;
    Icon.addPixmap(cancelButton, QIcon::Normal, QIcon::Off);
    ui.pushButton->setIcon(Icon);
    ui.pushButton->setIconSize(QSize(40, 40));
    ui.pushButton->setFixedHeight(40);
    ui.pushButton->setFixedWidth(40);

    QRect *rect = new QRect(0, 0, 40, 40);
    QRegion *region = new QRegion(*rect, QRegion::Ellipse);
    ui.pushButton->setMask(*region);


    QPixmap pauseButton(":/view/start.png");
    QIcon Icon3;
    Icon3.addPixmap(pauseButton, QIcon::Normal, QIcon::Off);
    ui.pushButton_3->setIcon(Icon3);
    ui.pushButton_3->setIconSize(QSize(60, 60));
    ui.pushButton_3->setFixedHeight(60);
    ui.pushButton_3->setFixedWidth(60);

    QRect *rect3 = new QRect(0, 0, 60, 60);
    QRegion *region3 = new QRegion(*rect3, QRegion::Ellipse);
    //ui.pushButton_3->setMask(*region3);


    QPixmap replyButton(":/view/undo.png");
    QIcon Icon4;
    Icon4.addPixmap(replyButton, QIcon::Normal, QIcon::Off);
    ui.pushButton_4->setIcon(Icon4);
    ui.pushButton_4->setIconSize(QSize(60, 60));
    ui.pushButton_4->setFixedHeight(60);
    ui.pushButton_4->setFixedWidth(60);

    QRect *rect4 = new QRect(0, 0, 60, 60);
    QRegion *region4 = new QRegion(*rect4, QRegion::Ellipse);
    //ui.pushButton_4->setMask(*region4);


    QPixmap settingButton(":/view/setting.png");
    QIcon Icon2;
    Icon2.addPixmap(settingButton, QIcon::Normal, QIcon::Off);
    ui.pushButton_2->setIcon(Icon2);
    ui.pushButton_2->setIconSize(QSize(80, 80));
    ui.pushButton_2->setFixedHeight(80);
    ui.pushButton_2->setFixedWidth(80);

    QRect *rect2 = new QRect(0, 0, 80, 80);
    QRegion *region2 = new QRegion(*rect2, QRegion::Ellipse);
    ui.pushButton_2->setMask(*region2);


    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            board[i][j].setFrameStyle(QFrame::StyledPanel + QFrame::Sunken);
          
            ui.gridLayout->addWidget(&board[i][j], i, j);
        }
    }


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            preview[i][j].setFrameStyle(QFrame::StyledPanel + QFrame::Sunken);

            ui.gridLayout_2->addWidget(&preview[i][j], i, j);
        }
    }
}

void view::changeIcon()
{
    if (stat == 0)
    {
	
        if (myController->getPlayStat() == 1)
        {
            myController->userHasInput(Controller::pause);
        }
        QPixmap startButton(":/view/start.png");
        QIcon Icon5;
        Icon5.addPixmap(startButton, QIcon::Normal, QIcon::Off);
        ui.pushButton_3->setIcon(Icon5);
        ui.pushButton_3->setIconSize(QSize(60, 60));
        ui.pushButton_3->setFixedHeight(60);
        ui.pushButton_3->setFixedWidth(60);

        QRect *rect5 = new QRect(0, 0, 60, 60);
        QRegion *region5 = new QRegion(*rect5, QRegion::Ellipse);
        this->stat = 1;
    }
    else
    {
        if (myController->getPlayStat() == 0)
        {
            myController->userHasInput(Controller::start);
        }
        if (myModel->getState() == Model::pause)
        {
            myController->userHasInput(Controller::resume);
        }
        QPixmap startButton(":/view/pause.ico");
        QIcon Icon5;
        Icon5.addPixmap(startButton, QIcon::Normal, QIcon::Off);
        ui.pushButton_3->setIcon(Icon5);
        ui.pushButton_3->setIconSize(QSize(60, 60));
        ui.pushButton_3->setFixedHeight(60);
        ui.pushButton_3->setFixedWidth(60);

        QRect *rect5 = new QRect(0, 0, 60, 60);
        QRegion *region5 = new QRegion(*rect5, QRegion::Ellipse);
        this->stat = 0;
    }
}

void view::changeView(Model::State myState)
{
    if (myState == Model::playing || myState == Model::idle)
    {
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
            {
                if (myModel->frame[i][j] == 1)
                {
                    board[i][j].setStyleSheet("QLabel{ background-color : red }");
                }
                else if(myModel->frame[i][j] == 0)
                {
                    board[i][j].setStyleSheet("QLabel{ background-color : rgba(0, 0, 0, 0%) }");
                }
				else if (myModel->frame[i][j] == 2)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : blue }");
				}
				else board[i][j].setStyleSheet("QLabel{ background-color : green }");
            }
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            preview[i][j].setStyleSheet("QLabel{ background-color : rgba(0, 0, 0, 0%) }");
        }

    switch (myModel->random)
    {
        case 0:
        {
            preview[0][1].setStyleSheet("QLabel{ background-color : red }");
            preview[1][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][1].setStyleSheet("QLabel{ background-color : red }");
            preview[3][1].setStyleSheet("QLabel{ background-color : red }");
            break;
        }

        case 1:
        {
            preview[1][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][2].setStyleSheet("QLabel{ background-color : red }");
            preview[2][3].setStyleSheet("QLabel{ background-color : red }");
            break;
        }

        case 2:
        {
            preview[1][2].setStyleSheet("QLabel{ background-color : red }");
            preview[2][2].setStyleSheet("QLabel{ background-color : red }");
            preview[2][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][0].setStyleSheet("QLabel{ background-color : red }");
            break;
        }

        case 3:
        {
            preview[1][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][2].setStyleSheet("QLabel{ background-color : red }");
            preview[1][2].setStyleSheet("QLabel{ background-color : red }");
            break;
        }

        case 4:
        {
            preview[3][1].setStyleSheet("QLabel{ background-color : red }");
            preview[3][2].setStyleSheet("QLabel{ background-color : red }");
            preview[2][2].setStyleSheet("QLabel{ background-color : red }");
            preview[2][3].setStyleSheet("QLabel{ background-color : red }");
            break;
        }

        case 5:
        {
            preview[2][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][2].setStyleSheet("QLabel{ background-color : red }");
            preview[1][2].setStyleSheet("QLabel{ background-color : red }");
            preview[2][3].setStyleSheet("QLabel{ background-color : red }");
            break;
        }

        case 6:
        {
            preview[1][0].setStyleSheet("QLabel{ background-color : red }");
            preview[1][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][1].setStyleSheet("QLabel{ background-color : red }");
            preview[2][2].setStyleSheet("QLabel{ background-color : red }");
            break;
        }

        default:
            cout << "ERROR NEW BLOCK TYPE!";
            break;
    }
}

void view::showSetting()
{
    newDialog = new ExternalDialog(this);

    //QDialog *Dialog = new QDialog;
    //myDialog.setupUi(Dialog);
    //Dialog->exec();
}

void view::restart()
{
    stat = 0;
    myController->restart();


    QPixmap pauseButton(":/view/pause.ico");
    QIcon Icon3;
    Icon3.addPixmap(pauseButton, QIcon::Normal, QIcon::Off);
    ui.pushButton_3->setIcon(Icon3);
    ui.pushButton_3->setIconSize(QSize(60, 60));
    ui.pushButton_3->setFixedHeight(60);
    ui.pushButton_3->setFixedWidth(60);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            preview[i][j].setStyleSheet("QLabel{ background-color : rgba(0, 0, 0, 0%) }");
        }
}

void view::keyPressEvent(QKeyEvent *event) {
    rotateTemp = myRotate;
    downTemp = myDown;
    leftTemp = myLeft;
    rightTemp = myRight;
    fallTemp = myFall;

    qDebug() << "click:";
    qDebug() << rotateTemp;
    qDebug() << downTemp;
    qDebug() << leftTemp;
    qDebug() << rightTemp;
    qDebug() << fallTemp;

    if (event->key() == rotateTemp)
    {
        myController->userHasInput(Controller::rotate);
    }
    else if (event->key() == downTemp)
    {
        myController->userHasInput(Controller::down);
    }
    else if (event->key() == leftTemp)
    {
        myController->userHasInput(Controller::left);
    }
    else if (event->key() == rightTemp)
    {
        myController->userHasInput(Controller::right);
    }
	else if (event->key() == fallTemp)
	{
		myController->userHasInput(Controller::drop);
	}

}

void view::printSecond()
{
	ui.label_3->setText(QString::number(myModel->minute) + "m" + QString::number(myModel->second) + "s");
}

void view::updateScore(int score)
{
	ui.label_2->clear();
	ui.label_2->setText(QString::number(score));
}

void view::updateLevel(int level)
{
	ui.label->clear();
	ui.label->setText(QString::number(level));
}

void view::callForChangeLevel(int level)
{
    myModel->changeLevel(level);
}
