#include "network.h"
#include "Constants.h"
#include "Message.h"
#include "NetLayerMessage.h"
uint64_t msgId=0;

//xbee
void handleGetRequst();
void handleSetRequst();
void handleGetResponse();
void handleTrap();
void handleNetwork();
void handleAck();

Rx16Response rx16 = Rx16Response();

//serial
void _findNeighbors();
void _setRequest();
void _getRequest();

//parameters
uint64_t TIME_TO_REBUILD_NETWORK=60000; // every 1 minthe minutes 
uint16_t NUMBER_ATTEMPTS_SEND_MESSAGE=2;
uint64_t TIME_TO_GET_ACK=5000; // wait up to 5 seconds for response

Network::Network(XBee xbeeNet, HardwareSerial* serial) {
    this->xbeeNet=xbeeNet;
    this->serial=serial;
}


void Network::addSon(uint16_t s){
    if (sons_size<SON_SIZE && !ifSon(s))
        this->sonArray[sons_size++]=s;
}
bool Network::ifSon(uint16_t s){
    for (int i=0;i<sons_size;i++)
        if (this->sonArray[i]==s)
            return true;
    return false;
}
void Network::addFather(uint16_t f){
    if (fathers_size<FATHERS_SIZE && !ifFather(f))
        this->fatherArray[fathers_size++]=f;
}
bool Network::ifFather(uint16_t f){
    for (int i=0;i<fathers_size;i++)
        if (this->fatherArray[i]==f)
            return true;
    return false;
}

void  Network::writeToSerial(uint8_t* str){
    (*serial).println((char*)str);
}

void Network::updateSate(){

    // #ifdef master
    // uint8_t serialData[100] ;
    // //serial
    // if ((*serial).available()) {
    //   (*serial).readBytes(serialData, sizeof(serialData));
    // //  (*serial).println("serialData:");
    // //   for (int i=0;i< sizeof(serialData);i++){
    // //      (*serial).println(serialData[i]);
    // //   }


    // if (serialData[0]==BUILD_NETWORK){
    //     (*serial).print(BUILD_NETWORK);
    //     //Serial.println("*****************");
    //     _findNeighbors();
    // }  

    // //else if (serialData[0]==SET_REQUEST)  _setRequest();

    // ///else if (serialData[0]==GET_RESPONSE)  _getRequest();
    
    // }
    // #endif
    

    Rx16Response rx16 = Rx16Response();
    xbeeNet.readPacket();
    //Serial.println("**");
    if (xbeeNet.getResponse().isAvailable()) {
      // got something
        Serial.println("#############");
        // got a rx packet       
        if (xbeeNet.getResponse().getApiId() == RX_16_RESPONSE) {
            xbeeNet.getResponse().getRx16Response(rx16);

            for (int i = 0; i < rx16.getFrameDataLength(); i++) {
                Serial.print("res: [");
                Serial.print(i, DEC);
                Serial.print("] is ");
                Serial.print(rx16.getFrameData()[i], HEX);
                Serial.println("-");
            }  
            //Serial.print("api id:");  
           // Serial.println(rx16.getApiId(), HEX); 

        //     for (int i = 0; i < rx16.getDataLength(); i++) {
        //     Serial.print("res: [");
        //     Serial.print(i, DEC);
        //     Serial.print("] is ");
        //     Serial.print(rx16.getData()[i], HEX);
        //     Serial.println("-");
        //   }   
            if (rx16.getData()[HEADER_LAYERID]==HEADER_NET_LAYER){ // net layer

                switch(rx16.getData()[HEADER_SIZR]){
                 //case GET_REQUEST: handleGetRequst();
                 //           break;
                //case SET_REQUEST : handleSetRequst();
                //            break;
                //case GET_RESPONSE: handleGetResponse();
                //            break;
                case TRAP: handleTrap();
                        ///אם אתה הקדקוד מעביר לסיריאל
                        ///אחרת- מעביר לאיקסבי
                        break;
                case NETWORK: handleNetwork();
                        if (rx16.getData()[HEADER_SIZR+1]==DISC_NEIGH){
                            ///לבדוק אם מי שקיבלתי ממנו את ההודעה הוא לא בן
                            // NetMessage selfPubMsg;
                            // selfPubMsg.SetTypeNum(SELF_PUB)
                            // selfPubMsg.setDirection(0);
                            // selfPubMsg.setLayerId(0);
                            // selfPubMsg.setMsgId(ID+msgId);
                            // msgId++;
                            ////sent to the adress i recive from
                        }
                        else if (rx16.getData()[HEADER_SIZR+1]==SELF_PUB){
                            /// save the son number in array
                            // NetMessage connMsg;
                            // connMsg.SetTypeNum(CONNECTED)
                            // connMsg.setDirection(1);
                            // connMsg.setLayerId(0);
                            // connMsg.setMsgId(ID+msgId);
                            // msgId++;
                            ////sent to the adress i recive from
                            /// לשלוח הודעת trap לאבות 
                            

                        }
                        else if (rx16.getData()[HEADER_SIZR+1]==CONNECTED){
                            ///save the father number in array
                        }

                        break;
                case ACK: handleAck();
                        break;
                }
            }
            else if (rx16.getData()[HEADER_LAYERID]==HEADER_APP_LAYER) {} // app layer

        }
    } 
}

// #ifdef master
// sendDataInSerial(...)
// #endif

//xbee

void handleGetRequst(){

}

void handleSetRequst(){

}

void handleGetResponse(){

}

void handleTrap(){

}

void handleNetwork(){

}

void handleAck(){

}

void Network::writeXbee(uint16_t dest,Payload payload,uint8_t payloadSize){
    //Tx16Request tx = Tx16Request(dest, payload, payloadSize);
   // xbeeNet.send(tx);
}

//serial

void Network::_findNeighbors(){
    (*serial).println("_findNeighbors");
    NetworkMsg netMsg(HEADER_DIRECTION_BRODCAST,HEADER_NET_LAYER,ID+msgId,ID,NETWORK_SIZE,NETWORK,DISC_NEIGH);
    msgId++;
    this->send(&netMsg);

}

void _setRequest(){

}

 void _getRequest(){

 }


void Network::send(Message* p){
	Payload to_send=*(p->generatePayload());
    if (p->getHeader()->getDirection()==HEADER_DIRECTION_BRODCAST){ //brodcasr
        Tx16Request tx = Tx16Request(0xffff, to_send.buffer, to_send.length);
	     xbeeNet.send(tx);
    }

    else if (p->getHeader()->getDirection()==HEADER_DIRECTION_DOWN) {//sons
            for (int i=0;i<sons_size;i++){
                Tx16Request tx = Tx16Request(this->sonArray[i], to_send.buffer, to_send.length);
                 xbeeNet.send(tx);
            }
    }
    else if (p->getHeader()->getDirection()==HEADER_DIRECTION_UP) {//fathers
            for (int i=0;i<fathers_size;i++){
                Tx16Request tx = Tx16Request(this->fatherArray[i], to_send.buffer, to_send.length);
                 xbeeNet.send(tx);
            }
    }
}


