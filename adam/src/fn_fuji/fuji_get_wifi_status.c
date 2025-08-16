#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <eos.h>
#include "fujinet-fuji.h"
#include "response.h"

bool fuji_get_wifi_status(uint8_t *status)
{
  unsigned char c=FUJICMD_GET_WIFISTATUS;

  sleep(1);
  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  eos_read_character_device(FUJI_DEV,response,sizeof(response));

  *status = response[0];

  return true;
}
