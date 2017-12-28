#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	QWidget *window = new QWidget;


	//QVBoxLayout *vBoxLayout = new QVBoxLayout;
	QPixmap blockImg("D:block.png");
	QLabel *label = new QLabel;
	blockImg.scaled(25, 25);
	label->setPixmap(blockImg.scaled(25, 25));
	label->setFrameStyle(QFrame::Panel + QFrame::Sunken);
	
	QLabel *label10 = new QLabel;
	blockImg.scaled(25, 25);
	label10->setPixmap(blockImg.scaled(25, 25));
	label10->setFrameStyle(QFrame::Panel + QFrame::Sunken);
	QLabel *label13 = new QLabel;
	blockImg.scaled(25, 25);
	label13->setPixmap(blockImg.scaled(25, 25));
	label13->setFrameStyle(QFrame::Panel + QFrame::Sunken);
	QLabel *label12 = new QLabel;
	blockImg.scaled(25, 25);
	label12->setPixmap(blockImg.scaled(25, 25));
	label12->setFrameStyle(QFrame::Panel + QFrame::Sunken);
	QLabel *label14 = new QLabel;
	blockImg.scaled(25, 25);
	label14->setPixmap(blockImg.scaled(18,18));

	QLabel *label15 = new QLabel;
	blockImg.scaled(25, 25);
	label15->setPixmap(blockImg.scaled(18, 18));

	QLabel *label16 = new QLabel;
	blockImg.scaled(25, 25);
	label16->setPixmap(blockImg.scaled(18, 18));

	QLabel *label17 = new QLabel;
	blockImg.scaled(25, 25);
	label17->setPixmap(blockImg.scaled(18, 18));

	QPushButton *undoBtn = new QPushButton;
	QPixmap pixmap("D:undo.png");
	QIcon ButtonIcon(pixmap);
	undoBtn->setIcon(ButtonIcon);
	undoBtn->setIconSize(QSize(75,75));

	QPushButton *pauseBtn = new QPushButton;
	QPixmap pixmap2("D:pause.ico");
	QIcon ButtonIcon2(pixmap2);
	pauseBtn->setIcon(ButtonIcon2);
	pauseBtn->setIconSize(QSize(75, 75));

	QPushButton *cancelBtn = new QPushButton;
	QPixmap pixmap3("D:cancel.png");
	QIcon ButtonIcon3(pixmap3);
	cancelBtn->setIcon(ButtonIcon3);
	cancelBtn->setIconSize(QSize(40, 40));

	QPushButton *settingBtn = new QPushButton;
	settingBtn->setFixedHeight(75);
	settingBtn->setFixedWidth(75);
	QRect *rect = new QRect(0, 0, 75, 75);
	QRegion* region = new QRegion(*rect, QRegion::Ellipse);

	settingBtn->setMask(*region);
	settingBtn->setText("setting");






	QGridLayout *layoutBiggest = new QGridLayout;
	QGridLayout *layoutBlockFrame = new QGridLayout;
	QGridLayout *layoutNextBlock = new QGridLayout;
	QGridLayout *layoutRightSide = new QGridLayout;
	
	for (int i = 0; i < 4; i++)
	{
		layoutNextBlock->setRowMinimumHeight(i, 18);
	}
	for (int i = 0; i < 4; i++)
	{
		layoutRightSide->setRowMinimumHeight(i, 18);
	}
	for (int i = 0; i < 4; i++)
	{
		layoutNextBlock->setColumnMinimumWidth(i, 18);
	}
	for (int i = 2; i < 6; i++)
	{
		
		layoutBiggest->setRowMinimumHeight(i, 75);
	}
	layoutBiggest->setRowMinimumHeight(0, 20);
	layoutBiggest->setRowMinimumHeight(1, 20);
	for (int i = 0; i < 3; i++)
	{
		layoutBiggest->setColumnMinimumWidth(i, 20);
	}
	for (int i = 3; i < 5; i++)
	{
		layoutBiggest->setColumnMinimumWidth(i, 75);
	}
	layoutBiggest->setColumnMinimumWidth(0, 20);
	layoutBiggest->setColumnMinimumWidth(5, 40);
	for (int i = 0; i < 20; i++)
	{
		
		layoutBlockFrame->setRowMinimumHeight(i, 25);
	}
	for (int i = 0; i < 12; i++)
	{
		layoutBlockFrame->setColumnMinimumWidth(i, 25);
	}
	/*layout->setColumnMinimumWidth(0, 200);
	layout->setColumnMinimumWidth(1, 100);
	layout->setColumnMinimumWidth(2, 100);
	layout->setColumnMinimumWidth(3, 100);*/
	QLabel *labelLevelNumber = new QLabel("1");
	labelLevelNumber->setFrameStyle(QFrame::Panel + QFrame::Sunken);
	labelLevelNumber->setAlignment(Qt::AlignCenter);
	//label1->resize(QSize(5, 5));
	QLabel *labelLevelString = new QLabel("Level");
	labelLevelString->setAlignment(Qt::AlignCenter);
	QLabel *labelScoreNumber = new QLabel("3456");
	labelScoreNumber->setFrameStyle(QFrame::Panel + QFrame::Sunken);
	labelScoreNumber->setAlignment(Qt::AlignCenter);
	QLabel *labelScoreString = new QLabel("Score");
	labelScoreString->setAlignment(Qt::AlignCenter);
	QLabel *labelTimeString = new QLabel("Time");
	labelTimeString->setAlignment(Qt::AlignCenter);
	QLabel *labelTimeNumber = new QLabel("1min10s");
	labelTimeNumber->setFrameStyle(QFrame::Panel + QFrame::Sunken);
	labelTimeNumber->setAlignment(Qt::AlignCenter);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			QLabel *label = new QLabel;
			label->setFrameStyle(QFrame::Panel + QFrame::Sunken);
			layoutBlockFrame->addWidget(label, i, j);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			QLabel *label = new QLabel;
			label->setFrameStyle(QFrame::Panel + QFrame::Sunken);
			label->setFixedHeight(18);
			layoutNextBlock->addWidget(label, i, j);
		}
	}
	layoutBiggest->addWidget(labelLevelNumber, 0, 0);
	layoutBiggest->addWidget(labelScoreNumber, 0, 1);
	layoutBiggest->addWidget(labelLevelString, 1, 0);
	layoutBiggest->addWidget(labelScoreString, 1, 1);
	layoutBiggest->addWidget(labelTimeNumber, 0, 3);
	layoutBiggest->addWidget(labelTimeString, 1, 3);
	layoutRightSide->addWidget(undoBtn, 0, 0);
	layoutRightSide->addWidget(pauseBtn, 1, 0);
	layoutBiggest->addWidget(cancelBtn, 0, 5);
	layoutRightSide->addLayout(layoutNextBlock, 3, 0);
	layoutRightSide->addWidget(settingBtn, 4, 0);
	layoutBiggest->addLayout(layoutRightSide, 3, 4);
	layoutBlockFrame->addWidget(label, 1, 0);
	layoutBlockFrame->addWidget(label10, 2, 0);
	layoutBlockFrame->addWidget(label13, 3, 0);
	layoutBlockFrame->addWidget(label12, 4, 0);
	layoutNextBlock->addWidget(label14, 1, 0);
	layoutNextBlock->addWidget(label15, 2, 0);
	layoutNextBlock->addWidget(label16, 2, 1);
	layoutNextBlock->addWidget(label17, 2, 2);
	layoutBiggest->addLayout(layoutBlockFrame, 3, 1);

	window->setLayout(layoutBiggest);
	window->show();

	return app.exec();
}
