#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include <eos.h>
#include "response.h"

bool fuji_scan_for_networks(uint8_t *count)
{
  unsigned char c=FUJICMD_SCAN_NETWORKS;

  eos_write_character_device(FUJI_DEV,&c,1);
  eos_read_character_device(FUJI_DEV,response,sizeof(response));

  if (count) {
    *count = response[0];
    return true;
  } else 
    return false;
}

