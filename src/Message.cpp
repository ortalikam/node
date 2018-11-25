#include "Message.h"
#include "Constants.h"

 Message::Message (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size){
  this->header=new Header( direction, layerId, msgId, senderId);
  this->size=size;
}

//  void Message::SetHeader (Header* header){
//    this->header=*header;
//  }

  Header* Message::getHeader(){
      return this->header;
  }

  void  Message::SetSize (uint16_t size){
    this->size=size;
  }
   uint16_t  Message::getSize (){
     return this->size;
   }
