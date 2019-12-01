// SPDX-License-Identifier: GPL-2.0+

#pragma once

#include <QMetaType>
#include <QString>
#include <stdint.h>

#define HANTEK_GAIN_STEPS 8

namespace Hantek {
/// \enum UsedChannels
/// \brief The enabled channels.
enum class UsedChannels : uint8_t {
    USED_CH1,    ///< Only channel 1 is activated
    USED_CH2,    ///< Only channel 2 is activated
    USED_CH1CH2, ///< Channel 1 and 2 are both activated
    USED_NONE,    ///< No channels are activated
};

#pragma pack(push, 1)
struct Offset {
    unsigned short start = 0x0000;
    unsigned short end = 0xffff;
};

struct OffsetsPerGainStep {
    Offset step[HANTEK_GAIN_STEPS];
};

#pragma pack(pop)

}
