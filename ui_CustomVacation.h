/********************************************************************************
** Form generated from reading UI file 'CustomVacation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMVACATION_H
#define UI_CUSTOMVACATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomVacation
{
public:
    QLabel *label_2;
    QPushButton *pushButtonFirst;
    QPushButton *pushButtonSecond;
    QListWidget *listWidgetFirst;
    QListWidget *listWidgetSecond;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *souvAvailable;
    QLabel *label_6;
    QListWidget *souvSelected;
    QPushButton *pushButtonSouv1;
    QPushButton *pushButtonSouv2;
    QLabel *label_7;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *allTeamPlan;
    QPushButton *bookYourTrip;
    QLabel *hiddenLabel;
    QLabel *result_lbl;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QCheckBox *offer;

    void setupUi(QWidget *CustomVacation)
    {
        if (CustomVacation->objectName().isEmpty())
            CustomVacation->setObjectName(QString::fromUtf8("CustomVacation"));
        CustomVacation->resize(953, 804);
        label_2 = new QLabel(CustomVacation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 20, 101, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        pushButtonFirst = new QPushButton(CustomVacation);
        pushButtonFirst->setObjectName(QString::fromUtf8("pushButtonFirst"));
        pushButtonFirst->setGeometry(QRect(450, 150, 61, 32));
        pushButtonSecond = new QPushButton(CustomVacation);
        pushButtonSecond->setObjectName(QString::fromUtf8("pushButtonSecond"));
        pushButtonSecond->setGeometry(QRect(450, 200, 61, 32));
        listWidgetFirst = new QListWidget(CustomVacation);
        listWidgetFirst->setObjectName(QString::fromUtf8("listWidgetFirst"));
        listWidgetFirst->setGeometry(QRect(20, 130, 401, 111));
        listWidgetFirst->setStyleSheet(QString::fromUtf8(""));
        listWidgetSecond = new QListWidget(CustomVacation);
        listWidgetSecond->setObjectName(QString::fromUtf8("listWidgetSecond"));
        listWidgetSecond->setGeometry(QRect(530, 130, 391, 111));
        label_4 = new QLabel(CustomVacation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 110, 141, 16));
        label_5 = new QLabel(CustomVacation);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 110, 281, 16));
        souvAvailable = new QListWidget(CustomVacation);
        souvAvailable->setObjectName(QString::fromUtf8("souvAvailable"));
        souvAvailable->setGeometry(QRect(20, 270, 401, 111));
        label_6 = new QLabel(CustomVacation);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 250, 141, 16));
        souvSelected = new QListWidget(CustomVacation);
        souvSelected->setObjectName(QString::fromUtf8("souvSelected"));
        souvSelected->setGeometry(QRect(530, 270, 391, 111));
        pushButtonSouv1 = new QPushButton(CustomVacation);
        pushButtonSouv1->setObjectName(QString::fromUtf8("pushButtonSouv1"));
        pushButtonSouv1->setGeometry(QRect(450, 280, 61, 32));
        pushButtonSouv2 = new QPushButton(CustomVacation);
        pushButtonSouv2->setObjectName(QString::fromUtf8("pushButtonSouv2"));
        pushButtonSouv2->setGeometry(QRect(450, 330, 61, 32));
        label_7 = new QLabel(CustomVacation);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 250, 181, 16));
        scrollArea_2 = new QScrollArea(CustomVacation);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(510, 390, 411, 351));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 411, 351));
        verticalLayoutWidget_2 = new QWidget(scrollAreaWidgetContents_3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 30, 401, 341));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);
        scrollArea = new QScrollArea(CustomVacation);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 410, 381, 361));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 381, 361));
        scrollArea->setWidget(scrollAreaWidgetContents);
        allTeamPlan = new QPushButton(CustomVacation);
        allTeamPlan->setObjectName(QString::fromUtf8("allTeamPlan"));
        allTeamPlan->setGeometry(QRect(20, 60, 221, 41));
        bookYourTrip = new QPushButton(CustomVacation);
        bookYourTrip->setObjectName(QString::fromUtf8("bookYourTrip"));
        bookYourTrip->setGeometry(QRect(730, 750, 181, 41));
        hiddenLabel = new QLabel(CustomVacation);
        hiddenLabel->setObjectName(QString::fromUtf8("hiddenLabel"));
        hiddenLabel->setEnabled(true);
        hiddenLabel->setGeometry(QRect(650, 570, 21, 16));
        result_lbl = new QLabel(CustomVacation);
        result_lbl->setObjectName(QString::fromUtf8("result_lbl"));
        result_lbl->setGeometry(QRect(40, 770, 311, 31));
        pushButton = new QPushButton(CustomVacation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 60, 121, 41));
        pushButton_2 = new QPushButton(CustomVacation);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 60, 111, 41));
        pushButton_3 = new QPushButton(CustomVacation);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 60, 201, 41));
        offer = new QCheckBox(CustomVacation);
        offer->setObjectName(QString::fromUtf8("offer"));
        offer->setGeometry(QRect(710, 60, 181, 41));

        retranslateUi(CustomVacation);

        QMetaObject::connectSlotsByName(CustomVacation);
    } // setupUi

    void retranslateUi(QWidget *CustomVacation)
    {
        CustomVacation->setWindowTitle(QCoreApplication::translate("CustomVacation", "Plan Your Trip", nullptr));
        label_2->setText(QCoreApplication::translate("CustomVacation", "Plan Your Trip!", nullptr));
        pushButtonFirst->setText(QCoreApplication::translate("CustomVacation", ">>", nullptr));
        pushButtonSecond->setText(QCoreApplication::translate("CustomVacation", "<<", nullptr));
        label_4->setText(QCoreApplication::translate("CustomVacation", "Teams Available", nullptr));
        label_5->setText(QCoreApplication::translate("CustomVacation", "Destination Teams (check preferred start team)", nullptr));
        label_6->setText(QCoreApplication::translate("CustomVacation", "Souvenir Available", nullptr));
        pushButtonSouv1->setText(QCoreApplication::translate("CustomVacation", ">>", nullptr));
        pushButtonSouv2->setText(QCoreApplication::translate("CustomVacation", "<<", nullptr));
        label_7->setText(QCoreApplication::translate("CustomVacation", "Souvenir added to your cart", nullptr));
        allTeamPlan->setText(QCoreApplication::translate("CustomVacation", "Start at New England Patriots", nullptr));
        bookYourTrip->setText(QCoreApplication::translate("CustomVacation", "Book your Trip", nullptr));
        hiddenLabel->setText(QString());
        result_lbl->setText(QString());
        pushButton->setText(QCoreApplication::translate("CustomVacation", "Perform DFS", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CustomVacation", "Perform BFS", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CustomVacation", "Minimum Spanning Tree", nullptr));
        offer->setText(QCoreApplication::translate("CustomVacation", "Offer Shortest Distance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomVacation: public Ui_CustomVacation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMVACATION_H
