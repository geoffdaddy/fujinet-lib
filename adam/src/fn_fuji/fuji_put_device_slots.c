#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_put_device_slots(DeviceSlot *d, size_t size)
{
  unsigned char c[305]={FUJICMD_WRITE_DEVICE_SLOTS};

  memcpy(&c[1],d,size > 304 ? 304 : size);

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  csleep(10);

  return true;
}
