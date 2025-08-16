#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_get_host_slots(HostSlot *h, size_t size)
{
  unsigned char c=FUJICMD_READ_HOST_SLOTS;

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  eos_read_character_device(FUJI_DEV,response,sizeof(response));

  memcpy(h,response,size);
  return true;
}
