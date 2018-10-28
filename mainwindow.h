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
// File: mainwindow.h
// Desc: Header file and definition for MainWindow class.
// ---------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_backspace_pressed();

    void on_oneBtn_clicked();

    void on_clearBtn_clicked();

    void on_zeroBtn_clicked();

    void on_twoBtn_clicked();

    void on_threeBtn_clicked();

    void on_fourBtn_clicked();

    void on_fiveBtn_clicked();

    void on_sixBtn_clicked();

    void on_sevenBtn_clicked();

    void on_eightBtn_clicked();

    void on_nineBtn_clicked();

    void on_equalsBtn_clicked();

    void on_plusBtn_clicked();

    void on_subBtn_clicked();

    void on_multBtn_clicked();

    void on_divBtn_clicked();

    void on_exponentBtn_clicked();

    void on_periodBtn_clicked();

    void on_leftParenthBtn_clicked();

    void on_rightParenthBtn_clicked();

private:
    Ui::MainWindow *ui;
    QString curExp;

    void updateCurrentExp();
};

#endif // MAINWINDOW_H

// ===================================================
// End Of File
// ===================================================
