/*Declaracion de constantes*/
const TAM_MAX_NOM_ARCHIVO = 128;
const TAM_MAX_BLOQUE_ARCHIVO = 1024;

/*Declaracion de la estructura que permite enviar la canción en bloques al servidor de respaldo*/
struct bloque2 {
string nombreArchivo<TAM_MAX_NOM_ARCHIVO>;
opaque datos<TAM_MAX_BLOQUE_ARCHIVO>;
int size;
int dest_offset;
};
typedef struct bloque2 bloque2;

/*Definicion de las operaciones que se pueden realizar*/
program programa_compartir_canciones {
	version programa_compartir_canciones_version_2 {
		int crear_archivo_2(string archivo) = 1;
		int enviar_bloque_2(bloque2 *) = 2;	
	}=2;
}=0x20000002;
