#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"

bool fuji_close_directory()
{
	unsigned char c=FUJICMD_CLOSE_DIRECTORY;

	eos_write_character_device(FUJI_DEV,&c,sizeof(c));
}
