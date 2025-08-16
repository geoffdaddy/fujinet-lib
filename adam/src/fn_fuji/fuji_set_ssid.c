#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_set_ssid(NetConfig *nc)
{
  unsigned char c[98]={FUJICMD_SET_SSID};

  memcpy(&c[1],nc,sizeof(NetConfig));

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  return true;
}

