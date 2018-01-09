#include "externaldialog.h"
#include "ui_DialogButtonBottom.h"
#include <QDebug>
#include <string>
#include "view.h"

using namespace std;

int myFall = Qt::Key_F;
int myRotate = Qt::Key_W;
int myDown = Qt::Key_S;
int myLeft = Qt::Key_A;
int myRight = Qt::Key_D;
int myLevelIndex = 0;

ExternalDialog::ExternalDialog(view* parentView)
{
    myMainWindow = parentView;

    dialog = new QDialog;
    myDialog.setupUi(dialog);
    //dialog->setModal(true);

    QString key;

    qDebug() << char(myLeft);
    qDebug() << char(myRight);
    qDebug() << char(myDown);
    qDebug() << char(myRotate);
    qDebug() << char(myFall);

    myDialog.lineEdit_5->setText(QString(QChar::fromLatin1(char(myLeft))));
    myDialog.lineEdit_3->setText(QString(QChar::fromLatin1(char(myRight))));
    myDialog.lineEdit_6->setText(QString(QChar::fromLatin1(char(myDown))));
    myDialog.lineEdit_4->setText(QString(QChar::fromLatin1(char(myRotate))));
    myDialog.lineEdit_7->setText(QString(QChar::fromLatin1(char(myFall))));
    myDialog.comboBox->setCurrentIndex(myLevelIndex);

    dialog->setModal(true);
    dialog->show();
    //dialog->close();
    connect(myDialog.applyButton, SIGNAL(clicked()), this, SLOT(customSetting()));
    connect(myDialog.resetButton, SIGNAL(clicked()), this, SLOT(resetSetting()));
}

ExternalDialog::~ExternalDialog()
{
    delete dialog;
}

int ExternalDialog::getFall()
{
    return fall;
}

int ExternalDialog::getRotate()
{
    return rotate;
}

int ExternalDialog::getDown()
{
    return down;
}

int ExternalDialog::getLeft()
{
    return left;
}

int ExternalDialog::getRight()
{
    return right;
}

void ExternalDialog::resetSetting()
{
    myFall = fall;
    myRotate = rotate;
    myDown = down;
    myLeft = left;
    myRight = right;
    myLevelIndex = 0;
    myDialog.lineEdit_5->setText(QString(QChar::fromLatin1(char(myLeft))));
    myDialog.lineEdit_3->setText(QString(QChar::fromLatin1(char(myRight))));
    myDialog.lineEdit_6->setText(QString(QChar::fromLatin1(char(myDown))));
    myDialog.lineEdit_4->setText(QString(QChar::fromLatin1(char(myRotate))));
    myDialog.lineEdit_7->setText(QString(QChar::fromLatin1(char(myFall))));
    myDialog.comboBox->setCurrentIndex(myLevelIndex);
}

void ExternalDialog::customSetting()
{
    QString number;
    string temp;

    number = myDialog.lineEdit_7->text();
    temp = number.toStdString();
    myFall = toupper(temp[0]);
    qDebug() << "fall:" << myFall;
    
    number = myDialog.lineEdit_5->text();
    temp = number.toStdString();
    myLeft = toupper(temp[0]);
    qDebug() << "left:" << myLeft;
    
    number = myDialog.lineEdit_3->text();
    temp = number.toStdString();
    myRight = toupper(temp[0]);
    qDebug() << "right:" << myRight;
    
    number = myDialog.lineEdit_6->text();
    temp = number.toStdString();
    myDown = toupper(temp[0]);
    qDebug() << "down:" << myDown;
    
    number = myDialog.lineEdit_4->text();
    temp = number.toStdString();
    myRotate = toupper(temp[0]);
    qDebug() << "rotate:" << myRotate;
    
    levelIndex = myDialog.comboBox->currentIndex();
    myLevelIndex = levelIndex;
    myMainWindow->callForChangeLevel(levelIndex + 1);

    qDebug() << levelIndex;
    qDebug() << "Hello";

    dialog->close();
}