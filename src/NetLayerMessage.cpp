#include "NetLayerMessage.h"
#include "payload.h"
/////////////////////////////////////////////////////////////////////

NetLayerMessage::NetLayerMessage (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size,uint8_t typeNum)
: Message( direction, layerId, msgId, senderId, size) 
{
    this->typeNum=typeNum;
}

void NetLayerMessage::SetTypeNum(uint8_t num){
    this->typeNum=num;
}
uint8_t NetLayerMessage::getTypeNum(){
    return this->typeNum;
}

/////////////////////////////////////////////////////////////////////


void Ack::SetMsgId(uint32_t id){
    this->msgId;
}
 uint32_t Ack::getMsgId(){
     return this->msgId;
 }


Payload* Ack::generatePayload(){
	Payload* result=new Payload();
	uint8_t size= this->size;
	result->length=size;
	result->buffer=(uint8_t*)malloc(size);

	result->buffer[0]=this->header->getDirection();
    result->buffer[1]=this->header->getLayerId();
    result->buffer[2]=(uint8_t)this->header->getMsgId();
    result->buffer[3]=(uint8_t)(this->header->getMsgId() >> 2);
    result->buffer[4]=(uint8_t)(this->header->getMsgId() >> 4);
    result->buffer[5]=(uint8_t)(this->header->getMsgId() >> 8);
    // result->buffer[6]=this->typeNum;
    // result->buffer[7]=this->networkType;
	return result;
}

//////////////////////////////////////////////////////////////////////

void GetRequest::SetParam(uint8_t param){
    this->param=param;

}
uint8_t GetRequest::getParam(){
    return this->param;
}

Payload* GetRequest::generatePayload(){
	Payload* result=new Payload();
	uint8_t size= this->size;
	result->length=size;
	result->buffer=(uint8_t*)malloc(size);

	result->buffer[0]=this->header->getDirection();
    result->buffer[1]=this->header->getLayerId();
    result->buffer[2]=(uint8_t)this->header->getMsgId();
    result->buffer[3]=(uint8_t)(this->header->getMsgId() >> 2);
    result->buffer[4]=(uint8_t)(this->header->getMsgId() >> 4);
    result->buffer[5]=(uint8_t)(this->header->getMsgId() >> 8);
    // result->buffer[6]=this->typeNum;
    // result->buffer[7]=this->networkType;
	return result;
}

//////////////////////////////////////////////////////////////////////

void ParamDetails::setParamNum(uint8_t num){
    this->paramNum=num;
}
uint8_t ParamDetails::getParamNum(){
     return this->paramNum;
}

void ParamDetails::setParamVal(uint32_t val){
    this->paramVal-val;
}
uint32_t ParamDetails::getParamVal(){
    return this->paramVal;
}

//////////////////////////////////////////////////////////////////////

void SetRequest::setParamDetails(ParamDetails paramDet[MAX_PARAM],uint8_t paramSize){
    this->paramNum=paramSize;
    for (int i=0;i<paramSize;i++)
    {
        this->paramDetails[i].setParamNum(paramDet[i].getParamNum());
        this->paramDetails[i].setParamVal(paramDet[i].getParamVal());
    }

}
ParamDetails* SetRequest::getParamDetails(){
    return this->paramDetails;
}

Payload* SetRequest::generatePayload(){
	Payload* result=new Payload();
	uint8_t size= this->size;
	result->length=size;
	result->buffer=(uint8_t*)malloc(size);

	result->buffer[0]=this->header->getDirection();
    result->buffer[1]=this->header->getLayerId();
    result->buffer[2]=(uint8_t)this->header->getMsgId();
    result->buffer[3]=(uint8_t)(this->header->getMsgId() >> 2);
    result->buffer[4]=(uint8_t)(this->header->getMsgId() >> 4);
    result->buffer[5]=(uint8_t)(this->header->getMsgId() >> 8);
    // result->buffer[6]=this->typeNum;
    // result->buffer[7]=this->networkType;
	return result;
}

//////////////////////////////////////////////////////////////////////

void GetResponse::setParamDetails(ParamDetails paramDet[MAX_PARAM],uint8_t paramSize){
    this->paramNum=paramSize;
    for (int i=0;i<paramSize;i++)
    {
        this->paramDetails[i].setParamNum(paramDet[i].getParamNum());
        this->paramDetails[i].setParamVal(paramDet[i].getParamVal());
    }
}
ParamDetails* GetResponse::getParamDetails(){
    return this->paramDetails;
}

void GetResponse::setRequestId (uint32_t id){
    this->requestId=id;
}
uint32_t GetResponse::getRequestId(){
    return  this->requestId;
}

void GetResponse::setErrorStatus (uint8_t status){
    this->errorStatus=status;
}
uint8_t GetResponse::getErrorStatus(){
    return this->errorStatus;
}

void GetResponse::setErrorIndex (uint8_t index){
    this->errorIndex=index;
}
uint8_t GetResponse::getErrorIndex(){
    return this->errorIndex;
}

Payload* GetResponse::generatePayload(){
	Payload* result=new Payload();
	uint8_t size= this->size;
	result->length=size;
	result->buffer=(uint8_t*)malloc(size);

	result->buffer[0]=this->header->getDirection();
    result->buffer[1]=this->header->getLayerId();
    result->buffer[2]=(uint8_t)this->header->getMsgId();
    result->buffer[3]=(uint8_t)(this->header->getMsgId() >> 2);
    result->buffer[4]=(uint8_t)(this->header->getMsgId() >> 4);
    result->buffer[5]=(uint8_t)(this->header->getMsgId() >> 8);
    // result->buffer[6]=this->typeNum;
    // result->buffer[7]=this->networkType;
	return result;
}

/////////////////////////////////////////////////////////////

Trap::Trap (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size,uint8_t typeNum,uint8_t trapType,uint16_t participntId )
:NetLayerMessage( direction, layerId, msgId, senderId, size, typeNum)
{
    this->trapType=trapType;
    this->participntId=participntId;
}

void Trap::setTrapType (uint8_t type){
    this->trapType=type;
}
uint8_t Trap::getTrapType(){
    return this->trapType;
}

void Trap::setParticipntId (uint8_t parID){
    this->participntId=parID;
}
uint8_t Trap::getParticipntId(){
    return this->participntId;
}



Payload* Trap::generatePayload(){
	Payload* result=new Payload();
	uint8_t size= this->size;
	result->length=size;
	result->buffer=(uint8_t*)malloc(size);

	result->buffer[0]=this->header->getDirection();
    result->buffer[1]=this->header->getLayerId();
    result->buffer[2]=(uint8_t)this->header->getMsgId();
    result->buffer[3]=(uint8_t)(this->header->getMsgId() >> 2);
    result->buffer[4]=(uint8_t)(this->header->getMsgId() >> 4);
    result->buffer[5]=(uint8_t)(this->header->getMsgId() >> 8);
    result->buffer[6]=this->typeNum;
    result->buffer[7]=this->trapType;
    result->buffer[8]=(uint8_t)this->participntId;
    result->buffer[9]=(uint8_t)(this->participntId>> 2);
	return result;
}

//////////////////////////////////////////////////////////////

NetworkMsg::NetworkMsg (uint8_t direction,uint8_t layerId,uint32_t msgId,uint16_t senderId,uint16_t size,uint8_t typeNum,uint8_t networkType)
:NetLayerMessage( direction, layerId, msgId, senderId, size, typeNum)
{
    this->networkType=networkType;
}

void  NetworkMsg::setNetworkType (uint8_t type){
    this->networkType=type;
}
uint8_t  NetworkMsg::getNetworkType(){
    return this->networkType;
}


Payload* NetworkMsg::generatePayload(){
	Payload* result=new Payload();
	uint8_t size= this->size;
	result->length=size;
	result->buffer=(uint8_t*)malloc(size);

	result->buffer[0]=this->header->getDirection();
    result->buffer[1]=this->header->getLayerId();
    result->buffer[2]=(uint8_t)this->header->getMsgId();
    result->buffer[3]=(uint8_t)(this->header->getMsgId() >> 2);
    result->buffer[4]=(uint8_t)(this->header->getMsgId() >> 4);
    result->buffer[5]=(uint8_t)(this->header->getMsgId() >> 8);
    result->buffer[6]=this->typeNum;
    result->buffer[7]=this->networkType;
	return result;
}