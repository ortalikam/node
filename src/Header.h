#ifndef Header_h
#define Header_h
#include "Constants.h"
#include <HardwareSerial.h>

class Header {
public:

    Header(uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId); //c'tor

    void setDirection (uint8_t dir);
    uint8_t getDirection ();

    void setLayerId (uint8_t layer);
    uint8_t getLayerId ();

    void setMsgId (uint32_t msg);
    uint32_t getMsgId ();

     void setSenderId (uint16_t sender);
     uint16_t getSenderId ();

    
private:
    uint8_t direction;
    uint8_t layerId;
    uint32_t msgId;
    uint16_t senderId;
};

#endif //Header_h