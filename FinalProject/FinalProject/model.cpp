#include "model.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int flag = 0;

void Block::setName(string s)
{
    name = s;
}

void Block::rotate()
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

void Block::move(string direction)
{
    /*int temp[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp[i][j] = shape[i][j];
        }
    }*/
    if (direction == "ROTATE")
    {
        for (int i = 0; i < 4; i++)
        {//col
            for (int j = 0; j < 4; j++)
            {//row
                if (this->shape[i][j] == 1)
                {
                    frame[position.row + i][position.col + j] -= 1;
                }
            }
        }
        this->rotate();
        for (int i = 0; i < 4; i++)
        {//col
            for (int j = 0; j < 4; j++)
            {//row
                if (this->shape[i][j] == 1)
                {
                    frame[position.row + i][position.col + j] += 1;
                }
            }
        }

        if (this->checkFixed())
        {
            for (int i = 0; i < 4; i++)
            {//col
                for (int j = 0; j < 4; j++)
                {//row
                    if (this->shape[i][j] == 1)
                    {
                        frame[position.row + i][position.col + j] -= 1;
                    }
                }
            }
            this->rotate();
            this->rotate();
            this->rotate();
            for (int i = 0; i < 4; i++)
            {//col
                for (int j = 0; j < 4; j++)
                {//row
                    if (this->shape[i][j] == 1)
                    {
                        frame[position.row + j][position.col + i] += 1;
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
                if (this->shape[j][i] == 1)
                {
                    frame[position.row + j][position.col + i] -= 1;
                    frame[position.row + j][position.col + i - 1] += 1;
                }
            }
        }
        position.col -= 1;
        if (this->checkFixed()) this->move("RIGHT");
    }
    else if (direction == "RIGHT")
    {
        for (int i = 3; i >= 0; i--)
        {//col
            for (int j = 0; j < 4; j++)
            {//row
                if (this->shape[j][i] == 1)
                {
                    frame[position.row + j][position.col + i] -= 1;
                    frame[position.row + j][position.col + i + 1] += 1;
                }
            }
        }
        position.col += 1;
        if (this->checkFixed()) this->move("LEFT");
    }
    else if (direction == "DOWN")
    {
        for (int j = 3; j >= 0; j--)
            for (int i = 0; i < 4; i++)
            {
                if (this->shape[j][i] == 1)
                {
                    frame[position.row + j][position.col + i] -= 1;
                    frame[position.row + j + 1][position.col + i] += 1;
                }
            }
        position.row += 1;
        if (this->checkFixed()) this->move("UP");
    }
    else if (direction == "UP")
    {
        flag++;
        for (int j = 0; j < 4; j++)
            for (int i = 0; i < 4; i++)
            {
                if (this->shape[j][i] == 1)
                {
                    frame[position.row + j][position.col + i] -= 1;
                    frame[position.row + j - 1][position.col + i] += 1;
                }
            }
        position.row -= 1;
        if (this->checkFixed()) this->move("DOWN");
    }
    else if (direction == "FALL")
    {
        flag = 0;
        while (!this->checkFixed())
        {
            
            this->move("DOWN");
            if (flag)    break;
            cout << endl;
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 12; j++)
                    cout << frame[i][j] << " ";
                cout << "\n";
            }
        }
        //this->move("UP");
    }
}

bool Block::checkFixed()
{
    //if (position.row > 16 || position.col > 7) return true;
    
    for (int i = 3; i >= 0; i--)
    {
        if (shape[i][0] + shape[i][1] + shape[i][2] + shape[i][3] > 0)
            if (position.row + i > 19) return true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (shape[0][i] + shape[1][i] + shape[2][i] + shape[3][i] > 0)
            if (position.col + i < 0) return true;
    }
    for (int i = 3; i >= 0; i--)
    {
        if (shape[0][i] + shape[1][i] + shape[2][i] + shape[3][i] > 0)
            if (position.col + i > 11) return true;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (frame[position.row + i][position.col + j] > 1)
                return true;
        }
    }

    return false;
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
    blockList[1].shape[0][1] = 1;
    blockList[1].shape[1][1] = 1;
    blockList[1].shape[1][2] = 1;
    blockList[1].shape[1][3] = 1;

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
    blockList[6].shape[0][1] = 1;
    blockList[6].shape[0][2] = 1;
    blockList[6].shape[1][2] = 1;
    blockList[6].shape[1][3] = 1;
}

void Model::createBlock()
{
    

    int random = getNextBox();

    current_block = blockList[random];
    current_block.position.row = 0;
    current_block.position.col = 4;
    memcpy(&frame[0][4], current_block.shape[0], 4 * sizeof(int));
    memcpy(&frame[1][4], current_block.shape[1], 4 * sizeof(int));
    memcpy(&frame[2][4], current_block.shape[2], 4 * sizeof(int));
    memcpy(&frame[3][4], current_block.shape[3], 4 * sizeof(int));

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 12; j++)
            cout << frame[i][j] << " ";
        cout << "\n";
    }
}

BlockType Model::getNextBox()
{
    srand(time(NULL));
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

void Model::movetest(string direction)
{
    current_block.move(direction);

    cout << endl;
    for (int i = 0; i < 20; i++)
    
       { for (int j = 0; j < 12; j++)
            cout << frame[i][j] << " ";
        cout << "\n";
    }
}


