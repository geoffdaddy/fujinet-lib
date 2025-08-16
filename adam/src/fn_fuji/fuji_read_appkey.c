#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include "fujinet-network-adam.h"
#include <eos.h>

uint16_t fn_adam_creator_id;
uint8_t fn_adam_app_id;
enum AppKeySize fn_adam_keysize;

bool fuji_read_appkey(uint8_t key_id, uint16_t *count, uint8_t *data)
{
  unsigned char r=0;
  DCB *dcb = 0;

  struct
  {
    unsigned char cmd;
    unsigned short creator;
    unsigned char app;
    unsigned char key;
    char data[64];
  } a;
  
  a.cmd = FUJICMD_READ_APPKEY;
  a.creator = fn_adam_creator_id;
  a.app = fn_adam_app_id;
  a.key = key_id;

  r=eos_write_character_device(FUJI_DEV,(unsigned char *)a,sizeof(a));
  if (r > 0x80)
    return false;
  else
  {
    dcb = eos_find_dcb(FUJI_DEV); // Replace with net device
    unsigned char r=eos_read_character_device(FUJI_DEV,data,MAX_APPKEY_LEN);
    
    if (r == 0x80)
      {
        *count = dcb->len;
        return true;
      }
    else
      return false;
  }
}

