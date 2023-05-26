#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <ti/drivers/UART.h>

typedef UART_Handle SerialPort;
typedef UART_Params SerialPortParams;

void SerialPortParamsInit(SerialPortParams *params);

SerialPort SerialPort_open(SerialPortParams *params);

int_fast32_t SerialPort_write(SerialPort serialPort, const uint8_t *data, size_t len);

void SerialPort_close(SerialPort serialPort);

#endif // SERIAL_PORT_H
