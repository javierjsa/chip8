#include "chip8.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

void draw(void);
void debug(chip8 *chip);
int main(int argc, char *argv[]){

   /* glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutInitWindowPosition(50,25);
    glutInitWindowSize(128,64);
    glutCreateWindow("Chip8");
    glutDisplayFunc(draw);
    glutMainLoop();*/


    chip8 chip;

    initialize(&chip);  
    if(argc==2){
       int res=loadGame(&chip,argv[1]);
       debug(&chip);
    }

    for(;;){
        emulateCycle(&chip);
        if(chip.drawFlag==1)
            drawGraphics(&chip);
        }
    
return 0;

}

void draw(void) {
    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //Draw i
    glFlush();
}

void debug(chip8 *chip){
    int i=0;
    for(i=0;i<4096;i++){
        printf("%x",(*chip).mem[i]);
        }
    for(i=0;i<15;i++){
        printf("%d",(*chip).registros[i].val);
        }
}    



