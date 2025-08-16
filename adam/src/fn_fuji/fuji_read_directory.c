#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include <eos.h>
#include "response.h"

bool fuji_read_directory(uint8_t maxlen, uint8_t aux2, char *buffer)
{
  unsigned char c[3]={FUJICMD_READ_DIR_ENTRY,0x00,0x00};
  c[1]=maxlen;
  c[2]=aux2;
  
  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  eos_read_character_device(FUJI_DEV,buffer,maxlen);

  return true;
}
