#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <strings.h>
#include "validaciones.h"
#include "estructuras.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"

void ordenarPorNombreYApellido(EPersona arrayPersona[], int cantidad)
{
    int i,j,k;
    int flag;
    comprimirArrayPersonas(arrayPersona,cantidad,1);
    EPersona auxiliarPersona;
    for(i=0; i<cantidad; i++)
    {
        if(arrayPersona[i].isEmpty==1)
        {
            break;
        }
        flag=0;
        auxiliarPersona = arrayPersona[i];
        for(j=i; j > 0 && stricmp(auxiliarPersona.nombre,arrayPersona[j-1].nombre)<=0 ; j--)
        {
            if(stricmp(auxiliarPersona.nombre,arrayPersona[j-1].nombre)<0)
            {
                flag=1;
                continue;
            }
            else if((stricmp(auxiliarPersona.nombre,arrayPersona[j-1].nombre))==0)
            {
                if(stricmp(auxiliarPersona.apellido,arrayPersona[j-1].apellido)>0)
                {
                    flag=1;
                }
                else if((stricmp(auxiliarPersona.apellido,arrayPersona[j-1].apellido)<0))
                {
                    break;
                }
            }


        }
        if(flag==1)
        {
            for(k=i; k>j; k--)
            {
                arrayPersona[k]=arrayPersona[k-1];
            }
            arrayPersona[j]=auxiliarPersona;
        }

    }
}



void comprimirArrayPersonas (EPersona arrayPersonas[],int cantidad, int banderaLibre)
{
    int i;
    for (i=0 ; i<cantidad; i++)
    {
        if(arrayPersonas[i].isEmpty==banderaLibre)
        {
            for(; i<cantidad-1; i++)
            {
                arrayPersonas[i]=arrayPersonas[i+1];
            }
            arrayPersonas[cantidad-1].isEmpty=banderaLibre;
        }
    }
}

int sortEmployeeByName(EPersona pEmployee[], int length, int order)
{
    /** order==1 es descendente y order==0 es ascendente**/
    int i,retorno = -1,flagSwap;
    EPersona auxiliar;

    if(pEmployee != NULL && length > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<length-1; i++)
            {
                if(strcmp(pEmployee[i].nombre,pEmployee[i+1].nombre)> 0 && order == 1 )
                {
                    auxiliar = pEmployee[i];
                    pEmployee[i] = pEmployee[i+1];
                    pEmployee[i+1] = auxiliar;
                    flagSwap = 1;
                }
                else if (strcmp(pEmployee[i].nombre,pEmployee[i+1].nombre)< 0 && order == 0 )
                {
                    auxiliar = pEmployee[i];
                    pEmployee[i] = pEmployee[i+1];
                    pEmployee[i+1] = auxiliar;
                    flagSwap = 1;
                }


            }


        }
        while(flagSwap);

    }
    return retorno;
}

void ordenarPorNombreYComprimir (EPersona arrayPersona[], int cantidad)
{
    /**Esta funcion primero comprime eel array y luego valida los espacios vacios**/
    comprimirArrayPersonas(arrayPersona,cantidad,0);
    int i,j;
    EPersona auxiliarPersona;
    for(i=0; i<cantidad; i++)
    {
        if(arrayPersona[i].isEmpty==1)
        {
            continue;
        }
        auxiliarPersona = arrayPersona[i];
        j=i;
        for( ; j>0 && stricmp(auxiliarPersona.nombre,arrayPersona[j-1].nombre)<0 ; j--)
        {
            if(arrayPersona[j].isEmpty==1)
            {
                continue;
            }
            arrayPersona[j]=arrayPersona[j-1];
        }
        arrayPersona[j]=auxiliarPersona;
    }
}

//-------------------------------------------------------------------------

int sortEmployeeByNameAndLastname(EPersona listaAfiliados[], int length, int order)
{
    /** order==1 es descendente y order==0 es ascendente**/
    int i;
    int retorno = -1;
    int flagSwap;
    EPersona auxiliar;

    if(listaAfiliados != NULL && length > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<length-1; i++)
            {
                if(strcmp(listaAfiliados[i].nombre,listaAfiliados[i+1].nombre)>0 && order == 1 )
                {
                    auxiliar = listaAfiliados[i];
                    listaAfiliados[i] = listaAfiliados[i+1];
                    listaAfiliados[i+1] = auxiliar;
                    flagSwap = 1;
                }
                else
                {
                    if(strcmp(listaAfiliados[i].nombre,listaAfiliados[i+1].nombre)==0)
                    {
                        flagSwap= 0;
                        if(strcmp(listaAfiliados[i].apellido,listaAfiliados[i+1].apellido)> 0 && order == 1 )
                        {
                            auxiliar = listaAfiliados[i];
                            listaAfiliados[i] = listaAfiliados[i+1];
                            listaAfiliados[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
                }

                if(strcmp(listaAfiliados[i].nombre,listaAfiliados[i+1].nombre)<0 && order == 0 )
                {
                    auxiliar = listaAfiliados[i];
                    listaAfiliados[i] = listaAfiliados[i+1];
                    listaAfiliados[i+1] = auxiliar;
                    flagSwap = 1;
                }
                else
                {
                    if(strcmp(listaAfiliados[i].nombre,listaAfiliados[i+1].nombre)==0)
                    {
                        flagSwap= 0;
                        if(strcmp(listaAfiliados[i].apellido,listaAfiliados[i+1].apellido)< 0 && order == 0 )
                        {
                            auxiliar = listaAfiliados[i];
                            listaAfiliados[i] = listaAfiliados[i+1];
                            listaAfiliados[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
                }
            }

        }
        while(flagSwap);
    }
    return retorno;
}


void graficoEdad(EPersona listaAfiliados[],int cantidad)
{
    int contMenos18=0;
    int contEntre18y35=0;
    int contMas35=0;
    int i;
    int edad;

    for(i=0; i<cantidad; i++)
    {
        if(listaAfiliados[i].isEmpty==0)
        {


            edad=atoi(listaAfiliados[i].edad);
            if(edad<=18)
            {
                contMenos18++;
            }
            else if(edad>18 && edad<35)
            {
                contEntre18y35++;
            }
            else
            {
                contMas35++;
            }
        }
    }
    for(i=cantidad; i>0; i--)
    {
        if(!(contEntre18y35<i&&contMas35<i &&contMenos18<i))
        {
            if(i==contMenos18)
            {
                printf("\n*\t");
            }
            else
            {
                printf("\n \t");
            }

            if(i==contEntre18y35)
            {
                printf("*\t");
                contEntre18y35--;
            }
            else
            {
                printf("\t");
            }
            if(i==contMas35)
            {
                printf("*\n");
                contMas35--;
            }
            else
                printf("\n");

        }

    }
    printf("\n<18\t19-35\t>35\n");
}
