#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANTPERS 20
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "lib.h"

#define CANT 1000
#define CANTIDADLLAMADAS 5000


int main()
{
    char seguir='s';
    char opcion='0';
    EPersona listaAfiliados[CANT];
    ELlamadas listaLlamadas[CANTIDADLLAMADAS];
    EMotivo motivos[3];

    int generadorID=0;
    int generadorIdLlamadas=0;
    int generadorIdAmbulancia=0;
    int afiliadosConMasLlamadas[CANT];
    int i;

    inicializarListaDePersonas(listaAfiliados,CANT,1);
    inicializarListaDeLlamadas(listaLlamadas,CANTIDADLLAMADAS,1);
    inicializarArrayDeIndices(afiliadosConMasLlamadas,CANT,-1);
    strcpy(motivos[0].tipo,"INFARTO");
    strcpy(motivos[1].tipo,"ACV");
    strcpy(motivos[2].tipo,"GRIPE");


    //-----------------------------------------------------------------------------------------------------------------
    strcpy(listaAfiliados[0].nombre,"ZZ");
    strcpy(listaAfiliados[0].apellido,"BBB");
    strcpy(listaAfiliados[0].edad,"30");
    listaAfiliados[0].isEmpty=0;
    listaAfiliados[0].id=0;

    strcpy(listaAfiliados[1].nombre,"ZZ");
    strcpy(listaAfiliados[1].apellido,"AAA");
     strcpy(listaAfiliados[1].edad,"19");
    listaAfiliados[1].isEmpty=0;
    listaAfiliados[1].id=1;

    strcpy(listaAfiliados[2].nombre,"AA");
    strcpy(listaAfiliados[2].apellido,"ZZZ");
     strcpy(listaAfiliados[2].edad,"37");
    listaAfiliados[2].isEmpty=0;
    listaAfiliados[2].id=2;

    listaLlamadas[0].duracion=50;
    listaLlamadas[0].id=0;
    listaLlamadas[0].idAmbulancia=0;
    listaLlamadas[0].idUsuario=2;
    strcpy(listaLlamadas[0].motivo,motivos[0].tipo);
    strcpy(listaLlamadas[0].estado,"CUMPLIDO");
    listaLlamadas[0].isEmpty=0;

    listaLlamadas[1].id=1;
    listaLlamadas[1].idUsuario=2;
    strcpy(listaLlamadas[1].motivo,motivos[2].tipo);
    strcpy(listaLlamadas[1].estado,"PENDIENTE");
    listaLlamadas[1].isEmpty=0;

    listaLlamadas[2].duracion=40;
    listaLlamadas[2].id=0;
    listaLlamadas[2].idAmbulancia=0;
    listaLlamadas[2].idUsuario=2;
    strcpy(listaLlamadas[2].motivo,motivos[0].tipo);
    strcpy(listaLlamadas[2].estado,"CUMPLIDO");
    listaLlamadas[2].isEmpty=0;

    listaLlamadas[3].duracion=45;
    listaLlamadas[3].id=0;
    listaLlamadas[3].idAmbulancia=0;
    listaLlamadas[3].idUsuario=2;
    strcpy(listaLlamadas[3].motivo,motivos[1].tipo);
    strcpy(listaLlamadas[3].estado,"CUMPLIDO");
    listaLlamadas[3].isEmpty=0;



//--------------------------------------------------------------------------------

    do
    {

        printf("SERVICIO DE ASISTENCIA MEDICA.\n\n");
        printf("1- ALTA DEL ASOCIADO.\n");
        printf("2- MODIFICAR DATOS DEL ASOCIADO.\n");
        printf("3- BAJA DEL ASOCIADO:.\n");
        printf("4- NUEVA LLAMADA.\n");
        printf("5- ASIGNAR AMBULANCIA.\n");
        printf("6- INFORMAR.\n");
        printf("7- .\n");
        printf("8- ORDENAR POR NOMBRE Y APELLIDO.\n");
        printf("9- GRAFICO EDAD.\n");
        printf("10- Salir.\n");
        fflush(stdin);
        opcion=getChar("\nElija una opcion: ");

        switch(opcion)
        {
        case '1':
            if(alta(listaAfiliados,CANT,generadorID))
            {
                generadorID++;
            }
            break;
        case '2':
            modificar (listaAfiliados,CANT,"Ingrese ID del afiliado a modificar","\nId erroneo.\n","ID no encontrado");

            break;
        case '3':
            baja(listaAfiliados,CANT,"ingresar ID  del afiliado:","ID incorrecto","El ID no pertenece a ningún afiliado activo.");
            break;
        case '4':
            nuevaLlamada(listaAfiliados,CANT,listaLlamadas,CANTIDADLLAMADAS,generadorIdLlamadas);
            break;
        case '5':
            asignarAmbulancia(listaAfiliados,CANT,listaLlamadas,CANTIDADLLAMADAS,generadorIdAmbulancia);
            break;
        case '6':
            informarAfiliadosMasLlamadas(listaLlamadas,CANTIDADLLAMADAS,listaAfiliados,CANT,afiliadosConMasLlamadas);
            informarMotivosMasRepetidos(listaLlamadas,CANTIDADLLAMADAS,motivos);
            informarMotivosMasDemorados(listaLlamadas,CANTIDADLLAMADAS,motivos);


            break;
        case '7':
            system("cls");
            printf("\n");
            for(i=0; i<CANT; i++)
            {
                if(listaAfiliados[i].isEmpty==0)
                {
                    printf("Nombre %s --Apellido %s -- Edad %s --  -- ID: %d\n\n",listaAfiliados[i].nombre,listaAfiliados[i].apellido,listaAfiliados[i].edad,listaAfiliados[i].id);
                }
            }
            printf("\n\n");
            break;
        case '8':
            printf("Ordenar por nombre y apellido\n\n");
            sortEmployeeByNameAndLastname(listaAfiliados,CANT,0);
            for(i=0; i<CANT; i++)
            {
                if(listaAfiliados[i].isEmpty==0)
                {
                    printf("Nombre %s --Apellido %s\n\n",listaAfiliados[i].nombre,listaAfiliados[i].apellido);
                }
            }
            break;
        case '9':
            printf("GRAFICO EDAD.\n");
            graficoEdad(listaAfiliados,CANT);
            break;
        default :
            printf("Opcion incorrecta.\n");
            system("cls");
            break;
        }

    }
    while(seguir=='s');

    return 0;
}
