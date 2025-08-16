#include <stdint.h>
#include "response.h"
#include <eos.h>
#include "fujinet-network.h"
#include <stdlib.h>
#include <string.h>
#include "fujinet-network-adam.h"
#include "stdio.h"
#include "response.h"

unsigned char debug_buf[32];

int16_t network_read_adam(char* devicespec, uint8_t *buf, uint16_t len)
{
  uint8_t u = network_unit_adamnet(devicespec);


  if (!u) {
    return FN_ERR_BAD_CMD;
  }

  DCB *dcb = eos_find_dcb(u); // Replace with net device

  if (eos_read_character_device(u,response,1024) == 0x80)
  {
    memcpy(buf,response,dcb->len);
    return FN_ERR_OK;
  }

  return FN_ERR_IO_ERROR;
}
