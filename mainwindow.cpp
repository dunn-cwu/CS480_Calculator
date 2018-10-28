// ---------------------------------
// Course: CS 480 Advanced Software Engineering
// Section: 8:00 AM
// Instructor: Dr. Szilárd VAJDA
// Quarter: Fall 2018
// Date: 10/27/2018
//
// Assignment: Lab 3
// Student: Andrew Dunn
//
// File: mainwindow.cpp
// Desc: Implementation of MainWindow class.
// ---------------------------------

#include <QShortcut>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "postfixexpression.h"

// Main constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Set up main window GUI
    ui->setupUi(this);

    // Make window non-resizable
    this->setFixedSize(QSize(315, 390));

    // Initialize current expression as empty string
    curExp = "";

    // Set up and link a shortcut key for the backspace button that deletes
    // one character from the current expression entered into the calculator
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Backspace), this);
    QObject::connect(shortcut, &QShortcut::activated, this, &MainWindow::on_backspace_pressed);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Updates the expression and answer GUI text boxes
// to display the current expression
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

// Called when the backspace hotkey is pressed.
// Deletes one char from the end of the current expression.
void MainWindow::on_backspace_pressed()
{
    if (curExp.isEmpty()) return;

    curExp.truncate(curExp.length() - 1);
    updateCurrentExp();
}

// Called when the '=' button is clicked on the calculator
void MainWindow::on_equalsBtn_clicked()
{
    // Create an instance of the PostfixExpression class
    // which is used to solve the expression entered by the user.
    PostfixExpression pfExp;

    // User input expression will be in infix form, so we
    // must first convert it to postfix to simplify the
    // solving process.
    bool success = pfExp.fromInfix(curExp);

    // There was an error when converting the expression
    if (!success)
    {
        ui->ansTextBox->setText("ERR: Invalid Expression");
        return;
    }

    // Solve the now converted postfix expression.
    double result = 0.0;
    success = pfExp.solve(result);

    // There was an error when attempting to solve the expression.
    if (!success)
    {
        ui->ansTextBox->setText("ERR: Invalid Expression");
        return;
    }

    // Convert the result to a string and then plug it into
    // the answer textbox
    QString ans = QString::number(result);
    ui->ansTextBox->setText(ans);
}

// Called when the 'C' button is clicked on the calculator.
// Clears the current input expression.
void MainWindow::on_clearBtn_clicked()
{
    curExp = "";
    updateCurrentExp();
}

// Called when the '+' button is clicked on the calculator.
void MainWindow::on_plusBtn_clicked()
{
    curExp.append("+");
    updateCurrentExp();
}

// Called when the '-' button is clicked on the calculator.
void MainWindow::on_subBtn_clicked()
{
    curExp.append("-");
    updateCurrentExp();
}

// Called when the '*' button is clicked on the calculator.
void MainWindow::on_multBtn_clicked()
{
    curExp.append("*");
    updateCurrentExp();
}

// Called when the '÷' button is clicked on the calculator.
void MainWindow::on_divBtn_clicked()
{
    curExp.append("/");
    updateCurrentExp();
}

// Called when the '^' button is clicked on the calculator.
void MainWindow::on_exponentBtn_clicked()
{
    curExp.append("^");
    updateCurrentExp();
}

// Called when the '.' button is clicked on the calculator.
void MainWindow::on_periodBtn_clicked()
{
    curExp.append(".");
    updateCurrentExp();
}

// Called when the '(' button is clicked on the calculator.
void MainWindow::on_leftParenthBtn_clicked()
{
    curExp.append("(");
    updateCurrentExp();
}

// Called when the ')' button is clicked on the calculator.
void MainWindow::on_rightParenthBtn_clicked()
{
    curExp.append(")");
    updateCurrentExp();
}

// Called when the '0' button is clicked on the calculator.
void MainWindow::on_zeroBtn_clicked()
{
    curExp.append("0");
    updateCurrentExp();
}

// Called when the '1' button is clicked on the calculator.
void MainWindow::on_oneBtn_clicked() {
    curExp.append("1");
    updateCurrentExp();
}

// Called when the '2' button is clicked on the calculator.
void MainWindow::on_twoBtn_clicked() {
    curExp.append("2");
    updateCurrentExp();
}

// Called when the '3' button is clicked on the calculator.
void MainWindow::on_threeBtn_clicked() {
    curExp.append("3");
    updateCurrentExp();
}

// Called when the '4' button is clicked on the calculator.
void MainWindow::on_fourBtn_clicked() {
    curExp.append("4");
    updateCurrentExp();
}

// Called when the '5' button is clicked on the calculator.
void MainWindow::on_fiveBtn_clicked() {
    curExp.append("5");
    updateCurrentExp();
}

// Called when the '6' button is clicked on the calculator.
void MainWindow::on_sixBtn_clicked() {
    curExp.append("6");
    updateCurrentExp();
}

// Called when the '7' button is clicked on the calculator.
void MainWindow::on_sevenBtn_clicked() {
    curExp.append("7");
    updateCurrentExp();
}

// Called when the '8' button is clicked on the calculator.
void MainWindow::on_eightBtn_clicked() {
    curExp.append("8");
    updateCurrentExp();
}

// Called when the '9' button is clicked on the calculator.
void MainWindow::on_nineBtn_clicked() {
    curExp.append("9");
    updateCurrentExp();
}

// ===================================================
// End Of File
// ===================================================
