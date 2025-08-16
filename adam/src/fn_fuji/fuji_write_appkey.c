#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include "fujinet-network-adam.h"
#include <eos.h>

extern enum AppKeySize fn_adam_keysize;

bool fuji_write_appkey(uint8_t key_id, uint16_t count, uint8_t *data)
{
  unsigned char r=0;

  struct
  {
    unsigned char cmd;
    unsigned short creator;
    unsigned char app;
    unsigned char key;
    char data[64];
  } a;

  a.cmd = FUJICMD_WRITE_APPKEY;
  a.creator = fn_adam_creator_id;
  a.app = fn_adam_app_id;
  a.key = key_id;
  strncpy(a.data,data,sizeof(a.data));

  r = eos_write_character_device(FUJI_DEV,(unsigned char *)a,sizeof(a));
  return r > 80 ? false : true;
}

