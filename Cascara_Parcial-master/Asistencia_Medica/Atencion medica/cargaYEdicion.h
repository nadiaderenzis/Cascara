/**
 tiene un motivo , un
estado y transcurre un tiempo en ser asignada una ambulancia.
(ID, DNI, NOMBRE,
APELLIDO, EDAD
**/
typedef struct
{
    char nombre[50];
    char apellido[50];
    char dni[9];
    char edad[50];
    int id;
    int isEmpty;
} EPersona;

typedef struct
{
    char motivo[150];
    char estado[50];
    int id;
    int isEmpty;
    int idUsuario;
    int idAmbulancia;
    int duracion;
} ELlamadas;


typedef struct
{
    char tipo[15];
} EMotivo;


int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
int getNumeroAleatorio(int desde, int hasta, int iniciar);
void getString(char mensaje[],char arrayChar[]);
int getNumerosChar (char array[],char mensaje[]);
int getStringLetras(char mensaje[],char input[]);



int comentarioMasLikes (ELlamadas comentarios[],int cantidad,int listaComentariosPopulares[]);
int ingresarSoloLetras (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarDNI (EPersona lista[],int cant,char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarEdad (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarNumero (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[],int minimo, int maximo);
int motivoLlamada(ELlamadas listaLlamadas[],int cantidadLlamadas,int indice);


void inicializarArrayDeIndices (int array[],int cantidad,int valor);
void inicializarListaDePersonas(EPersona lista[],int cantidad,int estado);
void inicializarListaDeLlamadas(ELlamadas lista[],int cantidad,int estado);
void inicializarLikes(ELlamadas lista[],int cantidad,int estado);
void inicializarArrayDeIndices (int array[],int cantidad,int valor);
