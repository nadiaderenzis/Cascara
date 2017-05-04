#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <strings.h>
#include "validaciones.h"
#include "estructuras.h"
#include "cargaYEdicion.h"
#include "busqueda.h"

int getInt(char mensaje[])
{
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    return entero;
}

float getFloat(char mensaje[])
{
    float flotante;
    printf("%s",mensaje);
    scanf("%f",&flotante);
    return flotante;
}
char getChar(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin); // Win
    // fpurge(stdin); //Linux y OSx
    scanf("%c",&caracter);
    return caracter;
}

int getNumeroAleatorio(int desde, int hasta, int iniciar)/////////////////////////////
{
    /***chequear**/
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

void getString(char mensaje[],char arrayChar[])
{
    printf("%s",mensaje);
    scanf("%s",arrayChar);
}

int getNumerosChar (char array[],char mensaje[])
{
    getString(mensaje,array);
    if(esNumeroChar(array))
    {
        return 1;
    }
    return 0;
}
/**
* \brief Solicita un texto al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param input Array donde se cargará el texto ingresado
* \return 1 si el texto contiene solo letras
*/
int getStringLetras(char mensaje[],char input[])
{
    getString(mensaje,input);
    if(esSoloLetras(input))
    {
        return 1;
    }
    return 0;
}


void inicializarListaDePersonas(EPersona lista[],int cantidad,int estado)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lista[i].isEmpty=estado;
    }
}


void inicializarListaDeLlamadas(ELlamadas lista[],int cantidad,int estado)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lista[i].isEmpty=estado;
    }
}

int ingresarSoloLetras (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[])
{
    char seguir='s';
    int cargaExitosa;
    do
    {
        cargaExitosa=getStringLetras(mensajeParaPedirDato,auxiliar);
        if(!(cargaExitosa))
        {
            printf(mensajeError);// Ejemplo "Ha ingresado caracteres invalidos para un nombre.\n"
            seguir=getChar("Desea reintentar? s/n");
        }
    }
    while(cargaExitosa!=1 && seguir == 's');
    return cargaExitosa;
}

int cargarDNI (EPersona lista[],int cant,char auxiliar[], char mensajeParaPedirDato[],char mensajeError[])
{
    char seguir='s';
    int indiceDniRepetido;
    int retorno=0;
    int cargaExitosa;
    do
    {
        cargaExitosa=getNumerosChar(auxiliar,mensajeParaPedirDato);
        if(!(cargaExitosa) || (strlen(auxiliar)!=8))
        {
            printf(mensajeError);  // Ejemplo "Ha ingresado caracteres invalidos para un nombre.\n"
            seguir=getChar("Desea reintentar? s/n");
            continue;
        }
        indiceDniRepetido=buscarPorDni(lista,cant,auxiliar);
        if(indiceDniRepetido==-1)
        {
            retorno = 1;
        }
        else
        {
            printf("Este DNI se encuentra ingresado en el sistema.");
            seguir=getChar("Desea reintentar? s/n");
        }

    }
    while(retorno!=1 && seguir == 's');

    return retorno;
}

int cargarEdad (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[])
{
    char seguir='s';
    int retorno=0;
    int cargaExitosa;
    do
    {

        cargaExitosa=getNumerosChar(auxiliar,mensajeParaPedirDato);
        if(!(cargaExitosa) || (atoi(auxiliar)>100))
            {
            printf(mensajeError);  // Ejemplo "Ha ingresado caracteres invalidos para un nombre.\n"
            seguir=getChar("Desea reintentar? s/n");
            continue;
            }
            else
            {
            retorno = 1;
            }
    }while(retorno!=1 && seguir == 's');
    return retorno;
}

int cargarNumero (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[],int minimo, int maximo)
{
    char seguir='s';
    int retorno=0;
    int cargaExitosa;
    do
    {

        cargaExitosa=getNumerosChar(auxiliar,mensajeParaPedirDato);
        if(!(cargaExitosa) || (atoi(auxiliar)>maximo) || (atoi(auxiliar)<minimo))
            {
            printf(mensajeError);  // Ejemplo "Ha ingresado caracteres invalidos para un nombre.\n"
            seguir=getChar("Desea reintentar? s/n");
            continue;
            }
            else
            {
            retorno = 1;
            }


    }while(retorno!=1 && seguir == 's');

    return retorno;
}


int motivoLlamada(ELlamadas listaLlamadas[],int cantidadLlamadas,int indice)
{
    char opcion;
    int retorno=0;
    opcion=getChar("Ingrese la opcion a modificar, \n\n 1-ACV.\n 2-INFARO.\n3-GRIPE.\n");
    switch(opcion)
    {
    case '1':
            strcpy(listaLlamadas[indice].motivo,"ACV");
            retorno =1;
        break;
    case '2':
            strcpy(listaLlamadas[indice].motivo,"INFARTO");
            retorno =1;
        break;
    case '3':
            strcpy(listaLlamadas[indice].motivo,"GRIPE");
            retorno =1;
        break;
    default :
        printf("Error. Opcion incorrecta.");
        break;
    }
    return retorno;
}

void inicializarArrayDeIndices (int array[],int cantidad,int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        array[i]=valor;
    }
}


