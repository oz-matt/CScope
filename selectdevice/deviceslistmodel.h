// SPDX-License-Identifier: GPL-2.0+
#pragma once

#include <QAbstractTableModel>
#include "devicelistentry.h"

class FindDevices;

/**
 * Provides a Model for the Qt Model/View concept. The {@see FindDevices} is required
 * to update the list of available devices.
 */
class DevicesListModel: public QAbstractTableModel {
public:
    DevicesListModel(FindDevices* findDevices);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    void updateDeviceList();
private:
    std::vector<DeviceListEntry> entries;
    FindDevices* findDevices;
};
