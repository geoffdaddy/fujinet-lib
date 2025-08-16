#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_unmount_disk_image(uint8_t ds)
{
  char c[2]={FUJICMD_UNMOUNT_IMAGE,0x00};
  c[1]=ds;

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  return true;
}
