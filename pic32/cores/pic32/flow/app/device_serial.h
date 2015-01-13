/*******************************************************************************
  Device Serial Number APIs Header

  File Name:
    device_serial.h

  Summary:
    APIs for retrieving the device's serial number

  Description:

 *******************************************************************************/
#ifndef __DEVICE_SERIAL_H_
#define __DEVICE_SERIAL_H_

#include <stdint.h>
#include <stdbool.h>

uint64_t DeviceSerial_GetCpuSerialNumberUint64(void);
bool DeviceSerial_GetCpuSerialNumberHexString (char* buffer, uint32_t buffSize);

#endif // __DEVICE_SERIAL_H_