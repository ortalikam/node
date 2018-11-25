#ifndef Network_h
#define Network_h
#include <XBee.h>
#include <HardwareSerial.h>
#include "Message.h"
#include "NetLayerMessage.h"
class Network {
public:
  
    /**
	 * Default constructor
	 */
    Network( XBee xbeeNet,HardwareSerial* serial );

    void  writeToSerial(uint8_t* str);

	void writeXbee(uint16_t dest,Payload payload,uint8_t payloadSize);

    void updateSate();

    void send(Message* p);

    void addSon(uint16_t s);
    bool ifSon(uint16_t s);

    void addFather(uint16_t f);
    bool ifFather(uint16_t f);

    #ifdef master
        //func
        void _findNeighbors() ;     
    #endif
    

private:
    XBee xbeeNet;
    HardwareSerial* serial;

    uint16_t sonArray[SON_SIZE]; // array of suns
    int sons_size=0; //how much sons exists

    uint16_t fatherArray[FATHERS_SIZE]; // array of suns
    int fathers_size=0; //how much sons exists


     //parameters
    int Number_attempts_send_message; //define-2 
    int Time_to_get_ack; //define-3 ,in microsecond 

    
    #ifdef master
        
         //parameters
         int time_to_rebuild_network; //define-1 , in microsecond
    #else
        uint32_t fathers[FATHERS_SIZE]; // array of fathers
        int father_size=0; //how much fathers exists
       
    #endif

  // מערך ציקלי של הודעות 

};





#endif //Network_h
