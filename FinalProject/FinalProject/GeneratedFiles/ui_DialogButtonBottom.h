/********************************************************************************
** Form generated from reading UI file 'DialogButtonBottom.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBUTTONBOTTOM_H
#define UI_DIALOGBUTTONBOTTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QSplitter *splitter_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QSplitter *splitter_3;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QHBoxLayout *bottom;
    QComboBox *comboBox;
    QSpacerItem *space;
    QPushButton *resetButton;
    QPushButton *applyButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 207);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_5);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_7);

        lineEdit_6 = new QLineEdit(layoutWidget1);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lineEdit_6);

        splitter->addWidget(layoutWidget1);

        horizontalLayout_5->addWidget(splitter);

        splitter_2 = new QSplitter(Dialog);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget2 = new QWidget(splitter_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        lineEdit_3 = new QLineEdit(layoutWidget2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_3);

        splitter_2->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(splitter_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        lineEdit_4 = new QLineEdit(layoutWidget3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_4);

        splitter_2->addWidget(layoutWidget3);

        horizontalLayout_5->addWidget(splitter_2);


        verticalLayout->addLayout(horizontalLayout_5);

        splitter_3 = new QSplitter(Dialog);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(splitter_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(label_8);
        lineEdit_7 = new QLineEdit(splitter_3);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(lineEdit_7);

        verticalLayout->addWidget(splitter_3);

        bottom = new QHBoxLayout();
        bottom->setSpacing(6);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        bottom->addWidget(comboBox);

        space = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottom->addItem(space);

        resetButton = new QPushButton(Dialog);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        bottom->addWidget(resetButton);

        applyButton = new QPushButton(Dialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        bottom->addWidget(applyButton);


        verticalLayout->addLayout(bottom);


        retranslateUi(Dialog);
        QObject::connect(applyButton, SIGNAL(clicked()), Dialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Settings", nullptr));
        label_6->setText(QApplication::translate("Dialog", "Left", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("Dialog", "A", nullptr));
        label_7->setText(QApplication::translate("Dialog", "Down", nullptr));
        lineEdit_6->setText(QString());
        lineEdit_6->setPlaceholderText(QApplication::translate("Dialog", "S", nullptr));
        label_5->setText(QApplication::translate("Dialog", "Right", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("Dialog", "D", nullptr));
        label_4->setText(QApplication::translate("Dialog", "Rotate", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("Dialog", "W", nullptr));
        label_8->setText(QApplication::translate("Dialog", "Fall", nullptr));
        lineEdit_7->setPlaceholderText(QApplication::translate("Dialog", "F", nullptr));
        comboBox->setItemText(0, QApplication::translate("Dialog", "Level 1", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog", "Level 2", nullptr));
        comboBox->setItemText(2, QApplication::translate("Dialog", "Level 3", nullptr));
        comboBox->setItemText(3, QApplication::translate("Dialog", "Level 4", nullptr));
        comboBox->setItemText(4, QApplication::translate("Dialog", "Level 5", nullptr));
        comboBox->setItemText(5, QApplication::translate("Dialog", "Level 6", nullptr));
        comboBox->setItemText(6, QApplication::translate("Dialog", "Level 7", nullptr));
        comboBox->setItemText(7, QApplication::translate("Dialog", "Level 8", nullptr));
        comboBox->setItemText(8, QApplication::translate("Dialog", "Level 9", nullptr));
        comboBox->setItemText(9, QApplication::translate("Dialog", "Level 10", nullptr));

        resetButton->setText(QApplication::translate("Dialog", "Reset", nullptr));
        applyButton->setText(QApplication::translate("Dialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBUTTONBOTTOM_H
