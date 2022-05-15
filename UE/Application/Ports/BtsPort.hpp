#pragma once

#include "IBtsPort.hpp"
#include "Logger/PrefixedLogger.hpp"
#include "ITransport.hpp"
#include "Messages/PhoneNumber.hpp"

namespace ue
{

class BtsPort : public IBtsPort
{
public:
    BtsPort(common::ILogger& logger, common::ITransport& transport, common::PhoneNumber phoneNumber);
    void start(IBtsEventsHandler& handler);
    void stop();


    void sendAttachRequest(common::BtsId) override;
    void sendSms(common::PhoneNumber, std::string, int) override;
    void sendCallRequest(common::PhoneNumber) override;
    common::PhoneNumber getMyPhoneNumber() override;
    void sendDropCall(common::PhoneNumber) override;
    void sendCallAccepted(common::PhoneNumber) override;

private:
    void handleMessage(BinaryMessage msg);

    common::PrefixedLogger logger;
    common::ITransport& transport;
    common::PhoneNumber phoneNumber;

    IBtsEventsHandler* handler = nullptr;
};

}
