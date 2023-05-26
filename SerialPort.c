#include "SerialPort.h"
#include "Board.h"

// is this module initialized
static bool initialized = false;

static SerialPortParams defaultParams;

void SerialPortParamsInit(SerialPortParams *params) {
    UART_Params_init(params);
    params->writeMode = UART_MODE_BLOCKING;
    params->writeDataMode = UART_DATA_BINARY;
    params->readEcho = UART_ECHO_OFF;
}

SerialPort SerialPort_open(SerialPortParams *params) {
    if (!initialized) {
        initialized = true;
        UART_init();
        SerialPortParamsInit(&defaultParams);
    }

    if (params == NULL) {
        params = &defaultParams;
    }

    // Open the UART
    SerialPort serialPort;
    serialPort = UART_open(Board_UART0, params);
    return serialPort;
}

int_fast32_t SerialPort_write(SerialPort serialPort, const uint8_t *data, size_t len) {
    return UART_write(serialPort, data, len);
}

void SerialPort_close(SerialPort serialPort) {
    return UART_close(serialPort);
}
