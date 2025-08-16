#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_get_adapter_config(AdapterConfig *ac)
{
  unsigned char c=FUJICMD_GET_ADAPTERCONFIG;

  io_command_and_response(&c,1);
  memcpy(ac,response,sizeof(AdapterConfig));
  return true;
}
