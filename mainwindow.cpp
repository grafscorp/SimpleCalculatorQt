#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->InputedLabel->setText("0");
    //Operations
    connect(ui->grACBtn,SIGNAL(clicked()),this,SLOT(cleanInputLabel()));
    connect(ui->grSignBtn, SIGNAL(clicked()),this, SLOT(asign()));

    connect(ui->orPlusBtn,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->orMinusBtn,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->orDevidedBtn,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->orMultupliedBtn,SIGNAL(clicked()), this, SLOT(operation()));

    connect(ui->orEqualBtn,SIGNAL(clicked()), this, SLOT(equal()));

    connect(ui->grProcentBtn, SIGNAL(clicked()),this,SLOT(percent()));

    connect(ui->drPointBtn,SIGNAL(clicked()),this,SLOT(addPoint()));

    //DigitalsBTN
    connect(ui->drZeroBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drOneBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drTwoBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drThreeBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drFourBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drFiveBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drSixBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drSevenBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drEightBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->drNineBtn,SIGNAL(clicked()),this,SLOT(addDigital()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDigital()
{
    QPushButton* senderBtn = (QPushButton*) sender();
    if (ui->InputedLabel->text()=="0" || newChar == true)
        ui->InputedLabel->setText(senderBtn->text());
    else{
        QString newLabelText = QString(ui->InputedLabel->text() + senderBtn->text());

        newLabelText = QString::number(newLabelText.toDouble(),'g',9);
        ui->InputedLabel->setText(newLabelText);
    }
    newChar = false;
}

void MainWindow::cleanInputLabel()
{
    ui->InputedLabel->setText("0");
    firstNum = 0;
}

void MainWindow::asign()
{
    double newAsignInput = ui->InputedLabel->text().toDouble();
    ui->InputedLabel->setText(QString::number(newAsignInput*-1,'g',9));
}

void MainWindow::operation()
{
    QPushButton* senderBTN = (QPushButton*) sender();
    operationChar = senderBTN->text().toStdString()[0];
    if (firstNum != 0 && !(ui->InputedLabel->text().isEmpty()))
    {
        equal();
    }
    firstNum = ui->InputedLabel->text().toDouble();
    newChar = true;

}

void MainWindow::equal( )
{
    if (firstNum == 0) return;
    double result;
    switch (operationChar) {
    case '+':
        result = firstNum + (ui->InputedLabel->text().toDouble() );
        break;
    case '-':
        result = firstNum - ui->InputedLabel->text().toDouble();
        break;
    case 'x':
        result = firstNum * ui->InputedLabel->text().toDouble();
        break;
    case '/':
        result = firstNum / ui->InputedLabel->text().toDouble();
        break;
    // case '%':
    //     result = firstNum % ui->InputedLabel->text().toDouble();
    default:
        result = firstNum;
        break;
    }
    ui->InputedLabel->setText(QString::number(result,'g',9));
    firstNum = 0;
    newChar = true;


}

void MainWindow::percent()
{
    if(firstNum ==0 && (ui->InputedLabel->text().isEmpty() ||ui->InputedLabel->text()=="0" )) return;
    double percentValue = firstNum/100 * ui->InputedLabel->text().toDouble();
    ui->InputedLabel->setText(QString::number(percentValue,'g',9));
    equal();
}

void MainWindow::addPoint()
{
    for(int i = 0; i<ui->InputedLabel->text().length();i++)
    {
        if (ui->InputedLabel->text()[i] == '.') return;
    }
    ui->InputedLabel->setText(ui->InputedLabel->text() + ".");
}






