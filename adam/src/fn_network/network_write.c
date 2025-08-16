#include <stdbool.h>
#include <stdint.h>
#include <eos.h>
#include "fujinet-network.h"
#include "fujinet-network-adam.h"
#include <stdio.h>

uint8_t network_write(const char *devicespec, const uint8_t *buf, uint16_t len)
{
    uint16_t send_len;
    unsigned char w[1025] = {'W'};

    uint8_t u = network_unit_adamnet(devicespec);

    if (!u) {
        return FN_ERR_NO_DEVICE;
    }    
    
    while (len)
    {
        send_len = (len > 1024) ? 1024 : len;
        memcpy(&w[1],buf,send_len);
        len -= send_len;

        if (eos_write_character_device(u,w,send_len + 1) != ADAMNET_OK) {
           return FN_ERR_IO_ERROR;
        }
    }

    return FN_ERR_OK;
}
