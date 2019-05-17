#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
*   hacer:
*   1. funcion cargar enteros
*   2.         mostrar
*   3.         ordenar
*   4.         calcule maximo
*   5.         calcule promedo
*/
int getCharacter (char*);
void printChar(char* character);
int main()
{
    char characterVar;
    uselessFunction(&characterVar);
    printf("\nEl caracter guardado es: %c",characterVar);
    return 0;
}
int getCharacter (char*)
{

}
void printChar (char* character)
{
    char* pCharacter = character;
    printf("Direccion del puntero %p\n",&pCharacter);
    printf("Direccion de la variable %p\n",character);
    printf("Contenido del puntero %p\n\n",pCharacter);
    pCharacter = character;
    printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c",pCharacter);
    printf("\nDireccion del puntero %p\n",&pCharacter);
    printf("Direccion de la variable %p\n",character);
    printf("Contenido del puntero %p\n\n",pCharacter);
}
