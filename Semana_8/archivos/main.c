#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIVO ".\\alumnos.csv"
#define REDUNDANCIA 10
typedef struct
{
    char nombre [51];
    int legajo;
    int nota;
    int estado;
} ePersona;
ePersona* newPersona ();
void getName (ePersona* per);
void getNota (ePersona* per);
void getlegajo (ePersona* per);
ePersona* hCodedPersona ();
ePersona** nuevaLista ();

int main()
{
    ePersona** lista = nuevaLista();
    printf("%d\n", sizeof(lista));
    //ePersona** listaPersonas = malloc(sizeof(ePersona*)*100);
    FILE* pArchivo;
    //ePersona* per1 = hCodedPersona();
    if ( (pArchivo = fopen(ARCHIVO,"r")) == NULL)
    {
        printf("\nNo se pudo abrir");
        exit(1);
    }
    else
    {
        char renglon [233];
        int datosLeidos;
        printf("\nSe abrio e archivo\n\n");
        while( !feof(pArchivo) )
        {
            datosLeidos = fread (renglon,sizeof(char),232,pArchivo);
            printf("cantidad: %d  \nTexto:\n %s \n",datosLeidos,renglon);
        }
        //char texto[] = "lalala;100;10;1;\nlelele;200;20;1\n";
        //fwrite(texto,sizeof(char),strlen(texto),pArchivo);
    }
    fclose(pArchivo);
    //printf("%p\n\n", pPersonasFILE);
    system("pause");
    return 0;
}
ePersona* newPersona ()
{
    ePersona* retPersona = (ePersona*) malloc(sizeof(ePersona));
    if (retPersona!=NULL)
    {
        getName(retPersona);
        getNota(retPersona);
        getlegajo(retPersona);
        retPersona->estado = 1;
    }
    return retPersona;
}
void getName (ePersona* per)
{
    if (per != NULL)
    {
        printf("\nIngrese el nombre: ");
        gets(per->nombre);
        printf("\n");
        system("pause");
    }
}
void getNota (ePersona* per)
{
    if (per!=NULL)
    {
        printf("\nIngrese la nota: ");
        scanf("%d",&(per->nota));
        printf("\n");
        system("pause");
    }
}
void getlegajo (ePersona* per)
{
    if (per!=NULL)
    {
        printf("\nIngrese el legajo: ");
        scanf("%d",&(per->legajo));
        printf("\n");
        system("pause");
    }
}
ePersona* hCodedPersona ()
{
    ePersona* retPer = (ePersona*) malloc(sizeof(retPer));
    retPer->estado = 1;
    retPer->legajo = 100;
    retPer->nota = 10;
    strcpy(retPer->nombre, "juan");
    return retPer;
}
ePersona** parserPersonas (FILE* dataFile)
{
    if (dataFile!=NULL)
    {
        ePersona** listaPersonas = nuevaLista();
        if (listaPersonas != NULL)
        {
            int i = 0;
            char auxLegajo [51];
            char auxNota [51];
            char auxEstado [51];
            while(!feof(dataFile))
            {
                ePersona* per = newPersona;
                fscanf(dataFile, "%[^;],%[^;],%[^;],%[^\n]\n", &(per->nombre) , auxLegajo , auxNota , auxEstado );
                per->legajo = atoi(auxLegajo);
                per->nota = atoi(auxNota);
                per->estado = atoi(auxEstado);
                listaPersonas[i] = per;
                i++;

            }
        }



    }
}
ePersona** nuevaLista ()
{
    ePersona** listaPersonas = (ePersona**) malloc(sizeof(ePersona*)*REDUNDANCIA);
    return listaPersonas;
}
ePersona* nuevaPersona ()
{
    ePersona* per = (ePersona*) malloc(sizeof(ePersona));
    return ePersona;
}
/*char* getDatosArchivo (FILE* dataFile)
{
    char* savedData;
    if (dataFile != NULL)
    {
        int datosLeidos;
        int i = 0;
        savedData = (char*) malloc (sizeof(char)* REDUNDANCIA);
        while(!feof(dataFile))
        {
            datosLeidos = fread(savedData[i],sizeof(char),1,dataFile);
            i++;
            if (i >= (sizeof(savedData)-1) )
            {
                char* aux = (char*) realloc(savedData,(sizeof(savedData))+(sizeof(char)*REDUNDANCIA) );
                if ( aux != NULL )
                {
                    savedData = aux;
                }
            }
        }
        datosLeidos[i] = '\0';
        fclose(dataFile);
    }
    return savedData;
}*/
/*ePersona** char_To_ePersona (char* data)
{
    int i;
    char auxName [51];
    char
    for ( i=0 ; i < strlen(data) ; i++ )
    {

    }
}*/

