#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->InputedLabel->setText("0");
    //Operations
    connect(ui->ACBtn,SIGNAL(clicked()),this,SLOT(cleanInputLabel()));
    connect(ui->SignBtn, SIGNAL(clicked()),this, SLOT(asign()));

    connect(ui->PlusBtn,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->MinusBtn,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->DevidedBtn,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->MultupliedBtn,SIGNAL(clicked()), this, SLOT(operation()));

    connect(ui->EqualBtn,SIGNAL(clicked()), this, SLOT(equal()));

    connect(ui->ProcentBtn, SIGNAL(clicked()),this,SLOT(percent()));

    connect(ui->PointBtn,SIGNAL(clicked()),this,SLOT(addPoint()));

    //DigitalsBTN
    connect(ui->ZeroBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->OneBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->TwoBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->ThreeBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->FourBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->FiveBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->SixBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->SevenBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->EightBtn,SIGNAL(clicked()),this,SLOT(addDigital()));
    connect(ui->NineBtn,SIGNAL(clicked()),this,SLOT(addDigital()));


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

void MainWindow::updateInputLabel()
{
    //ui->InputedLabel->setText(QString::number(newInputLabelText,'g',9));
    //ui->InputedLabel->setText();
}



