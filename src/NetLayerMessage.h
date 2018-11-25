
#ifndef NetMessage_h
#define NetMessage_h
#include <XBee.h>
#include <HardwareSerial.h>
#include "Message.h"
#include "payload.h"
class NetLayerMessage: public Message {
public:

    NetLayerMessage (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size,uint8_t typeNum);

    void SetTypeNum(uint8_t num);
    uint8_t getTypeNum();



    virtual Payload* generatePayload()=0;

protected:
    uint8_t typeNum;
   

};
///////////////////////////////////////////////////////////////////////////////////////////

class Ack: public NetLayerMessage {
public:
    void SetMsgId(uint32_t id);
    uint32_t getMsgId();

    Payload* generatePayload();

private:
    uint32_t msgId;
};


///////////////////////////////////////////////////////////////////////////////////////////

class GetRequest: public NetLayerMessage {
public:
    void SetParam(uint8_t param);
    uint8_t getParam();

    Payload* generatePayload();

private:
    uint8_t param;

};

class ParamDetails {
public:
    void setParamNum(uint8_t num);
    uint8_t getParamNum();

    void setParamVal(uint32_t val);
    uint32_t getParamVal();

private:
    uint8_t paramNum;
    uint32_t paramVal;
};

///////////////////////////////////////////////////////////////////////////////////////////

class SetRequest: public NetLayerMessage {
public:
    void setParamDetails(ParamDetails paramDet[MAX_PARAM],uint8_t paramSize);
    ParamDetails* getParamDetails();

    Payload* generatePayload();

private:
    uint8_t paramNum;
   //ParamDetails par;
    ParamDetails paramDetails [MAX_PARAM];

};


///////////////////////////////////////////////////////////////////////////////////////////
class GetResponse: public NetLayerMessage {
public:
    void setParamDetails(ParamDetails paramDet[MAX_PARAM],uint8_t paramSize);
    ParamDetails* getParamDetails();

    void setRequestId (uint32_t id);
    uint32_t getRequestId();

    void setErrorStatus (uint8_t status);
    uint8_t getErrorStatus();

    void setErrorIndex (uint8_t index);
    uint8_t getErrorIndex();

    Payload* generatePayload();


private:
   uint32_t requestId;
   uint8_t paramNum;
   uint8_t errorStatus;
   uint8_t errorIndex;
   ParamDetails paramDetails[MAX_PARAM];

};

///////////////////////////////////////////////////////////////////////////////////////////

class Trap: public NetLayerMessage {
public:
    
    Trap (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size,uint8_t typeNum,uint8_t trapType,uint16_t participntId );

    void setTrapType (uint8_t type);
    uint8_t getTrapType();

    void setParticipntId (uint8_t parID);
    uint8_t getParticipntId();

    Payload* generatePayload();

private:
   uint8_t trapType;
   uint16_t participntId;
};

///////////////////////////////////////////////////////////////////////////////////////////

class NetworkMsg: public NetLayerMessage {
public:
    NetworkMsg (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size,uint8_t typeNum,uint8_t networkType);

    //NetworkMsg (uint8_t typeNum,uint8_t networkType);
    void setNetworkType (uint8_t type);
    uint8_t getNetworkType();

    Payload* generatePayload();

private:
   uint8_t networkType;

};

#endif //NetMessage_h