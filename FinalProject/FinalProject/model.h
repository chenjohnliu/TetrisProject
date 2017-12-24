#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

using namespace std;

const int ROW = 20;
const int COL = 12;
enum State { idle = 1, setting, playing, pause };
enum BlockType { NON = -1, I, J, L, O, S, T, Z };


class Block
{
    friend class Model;
public:
    void setName(string s);
    void rotate();
    void move(string direction);
    bool checkFixed();

private:
    string name;
    int shape[4][4] = { 0 };
    struct currentPosition
    {
        int row;
        int col;
    } position;
};

class Model
{
    friend class Block;
public:
    void setBlock();
    void createBlock();
    Block getBlock()
    {
        return current_block;
    }
    void movetest(string);
    BlockType getNextBox();
    //Model();
    //State getState();
    //void setState(State newState);
    //void customSetting(char rotation, char moveleft, char drop, char moveright);
    //void motion(int move); // 5:drop 1 step
    //Block getNextBox();

private:
    Block blockList[7];
    Block current_block;
};

static int frame[ROW][COL] = { 0 };

#endif