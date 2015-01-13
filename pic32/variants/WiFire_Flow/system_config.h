/*******************************************************************************
  Ethernet PHY Driver Testbench Configurations

  Company:
    Microchip Technology Inc.

  File Name:
    system_config.h

  Summary:
    Ethernet PHY driver testbench configuration definitions

  Description:
    These definitions statically define the driver's mode of operation.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

/* This is a temporary workaround for an issue with the peripheral library "Exists"
   functions that causes superfluous warnings.  It "nulls" out the definition of
   The PLIB function attribute that causes the warning.  Once that issue has been
   resolved, this definition should be removed. */
#ifndef _PLIB_UNSUPPORTED
     #define _PLIB_UNSUPPORTED
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "sys_fs_config.h"
//#include "system/debug/sys_debug.h"
#include "tcpip/src/system/system_command.h"

#include "tcpip_stack_config.h"
#include "bsp_config.h"

/* BSP LED Re-directs */
#define APP_TCPIP_LED_1 BSP_LED_1
#define APP_TCPIP_LED_2 BSP_LED_2
#define APP_TCPIP_LED_3 BSP_LED_3
#define APP_TCPIP_LED_4 BSP_LED_4

#define APP_TCPIP_SWITCH_1 BSP_SWITCH_1
#define APP_TCPIP_SWITCH_2 BSP_SWITCH_2

// *****************************************************************************
// *****************************************************************************
// Section: System Error Message Support
// *****************************************************************************
// *****************************************************************************

#include "assert_to_ide.h"

#ifndef SYSTEM_CURRENT_ERROR_LEVEL
    #define SYSTEM_CURRENT_ERROR_LEVEL  SYS_ERROR_WARNING
#endif

#if defined(USE_ISP_DEBUG) && defined(__MPLAB_DEBUGGER_PIC32MXSK)
#define PLIB_ASSERT(test,message)   ((void)( (test) ? 0 : AssertToIDE(#test,message,__LINE__,__FILE__), 0))
#endif

typedef enum
{
    SYS_MODULE_ETH_1,
    SYS_MODULE_UART_1,
    SYS_MODULE_UART_2,
	SYS_MODULE_UART_3,
	SYS_MODULE_UART_4,
	SYS_MODULE_UART_5,
	SYS_MODULE_UART_6,
    SYS_MODULE_CHAR_LCD,
    SYS_MODULE_DBAPPIO,
    SYS_MODULE_TELNETS,
    SYS_MODULE_ETH_PHY,

} SYS_MODULE_ID;

// *****************************************************************************
// *****************************************************************************
// Section: Ethernet PHY Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* ETHPHY hardware instance configuration

  Summary:
    Selects the maximum number of hardware instances that can be supported by
    the dynamic driver

  Description:
    This definition selects the maximum number of hardware instances that can be
    supported by the dynamic driver. Not defining it means using a static driver.

  Remarks:
    None
*/

#define DRV_ETHPHY_INSTANCES_NUMBER                1


// *****************************************************************************
/* ETHPHY Maximum Number of Clients

  Summary:
    Selects the miximum number of clients

  Description:
    This definition select the maximum number of clients that the ETHPHY driver can
    support at run time. Not defining it means using a single client.

  Remarks:
    None.

*/

#define DRV_ETHPHY_CLIENTS_NUMBER                1


// *****************************************************************************
/* ETHPHY Static Index Selection

  Summary:
    ETHPHY Static Index selection

  Description:
    ETHPHY Static Index selection for the driver object reference

  Remarks:
    This index is required to make a reference to the driver object
*/

#define DRV_ETHPHY_INDEX                                DRV_ETHPHY_INDEX_1


// *****************************************************************************
/* ETHPHY Interrupt And Polled Mode Operation Control

*/
// Ethernet PHY has no interrupts
//#define DRV_ETHPHY_INTERRUPT_MODE          true


// Section: Initialization Overrides
/* This section defines the initialization overrides */

// *****************************************************************************
/* ETHPHY Peripheral ID Selection

  Summary:
    Defines an override of the peripheral id.

  Description:
    Defines an override of the peripheral id, using macros

  Remarks:

    Note: Some devices also support ETHPHY_ID_0
*/

#define DRV_ETHPHY_PERIPHERAL_ID                         ETHPHY_ID_1


// *****************************************************************************
/* ETHPHY power state configuration

  Summary:
    Defines an override of the power state of the ETHPHY driver.

  Description:
    Defines an override of the power state of the ETHPHY driver.

  Remarks:
    Note: This feature may not be available in the device or the ETHPHY module
    selected.
*/

// Has no power modes
//#define DRV_ETHPHY_POWER_STATE                 SYS_MODULE_POWER_IDLE_STOP


// Additional Initialization Overrides

// Originally in eth_pic32_ext_phy.h

#define DRV_ETHPHY_NEG_INIT_TMO  1       // negotiation initiation timeout, ms.

#define DRV_ETHPHY_NEG_DONE_TMO  2000        // negotiation complete timeout, ms.
                        // based on IEEE 802.3 Clause 28 Table 28-9 autoneg_wait_timer value (max 1s)

#define DRV_ETHPHY_RESET_CLR_TMO 500     // reset self clear timeout, ms.
                        // IEEE 802.3 Clause 22 Table 22-7 and paragraph "22.2.4.1.1 Reset" (max 0.5s)

// *****************************************************************************
// *****************************************************************************
// Section: Ethernet MAC Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Ethernet MAC hardware instance configuration

  Summary:
    Selects the maximum number of hardware instances that can be supported by
    the dynamic driver

  Description:
    This definition selects the maximum number of hardware instances that can be
    supported by the dynamic driver. Not defining it means using a static driver.

  Remarks:
    None
*/

#define DRV_ETHMAC_INSTANCES_NUMBER  1


// *****************************************************************************
/* Ethernet MAC Maximum Number of Clients

  Summary:
    Selects the miximum number of clients

  Description:
    This definition select the maximum number of clients that the Ethernet MAC
    driver can support at run time. Not defining it means using a single client.

  Remarks:
    None.

*/

#define DRV_ETHMAC_CLIENTS_NUMBER  1


// *****************************************************************************
/* Ethernet MAC Static Index Selection

  Summary:
    Ethernet MAC Static Index selection

  Description:
    Ethernet MAC Static Index selection for the driver object reference

  Remarks:
    This index is required to make a reference to the driver object
*/

#define DRV_ETHMAC_INDEX  DRV_ETHMAC_INDEX_1


// *****************************************************************************
/* Ethernet MAC Interrupt And Polled Mode Operation Control

  Summary:
    Macro controls operation of the driver in the interrupt or polled mode

  Description:
    This macro controls the operation of the driver in the interrupt
    mode of operation. The possible values of this macro is

    - true  - Select if interrupt mode of timer operation is desired

    - false - Select if polling mode of timer operation is desired

    Not defining this option to true or false will result in build error.

  Remarks:
    None.
*/

#define DRV_ETHMAC_INTERRUPT_MODE  true


// Section: Initialization Overrides
/* This section defines the initialization overrides */

// *****************************************************************************
/* Ethernet MAC Peripheral ID Selection

  Summary:
    Defines an override of the peripheral id.

  Description:
    Defines an override of the peripheral id, using macros

  Remarks:

    Note: Some devices also support ETHMAC_ID_0
*/

#define DRV_ETHMAC_PERIPHERAL_ID  ETHMAC_ID_1


// *****************************************************************************
/* Ethernet MAC Interrupt Source

  Summary:
    Defines an override of the interrupt source in case of static driver.

  Description:
    Defines an override of the interrupt source in case of static driver.

  Remarks:
    Refer to the INT PLIB document for more information on INT_SOURCE
    enumeration.

*/

#define DRV_ETHMAC_INTERRUPT_SOURCE  INT_SOURCE_ETH_1

// *****************************************************************************
/* Ethernet PHY Interrupt Source

  Summary:
    Defines an override of the interrupt source in case of static driver.

  Description:
    Defines an override of the interrupt source in case of static driver.

  Remarks:
    Refer to the INT PLIB document for more information on INT_SOURCE
    enumeration.

*/

#define DRV_ETHPHY_INTERRUPT_SOURCE  INT_SOURCE_EXTERNAL_3

// *****************************************************************************
/* Ethernet Ethernet MAC Interrupt Vector

  Summary:
    Defines an override of the interrupt vector in case of static driver.

  Description:
    Defines an override of the interrupt vector in case of static driver.

  Remarks:
    Refer to the INT PLIB document for more information on INT_VEECTOR
    enumeration.

*/
#define DRV_ETHMAC_INTERRUPT_VECTOR      INT_VECTOR_ETH

// *****************************************************************************
/* Ethernet MAC power state configuration

  Summary:
    Defines an override of the power state of the Ethernet MAC driver.

  Description:
    Defines an override of the power state of the Ethernet MAC driver.

  Remarks:
    Note: This feature may not be available in the device or the Ethernet MAC module
    selected.
*/

#define DRV_ETHMAC_POWER_STATE  SYS_MODULE_POWER_IDLE_STOP

#endif // _SYSTEM_CONFIG_H


#ifndef __SYSTEM_PROFILE_H_
#define __SYSTEM_PROFILE_H_


#if defined (HARMONY_TMR_PORTING)
/*****************************************************************************
 * Timer/Counter width.
 * This is used to define the timer/counter width in system.
 * This implementation uses the core timer
 *****************************************************************************/
#define TMR_ID                      TMR_ID_2

#define TMR_INT_SOURCE              INT_SOURCE_TIMER_2

#define TMR_INT_VECTOR              INT_VECTOR_T2

#define DRV_TMR_COUNT_WIDTH         32

#define DRV_TMR_INSTANCES_NUMBER    4

#define DRV_TMR_CLIENTS_NUMBER      4

#define SYS_TMR_MAX_PERIODIC_EVENTS 4

#define DRV_TMR_INTERRUPT_MODE      1

/*****************************************************************************
 * Timer/Counter period.
 * This is used to define the timer/counter width in system.
 * This implementation uses the core timer
 *****************************************************************************/
#define TIMER_PERIOD                500

#endif

/*****************************************************************************
 * The system debug enable
 * Use to enable the debug messages.
 *****************************************************************************/
#define SYS_DEBUG_ENABLE
#define RESET_ON_ASSERT

/*****************************************************************************
 * The system debug peripheral
 * Specify the debug port.
 *****************************************************************************/
//#define SYS_DEBUG_PORT          SYS_DEVICE_DBAPPIO
#define SYS_DEBUG_PORT          SYS_MODULE_UART_4

#ifndef UART4
#define UART4                   1
#endif

/*****************************************************************************
 * The system debug peripheral
 * Specify the debug port baud rate.
 *****************************************************************************/
#define SYS_DEBUG_BAUDRATE      115200

/*****************************************************************************
 * The system console enable
 * Use to enable the system console
 *****************************************************************************/
#define SYS_CONSOLE_ENABLE


/*****************************************************************************
 * The system console comm channel
 * Specify the console port.
 *****************************************************************************/
//#define SYS_CONSOLE_PORT          SYS_DEVICE_DBAPPIO
#define SYS_CONSOLE_PORT          SYS_MODULE_UART_4
#ifndef UART4
#define UART4                   1
#endif
/*****************************************************************************
 * The system console comm channel
 * Specify the console bit rate.
 *****************************************************************************/
#define SYS_CONSOLE_BAUDRATE     115200

/*****************************************************************************
 * The system console buffer space
 * Specify the length of the buffering for the console operations.
 *****************************************************************************/
#define SYS_CONSOLE_BUFFER_LEN   1024




/*****************************************************************************
 * The system Arduino shield's serial comms channel
 * Use to enable serial comms to an Arduino Shield
 *****************************************************************************/
#define SYS_ARDUINO_SERIAL_ENABLE

/*****************************************************************************
 * The system's Arduido shield comm channel
 *****************************************************************************/
#define SYS_ARDUINO_SERIAL_PORT     SYS_MODULE_UART_6
#ifndef UART6
#define UART6                   1
#endif

/*****************************************************************************
 * The system console comm channel
 * Specify the console bit rate.
 *****************************************************************************/
#define SYS_ARDUINO_SERIAL_BAUDRATE     115200


/*****************************************************************************
 * The system console buffer space
 * Specify the length of the buffering for the console operations.
 *****************************************************************************/
#define SYS_ARDUINO_SERIAL_BUFFER_LEN   1024




// *****************************************************************************
// *****************************************************************************
// Section: SYS RANDOM Configuration
// *****************************************************************************
// *****************************************************************************

#define SYS_RANDOM_CRYPTO_SEED_SIZE             (440/8)

/*****************************************************************************
 * The system command parser module
 * Use to enable the system command parser functionality
 *****************************************************************************/
#define SYS_COMMAND_ENABLE

/*****************************************************************************
 * The system user io interface module
 * Use to enable the system user io functionality (buttons, LEDs, etc.)
 *****************************************************************************/
#define SYS_USERIO_ENABLE

/*****************************************************************************
 * The system File System module
 * Use to enable the File System functionality (see FS configuration file for details).
 *****************************************************************************/
#define SYS_FS_ENABLE

// *****************************************************************************
// *****************************************************************************
// Section: SYS CLK Configuration
// *****************************************************************************
// *****************************************************************************

/* Primary oscillator input frequency, the frequency from the crystal */
#define SYS_CLK_CONFIG_PRIMARY_XTAL                     24000000UL

/* Secondary oscillator input frequency, the frequency from the crystal */
#define SYS_CLK_CONFIG_SECONDARY_XTAL                   32768UL

/* USB PLL is enabled through configuration bits */
#define SYS_CLK_CONFIGBIT_USBPLL_ENABLE                 true

/* USB PLL input divisor value set through configuration bits */
#define SYS_CLK_CONFIGBIT_USBPLL_DIVISOR               2

/* System PLL input divisor */
#define SYS_CLK_CONFIG_SYSPLL_INP_DIVISOR              3

/* External clock input */
#define SYS_CLK_CONFIG_EXTERNAL_CLOCK                   40000000UL

/* Frequency error limit */
#define SYS_CLK_CONFIG_FREQ_ERROR_LIMIT                 10

/* Allow Reference clock to alter the settings of System
PLL to achive the requested frequency. */
#define SYS_CLK_CONFIG_REFCLK_EDIT_SYSPLL               true

#define SYS_CLOCK_USB_CLOCK                             48000000


/* System clock source */
#define SYS_CLK_SOURCE                                  SYS_CLK_SOURCE_PRIMARY_SYSPLL

#define SYS_CLK_FREQ                        200000000

// *****************************************************************************
// *****************************************************************************
// Section: SYS DEVCON Configuration
// *****************************************************************************
// *****************************************************************************

/* System clock frequency */
#define SYS_DEVCON_SYSTEM_CLOCK                         200000000UL

/* Maximum peripheral bus frequency */
#define SYS_DEVCON_PIC32MZ_MAX_PB_FREQ                  200000000UL

//----------------------------
// MRF24W WiFi I/O pins
//----------------------------
// If you have a MRF24W WiFi PICtail, you must uncomment one of
// these two lines to use it.  SPI1 is the top-most slot in the Explorer 16
// (closer to the LCD and prototyping area) while SPI2 corresponds to
// insertion of the PICtail into the middle of the side edge connector slot.
// specify we want to use the MRF24W interface

#define MRFWB0M_INT_SOURCE    INT_SOURCE_EXTERNAL_4
#define MRFWB0M_INT_VECTOR    INT_VECTOR_INT4

#define MRF24W_IN_SPI4
#define MRF24W_USE_INT4_INT
#define MRF24W_SPI_CHN   4   // 1 - SPI1, 2 - SPI2, 4 - SPI4

// MRF24W in SPI4 slot
#define WF_CS_TRIS                  (TRISDbits.TRISD9)
#define WF_CS_IO                    (LATDbits.LATD9)
#define WF_CS_PORT_CHANNEL      PORT_CHANNEL_D
#define WF_CS_BIT_POS           9

#define WF_RESET_TRIS               (TRISFbits.TRISF4)
#define WF_RESET_IO                 (LATFbits.LATF4)
#define WF_RESET_PORT_CHANNEL   PORT_CHANNEL_F
#define WF_RESET_BIT_POS        4

#define WF_HIBERNATE_TRIS           (TRISGbits.TRISG1)
#define WF_HIBERNATE_IO             (PORTGbits.RG1)
#define WF_HIBERNATE_PORT_CHANNEL PORT_CHANNEL_G
#define WF_HIBERNATE_BIT_POS         1

#define WF_INT_PRIORITY         	3
#define WF_INT_SUBPRIORITY      	1
#define WF_INT_PORT_CHANNEL     	PORT_CHANNEL_A
#define WF_INT_BIT_POS          	15

//#define OSAL_USE_NONE
	  


// Enable runtime SoftAP/Interactive mode support
#define DYNAMIC_SSL_SERVER_MODE_SWITCH
#ifdef DYNAMIC_SSL_SERVER_MODE_SWITCH
extern bool g_sslServerMode;
#endif
#include "drv_spi_config.h"
#include "system_tmr_config.h"
#include "tcpip/src/system/system_mapping.h"

#endif  // __SYSTEM_PROFILE_H_

