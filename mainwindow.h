#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include "post/ppresult.h"
#include <QMainWindow>
#include <memory>

class SpectrumGenerator;
class HantekDsoControl;
class DsoSettings;
class ExporterRegistry;
class DsoWidget;
class HorizontalDock;
class TriggerDock;
class SpectrumDock;
class VoltageDock;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(HantekDsoControl *dsoControl, DsoSettings *mSettings, ExporterRegistry *exporterRegistry,
                        QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;// Central widgets
    DsoWidget *dsoWidget;

    // Settings used for the whole program
    DsoSettings *mSettings;
    ExporterRegistry *exporterRegistry;
};
#endif // MAINWINDOW_H
