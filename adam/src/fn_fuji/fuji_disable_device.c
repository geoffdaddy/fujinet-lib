#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_disable_device(uint8_t d)
{
  struct
  {
    unsigned char cmd;
    unsigned char dev;
  } dd;

  dd.cmd = FUJICMD_DISABLE_DEVICE;
  dd.dev = d;

  eos_write_character_device(FUJI_DEV,dd,sizeof(dd));
  return true;
}
