# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = CScope

LIBS += -lfftw3 -lfftw3f -lm

QMAKE_LFLAGS += -lusb-1.0

HEADERS = \
   $$PWD/configdialog/configdialog.h \
   $$PWD/configdialog/DsoConfigAnalysisPage.h \
   $$PWD/configdialog/DsoConfigColorsPage.h \
   $$PWD/configdialog/DsoConfigFilePage.h \
   $$PWD/configdialog/DsoConfigScopePage.h \
   $$PWD/docks/dockwindows.h \
   $$PWD/docks/HorizontalDock.h \
   $$PWD/docks/SpectrumDock.h \
   $$PWD/docks/TriggerDock.h \
   $$PWD/docks/VoltageDock.h \
   $$PWD/exporting/exportcsv.h \
   $$PWD/exporting/exporterinterface.h \
   $$PWD/exporting/exporterprocessor.h \
   $$PWD/exporting/exporterregistry.h \
   $$PWD/exporting/exportimage.h \
   $$PWD/exporting/exportprint.h \
   $$PWD/exporting/exportsettings.h \
   $$PWD/exporting/legacyexportdrawer.h \
   $$PWD/hantekdso/models/modelDSO6022.h \
   $$PWD/hantekdso/controlsettings.h \
   $$PWD/hantekdso/controlspecification.h \
   $$PWD/hantekdso/dsomodel.h \
   $$PWD/hantekdso/dsosamples.h \
   $$PWD/hantekdso/enums.h \
   $$PWD/hantekdso/errorcodes.h \
   $$PWD/hantekdso/hantekdsocontrol.h \
   $$PWD/hantekdso/modelregistry.h \
   $$PWD/hantekdso/states.h \
   $$PWD/hantekprotocol/controlcode.h \
   $$PWD/hantekprotocol/controlcommand.h \
   $$PWD/hantekprotocol/controlStructs.h \
   $$PWD/hantekprotocol/controlvalue.h \
   $$PWD/hantekprotocol/definitions.h \
   $$PWD/hantekprotocol/types.h \
   $$PWD/iconfont/QtAwesome.h \
   $$PWD/iconfont/QtAwesomeAnim.h \
   $$PWD/post/graphgenerator.h \
   $$PWD/post/mathchannelgenerator.h \
   $$PWD/post/postprocessing.h \
   $$PWD/post/postprocessingsettings.h \
   $$PWD/post/ppresult.h \
   $$PWD/post/processor.h \
   $$PWD/post/spectrumgenerator.h \
   $$PWD/selectdevice/devicelistentry.h \
   $$PWD/selectdevice/deviceslistmodel.h \
   $$PWD/selectdevice/newdevicemodelfromexisting.h \
   $$PWD/selectdevice/rawdevicelistentry.h \
   $$PWD/selectdevice/rawdeviceslistmodel.h \
   $$PWD/selectdevice/selectsupporteddevice.h \
   $$PWD/usb/ezusb.h \
   $$PWD/usb/finddevices.h \
   $$PWD/usb/uploadFirmware.h \
   $$PWD/usb/usbdevice.h \
   $$PWD/usb/usbdevicedefinitions.h \
   $$PWD/utils/enumclass.h \
   $$PWD/utils/printutils.h \
   $$PWD/widgets/colorbox.h \
   $$PWD/widgets/datagrid.h \
   $$PWD/widgets/levelslider.h \
   $$PWD/widgets/sispinbox.h \
   $$PWD/dsowidget.h \
   $$PWD/glscope.h \
   $$PWD/glscopegraph.h \
   $$PWD/mainwindow.h \
   $$PWD/OH_VERSION.h \
   $$PWD/scopesettings.h \
   $$PWD/settings.h \
   $$PWD/viewconstants.h \
   $$PWD/viewsettings.h \
   $$PWD/ui_mainwindow.h\
   $$PWD/ui_newdevicemodelfromexisting.h \
   $$PWD/ui_selectsupporteddevice.h

SOURCES = \
   $$PWD/configdialog/configdialog.cpp \
   $$PWD/configdialog/DsoConfigAnalysisPage.cpp \
   $$PWD/configdialog/DsoConfigColorsPage.cpp \
   $$PWD/configdialog/DsoConfigFilePage.cpp \
   $$PWD/configdialog/DsoConfigScopePage.cpp \
   $$PWD/docks/dockwindows.cpp \
   $$PWD/docks/HorizontalDock.cpp \
   $$PWD/docks/SpectrumDock.cpp \
   $$PWD/docks/TriggerDock.cpp \
   $$PWD/docks/VoltageDock.cpp \
   $$PWD/exporting/exportcsv.cpp \
   $$PWD/exporting/exporterprocessor.cpp \
   $$PWD/exporting/exporterregistry.cpp \
   $$PWD/exporting/exportimage.cpp \
   $$PWD/exporting/exportprint.cpp \
   $$PWD/exporting/legacyexportdrawer.cpp \
   $$PWD/hantekdso/models/modelDSO6022.cpp \
   $$PWD/hantekdso/controlsettings.cpp \
   $$PWD/hantekdso/controlspecification.cpp \
   $$PWD/hantekdso/dsomodel.cpp \
   $$PWD/hantekdso/enums.cpp \
   $$PWD/hantekdso/hantekdsocontrol.cpp \
   $$PWD/hantekdso/modelregistry.cpp \
   $$PWD/hantekprotocol/controlcommand.cpp \
   $$PWD/hantekprotocol/controlStructs.cpp \
   $$PWD/iconfont/QtAwesome.cpp \
   $$PWD/iconfont/QtAwesomeAnim.cpp \
   $$PWD/post/graphgenerator.cpp \
   $$PWD/post/mathchannelgenerator.cpp \
   $$PWD/post/postprocessing.cpp \
   $$PWD/post/postprocessingsettings.cpp \
   $$PWD/post/ppresult.cpp \
   $$PWD/post/spectrumgenerator.cpp \
   $$PWD/selectdevice/deviceslistmodel.cpp \
   $$PWD/selectdevice/newdevicemodelfromexisting.cpp \
   $$PWD/selectdevice/rawdeviceslistmodel.cpp \
   $$PWD/selectdevice/selectsupporteddevice.cpp \
   $$PWD/usb/ezusb.cpp \
   $$PWD/usb/finddevices.cpp \
   $$PWD/usb/uploadFirmware.cpp \
   $$PWD/usb/usbdevice.cpp \
   $$PWD/utils/printutils.cpp \
   $$PWD/widgets/colorbox.cpp \
   $$PWD/widgets/datagrid.cpp \
   $$PWD/widgets/levelslider.cpp \
   $$PWD/widgets/sispinbox.cpp \
   $$PWD/dsowidget.cpp \
   $$PWD/glscope.cpp \
   $$PWD/glscopegraph.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp \
   $$PWD/settings.cpp

INCLUDEPATH = \
    $$PWD/. \
    $$PWD/configdialog \
    $$PWD/docks \
    $$PWD/exporting \
    $$PWD/hantekdso \
    $$PWD/hantekdso/models \
    $$PWD/hantekprotocol \
    $$PWD/iconfont \
    $$PWD/post \
    $$PWD/selectdevice \
    $$PWD/usb \
    $$PWD/utils \
    $$PWD/widgets

#DEFINES = 

QT += widgets
QT += printsupport
