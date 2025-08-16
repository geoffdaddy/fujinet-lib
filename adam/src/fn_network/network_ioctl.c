#include <stdbool.h>
#include <stdint.h>
#include "fujinet-network.h"
#include <stdio.h>

uint8_t network_ioctl(uint8_t cmd, uint8_t aux1, uint8_t aux2, const char* devicespec, ...)
{
	printf("network_ioctl");
	return 0;
}
