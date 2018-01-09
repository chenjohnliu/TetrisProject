#pragma once

#include <QDialog>
#include <QKeyEvent>
#include "ui_DialogButtonBottom.h"

class view;

class ExternalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExternalDialog(QWidget *parent = 0) {};
    ExternalDialog(view* parentView);
    ~ExternalDialog();
    int getFall();
    int getRotate();
    int getDown();
    int getLeft();
    int getRight();

public slots:
    void customSetting();
    void resetSetting();

private:
    Ui::Dialog myDialog;
    QDialog *dialog;
    view *myMainWindow;

    int levelIndex = 0;

    int fall = Qt::Key_F;
    int rotate = Qt::Key_W;
    int down = Qt::Key_S;
    int left = Qt::Key_A;
    int right = Qt::Key_D;
};

extern int myLevelIndex;
extern int myFall;
extern int myRotate;
extern int myDown;
extern int myLeft;
extern int myRight;