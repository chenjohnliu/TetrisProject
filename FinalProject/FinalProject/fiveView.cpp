#include "fiveView.h"


void B10432014::changeView(Model::State myState)
{
	if (myState == Model::playing || myState == Model::idle)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
			{
				if (myModel->getFrame(i, j) == 1)
				{
					//board[i][j].setStyleSheet("QLabel{ background-color : black }");
					board[i][j].setStyleSheet(QString("border-image:url(:/view/teacher.png);"));
				}
				else if (myModel->getFrame(i, j) == 0)
				{
					//board[i][j].setStyleSheet("QLabel{ background-color : darkGray }");
					if (((i != 0) && (i % 4 == 0)) && j == 1) board[i][j].setStyleSheet(QString("border-image:url(:/view/greenHat.jpg);"));
					else if (((i != 0) && (i % 4 == 0)) && j == 5) board[i][j].setStyleSheet(QString("border-image:url(:/view/giveU.jpg);"));
					else if (((i != 0) && (i % 4 == 0)) && j == 10) board[i][j].setStyleSheet(QString("border-image:url(:/view/greenHat2.jpg);"));
					else if (((i != 0) && (i % 2 == 0)) && j == 3) board[i][j].setStyleSheet(QString("border-image:url(:/view/greenHat3.png);"));
					else if (((i != 0) && (i % 2 == 0)) && j == 5) board[i][j].setStyleSheet(QString("border-image:url(:/view/greenHat4.jpg);"));
					else if (((i != 0) && (i % 2 == 0)) && j == 7) board[i][j].setStyleSheet(QString("border-image:url(:/view/greenHat5.jpg);"));

					else board[i][j].setStyleSheet("QLabel{ background-color : darkGray }");
				}
				else if (myModel->getFrame(i, j) == 2)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : blue }");
				}
				else board[i][j].setStyleSheet("QLabel{ background-color : green }");
			}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			preview[i][j].setStyleSheet("QLabel{ background-color : darkGray }");
		}

	switch (myModel->getRandom())
	{
	case 0:
	{
		preview[0][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[1][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[3][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		break;		
	}				
					
	case 1:			
	{				
		preview[1][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][3].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		break;		
	}				
					
	case 2:			
	{				
		preview[1][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][0].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		break;		
	}				
					
	case 3:			
	{				
		preview[1][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[1][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		break;	
	}			
				
	case 4:		
	{			
		preview[2][0].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[1][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[1][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		break;		
	}				
					
	case 5:			
	{				
		preview[2][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[1][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][3].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		break;		
	}				
					
	case 6:			
	{				
		preview[1][0].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[1][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][1].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		preview[2][2].setStyleSheet(QString("border-image:url(:/view/hehe.jpg);"));
		break;												    
	}

	default:
		cout << "ERROR NEW BLOCK TYPE!";
		break;
	}
}

void B10432040::changeView(Model::State myState)
{
	if (myState == Model::playing || myState == Model::idle)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
			{
				if (myModel->getFrame(i, j) == 1)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : blue }");
				}
				else if (myModel->getFrame(i, j) == 0)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : rgba(0, 0, 0, 0%) }");
				}
				else if (myModel->getFrame(i, j) == 2)
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

	switch (myModel->getRandom())
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

void B10432007::changeView(Model::State myState)
{
	if (myState == Model::playing || myState == Model::idle)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
			{
				if (myModel->getFrame(i, j) == 1)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 100%) }");
				}
				else if (myModel->getFrame(i, j) == 0)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : rgba(199, 237, 204, 100%) }");
				}
				else if (myModel->getFrame(i, j) == 2)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : blue }");
				}
				else board[i][j].setStyleSheet("QLabel{ background-color : green }");
			}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			preview[i][j].setStyleSheet("QLabel{ background-color : rgba(199, 237, 204, 70%) }");
		}

	switch (myModel->getRandom())
	{
	case 0:
	{
		preview[0][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[1][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[3][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		break;
	}

	case 1:
	{
		preview[1][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][3].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		break;
	}

	case 2:
	{
		preview[1][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][0].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		break;
	}

	case 3:
	{
		preview[1][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[1][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		break;
	}

	case 4:
	{
		preview[3][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[3][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][3].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		break;
	}

	case 5:
	{
		preview[2][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[1][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][3].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		break;
	}

	case 6:
	{
		preview[1][0].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[1][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][1].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		preview[2][2].setStyleSheet("QLabel{ background-color : rgba(0, 127, 255, 70%) }");
		break;
	}

	default:
		cout << "ERROR NEW BLOCK TYPE!";
		break;
	}
}

void B10432001::changeView(Model::State myState)
{
	if (myState == Model::playing || myState == Model::idle)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
			{
				if (myModel->getFrame(i, j) == 1)
				{
					QRect *rect = new QRect(0, 0, 23, 23);
					QRegion* region = new QRegion(*rect, QRegion::Ellipse);
					board[i][j].setMask(*region);
					board[i][j].setStyleSheet("QLabel{ background-color : black }");
					board[i][j].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
				}
				else if (myModel->getFrame(i, j) == 0)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : rgba(256, 256, 256, 0%) }");
					board[i][j].setFrameStyle(QFrame::WinPanel + QFrame::Sunken);
					board[i][j].clearMask();
				}
				else if (myModel->getFrame(i, j) == 2)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : blue }");
					board[i][j].setFrameStyle(QFrame::Box + QFrame::Sunken);
				}
				else
				{
					board[i][j].setStyleSheet("QLabel{ background-color : green }");
					board[i][j].setFrameStyle(QFrame::Box + QFrame::Sunken);
				}
			}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			preview[i][j].setStyleSheet("QLabel{ background-color : rgba(256, 256, 256, 0%) }");
			preview[i][j].setFrameStyle(QFrame::WinPanel + QFrame::Sunken);
			preview[i][j].clearMask();
		}

	switch (myModel->getRandom())
	{
	case 0:
	{
		QRect *rect = new QRect(0, 0, 23, 23);
		QRegion* region = new QRegion(*rect, QRegion::Ellipse);
		preview[0][1].setMask(*region);
		preview[0][1].setStyleSheet("QLabel{ background-color : black }");
		preview[0][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[1][1].setMask(*region);
		preview[1][1].setStyleSheet("QLabel{ background-color : black }");
		preview[1][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][1].setMask(*region);
		preview[2][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[3][1].setMask(*region);
		preview[3][1].setStyleSheet("QLabel{ background-color : black }");
		preview[3][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);

		break;
	}

	case 1:
	{
		QRect *rect = new QRect(0, 0, 23, 23);
		QRegion* region = new QRegion(*rect, QRegion::Ellipse);
		preview[1][1].setMask(*region);
		preview[1][1].setStyleSheet("QLabel{ background-color : black }");
		preview[1][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][1].setMask(*region);
		preview[2][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][2].setMask(*region);
		preview[2][2].setStyleSheet("QLabel{ background-color : black }");
		preview[2][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][3].setMask(*region);
		preview[2][3].setStyleSheet("QLabel{ background-color : black }");
		preview[2][3].setFrameStyle(QFrame::WinPanel + QFrame::Raised);

		break;
	}

	case 2:
	{
		QRect *rect = new QRect(0, 0, 23, 23);
		QRegion* region = new QRegion(*rect, QRegion::Ellipse);
		preview[1][2].setMask(*region);
		preview[1][2].setStyleSheet("QLabel{ background-color : black }");
		preview[1][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][1].setMask(*region);
		preview[2][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][2].setMask(*region);
		preview[2][2].setStyleSheet("QLabel{ background-color : black }");
		preview[2][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][0].setMask(*region);
		preview[2][0].setStyleSheet("QLabel{ background-color : black }");
		preview[2][0].setFrameStyle(QFrame::WinPanel + QFrame::Raised);

		break;
	}

	case 3:
	{
		QRect *rect = new QRect(0, 0, 23, 23);
		QRegion* region = new QRegion(*rect, QRegion::Ellipse);
		preview[1][1].setMask(*region);
		preview[1][1].setStyleSheet("QLabel{ background-color : black }");
		preview[1][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][1].setMask(*region);
		preview[2][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][2].setMask(*region);
		preview[2][2].setStyleSheet("QLabel{ background-color : black }");
		preview[2][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[1][2].setMask(*region);
		preview[1][2].setStyleSheet("QLabel{ background-color : black }");
		preview[1][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);

		break;
	}

	case 4:
	{
		QRect *rect = new QRect(0, 0, 23, 23);
		QRegion* region = new QRegion(*rect, QRegion::Ellipse);
		preview[3][1].setMask(*region);
		preview[3][1].setStyleSheet("QLabel{ background-color : black }");
		preview[3][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[3][2].setMask(*region);
		preview[3][2].setStyleSheet("QLabel{ background-color : black }");
		preview[3][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][2].setMask(*region);
		preview[2][2].setStyleSheet("QLabel{ background-color : black }");
		preview[2][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][3].setMask(*region);
		preview[2][3].setStyleSheet("QLabel{ background-color : black }");
		preview[2][3].setFrameStyle(QFrame::WinPanel + QFrame::Raised);

		break;
	}

	case 5:
	{
		QRect *rect = new QRect(0, 0, 23, 23);
		QRegion* region = new QRegion(*rect, QRegion::Ellipse);
		preview[1][2].setMask(*region);
		preview[1][2].setStyleSheet("QLabel{ background-color : black }");
		preview[1][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][1].setMask(*region);
		preview[2][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][2].setMask(*region);
		preview[2][2].setStyleSheet("QLabel{ background-color : black }");
		preview[2][2].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][3].setMask(*region);
		preview[2][3].setStyleSheet("QLabel{ background-color : black }");
		preview[2][3].setFrameStyle(QFrame::WinPanel + QFrame::Raised);

		break;
	}

	case 6:
	{
		QRect *rect = new QRect(0, 0, 23, 23);
		QRegion* region = new QRegion(*rect, QRegion::Ellipse);
		preview[1][1].setMask(*region);
		preview[1][1].setStyleSheet("QLabel{ background-color : black }");
		preview[1][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][1].setMask(*region);
		preview[2][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][1].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[2][2].setMask(*region);
		preview[2][2].setStyleSheet("QLabel{ background-color : black }");
		preview[1][0].setFrameStyle(QFrame::WinPanel + QFrame::Raised);
		preview[1][0].setMask(*region);
		preview[1][0].setStyleSheet("QLabel{ background-color : black }");
		preview[1][0].setFrameStyle(QFrame::WinPanel + QFrame::Raised);

		break;
	}

	default:
		cout << "ERROR NEW BLOCK TYPE!";
		break;
	}
}

void B10432011::changeView(Model::State myState)
{
	if (myState == Model::playing || myState == Model::idle)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
			{
				if (myModel->getFrame(i, j) == 1)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : cyan }");
				}
				else if (myModel->getFrame(i, j) == 0)
				{
					board[i][j].setStyleSheet("QLabel{ background-color : rgba(0, 0, 0, 0%) }");
				}
				else if (myModel->getFrame(i, j) == 2)
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

	switch (myModel->getRandom())
	{
	case 0:
	{
		preview[0][1].setStyleSheet("QLabel{ background-color : blue }");
		preview[1][1].setStyleSheet("QLabel{ background-color : blue }");
		preview[2][1].setStyleSheet("QLabel{ background-color : blue }");
		preview[3][1].setStyleSheet("QLabel{ background-color : blue }");
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
		preview[1][2].setStyleSheet("QLabel{ background-color : green }");
		preview[2][2].setStyleSheet("QLabel{ background-color : green }");
		preview[2][1].setStyleSheet("QLabel{ background-color : green }");
		preview[2][0].setStyleSheet("QLabel{ background-color : green }");
		break;
	}

	case 3:
	{
		preview[1][1].setStyleSheet("QLabel{ background-color : magenta }");
		preview[2][1].setStyleSheet("QLabel{ background-color : magenta }");
		preview[2][2].setStyleSheet("QLabel{ background-color : magenta }");
		preview[1][2].setStyleSheet("QLabel{ background-color : magenta }");
		break;
	}

	case 4:
	{
		preview[3][1].setStyleSheet("QLabel{ background-color : yellow }");
		preview[3][2].setStyleSheet("QLabel{ background-color : yellow }");
		preview[2][2].setStyleSheet("QLabel{ background-color : yellow }");
		preview[2][3].setStyleSheet("QLabel{ background-color : yellow }");
		break;
	}

	case 5:
	{
		preview[2][1].setStyleSheet("QLabel{ background-color : gray }");
		preview[2][2].setStyleSheet("QLabel{ background-color : gray }");
		preview[1][2].setStyleSheet("QLabel{ background-color : gray }");
		preview[2][3].setStyleSheet("QLabel{ background-color : gray }");
		break;
	}

	case 6:
	{
		preview[1][0].setStyleSheet("QLabel{ background-color : black }");
		preview[1][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][1].setStyleSheet("QLabel{ background-color : black }");
		preview[2][2].setStyleSheet("QLabel{ background-color : black }");
		break;
	}

	default:
		cout << "ERROR NEW BLOCK TYPE!";
		break;
	}

}