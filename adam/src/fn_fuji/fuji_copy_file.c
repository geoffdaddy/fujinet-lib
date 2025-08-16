#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include <eos.h>

bool fuji_copy_file(uint8_t src_slot, uint8_t dst_slot, char *copy_spec)
{
  char cf[259]={FUJICMD_COPY_FILE,0x00,0x00};
  DCB *dcb = NULL;
  
  cf[1]=src_slot;
  cf[2]=dst_slot;
  strcpy(&cf[3],copy_spec);

  eos_write_character_device(FUJI_DEV,cf,sizeof(cf));

  while (eos_request_device_status(FUJI_DEV,dcb) != 0x80);
  return true;
}
