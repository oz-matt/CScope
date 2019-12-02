/********************************************************************************
** Form generated from reading UI file 'newdevicemodelfromexisting.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDEVICEMODELFROMEXISTING_H
#define UI_NEWDEVICEMODELFROMEXISTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDeviceModelFromExisting
{
public:
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QComboBox *cmbUSBdevices;
    QPushButton *btnRefresh;
    QCheckBox *checkBox;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupTemplate;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *cmbTemplateModel;
    QLineEdit *modelname;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupFirmware;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *lineFirmware;
    QLineEdit *lineLoader;
    QPushButton *btnSelectLoader;
    QPushButton *btnSelectFirmware;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewDeviceModelFromExisting)
    {
        if (NewDeviceModelFromExisting->objectName().isEmpty())
            NewDeviceModelFromExisting->setObjectName(QStringLiteral("NewDeviceModelFromExisting"));
        NewDeviceModelFromExisting->resize(442, 437);
        verticalLayout_6 = new QVBoxLayout(NewDeviceModelFromExisting);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox = new QGroupBox(NewDeviceModelFromExisting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        cmbUSBdevices = new QComboBox(groupBox);
        cmbUSBdevices->setObjectName(QStringLiteral("cmbUSBdevices"));

        verticalLayout->addWidget(cmbUSBdevices);

        btnRefresh = new QPushButton(groupBox);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));

        verticalLayout->addWidget(btnRefresh);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);


        verticalLayout_6->addWidget(groupBox);

        stackedWidget = new QStackedWidget(NewDeviceModelFromExisting);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupTemplate = new QGroupBox(page);
        groupTemplate->setObjectName(QStringLiteral("groupTemplate"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupTemplate->sizePolicy().hasHeightForWidth());
        groupTemplate->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupTemplate);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(groupTemplate);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setWordWrap(true);

        verticalLayout_2->addWidget(label_2);

        cmbTemplateModel = new QComboBox(groupTemplate);
        cmbTemplateModel->setObjectName(QStringLiteral("cmbTemplateModel"));

        verticalLayout_2->addWidget(cmbTemplateModel);

        modelname = new QLineEdit(groupTemplate);
        modelname->setObjectName(QStringLiteral("modelname"));

        verticalLayout_2->addWidget(modelname);


        verticalLayout_4->addWidget(groupTemplate);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupFirmware = new QGroupBox(page_2);
        groupFirmware->setObjectName(QStringLiteral("groupFirmware"));
        verticalLayout_3 = new QVBoxLayout(groupFirmware);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(groupFirmware);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setWordWrap(true);

        verticalLayout_3->addWidget(label_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_5 = new QLabel(groupFirmware);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(groupFirmware);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineFirmware = new QLineEdit(groupFirmware);
        lineFirmware->setObjectName(QStringLiteral("lineFirmware"));

        gridLayout->addWidget(lineFirmware, 1, 1, 1, 1);

        lineLoader = new QLineEdit(groupFirmware);
        lineLoader->setObjectName(QStringLiteral("lineLoader"));

        gridLayout->addWidget(lineLoader, 0, 1, 1, 1);

        btnSelectLoader = new QPushButton(groupFirmware);
        btnSelectLoader->setObjectName(QStringLiteral("btnSelectLoader"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSelectLoader->sizePolicy().hasHeightForWidth());
        btnSelectLoader->setSizePolicy(sizePolicy1);
        btnSelectLoader->setFlat(false);

        gridLayout->addWidget(btnSelectLoader, 0, 2, 1, 1);

        btnSelectFirmware = new QPushButton(groupFirmware);
        btnSelectFirmware->setObjectName(QStringLiteral("btnSelectFirmware"));
        sizePolicy1.setHeightForWidth(btnSelectFirmware->sizePolicy().hasHeightForWidth());
        btnSelectFirmware->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(btnSelectFirmware, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_5->addWidget(groupFirmware);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setWordWrap(true);

        verticalLayout_7->addWidget(label_6);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        verticalLayout_8 = new QVBoxLayout(page_4);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_7 = new QLabel(page_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setWordWrap(true);

        verticalLayout_8->addWidget(label_7);

        stackedWidget->addWidget(page_4);

        verticalLayout_6->addWidget(stackedWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(NewDeviceModelFromExisting);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_6->addWidget(buttonBox);


        retranslateUi(NewDeviceModelFromExisting);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewDeviceModelFromExisting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewDeviceModelFromExisting, SLOT(reject()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NewDeviceModelFromExisting);
    } // setupUi

    void retranslateUi(QDialog *NewDeviceModelFromExisting)
    {
        NewDeviceModelFromExisting->setWindowTitle(QApplication::translate("NewDeviceModelFromExisting", "New device from template", nullptr));
        groupBox->setTitle(QApplication::translate("NewDeviceModelFromExisting", "Select USB device", nullptr));
        btnRefresh->setText(QApplication::translate("NewDeviceModelFromExisting", "Refresh", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("NewDeviceModelFromExisting", "This is usually indicated by a light (red flashing)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("NewDeviceModelFromExisting", "This is usually indicated by a light (red flashing)", nullptr));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("NewDeviceModelFromExisting", "Firmware is uploaded already*", nullptr));
        groupTemplate->setTitle(QApplication::translate("NewDeviceModelFromExisting", "Template selection", nullptr));
        label_2->setText(QApplication::translate("NewDeviceModelFromExisting", "Select the existing model that should be used as template for your device. You may need to restart OpenHantek and try different models until it works for you.", nullptr));
        modelname->setPlaceholderText(QApplication::translate("NewDeviceModelFromExisting", "Please enter a model name", nullptr));
        groupFirmware->setTitle(QApplication::translate("NewDeviceModelFromExisting", "Firmware files", nullptr));
        label_3->setText(QApplication::translate("NewDeviceModelFromExisting", "Please select the firmware files in hex format, extracted from the windows driver for example. You need to open this dialog again after the firmware has been uploaded.", nullptr));
        label_5->setText(QApplication::translate("NewDeviceModelFromExisting", "Firmware", nullptr));
        label_4->setText(QApplication::translate("NewDeviceModelFromExisting", "Loader", nullptr));
        btnSelectLoader->setText(QApplication::translate("NewDeviceModelFromExisting", "...", nullptr));
        btnSelectFirmware->setText(QApplication::translate("NewDeviceModelFromExisting", "...", nullptr));
        label_6->setText(QApplication::translate("NewDeviceModelFromExisting", "No USB devices found or your operating system prohibited enumerating devices.", nullptr));
        label_7->setText(QApplication::translate("NewDeviceModelFromExisting", "No access granted for the selected USB device. Your operating system may prohibit access. On Windows you might need to install a generic driver first. On Linux you need to install an udev rule to grant access to your currently logged in user.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewDeviceModelFromExisting: public Ui_NewDeviceModelFromExisting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDEVICEMODELFROMEXISTING_H
