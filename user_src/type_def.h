/**
****************************************************************************
* @Warning :Without permission from the author,Not for commercial use
* @File    :type_def.h
* @Author  :Xiaowine
* @date    :2017/4/14
* @version :V 1.0.0
*************************************************
* @brief   :
****************************************************************************
**/

#ifndef __type_def_h__
#define __type_def_h__

/*主控芯片的头文件*/
//

/*bool 类型头文件*/
#include "stdbool.h"

/*总中断头文件*/
#include "intrinsics.h"

/*常用数据类型定义*/
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define EnableInterrupt __enable_interrupt()

#define SUCESS 1
#define FAILURE 0

//代码标志位
typedef union _fullflag_ {
    unsigned char BYTE;
    struct
    {
        unsigned char Bit0 : 1;
        unsigned char Bit1 : 1;
        unsigned char Bit2 : 1;
        unsigned char Bit3 : 1;
        unsigned char Bit4 : 1;
        unsigned char Bit5 : 1;
        unsigned char Bit6 : 1;
        unsigned char Bit7 : 1;
    } BIT;
} uFLAG, *P_uFLAG;
#define TRANSITION_STATUS_TRANSITION 0
#define TRANSITION_STATUS_EXECUTING 1
#define TRANSITION_STATUS_IDLE 2
typedef struct
{
    union {
        uint8_t VALUE; /*!< SPI Slave Status                                                      */

        struct
        {
            uint8_t MEM_ACC_STATUS : 1; /*!< *Instantaneous* value of an AHB read data underflow condition
                                                    for memory reads. The same bit doubles up as an AHB bus error
                                                     indicator for memory writes.                                         */
            uint8_t FW_STATUS : 4;      /*!< *Instantaneous* value of the firmware status of the radio controller
                                                    state machine.                                                        */
            uint8_t CMD_READY : 1;      /*!< *Instantaneous* value of the indicator to the host that no posted
                                                    (to the SPI Slave) radio controller command is currently awaiting
                                                     servicing by the firmware radio state machine running on the
                                                     Cortex-M0.                                                           */
            uint8_t EXT_IRQ_STATUS : 1; /*!< *Instantaneous* value of the commoned-up (bitwise OR of the)
                                                    external interrupt outputs from the ADF7030, made available
                                                     in this format to the host for use in pin-limited systems.           */
            uint8_t SPIS_READY : 1;     /*!< *Instantaneous* value of the confirmation to the external host
                                                    that the HCLK clock domain in the ADF7030 has power, is out
                                                     of reset and has a running clock.                                    */
        };                              /*!< BitSize                                                               */
    };
} ADF7030_1_STATUS_TYPE;

#endif
