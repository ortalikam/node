#include "Header.h"
#include "Constants.h"

Header::Header(uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId){
    this->direction=direction;
    this->layerId=layerId;
    this->msgId=msgId;
    this->senderId=senderId;
}

void Header::setDirection (uint8_t dir){
    this->direction=dir;
}
uint8_t Header::getDirection (){
    return this->direction;
}

void Header::setLayerId (uint8_t layer){
    this->layerId=layer;
}
uint8_t Header::getLayerId (){
    return this->layerId;
}

void Header::setMsgId (uint32_t msg){
    this->msgId=msg;
}
uint32_t Header::getMsgId (){
    return this->msgId;
}

void Header::setSenderId (uint16_t sender){
    this->senderId=sender;
}
uint16_t Header::getSenderId (){
    return this->senderId;
}