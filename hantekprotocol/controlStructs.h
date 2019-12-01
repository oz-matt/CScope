#pragma once

#include "controlcode.h"
#include "controlcommand.h"
#include "types.h"
#include "usb/usbdevicedefinitions.h"

#include <inttypes.h>
#include <memory>

namespace Hantek {
struct OffsetsPerGainStep;

/// \enum BulkIndex
/// \brief Can be set by CONTROL_BEGINCOMMAND, maybe it allows multiple commands
/// at the same time?
enum BulkIndex {
    COMMANDINDEX_0 = 0x03, ///< Used most of the time
    COMMANDINDEX_1 = 0x0a,
    COMMANDINDEX_2 = 0x09,
    COMMANDINDEX_3 = 0x01, ///< Used for ::BulkCode::SETTRIGGERANDSAMPLERATE sometimes
    COMMANDINDEX_4 = 0x02,
    COMMANDINDEX_5 = 0x08
};

/// \class ControlBeginCommand
class ControlBeginCommand : public ControlCommand {
  public:
    /// \brief Sets the command index to the given value.
    /// \param index The CommandIndex for the command.
    ControlBeginCommand(BulkIndex index = COMMANDINDEX_0);
};

/// \brief The CONTROL_GETSPEED parser.
class ControlGetSpeed : public ControlCommand {
  public:
    ControlGetSpeed();
    /// \brief Gets the speed of the connection.
    /// \return The speed level of the USB connection.
    ConnectionSpeed getSpeed();
};

struct ControlSetOffset : public ControlCommand {
    ControlSetOffset();
    /// \brief Sets the offsets to the given values.
    /// \param channel1 The offset for channel 1.
    /// \param channel2 The offset for channel 2.
    /// \param trigger The offset for ext. trigger.
    ControlSetOffset(uint16_t channel1, uint16_t channel2, uint16_t trigger);

    /// \brief Get the offset for the given channel.
    /// \param channel The channel whose offset should be returned.
    /// \return The channel offset value.
    uint16_t getChannel(ChannelID channel);
    /// \brief Set the offset for the given channel.
    /// \param channel The channel that should be set.
    /// \param offset The new channel offset value.
    void setChannel(ChannelID channel, uint16_t offset);
    /// \brief Get the trigger level.
    /// \return The trigger level value.
    uint16_t getTrigger();
    /// \brief Set the trigger level.
    /// \param level The new trigger level value.
    void setTrigger(uint16_t level);
};

struct ControlSetRelays : public ControlCommand {
    /// \brief Sets all relay states.
    /// \param ch1Below1V Sets the state of the Channel 1 below 1 V relay.
    /// \param ch1Below100mV Sets the state of the Channel 1 below 100 mV relay.
    /// \param ch1CouplingDC Sets the state of the Channel 1 coupling relay.
    /// \param ch2Below1V Sets the state of the Channel 2 below 1 V relay.
    /// \param ch2Below100mV Sets the state of the Channel 2 below 100 mV relay.
    /// \param ch2CouplingDC Sets the state of the Channel 2 coupling relay.
    /// \param triggerExt Sets the state of the external trigger relay.
    ControlSetRelays(bool ch1Below1V = false, bool ch1Below100mV = false, bool ch1CouplingDC = false,
                     bool ch2Below1V = false, bool ch2Below100mV = false, bool ch2CouplingDC = false,
                     bool triggerExt = false);

    /// \brief Get the below 1 V relay state for the given channel.
    /// \param channel The channel whose relay state should be returned.
    /// \return true, if the gain of the channel is below 1 V.
    bool getBelow1V(ChannelID channel);
    /// \brief Set the below 1 V relay for the given channel.
    /// \param channel The channel that should be set.
    /// \param below true, if the gain of the channel should be below 1 V.
    void setBelow1V(ChannelID channel, bool below);
    /// \brief Get the below 1 V relay state for the given channel.
    /// \param channel The channel whose relay state should be returned.
    /// \return true, if the gain of the channel is below 1 V.
    bool getBelow100mV(ChannelID channel);
    /// \brief Set the below 100 mV relay for the given channel.
    /// \param channel The channel that should be set.
    /// \param below true, if the gain of the channel should be below 100 mV.
    void setBelow100mV(ChannelID channel, bool below);
    /// \brief Get the coupling relay state for the given channel.
    /// \param channel The channel whose relay state should be returned.
    /// \return true, if the coupling of the channel is DC.
    bool getCoupling(ChannelID channel);
    /// \brief Set the coupling relay for the given channel.
    /// \param channel The channel that should be set.
    /// \param dc true, if the coupling of the channel should be DC.
    void setCoupling(ChannelID channel, bool dc);
    /// \brief Get the external trigger relay state.
    /// \return true, if the trigger is external (EXT-Connector).
    bool getTrigger();
    /// \brief Set the external trigger relay.
    /// \param ext true, if the trigger should be external (EXT-Connector).
    void setTrigger(bool ext);
};

struct ControlSetVoltDIV_CH1 : public ControlCommand {
    ControlSetVoltDIV_CH1();
    void setDiv(uint8_t val);
};

struct ControlSetVoltDIV_CH2 : public ControlCommand {
    ControlSetVoltDIV_CH2();
    void setDiv(uint8_t val);
};

struct ControlSetTimeDIV : public ControlCommand {
    ControlSetTimeDIV();
    void setDiv(uint8_t val);
};

struct ControlSetNumChannels : public ControlCommand {
    ControlSetNumChannels();
    void setDiv(uint8_t val);
};

struct ControlAcquireHardData : public ControlCommand {
    ControlAcquireHardData();
};

struct ControlGetLimits : public ControlCommand {
    ControlGetLimits(size_t channels);
};

struct ControlSetCalFreq : public ControlCommand {
    ControlSetCalFreq();
    void setCalFreq(uint8_t val);
};

}
