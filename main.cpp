/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <windows.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>


/* GLUT callback Handlers */

int posx = 300;

void Desenha (void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void Inicializa (void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Teclado (unsigned char tecla, int x, int y) {
    switch(tecla){
        case 27 : printf("Tchau!");
                  exit(0);
        case 'a': glutFullScreen();
                  break;
        case 's': glutReshapeWindow(100,100);
                  glutPositionWindow(500,500);
                  break;
        default : printf("Voce apertou [%c]\n", tecla);
    }
}
void TeclasEspeciais (int tecla, int x, int y) {
    switch(tecla){
        case GLUT_KEY_F1: printf("Voce apertou f1\n");
                break;
        case GLUT_KEY_LEFT:
                if (posx > 50) posx-=50;
                glutPositionWindow(posx, 300);
                break;
        case GLUT_KEY_RIGHT:
                if (posx < 500) posx += 500;
                glutPositionWindow(posx, 300);
                break;
        default: printf("Voce apertou outra tecla especial [%d]\n", tecla);
    }
}

void GerenciaMouse (int button, int state, int x, int y){
    if (state == GLUT_DOWN)
        printf("Botao %d apertado\n", button);
    else
        printf("Botao %d liberado\n", button);
}
void movimentoMouseBotaoApertado (int x, int y) {
    printf("Botao Apertado [%d, %d]\n",x ,y);
}
void movimentoMouse (int x, int y) {
    printf("[%d, %d]\n", x, y);
}

void ocioso(void){
    printf(".");
}


void menuCor (int op) {
    switch(op){
        case 0: glClearColor(1.0f, 0.0f, 0.0f, 1.0f); break;
        case 1: glClearColor(0.0f, 1.0f, 0.0f, 1.0f); break;
        case 2: glClearColor(0.0f, 0.0f, 1.0f, 1.0f); break;
        default: glClearColor(0.0f, 0.0f, 0.0f, 1.0f); break;
    }
    glutPostRedisplay();
}

void criaMenu(){
    int menu = glutCreateMenu(menuCor);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Preto", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main (void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    Inicializa();
    glutCreateWindow("Primeiro Progrma - TECLADO");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(TeclasEspeciais);
    glutMouseFunc(GerenciaMouse);
    glutMotionFunc(movimentoMouseBotaoApertado);
    glutPassiveMotionFunc(movimentoMouse);
    //glutIdleFunc(ocioso);
    criaMenu();
    glutMainLoop();
}
