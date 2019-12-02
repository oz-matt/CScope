/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionSampling;
    QAction *actionDigital_phosphor;
    QAction *actionZoom;
    QAction *actionMeasure;
    QAction *actionDocking_windows;
    QAction *actionToolbars;
    QAction *actionAbout;
    QAction *actionSettings;
    QAction *actionManualCommand;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuOscilloscope;
    QMenu *menuHelp;
    QMenu *menuExport;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSampling = new QAction(MainWindow);
        actionSampling->setObjectName(QStringLiteral("actionSampling"));
        actionSampling->setCheckable(true);
        actionDigital_phosphor = new QAction(MainWindow);
        actionDigital_phosphor->setObjectName(QStringLiteral("actionDigital_phosphor"));
        actionDigital_phosphor->setCheckable(true);
        actionZoom = new QAction(MainWindow);
        actionZoom->setObjectName(QStringLiteral("actionZoom"));
        actionZoom->setCheckable(true);
        actionMeasure = new QAction(MainWindow);
        actionMeasure->setObjectName(QStringLiteral("actionMeasure"));
        actionMeasure->setCheckable(true);
        actionDocking_windows = new QAction(MainWindow);
        actionDocking_windows->setObjectName(QStringLiteral("actionDocking_windows"));
        actionToolbars = new QAction(MainWindow);
        actionToolbars->setObjectName(QStringLiteral("actionToolbars"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionManualCommand = new QAction(MainWindow);
        actionManualCommand->setObjectName(QStringLiteral("actionManualCommand"));
        actionManualCommand->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuOscilloscope = new QMenu(menubar);
        menuOscilloscope->setObjectName(QStringLiteral("menuOscilloscope"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuExport = new QMenu(menubar);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuExport->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuOscilloscope->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuView->addAction(actionDigital_phosphor);
        menuView->addAction(actionZoom);
        menuView->addAction(actionMeasure);
        menuView->addSeparator();
        menuView->addAction(actionManualCommand);
        menuOscilloscope->addAction(actionSettings);
        menuOscilloscope->addSeparator();
        menuOscilloscope->addAction(actionSampling);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionSampling);
        toolBar->addSeparator();
        toolBar->addAction(actionDigital_phosphor);
        toolBar->addAction(actionZoom);
        toolBar->addAction(actionMeasure);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open layout", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save layout", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as ...", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionSampling->setText(QApplication::translate("MainWindow", "Sampling", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSampling->setShortcut(QApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_NO_SHORTCUT
        actionDigital_phosphor->setText(QApplication::translate("MainWindow", "Digital phosphor", nullptr));
        actionZoom->setText(QApplication::translate("MainWindow", "Zoom", nullptr));
        actionMeasure->setText(QApplication::translate("MainWindow", "Measure", nullptr));
        actionDocking_windows->setText(QApplication::translate("MainWindow", "Docking windows", nullptr));
        actionToolbars->setText(QApplication::translate("MainWindow", "Toolbars", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        actionManualCommand->setText(QApplication::translate("MainWindow", "Manual command", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "&View", nullptr));
        menuOscilloscope->setTitle(QApplication::translate("MainWindow", "&Oscilloscope", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
