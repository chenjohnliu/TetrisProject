#include "model.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include "view.h"

using namespace std;

int flag = 0;

Model::Model(view* viewClass)
{
   myView = viewClass;
}

void Block::setName(string s)
{
    name = s;
}

void Block::rotate()
{
	if (type == 0)
	{
		int n = 4;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = i; j < n - 1 - i; j++)
			{
				int temp = shape[i][j];
				shape[i][j] = shape[n - 1 - j][i];
				shape[n - 1 - j][i] = shape[n - 1 - i][n - 1 - j];
				shape[n - 1 - i][n - 1 - j] = shape[j][n - 1 - i];
				shape[j][n - 1 - i] = temp;
			}
		}
	}
	else
	{
		int n = 3;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = i; j < n - 1 - i; j++)
			{
				int temp = shape[i][j];
				shape[i][j] = shape[n - 1 - j][i];
				shape[n - 1 - j][i] = shape[n - 1 - i][n - 1 - j];
				shape[n - 1 - i][n - 1 - j] = shape[j][n - 1 - i];
				shape[j][n - 1 - i] = temp;
			}
		}
	}
}

void Model::setBlock()
{
	blockList[0].setName("I");
	blockList[1].setName("J");
	blockList[2].setName("L");
	blockList[3].setName("O");
	blockList[4].setName("S");
	blockList[5].setName("T");
	blockList[6].setName("Z");

	// for shape "I"
	for (int i = 0; i < 4; i++)
	{
		blockList[0].shape[i][1] = 1;
	}

	// for shape "J"
	blockList[1].shape[0][0] = 1;
	blockList[1].shape[1][0] = 1;
	blockList[1].shape[1][1] = 1;
	blockList[1].shape[1][2] = 1;

	// for shape "L"
	blockList[2].shape[0][2] = 1;
	blockList[2].shape[1][2] = 1;
	blockList[2].shape[1][1] = 1;
	blockList[2].shape[1][0] = 1;

	// for shape "O"
	blockList[3].shape[0][1] = 1;
	blockList[3].shape[0][2] = 1;
	blockList[3].shape[1][1] = 1;
	blockList[3].shape[1][2] = 1;

	// for shape "S"
	blockList[4].shape[1][0] = 1;
	blockList[4].shape[1][1] = 1;
	blockList[4].shape[0][1] = 1;
	blockList[4].shape[0][2] = 1;

	// for shape "T"
	blockList[5].shape[0][1] = 1;
	blockList[5].shape[1][0] = 1;
	blockList[5].shape[1][1] = 1;
	blockList[5].shape[1][2] = 1;

	// for shape "Z"
	blockList[6].shape[0][0] = 1;
	blockList[6].shape[0][1] = 1;
	blockList[6].shape[1][1] = 1;
	blockList[6].shape[1][2] = 1;

}

BlockType Model::getNextBox()
{
    iterator++;
	srand(time(NULL) + iterator);
	int random = rand() % 7;
	switch (random)
	{
	case 0:
		return L;
		break;
	case 1:
		return J;
		break;
	case 2:
		return I;
		break;
	case 3:
		return S;
		break;
	case 4:
		return Z;
		break;
	case 5:
		return O;
		break;
	case 6:
		return T;
		break;
	default:
		cout << "ERROR NEW BLOCK TYPE!";
		return NON;
		break;
	}
}

bool Model::gameOver()
{
    if (first == 1)
    {
		int tmp = getNextBox();
        current_block = blockList[tmp];
		current_block.type = tmp;
    }
    else
    {
        current_block = blockList[random];
		current_block.type = random;
    }
    current_block.position.row = 0;
    current_block.position.col = 4;
    first = 0;

    random = getNextBox();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (current_block.shape[i][j] == 1)
            {
                if (frame[0 + i][4 + j] == 1) return true;
            }
        }
        if (i == 3) return false;
    }
}

void Model::createBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (current_block.shape[i][j] == 1)
			{
				frame[0 + i][4 + j] = 1;
			}
		}
	}
}

void Model::cleanAll()
{
    first = 1;
	iterator = 0;
	score = 0;
    memset(&frame, 0, sizeof(frame[0][0]) * ROW * COL);
}

bool Model::checkFixed()
{
    //if (position.row > 16 || position.col > 7) return true;

    for (int i = 3; i >= 0; i--)
    {
        if (this->current_block.shape[i][0] + this->current_block.shape[i][1] + this->current_block.shape[i][2] + this->current_block.shape[i][3] > 0)
            if (this->current_block.position.row + i > 19) return true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (this->current_block.shape[0][i] + this->current_block.shape[1][i] + this->current_block.shape[2][i] + this->current_block.shape[3][i] > 0)
            if (this->current_block.position.col + i < 0) return true;
    }
    for (int i = 3; i >= 0; i--)
    {
        if (this->current_block.shape[0][i] + this->current_block.shape[1][i] + this->current_block.shape[2][i] + this->current_block.shape[3][i] > 0)
            if (this->current_block.position.col + i > 11) return true;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
			if (this->current_block.position.row + i > 19 || this->current_block.position.col + j < 0 || this->current_block.position.col + j>11)
				continue;
            if (frame[this->current_block.position.row + i][this->current_block.position.col + j] > 1)
                return true;
        }
    }

    return false;
}

void Model::move(string direction)
{
	if (direction == "ROTATE")
	{
		if (this->current_block.position.row > 16 || this->current_block.position.col < 0 || this->current_block.position.col>8 || this->current_block.type == 3) {}
		else
		{
			for (int i = 0; i < 4; i++)
			{//col
				for (int j = 0; j < 4; j++)
				{//row
					if (this->current_block.shape[i][j] == 1)
					{
						frame[this->current_block.position.row + i][this->current_block.position.col + j] -= 1;
					}
				}
			}
			this->current_block.rotate();
			for (int i = 0; i < 4; i++)
			{//col
				for (int j = 0; j < 4; j++)
				{//row
					if (this->current_block.shape[i][j] == 1)
					{
						frame[this->current_block.position.row + i][this->current_block.position.col + j] += 1;
					}
				}
			}

			if (this->checkFixed())
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (this->current_block.shape[i][j] == 1)
						{
							frame[this->current_block.position.row + i][this->current_block.position.col + j] -= 1;
						}
					}
				}
				this->current_block.rotate();
				this->current_block.rotate();
				this->current_block.rotate();
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (this->current_block.shape[i][j] == 1)
						{
							frame[this->current_block.position.row + i][this->current_block.position.col + j] += 1;
						}
					}
				}
			}
		}
	}
	else if (direction == "LEFT")
	{
		for (int i = 0; i < 4; i++)
		{//col
			for (int j = 0; j < 4; j++)
			{//row
				if (this->current_block.shape[j][i] == 1)
				{
					frame[this->current_block.position.row + j][this->current_block.position.col + i] -= 1;
					frame[this->current_block.position.row + j][this->current_block.position.col + i - 1] += 1;
				}
			}
		}
		this->current_block.position.col -= 1;
		if (this->checkFixed()) this->move("RIGHT");
	}
	else if (direction == "RIGHT")
	{
		for (int i = 3; i >= 0; i--)
		{//col
			for (int j = 0; j < 4; j++)
			{//row
				if (this->current_block.shape[j][i] == 1)
				{
					frame[this->current_block.position.row + j][this->current_block.position.col + i] -= 1;
					frame[this->current_block.position.row + j][this->current_block.position.col + i + 1] += 1;
				}
			}
		}
		this->current_block.position.col += 1;
		if (this->checkFixed()) this->move("LEFT");
	}
	else if (direction == "DOWN")
	{
		for (int j = 3; j >= 0; j--)
			for (int i = 0; i < 4; i++)
			{
				if (this->current_block.shape[j][i] == 1)
				{
					frame[this->current_block.position.row + j][this->current_block.position.col + i] -= 1;
					frame[this->current_block.position.row + j + 1][this->current_block.position.col + i] += 1;
				}
			}
		this->current_block.position.row += 1;
		if (this->checkFixed()) this->move("UP");
	}
	else if (direction == "UP")
	{
		flag++;
		for (int j = 0; j < 4; j++)
			for (int i = 0; i < 4; i++)
			{
				if (this->current_block.shape[j][i] == 1)
				{
					frame[this->current_block.position.row + j][this->current_block.position.col + i] -= 1;
					frame[this->current_block.position.row + j - 1][this->current_block.position.col + i] += 1;
				}
			}
		this->current_block.position.row -= 1;
		if (this->checkFixed()) this->move("DOWN");
	}
	else if (direction == "FALL")
	{
		flag = 0;
		while (!this->checkFixed())
		{
			this->move("DOWN");
			if (flag)    break;
		}
	}
}

bool Model::canMove()
{
    for (int i = 0; i < 4; i++)
    {//col
        for (int j = 3; j >= 0; j--)
        {//row
            if (this->current_block.shape[j][i] == 1)
            {
                if (frame[this->current_block.position.row + j + 1][this->current_block.position.col + i] == 1 || this->current_block.position.row + j + 1 > 19)
                    return false;
                else break;
            }
        }
        if (i == 3) return true;
    }
}

void Model::shiftRow()
{
	for (int i = 0; i < 4; i++)
	{//row
		for (int j = 0; j < COL; j++)
		{//col
			if (current_block.position.row + i > 19) break;
			else
			{
				if (frame[this->current_block.position.row + i][j] == 0)
				{
					break;
				}
				if (j == COL - 1)
				{
					frameDown(this->current_block.position.row + i);

					// 我不知道是不是?一行
					shiftCounter++;
					score += oneRowScore;
					changeScore(score);
				}
			}

		}
	}
}

void Model::frameDown(int row)
{
    for (int i = row; i > 0; i--)
    {
        for (int j = 0; j < COL; j++)
        {
            frame[i][j] = frame[i - 1][j];
        }
    }
    for (int k = 0;k < COL;k++)
    {
        frame[0][k] = 0;
    }
}

void Model::setState(State inputState)
{
    currentState = inputState;
    myView->changeView(inputState);
}

Model::State Model::getState()
{
    return currentState;
}

void Model::secondChanged()
{
	myView->printSecond();
}

void Model::changeScore(int num)
{
	myView->updateScore(num);
}

int Model::getFrame(int i, int j)
{
	return frame[i][j];
}
int Model::getRandom()
{
	return random;
}



//~~~~~~~~~~~~~~~~
int Model::getShiftCount()
{
	return shiftCounter;
}

//void Model::setLevel()
//{
//	shiftCounter = 0;
//	level++;
//	dropInterval /= dropRate;
//	oneRowScore *= scoreRate;
//	changeLevel(level);
//}

void Model::init()
{
	shiftCounter = 0;
	level = 1;
	dropInterval = 1000;
	oneRowScore = 100;
	changeLevel(level);
}

int Model::getInterval()
{
	return (int)dropInterval;
}

int Model::getLevelInterval()
{
	return levelInterval;
}


void Model::changeLevel(int userLevel)
{
    shiftCounter = 0;
    level = userLevel;
    dropIntervalLevel1 = 1000;
    oneRowScoreLevel1 = 100;
    for (; userLevel > 1; userLevel--)
    {
        dropIntervalLevel1 /= dropRate;
        oneRowScoreLevel1 *= scoreRate;
    }
    dropInterval = dropIntervalLevel1;
    oneRowScore = oneRowScoreLevel1;
    myView->updateLevel(level);
}