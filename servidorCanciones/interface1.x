/*Declaracion de constantes*/
const TAM_MAX_NOM_ARCHIVO = 128;
const TAM_MAX_BLOQUE_ARCHIVO = 1024;
const MAXNOM = 20;
/*Declaracion de la estructura que permite almacenar los datos de una cancion*/
struct cancion1{
    int codigoCancion;
    char titulo[MAXNOM];
    char artista[MAXNOM];
    char tipo[MAXNOM];
	int tamanioCancion; 
};

/*Declaracion de la estructura que permite enviar la canción en bloques*/
struct bloque1 {
string nombreArchivo<TAM_MAX_NOM_ARCHIVO>;
opaque datos<TAM_MAX_BLOQUE_ARCHIVO>;
int size;
int dest_offset;
};
typedef struct bloque1 bloque1;

/*Definicion de las operaciones que se pueden realizar*/
program programa_compartir_canciones {
	version programa_compartir_canciones_version_1 {
		int crear_archivo_1(string archivo) = 1;
		int enviar_bloque_1(bloque1 *) = 2;
		bool enviar_datos_cancion_1(cancion1 objCancion)=3;
        cancion1 consultar_cancion_1(string titulo)=4;	
	}=1;
}=0x20000001;
