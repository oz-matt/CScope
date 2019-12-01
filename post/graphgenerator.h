// SPDX-License-Identifier: GPL-2.0+

#pragma once

#include <deque>

#include <QObject>
#include <QVector3D>

#include "hantekdso/enums.h"
#include "hantekprotocol/types.h"
#include "processor.h"

struct DsoSettingsScope;
class PPresult;
namespace Dso {
struct ControlSpecification;
}

/// \brief Generates ready to be used vertex arrays
class GraphGenerator : public QObject, public Processor {
    Q_OBJECT

  public:
    GraphGenerator(const DsoSettingsScope *scope);
    void generateGraphsXY(PPresult *result, const DsoSettingsScope *scope);

  private:
    void generateGraphsTYvoltage(PPresult *result);
    void generateGraphsTYspectrum(PPresult *result);

    bool ready = false;
    const DsoSettingsScope *scope;

    // Processor interface
    void process(PPresult *data) override;
};
