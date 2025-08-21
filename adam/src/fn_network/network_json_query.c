/**
 * @brief   Return proper unit # for adamnet.
 * @author  Geoff Oltmans
 * @email   oltmansg at gmail dot com
 * @license gpl v. 3, see LICENSE for details.
 * @verbose ---
 * @param devicespec The Device Specification "N:..."
 * @return AdamNet unit number.
 */

#include <stdint.h>
#include "fujinet-network.h"
#include <stdio.h>

int16_t network_json_query(const char *devicespec, const char *query, char *s)
{
  char q[256];
  char r=ACK;
  uint8_t err = 0;
  uint8_t u = network_unit_adamnet(devicespec);

  if (!u) {
    return -FN_ERR_NO_DEVICE;
  }

  memset(response,0,sizeof(response));
  memset(q,0,sizeof(q));
  q[0] = 'Q';
  strncat(q,query,sizeof(q));

while (1)
{
  err = eos_write_character_device(u,q,sizeof(q));

	if (err == ADAMNET_TIMEOUT)
	continue;
	else if (err == ADAMNET_OK)
	break;  
//   return FN_ERR_OK;
	else
	return -FN_ERR_IO_ERROR;
}

//get the length somehow
  return r;
}
