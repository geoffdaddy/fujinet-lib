#include <stdbool.h>
#include <stdint.h>
#include "fujinet-fuji.h"
#include <stdlib.h>
#include <string.h>

bool fuji_open_directory(uint8_t hs, char *path_filter)
{
	// void io_open_directory(unsigned char hs, char *p, char *f)
	// {
	  char c[258];
	  char *e;
	
	  memset(&c,0,258);
	  c[0]=FUJICMD_OPEN_DIRECTORY;
	  c[1]=hs;
	  strcpy(&c[2],path_filter);
	  e=&c[2];
	
	//   if (f[0]!=0x00)
	// 	{
	// 	  while (*e != 0x00)
	// 	e++;
	
	// 	  e++;
	// 	  strcpy(e,f);
	// 	}
	
	  eos_write_character_device(FUJI_DEV,&c,sizeof(c));
	// }
	return true;
}