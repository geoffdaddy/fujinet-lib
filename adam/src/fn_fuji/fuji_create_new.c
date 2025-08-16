#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include <string.h>

bool fuji_create_new(NewDisk *new_disk)
{
	char nd[263]={FUJICMD_NEW_DISK,0x00,0x00,0x00,0x00,0x00,0x00};
	char *c = &nd[3];
	unsigned long *l = (unsigned long *)c;

	nd[1]=new_disk->hostSlot;
	nd[2]=new_disk->deviceSlot;
	*l=256; // number of k bytes... hardcode for now...
	strcpy(&nd[7],new_disk->filename);

	eos_write_character_device(FUJI_DEV,&nd,sizeof(nd));
	return true;
}
