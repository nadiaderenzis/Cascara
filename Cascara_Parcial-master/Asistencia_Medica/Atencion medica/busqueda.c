#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANTPERS 20
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "busqueda.h"

int obtenerIndicePorId(EPersona listaPersonas[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdUsuario(listaPersonas,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}


int obtenerIndiceLlamadaPorId(ELlamadas listaLlamadas[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdLlamadas(listaLlamadas,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}

int buscarPorDni(EPersona lista[], int cantidad,char dni[])
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(lista[i].dni,dni)==0)
            return i;
    }
    return -1;
}


int obtenerEspacioLibreLlamadas(ELlamadas lista[], int cantidad_elementos, int estado)
{
    int i;
    int retorno=-1;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].isEmpty==estado)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad_elementos, int estado)
{
    int i;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].isEmpty==estado)
        {
            return i;
        }
    }
    return -1;
}


int usuarioConMayorCantidadDeLlamadas (ELlamadas listaLlamadas[],int cantComent,EPersona listaUsuar[],int cantUsuar,int usuarConMasMensajes[])
{
    int retorno=0;
    int maximo=0;
    int contador;
    int i;
    int j;
    int k=0;
    inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
    for(i=0; i<cantUsuar; i++)
    {
        if(listaUsuar[i].isEmpty==1)
        {
            continue;
        }
        contador=0;
        for(j=0; j<cantComent; j++)
        {
            if(listaLlamadas[j].isEmpty==0 && listaLlamadas[j].idUsuario==listaUsuar[i].id)
            {
                contador++;

            }
        }
        if(contador>maximo)
        {
            k=0;
            inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
            usuarConMasMensajes[k]=i;
            maximo=contador;
            retorno = 1;

        }
        else if(contador==maximo)
        {
            k++;
            usuarConMasMensajes[k]=i;
        }

    }
    return retorno;
}

int buscarPorIdLlamadas(ELlamadas lista[], int cantidad,int idComentario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idComentario==lista[i].id) && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void motivoMasRepetido (ELlamadas lista[],int cantidad,EMotivo motivo[],int motivosMasRepetidos[])
{
    int contador[3]= {0,0,0};
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0)
        {
            if(strcmp(lista[i].motivo,motivo[0].tipo)==0)
            {
                contador[0]++;
            }
            else if(strcmp(lista[i].motivo,motivo[1].tipo)==0)
            {
                contador[1]++;
            }
            else
            {
                contador[2]++;
            }
        }
    }

    for(i=0; i<3; i++)
    {
        if(contador[i]>maximo)
        {
            inicializarArrayDeIndices(motivosMasRepetidos,3,0);
            motivosMasRepetidos[i]=1;
            maximo=contador[i];
        }
        else if(contador[i]==maximo)
        {
            motivosMasRepetidos[i]=1;
        }
    }
}

void motivoMasDemoraEnPromedio (ELlamadas lista[],int cantidad,EMotivo motivo[],int motivosMasDemorados[])
{
    int contador[3]= {0,0,0};
    int acumulador[3]= {0,0,0};
    int promedio[3]= {0,0,0};
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0 && (stricmp(lista[i].estado,"CUMPLIDO")==0))
        {
            if(strcmp(lista[i].motivo,motivo[0].tipo)==0)
            {
                contador[0]++;
                acumulador[0]=acumulador[0]+lista[i].duracion;

            }
            else if(strcmp(lista[i].motivo,motivo[1].tipo)==0)
            {
                contador[1]++;
                acumulador[1]=acumulador[1]+lista[i].duracion;
            }
            else
            {
                contador[2]++;
                acumulador[2]=acumulador[2]+lista[i].duracion;
            }
        }
    }
    for(i=0; i<3; i++)
    {
        if(contador[i]>0)
        {
            promedio[i]=(acumulador[i]/contador[i]);
        }

    }


    for(i=0; i<3; i++)
    {
        if(promedio[i]>maximo)
        {
            inicializarArrayDeIndices(motivosMasDemorados,3,0);
        motivosMasDemorados[i]=1;
            maximo=promedio[i];

        }
        else if(promedio[i]==maximo)
        {
            motivosMasDemorados[i]=1;
        }
    }
}


int usuarioConMayorCantidadDeComentarios (ELlamadas listaComent[],int cantComent,EPersona listaUsuar[],int cantUsuar,int usuarConMasMensajes[])
{
    int retorno=0;
    int maximo=0;
    int contador;
    int i;
    int j;
    int k=0;
    inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
    for(i=0; i<cantUsuar; i++)
    {
        if(listaUsuar[i].isEmpty==1)
        {
            continue;
        }
        contador=0;
        for(j=0; j<cantComent; j++)
        {
            if(listaComent[j].isEmpty==0 && listaComent[j].idUsuario==listaUsuar[i].id)
            {
                contador++;

            }
        }
        if(contador>maximo)
        {
            k=0;
            inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
            usuarConMasMensajes[k]=i;
            maximo=contador;
            retorno = 1;

        }
        else if(contador==maximo)
        {
            k++;
            usuarConMasMensajes[k]=i;
        }

    }
    return retorno;
}

int buscarPorIdUsuario(EPersona lista[], int cantidad,int idUsuario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idUsuario==lista[i].id) && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}




