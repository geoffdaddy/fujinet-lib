#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_get_device_filename(uint8_t ds, char *buffer)
{
	char c[2]={FUJICMD_GET_DEVICE_FULLPATH,0x00};
	c[1] = ds;

	eos_write_character_device(FUJI_DEV,c,sizeof(c));
	eos_read_character_device(FUJI_DEV,buffer,256);

	return true;
}
