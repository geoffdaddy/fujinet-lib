#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_mount_host_slot(uint8_t hs)
{
  unsigned char c[2]={0xF9,0x00};

  c[1] = hs;

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  
  return true;
}


