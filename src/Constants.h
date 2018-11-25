#pragma once


#define master 0
#define ID 0x2222
//msg
#define GET_REQUEST 1
#define SET_REQUEST 2
#define GET_RESPONSE 3
#define TRAP 4
///////////////////////////
#define NETWORK 5
#define NETWORK_SIZE 10 //8+1+1
//type:
#define DISC_NEIGH 0
#define SELF_PUB 1
#define CONNECTED 2
/////////////////////////
#define ACK 6

//serial 
#define BUILD_NETWORK 0




#define PARAM_TIME_TO_REBUILD_NETWORK 0
#define PARAM_NUMBER_ATTEMPTS_SEND_MESSAGE 1
#define PARAM_TIME_TO_GET_ACK 2
#define BUFFER_MSG 3

#define MAX_PARAM 32

#define REQUEST_ID_SIZE 2
#define PARAM_DATA_SIZE 50 

//header message
#define HEADER_SIZR 68
#define HEADER_DIRECTION_UP 0
#define HEADER_DIRECTION_DOWN 1
#define HEADER_DIRECTION_BRODCAST 2

#define HEADER_LAYERID 1



#define HEADER_NET_LAYER 0
#define HEADER_APP_LAYER 0



#define GET_REQ_SIZE 11 //6+1+4
#define SET_REQ_SIZE 136 //6+2+max 32 param * 4 bytes
#define GET_RES_SIZE 142 //6+1+5+max 32 param * 4 bytes
#define TRAP_SIZE 11 //6+1+5+max 32 param * 2 bytes
#define MAX_SIZE 76 


#define SON_SIZE 10
#define FATHERS_SIZE 10