#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "adminwindow.h"
#include "team.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QTableWidget>
#include <QList>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    unicorn::Team::initializeTeams();
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/img/unicorn.png"));
    QFile styleSheet(qApp->applicationDirPath()
                     + QDir::separator()
                     +"style.qss");

    if (!styleSheet.open(QIODevice::ReadWrite)) {
        qWarning("Unable to open :/style.qss");
        return;
    }
    qApp->setStyleSheet(styleSheet.readAll());
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    on_actionLogOut_triggered();
    ui->actionLogOut->setVisible(false);


    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(QString("SELECT TeamName FROM teams"));
    ui->teamComboBox->setModel(model);


    Team* ptr = Team::teamsBSTMap.getTreeNodes();
    Team::teamsBSTMap.display();
    int max = Team::teamsBSTMap.getBSTSize();

        for(int i=0;i<max;i++)
        {


                   std::cout <<"--------Team start here--------"<<endl;
                   std::cout<< (*(ptr+i)).getTeamId() << (*(ptr+i)).getTeamName()<<endl;
                   vector<Distance*> distanceV= (*(ptr+i)).getTeamStadium()->getDistanceFromOthers();
                           vector<SouvenirType*> souv= (*(ptr+i)).getSouvenirType();


                          std::cout <<"--------Distances--------"<<endl;
                          for (auto it2= distanceV.begin(); it2 !=  distanceV.end(); ++it2) {


                               std::cout << (*it2)->OtherStaduimName
                                        << (*it2)->OtherStaduimID
                                        <<  (*it2)->distance<<endl;
                           }
                           std::cout <<"--------Souviner--------"<<endl;

                           for (auto it3= souv.begin(); it3 !=  souv.end(); ++it3) {

                                std::cout  << (*it3)->SouvenirName
                                         << (*it3)->souvenirID
                                         <<  (*it3)->TeamID
                                         <<  (*it3)->price<<endl;
                            }
                    std::cout <<"--------Team end here--------"<<endl<<endl;
        }


}



void MainWindow::on_show_Teams_clicked()

{
    ui->numberLabel->setText("");
            QSqlQuery query;


            query.prepare(QString("SELECT TeamName FROM teams ORDER BY TeamName ASC"));


            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {

                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);
            }


            ui->numberLabel->setText(QString::number(ui->tableView->verticalHeader()->count()) + " Teams");

}

void MainWindow::on_show_AFC_Teams_clicked()
{
    ui->numberLabel->setText("");
            QSqlQuery query;
            query.prepare(QString("SELECT teams.TeamName,"
                                  "stadiums.StadiumName,stadiums.Conference,stadiums.Division "
                                  "FROM stadiums "
                                  "INNER JOIN teams ON teams.StadiumID = stadiums._id "
                                  "WHERE Conference LIKE 'American%' "
                                  "ORDER BY TeamName"));


            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {


                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);

                ui->numberLabel->setText(QString::number(ui->tableView->verticalHeader()->count()) + " AFC Teams");
            }


}

void MainWindow::on_show_NFC_Teams_clicked()
{
    ui->numberLabel->setText("");
    QSqlQuery query;
    query.prepare(QString("SELECT teams.TeamName,"
                          "stadiums.StadiumName,stadiums.Conference,stadiums.Division "
                          "FROM stadiums "
                          "INNER JOIN teams ON teams.StadiumID = stadiums._id "
                          "WHERE Conference LIKE 'National%' "
                          "ORDER BY TeamName"));

            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {


                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);

                ui->numberLabel->setText(QString::number(ui->tableView->verticalHeader()->count()) + " NFC Teams");
            }



}


void MainWindow::on_show_NFCNorth_clicked()
{
    ui->numberLabel->setText("");
            QSqlQuery query;

            query.prepare(QString("SELECT teams.TeamName,"
                                  "stadiums.StadiumName,stadiums.Conference,stadiums.Division "
                                  "FROM stadiums "
                                  "INNER JOIN teams ON teams.StadiumID = stadiums._id "
                                  "WHERE Division LIKE 'NFC  North%' "
                                  "ORDER BY TeamName"));
            //Error check
            if (!query.exec())
            {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
            else
            {


                QSqlQueryModel *search = new QSqlTableModel;
                search->setQuery(query);
                ui->tableView->show();
                ui->tableView->setModel(search);

                ui->numberLabel->setText(QString::number(ui->tableView->verticalHeader()->count()) + " NFC North Teams");
            }


}

void MainWindow::on_show_Stadiums_clicked()
{
    ui->numberLabel->setText("");
    QSqlQuery query;


    query.prepare(QString("SELECT stadiums.StadiumName,teams.TeamName FROM stadiums INNER JOIN teams ON teams.StadiumID = stadiums._id ORDER BY StadiumName ASC"));



    //Error check
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {


        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);
    }


}

void MainWindow::on_show_StadiumsByDate_clicked()
{
    ui->numberLabel->setText("");
    QSqlQuery query;


    query.prepare(QString("SELECT stadiums.StadiumName,teams.TeamName,stadiums.DateOpened FROM stadiums INNER JOIN teams ON teams.StadiumID = stadiums._id ORDER BY DateOpened ASC"));


    //Error check
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {


        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);

    }

}

void MainWindow::on_show_Selection_clicked()
{
    ui->numberLabel->setText("");
    QSqlQuery query;

    QString tName = ui->teamComboBox->currentText();

    query.prepare(QString("SELECT teams.teamName,stadiums.StadiumName,stadiums.SeatingCapacity,stadiums.Location,stadiums.Conference, "
                          "stadiums.Division,stadiums.SurfaceType,stadiums.StadiumRoofType,stadiums.DateOpened "
                          "FROM teams "
                          "INNER JOIN stadiums ON teams.stadiumID = stadiums._id "
                          "WHERE teamName LIKE '" + tName + "'"));

    //Error check
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);

    }
}

void MainWindow::on_show_openRoof_clicked()
{
    ui->numberLabel->setText("");
    QSqlQuery query;
    QList<QString> stadiumList;
    int count = 0;

    query.prepare(QString("SELECT teams.teamName,"
                          "stadiums.StadiumName,stadiums.SeatingCapacity,"
                          "stadiums.Location,stadiums.Conference,stadiums.Division,stadiums.SurfaceType,stadiums.StadiumRoofType,stadiums.DateOpened "
                          "FROM teams "
                          "INNER JOIN stadiums ON teams.StadiumID = stadiums._id "
                          "WHERE StadiumRoofType LIKE 'Open'"
                          "ORDER BY StadiumName"));

    //Error check
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {

        while(query.next())
        {
            QString stadiumN = query.value(1).toString();
            if(!stadiumList.contains(stadiumN))
            {
                stadiumList.append(stadiumN);
                count++;
            }

        }

        for(int i = 0; i < stadiumList.size(); i ++)
        {
            qDebug() << stadiumList.at(i);
        }

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);

        ui->numberLabel->setText(QString::number(count) + " Open Roof Stadiums");

    }
}

void MainWindow::on_show_SeatingCapacity_clicked()
{
    ui->numberLabel->setText("");
    QSqlQuery query;
    QList<QString> stadiumList;
    int seatCount = 0;
    int count = 0;
    int total=0;

    query.exec("select sum(SeatingCapacity) as capacity from stadiums");
    while(query.next())
    {
        total = query.value("capacity").toInt();

    }

    query.prepare(QString("SELECT stadiums.SeatingCapacity,stadiums.StadiumName,teams.teamName "
                          "FROM stadiums "
                          "INNER JOIN teams ON teams.StadiumID = stadiums._id "
                          "ORDER BY SeatingCapacity ASC"));

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {

        while(query.next())
        {
            QString name = query.value(1).toString();
            count = query.value(0).toInt();
            if(!stadiumList.contains(name))
            {
                stadiumList.append(name);
                seatCount += count;
            }

        }

        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);

       // ui->numberLabel->setText(QString::number(seatCount) + " Total Seats");
        ui->numberLabel->setText(QString::number(total) + " Total Seats");

    }
}

void MainWindow::on_show_Conference_clicked()
{
    ui->numberLabel->setText("");
    QSqlQuery query;

    query.prepare(QString("SELECT teams.teamName,stadiums.StadiumName,stadiums.Conference,Stadiums.Location "
                          "FROM stadiums "
                          "INNER JOIN teams ON teams.StadiumID = stadiums._id "
                          "ORDER BY Conference"));

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);
    }
}

void MainWindow::on_show_BermudaGrass_clicked()
{
    ui->numberLabel->setText("");

    QSqlQuery query;

    query.prepare(QString("SELECT teams.teamName,stadiums.StadiumName,stadiums.SurfaceType "
                          "FROM stadiums "
                          "INNER JOIN teams ON teams.StadiumID = stadiums._id "
                          "WHERE SurfaceType LIKE 'Bermuda Grass' "
                          "ORDER BY teamName"));

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);
    }

    ui->numberLabel->setText(QString::number(ui->tableView->verticalHeader()->count()) + " Teams Use Bermuda Grass");
}

void MainWindow::on_show_Selection_S_clicked()
{
    ui->numberLabel->setText("");

    QSqlQuery query;
    QString tName = ui->teamComboBox->currentText();

    query.prepare(QString("SELECT teams.teamName,"
                          "teams_souvenir.SouvenirName,teams_souvenir.Price "
                          "FROM teams_souvenir "
                          "INNER JOIN teams ON teams_souvenir.TeamId = teams._id "
                          "WHERE teamName LIKE '" + tName + "'"));

    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }
    else
    {
        QSqlQueryModel *search = new QSqlTableModel;
        search->setQuery(query);
        ui->tableView->show();
        ui->tableView->setModel(search);

        ui->numberLabel->setText(tName + " Team Souvenir's");
    }


}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAdmin_triggered()
{
    login logWindow;
    connect(&logWindow, &login::userIsAdmin, this, &MainWindow::userIsAdmin);
    logWindow.setModal(true);
    logWindow.exec();
}

void MainWindow::userIsAdmin()
{
    QMessageBox::information(this, "Login", "Username and Password is Correct");

    ui->actionLogOut->setVisible(true);
    ui->actionAdmin_Functions->setVisible(true);
    ui->actionLoad_Team->setVisible(true);
    ui->actionReset_Database->setVisible(true);
    ui->actionAdmin->setVisible(false);

}

void MainWindow::on_actionLogOut_triggered()
{
    ui->actionAdmin->setVisible(true);
    ui->actionLogOut->setVisible(false);
    ui->actionAdmin_Functions->setVisible(false);
    ui->actionLoad_Team->setVisible(false);
    ui->actionReset_Database->setVisible(false);
}

void MainWindow::on_actionAdmin_Functions_triggered()
{
    adminWindow aWindow;
    aWindow.setModal(true);
    aWindow.exec();
}

void MainWindow::on_pushButton_clicked()
{
     CustomVacation *vacWindow = new CustomVacation();
     vacWindow->show();

}

void MainWindow::on_actionReset_Database_triggered()
{
    QSqlQuery query;
    query.prepare(QString("DELETE FROM stadiums_distances WHERE _id>=117 AND _id<= 122"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    query.prepare(QString("DELETE FROM teams WHERE _id=33"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    query.prepare(QString("DELETE FROM stadiums WHERE _id=33"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(QString("SELECT TeamName FROM teams"));
    ui->teamComboBox->setModel(model);
}

void MainWindow::on_actionLoad_Team_triggered()
{
    QSqlQuery query;
    query.prepare(QString("INSERT INTO teams SELECT * FROM teams_sanDeigo"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    query.prepare(QString("INSERT INTO stadiums SELECT * FROM stadiums_sanDeigo"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    query.prepare(QString("INSERT INTO stadiums_distances SELECT * FROM stadiums_distances_sanDeigo;"));
    if (!query.exec())
    {
        QMessageBox::warning(this, "Fail", "Query did not execute");
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(QString("SELECT TeamName FROM teams"));
    ui->teamComboBox->setModel(model);
}
