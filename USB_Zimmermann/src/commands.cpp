#include "utils/commandline.h"

extern CommandLine cmdline;
extern int estado;

uint16_t cmd_pisca(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];
	// Esse comentado faz com que alterna entre piscar ou nao apenas com comando "pisca"
	//if(argc==1){
	//	size+=sprintf(buffer+size, "USB do Zimmermann\r\n");
	//	estado = estado^1; //esse xor faz com que alterne entre 0 e 1 cada vez que o comando é enviado
	//}

	if(argc==1){
			size+=sprintf(buffer+size, "USB do Zimmermann, comeca a piscar\r\n");
			estado = 1; //acende quando fala "pisca"
		}
	else if(argc==2){
			size+=sprintf(buffer+size, "USB do Zimmermann, para de piscar\r\n");
			estado = 0; //apaga quando fala "pisca nao" (na verdade apaga se enviar qualquer comando de duas palavras)
		}


	else {
		size+=sprintf(buffer+size, "Sintaxe: pisca\r\n");
	}
	return size;
}



CommandLine cmdline({"pisca"},
					{cmd_pisca});

