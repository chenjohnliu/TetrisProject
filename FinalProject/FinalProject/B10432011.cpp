#include"B10432011.h"

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