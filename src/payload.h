#ifndef payload_h
#define payload_h
#include "Constants.h"
#include <HardwareSerial.h>
#include "Message.h"

class Payload{
protected:

    //uint8_t* getText();
   // uint16_t getSize();


public:
    uint8_t* buffer;
    uint8_t length; 
   
};



#endif //payload_h