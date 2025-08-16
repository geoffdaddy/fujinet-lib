#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_get_scan_result(uint8_t n, SSIDInfo *ssid_info)
{
  unsigned char c[2]={FUJICMD_GET_SCAN_RESULT,0x00};

  c[1] = n;
  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
  eos_read_character_device(FUJI_DEV,response,sizeof(response));

  memcpy(ssid_info, response, sizeof (SSIDInfo));
  return true;
}

