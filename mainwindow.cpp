#include <QShortcut>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "postfixexpression.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(315, 390));

    curExp = "";

    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Backspace), this);

    // connect its 'activated' signal to your function 'foo'
    QObject::connect(shortcut, &QShortcut::activated, this, &MainWindow::on_backspace_pressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurrentExp()
{
    if (curExp.isEmpty())
    {
        ui->exprTextBox->setText("0");
        ui->ansTextBox->setText("Ans");
    }
    else
    {
         ui->exprTextBox->setText(curExp);
    }
}

void MainWindow::on_backspace_pressed()
{
    if (curExp.isEmpty()) return;

    curExp.truncate(curExp.length() - 1);
    updateCurrentExp();
}

void MainWindow::on_equalsBtn_clicked()
{
    PostfixExpression pfExp;
    bool success = pfExp.fromInfix(curExp);

    if (!success)
    {
        ui->ansTextBox->setText("ERR: Invalid Expression");
        return;
    }

    double result = 0.0;
    success = pfExp.solve(result);

    if (!success)
    {
        ui->ansTextBox->setText("ERR: Invalid Expression");
        return;
    }

    QString ans = QString::number(result);

    ui->ansTextBox->setText(ans);
}

void MainWindow::on_clearBtn_clicked()
{
    curExp = "";
    updateCurrentExp();
}

void MainWindow::on_plusBtn_clicked()
{
    curExp.append("+");
    updateCurrentExp();
}

void MainWindow::on_subBtn_clicked()
{
    curExp.append("-");
    updateCurrentExp();
}

void MainWindow::on_multBtn_clicked()
{
    curExp.append("*");
    updateCurrentExp();
}

void MainWindow::on_divBtn_clicked()
{
    curExp.append("/");
    updateCurrentExp();
}

void MainWindow::on_exponentBtn_clicked()
{
    curExp.append("^");
    updateCurrentExp();
}

void MainWindow::on_periodBtn_clicked()
{
    curExp.append(".");
    updateCurrentExp();
}

void MainWindow::on_leftParenthBtn_clicked()
{
    curExp.append("(");
    updateCurrentExp();
}

void MainWindow::on_rightParenthBtn_clicked()
{
    curExp.append(")");
    updateCurrentExp();
}

void MainWindow::on_zeroBtn_clicked()
{
    curExp.append("0");
    updateCurrentExp();
}

void MainWindow::on_oneBtn_clicked() {
    curExp.append("1");
    updateCurrentExp();
}

void MainWindow::on_twoBtn_clicked() {
    curExp.append("2");
    updateCurrentExp();
}

void MainWindow::on_threeBtn_clicked() {
    curExp.append("3");
    updateCurrentExp();
}

void MainWindow::on_fourBtn_clicked() {
    curExp.append("4");
    updateCurrentExp();
}

void MainWindow::on_fiveBtn_clicked() {
    curExp.append("5");
    updateCurrentExp();
}

void MainWindow::on_sixBtn_clicked() {
    curExp.append("6");
    updateCurrentExp();
}

void MainWindow::on_sevenBtn_clicked() {
    curExp.append("7");
    updateCurrentExp();
}

void MainWindow::on_eightBtn_clicked() {
    curExp.append("8");
    updateCurrentExp();
}

void MainWindow::on_nineBtn_clicked() {
    curExp.append("9");
    updateCurrentExp();
}
