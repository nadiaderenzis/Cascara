
int alta (EPersona listaPersonas[],int cantidad,int id);
void baja (EPersona listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void modificar (EPersona listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void nuevaLlamada (EPersona listaPersonas[],int cantidad, ELlamadas listaLlamadas[], int cantidadLlamas,int id);
void asignarAmbulancia (EPersona listaAfiliados[],int cantidadPersonas, ELlamadas listaLlamadas[],int cantiadLlamadas,int idAmbulancia);
void informarMotivosMasDemorados(ELlamadas listaLlamadas[],int canttidadLlamadas,EMotivo motivo[]);
void informarAfiliadosMasLlamadas(ELlamadas listaLlamadas[],int cantLlamadas,EPersona listaPersonas[],int cantidad,int afiliadosConMasLlamadas[]);
void informarAfiliadosMasLlamadas(ELlamadas listaLlamadas[],int cantLlamadas,EPersona listaPersonas[],int cantidad,int afiliadosConMasLlamadas[]);
void informarMotivosMasRepetidos(ELlamadas listaLlamadas[],int canttidadLlamadas,EMotivo motivo[]);
void imprimirListaPorNombre(EPersona listaPersonas[],int cantidad);
