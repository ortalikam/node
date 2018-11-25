#ifndef Message_h
#define Message_h
#include "Constants.h"
#include <HardwareSerial.h>
#include "Header.h"
#include "payload.h"

class Message{
public:

    Message (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size);
//    void SetHeader (Header* header);
    Header* getHeader ();

   void SetSize (uint16_t size);
   uint16_t getSize ();


   virtual Payload* generatePayload()=0;

protected:
    Header* header;
    uint16_t size; 
};



#endif //Message_h