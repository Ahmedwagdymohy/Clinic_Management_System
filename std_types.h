#ifndef _STD_TYPES_H
#define _STD_TYPES_H
#define ZERO_INIT 0
#define ZERO 0


typedef unsigned char uint8_t; //just make the code easer
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t; //just make the code easer
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef enum return_status{
    R_NOK,
    R_OK

}return_status_t;

typedef enum stack_status{
    STACK_empty,
    STACK_full,
    STACK_NOT_FULL

}stack_status_tt;










#endif // _STD_TYPES_H
