#ifndef CHIP8
#define CHIP8

#define DOS_BYTES unsigned short


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
    int drawFlag;

}chip8;


void initialize (chip8 *chip);
int loadGame (chip8 *chip, char *name);
void drawGraphics(chip8 *chip);
void emulateCycle(chip8 *chip);

#endif
