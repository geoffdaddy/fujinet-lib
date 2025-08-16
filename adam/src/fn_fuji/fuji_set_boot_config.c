#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_set_boot_config(uint8_t toggle)
{
  char c[2]={FUJICMD_CONFIG_BOOT,0x00};
  c[1]=toggle;

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  return true;
}
