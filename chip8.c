#include "chip8.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
/*
typedef enum {

	V0,V1,V2,V3,V4,V5,V6,V7,V8,V9,VA,VB,VC,VD,VE,VF
}nom;

typedef struct {
	nom R;
	DOS_BYTES val;
}reg;

typedef struct {

    reg registros[16];
    DOS_BYTES mem[4096];    			
    DOS_BYTES index;
    DOS_BYTES pc;	
    DOS_BYTES stack[16];
    DOS_BYTES sp;

}chip8;
*/



void initialize (chip8 *chip){
    printf("initialize\n");
    fflush(stdout);
	int i;
    
	for(i=0; i<4096;i++){
		(*chip).mem[i]=0;
        }
    for(i=i;i<15;++i){
        (*chip).registros[i].val=0;
        (*chip).stack[i]=0;
        }
    (*chip).index=0;
    (*chip).pc=0;
    (*chip).sp=0;
    (*chip).drawFlag=0;
}

int loadGame (chip8 *chip, char *name){
    printf("loadGame\n");
    fflush(stdout);    
    FILE *fichero;    
    fichero=fopen(name,"r+");
    if(fichero==NULL){
        printf("Error al abrir el fichero. %s\n",strerror(errno));
        return 1;
    }else{              
        fseek(fichero, 0, SEEK_END);
        long fsize = ftell(fichero);        
        fseek(fichero, 0, SEEK_SET); 
        fread(chip->mem+512,1,fsize,fichero);
        printf("Archivo leído: %s\n",name);
        printf("Tamaño %ld\n",fsize); 
        fflush(stdout);    
        fclose(fichero);       
        return 0;
        
    }
}
void drawGraphics(chip8 *chip){
//TODO
}

void emulateCycle(chip8 *chip){
}

