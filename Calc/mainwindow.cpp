#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->edit_ans->setText(QString::number(calcValue));
    connect(ui->button_num0, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num1, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num2, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num3, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num4, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num5, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num6, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num7, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num8, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_num9, SIGNAL(released()), this, SLOT(NumPressed()));
    connect(ui->button_mul, SIGNAL(released()), this, SLOT(MathPressed()));
    connect(ui->button_div, SIGNAL(released()), this, SLOT(MathPressed()));
    connect(ui->button_plus, SIGNAL(released()), this, SLOT(MathPressed()));
    connect(ui->button_minus, SIGNAL(released()), this, SLOT(MathPressed()));
    connect(ui->button_ans, SIGNAL(released()), this, SLOT(ResultPressed()));
    connect(ui->button_clear, SIGNAL(released()), this, SLOT(ClearPressed()));
    connect(ui->button_dot, SIGNAL(released()), this, SLOT(DotPressed()));
    connect(ui->button_plusminus, SIGNAL(released()), this,
                                  SLOT(ChangeSignPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton*)sender();
    QString buttonValue = button -> text();
    QString editValue = ui->edit_ans->text();

    if((editValue.toDouble() == 0) || (editValue.toDouble() == 0.0)){
        ui->edit_ans->setText(buttonValue);
    } else {
        QString newValue = editValue + buttonValue;
        double newDblValue = newValue.toDouble();
        ui->edit_ans->setText(QString::number(newDblValue, 'g', 16));
    }
}

void MainWindow::MathPressed(){
    divide = false;
    multip = false;
    subtrc = false;
    additn = false;

    QString editValue = ui->edit_ans->text();
    calcValue = editValue.toDouble();
    QPushButton *button = (QPushButton*)sender();
    QString buttonValue = button -> text();

    if (buttonValue == "÷"){
        divide = true;
        ui->edit_ans->setText("÷");
    } else if (buttonValue == "×"){
        multip = true;
        ui->edit_ans->setText("×");
    } else if (buttonValue == "–"){
        subtrc = true;
        ui->edit_ans->setText("–");
    } else if (buttonValue == "+"){
        additn = true;
        ui->edit_ans->setText("+");
    }

    //ui->edit_ans->setText("");
}

void MainWindow::ResultPressed(){
    double result = 0.0f;

    QString editValue = ui->edit_ans->text();
    double DblValue = editValue.toDouble();

    if (divide) result = calcValue / DblValue;
    if (multip) result = calcValue * DblValue;
    if (subtrc) result = calcValue - DblValue;
    if (additn) result = calcValue + DblValue;

    ui->edit_ans->setText(QString::number(result));
}

void MainWindow::ChangeSignPressed(){
    QString editValue = ui->edit_ans->text();
    double newDblValue = editValue.toDouble();
    newDblValue = newDblValue * -1;
    ui->edit_ans->setText(QString::number(newDblValue, 'g', 16));
}

void MainWindow::ClearPressed(){
    ui->edit_ans->setText("0");
    calcValue = 0.0f;
}

void MainWindow::DotPressed(){
    QString editValue = ui->edit_ans->text();
    editValue += ".";
    ui->edit_ans->setText(editValue);
}

















