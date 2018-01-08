#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include "controller.h"
#include <QLabel>
#include <QString>
class view;

using namespace std;

const int ROW = 20;
const int COL = 12;
enum BlockType { NON = -1, I, J, L, O, S, T, Z };


class Block
{
    friend class Model;
public:
    void setName(string s);
    void rotate();

private:
    string name;
    int shape[4][4] = { 0 };
    struct currentPosition
    {
        int row;
        int col;
    } position;
    bool canMove = true;
	int type = -1;
};


class Model
{
    friend class Block;
	friend class view;
public:
	enum State { idle = 1, setting, playing, pause };
	int second = 0;
	int minute = 0;
    Model() {};
    Model(view* viewClass);

    void setBlock();
	bool gameOver();
	BlockType getNextBox();
	void createBlock();

    void cleanAll();

    bool canMove();
	void move(string direction);
	bool checkFixed();

    void shiftRow();
    void frameDown(int row);

    void setState(State inputState);
	void secondChanged();
    State getState();
	Block getBlock()
	{
		return current_block;
	}
	void changeScore(int);
	int score = 0;
    //Model();
    //State getState();
    //void setState(State newState);
    //void customSetting(char rotation, char moveleft, char drop, char moveright);
    //void motion(int move); // 5:drop 1 step
    //Block getNextBox();
	int getFrame(int i, int j);
	int getRandom();

	//~~~~~
	int getShiftCount();
	int getLevelInterval();
	void setLevel();
	void init();
	int getInterval();

	void changeLevel(int);

private:
    Block blockList[7];
    Block current_block;
    State currentState;
    view* myView;
	int frame[ROW][COL] = { 0 };
	
    int first = 1;
    int random;
    int iterator = 0;


	//~~~~~~~~~~~~~~
	int shiftCounter = 0;
	int level = 1;
	double dropInterval = 1000;
	double oneRowScore = 100;

	double dropRate = 1.2;
	double scoreRate = 1.5;
	int levelInterval = 5;
};


#endif
