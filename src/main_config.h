#include <Arduino.h>
/** Add you required includes after Arduino.h */
#include <Wire.h>

#include <WisBlock-API.h>

// Debug output set to 0 to disable app debug output
#ifndef MY_DEBUG
#define MY_DEBUG 1
#endif

#ifdef NRF52_SERIES
#if MY_DEBUG > 0
#define MYLOG(tag, ...)                     \
	do                                      \
	{                                       \
		if (tag)                            \
			PRINTF("[%s] ", tag);           \
		PRINTF(__VA_ARGS__);                \
		PRINTF("\n");                       \
		if (g_ble_uart_is_connected)        \
		{                                   \
			g_ble_uart.printf(__VA_ARGS__); \
			g_ble_uart.printf("\n");        \
		}                                   \
	} while (0)
#else
#define MYLOG(...)
#endif
#endif
#ifdef ARDUINO_ARCH_RP2040
#if MY_DEBUG > 0
#define MYLOG(tag, ...)                  \
	do                                   \
	{                                    \
		if (tag)                         \
			Serial.printf("[%s] ", tag); \
		Serial.printf(__VA_ARGS__);      \
		Serial.printf("\n");             \
	} while (0)
#else
#define MYLOG(...)
#endif
#endif

/** Define the version of your SW */
#define SW_VERSION_1 1 // major version increase on API change / not backwards compatible
#define SW_VERSION_2 0 // minor version increase on API change / backward compatible
#define SW_VERSION_3 0 // patch version increase on bugfix, no affect on API
