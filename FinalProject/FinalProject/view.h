#pragma once

#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <string>
#include <QKeyEvent>
#include "ui_view.h"
#include "externaldialog.h"

//~~~~~~~~~~~~~~~~~~
#include"model.h"
#include"controller.h"
#include <QLabel>
#include <QString>
//~~~~~~~~~~~~~~~

class view : public QMainWindow
{
    friend class Model;
    Q_OBJECT

public:
    view(QWidget *parent = Q_NULLPTR);
    virtual void changeView(Model::State myState);
	void updateLevel(int level);
    void callForChangeLevel(int level);

public slots:
    void changeIcon();
    void showSetting();
    void restart();
    void keyPressEvent(QKeyEvent *event);

protected:
	void updateScore(int score);
    Ui::viewClass ui;
    int stat = 1;   // stat = 0 -> pause icon, stat = 1 -> resume icon
    //Ui::Dialog myDialog;
    QLabel board[ROW][COL];
    QLabel preview[12][6];
    //
	void printSecond();
    Controller *myController;
    Model *myModel;
    //

    int fallTemp = Qt::Key_F;
    int rotateTemp = Qt::Key_W;
    int downTemp = Qt::Key_S;
    int leftTemp = Qt::Key_A;
    int rightTemp = Qt::Key_D;

    ExternalDialog *newDialog;
};