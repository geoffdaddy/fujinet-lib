#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_get_ssid(NetConfig *net_config)
{
  unsigned char c=FUJICMD_GET_SSID;

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  eos_read_character_device(FUJI_DEV,response,sizeof(response));

  memcpy (net_config, response, sizeof(NetConfig));
  return true;
}
