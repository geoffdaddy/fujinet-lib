#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_get_device_slots(DeviceSlot *d, size_t size)
{
	unsigned char c=FUJICMD_READ_DEVICE_SLOTS;

	eos_write_character_device(FUJI_DEV,&c,sizeof(c));

	memcpy(d,response,304);

	return true;
}

