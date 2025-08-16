#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_enable_device(uint8_t d)
{
  struct
  {
    unsigned char cmd;
    unsigned char dev;
  } ed;

  ed.cmd = FUJICMD_ENABLE_DEVICE;
  ed.dev = d;

  eos_write_character_device(FUJI_DEV,ed,sizeof(ed));
  return true;

}
