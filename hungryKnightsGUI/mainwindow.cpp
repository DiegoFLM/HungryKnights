#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "/home/diegoflm/Documents/VU/IngSistemas/MateriasYTemas/Semestre6/AI/project2/p2Code/node.h"
#include "/home/diegoflm/Documents/VU/IngSistemas/MateriasYTemas/Semestre6/AI/project2/p2Code/handler.h"

QLabel* labelsList[8][8];


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labelsList[0][0] = ui->label;
    labelsList[0][1] = ui->label_2;
    labelsList[0][2] = ui->label_3;
    labelsList[0][3] = ui->label_4;
    labelsList[0][4] = ui->label_5;
    labelsList[0][5] = ui->label_6;
    labelsList[0][6] = ui->label_7;
    labelsList[0][7] = ui->label_8;

    labelsList[1][0] = ui->label_9;
    labelsList[1][1] = ui->label_10;
    labelsList[1][2] = ui->label_11;
    labelsList[1][3] = ui->label_12;
    labelsList[1][4] = ui->label_13;
    labelsList[1][5] = ui->label_14;
    labelsList[1][6] = ui->label_15;
    labelsList[1][7] = ui->label_16;

    labelsList[2][0] = ui->label_17;
    labelsList[2][1] = ui->label_18;
    labelsList[2][2] = ui->label_19;
    labelsList[2][3] = ui->label_20;
    labelsList[2][4] = ui->label_21;
    labelsList[2][5] = ui->label_22;
    labelsList[2][6] = ui->label_23;
    labelsList[2][7] = ui->label_24;

    labelsList[3][0] = ui->label_25;
    labelsList[3][1] = ui->label_26;
    labelsList[3][2] = ui->label_27;
    labelsList[3][3] = ui->label_28;
    labelsList[3][4] = ui->label_29;
    labelsList[3][5] = ui->label_30;
    labelsList[3][6] = ui->label_31;
    labelsList[3][7] = ui->label_32;

    labelsList[4][0] = ui->label_33;
    labelsList[4][1] = ui->label_34;
    labelsList[4][2] = ui->label_35;
    labelsList[4][3] = ui->label_36;
    labelsList[4][4] = ui->label_37;
    labelsList[4][5] = ui->label_38;
    labelsList[4][6] = ui->label_39;
    labelsList[4][7] = ui->label_40;

    labelsList[5][0] = ui->label_41;
    labelsList[5][1] = ui->label_42;
    labelsList[5][2] = ui->label_43;
    labelsList[5][3] = ui->label_44;
    labelsList[5][4] = ui->label_45;
    labelsList[5][5] = ui->label_46;
    labelsList[5][6] = ui->label_47;
    labelsList[5][7] = ui->label_48;

    labelsList[6][0] = ui->label_49;
    labelsList[6][1] = ui->label_50;
    labelsList[6][2] = ui->label_51;
    labelsList[6][3] = ui->label_52;
    labelsList[6][4] = ui->label_53;
    labelsList[6][5] = ui->label_54;
    labelsList[6][6] = ui->label_55;
    labelsList[6][7] = ui->label_56;

    labelsList[7][0] = ui->label_57;
    labelsList[7][1] = ui->label_58;
    labelsList[7][2] = ui->label_59;
    labelsList[7][3] = ui->label_60;
    labelsList[7][4] = ui->label_61;
    labelsList[7][5] = ui->label_62;
    labelsList[7][6] = ui->label_63;
    labelsList[7][7] = ui->label_64;

    for (int r=0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            if ((r+ c)%2 == 0){
                labelsList[r][c]->setPixmap(QPixmap("/home/diegoflm/Documents/VU/IngSistemas/MateriasYTemas/Semestre6/AI/project2/p2Code/hungryKnightsGUI/ws.png"));
            }else{
                labelsList[r][c]->setPixmap(QPixmap("/home/diegoflm/Documents/VU/IngSistemas/MateriasYTemas/Semestre6/AI/project2/p2Code/hungryKnightsGUI/bs.png"));
            }

        }
    }
    labelsList[4][3]->setPixmap(QPixmap("/home/diegoflm/Documents/VU/IngSistemas/MateriasYTemas/Semestre6/AI/project2/p2Code/hungryKnightsGUI/wkbs.png"));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label_11->setPixmap(QPixmap("/home/diegoflm/Documents/VU/IngSistemas/MateriasYTemas/Semestre6/AI/project2/p2Code/hungryKnightsGUI/wkws.png"));
}

