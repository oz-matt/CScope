/********************************************************************************
** Form generated from reading UI file 'selectsupporteddevice.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSUPPORTEDDEVICE_H
#define UI_SELECTSUPPORTEDDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectSupportedDevice
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *labelSupportedDevices;
    QComboBox *cmbDevices;
    QLabel *labelReadyState;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *btnAddDevice;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SelectSupportedDevice)
    {
        if (SelectSupportedDevice->objectName().isEmpty())
            SelectSupportedDevice->setObjectName(QStringLiteral("SelectSupportedDevice"));
        SelectSupportedDevice->resize(550, 400);
        verticalLayout = new QVBoxLayout(SelectSupportedDevice);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(SelectSupportedDevice);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        labelSupportedDevices = new QLabel(tab);
        labelSupportedDevices->setObjectName(QStringLiteral("labelSupportedDevices"));
        labelSupportedDevices->setWordWrap(true);

        gridLayout->addWidget(labelSupportedDevices, 0, 1, 1, 1);

        cmbDevices = new QComboBox(tab);
        cmbDevices->setObjectName(QStringLiteral("cmbDevices"));

        gridLayout->addWidget(cmbDevices, 1, 1, 1, 1);

        labelReadyState = new QLabel(tab);
        labelReadyState->setObjectName(QStringLiteral("labelReadyState"));
        labelReadyState->setWordWrap(true);

        gridLayout->addWidget(labelReadyState, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setWordWrap(true);
        label_2->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(label_2);

        btnAddDevice = new QPushButton(tab_2);
        btnAddDevice->setObjectName(QStringLiteral("btnAddDevice"));

        verticalLayout_2->addWidget(btnAddDevice);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(SelectSupportedDevice);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SelectSupportedDevice);
        QObject::connect(buttonBox, SIGNAL(accepted()), SelectSupportedDevice, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectSupportedDevice, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SelectSupportedDevice);
    } // setupUi

    void retranslateUi(QDialog *SelectSupportedDevice)
    {
        SelectSupportedDevice->setWindowTitle(QApplication::translate("SelectSupportedDevice", "Select device", nullptr));
        label->setText(QApplication::translate("SelectSupportedDevice", "Devices:", nullptr));
        labelSupportedDevices->setText(QApplication::translate("SelectSupportedDevice", "...", nullptr));
        labelReadyState->setText(QApplication::translate("SelectSupportedDevice", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SelectSupportedDevice", "Supported device", nullptr));
        label_2->setText(QApplication::translate("SelectSupportedDevice", "<html><head/><body><p>Your device might not directly be supported by OpenHantek. But it might be compatible to one of the existing devices. Help us to identify those devices and report back on our <a href=\"https://github.com/OpenHantek/openhantek/issues\"><span style=\" text-decoration: underline; color:#0000ff;\">issue tracker</span></a>.</p></body></html>", nullptr));
        btnAddDevice->setText(QApplication::translate("SelectSupportedDevice", "Add new device from template", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SelectSupportedDevice", "Try unsupported", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectSupportedDevice: public Ui_SelectSupportedDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSUPPORTEDDEVICE_H
