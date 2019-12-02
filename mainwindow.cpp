#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"

#include "HorizontalDock.h"
#include "SpectrumDock.h"
#include "TriggerDock.h"
#include "VoltageDock.h"
#include "dockwindows.h"

#include "configdialog.h"
#include "dockwindows.h"
#include "dsomodel.h"
#include "dsowidget.h"
#include "exporting/exporterinterface.h"
#include "exporting/exporterregistry.h"
#include "hantekdsocontrol.h"
#include "usb/usbdevice.h"
#include "viewconstants.h"
#include "settings.h"

MainWindow::MainWindow(HantekDsoControl *dsoControl, DsoSettings *settings, ExporterRegistry *exporterRegistry,
                       QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mSettings(settings), exporterRegistry(exporterRegistry)

{
    ui->setupUi(this);
    DsoSettingsScope *scope = &(mSettings->scope);
        const Dso::ControlSpecification *spec = dsoControl->getDevice()->getModel()->spec();

    dsoWidget = new DsoWidget(&mSettings->scope, &mSettings->view, spec);
        setCentralWidget(dsoWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

