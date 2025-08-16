#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include <eos.h>

bool fuji_mount_disk_image(uint8_t ds, uint8_t mode)
{
	char c[3]={FUJICMD_MOUNT_IMAGE,0x00,0x00};
	c[1]=ds;
	c[2]=mode;

	eos_write_character_device(FUJI_DEV,&c,sizeof(c));
	return true;
}
