#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_set_directory_position(uint16_t pos)
{
  unsigned char c[3]={FUJICMD_SET_DIRECTORY_POSITION,0x00,0x00};

  memcpy(&c[1],&pos,sizeof(pos));

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  return true;
}
