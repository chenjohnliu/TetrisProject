#include<iostream>
#include "model.h"
//#include <QtCore/QCoreApplication>
//
//int main(int argc[], char *argv[])
//{
//	QCoreApplication a(argc, argv);
//
//  return a.exec();
//}

int main()
{
	Model model;
	Block test;
	model.setBlock();
	model.createBlock();



	for (int i = 0; i < 6; i++) model.movetest("RIGHT");


	system("pause");
}