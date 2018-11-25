#include <XBee.h>
#include <network.h>
#include <Constants.h>



//XBeeResponse response = XBeeResponse();
XBee xbee = XBee();
// create reusable response objects for responses we expect to handle 
//Rx16Response rx16 = Rx16Response();

Network network(xbee,&Serial);
 
//Buffer for receiving Serial data



void setup() {
  
  // start serial
  Serial1.begin(9600);
  Serial.begin(9600);
  xbee.setSerial(Serial1);
 //network=Network(xbee,&Serial);
}

// continuously reads packets, looking for RX16 or RX64
void loop() {
    
    network.updateSate();

    

  
}

