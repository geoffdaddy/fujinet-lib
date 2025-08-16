#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include <eos.h>
#include "response.h"


bool fuji_get_device_enabled_status(uint8_t d)
{
  struct
  {
    unsigned char cmd;
    unsigned char dev;
  } ds;

  ds.cmd = FUJICMD_DEVICE_ENABLE_STATUS; // Get Device status
  ds.dev = d;

  eos_write_character_device(FUJI_DEV,ds,sizeof(ds));
  eos_read_character_device(FUJI_DEV,response,sizeof(response));

  if (response[0])
    return true;
  else
    return false;

}
