#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_put_host_slots(HostSlot *h, size_t size)
{
  unsigned char c[257]={FUJICMD_WRITE_HOST_SLOTS};

  memcpy(&c[1],h,256);

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));

  return true;
}

