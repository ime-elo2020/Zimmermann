#include "utils/commandline.h"

extern CommandLine cmdline;
extern int estado;

uint16_t cmd_pisca(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	if(argc==1){
		size+=sprintf(buffer+size, "USB do Zimmermann\r\n");
		estado = estado^1;
	} else {
		size+=sprintf(buffer+size, "Sintaxe: pisca\r\n");
	}
	return size;
}


CommandLine cmdline({"pisca"},
					{cmd_pisca});

