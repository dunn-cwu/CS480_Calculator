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
// File: main.cpp
// Desc: Program entry point
// ---------------------------------

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Start QT Application
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

// ===================================================
// End Of File
// ===================================================
