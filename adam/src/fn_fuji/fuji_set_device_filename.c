#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include "response.h"

//TODO Geoff
bool fuji_set_device_filename(uint8_t mode, uint8_t hs, uint8_t ds, char *buffer)
{
// 	void io_set_device_filename(unsigned char ds, char* e)
// {
  char c[258]={FUJICMD_SET_DEVICE_FULLPATH,0x00};

  c[1] = ds;

  strcpy(&c[2],buffer);

  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
// }


	return true;
}
