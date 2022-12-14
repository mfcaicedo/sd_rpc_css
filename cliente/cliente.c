/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "interface1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

struct stat st; 

/**
 * @brief Método para partir una línea 
 * 
 * @param couple 
 * @param tosplit 
 * @param culprit 
 * @return char** retorno. 
 */
char** split( char** couple, char* tosplit, char* culprit ) { 
    int i = 0; 
    // Returns first token  
    char *token = strtok( tosplit, culprit);    
    for( int i = 0; token != NULL && i < 2; i++ ) { 
        couple[i] = token; 
        token = strtok(NULL, culprit); 
    } 
    return couple;
}
/**
 * @brief Obtener la extensión de un archivo 
 * 
 * @param filename nombre del archivo 
 * @return const char* retorna extesion. 
 */
const char * get_filename_ext(const char *filename) {
	const char *dot = strrchr(filename, '.');
	if(!dot || dot == filename) return "";
	return dot + 1;
}
/**
 * @brief Método para enviar la canción al servidor
 * 
 * @param nombreArchivo nombre del archivo a enviar
 * @param clnt referencia del cliente que enviará el archivo al servidor. 
 */
void enviarArchivoAlServidor(char * nombreArchivo, CLIENT  *clnt){

	//fopen abrimos el archivo en modo lectura r 
	FILE *file = fopen(nombreArchivo, "r");
	bool bandera = TRUE; 
	int pos = 0, cantidadBloques = 0; 
	bloque1 objBloque; 
	objBloque.nombreArchivo = (char*)malloc(20*sizeof(char));
	strcpy(objBloque.nombreArchivo, nombreArchivo);
	objBloque.datos.datos_val = (char *)malloc(TAM_MAX_BLOQUE_ARCHIVO * sizeof(char));

	do{
		//la funcion fread lee 1024 bytes del archivo 
		//los guarda en el campo datos_val del campo datos, de la variable objBLoque
		objBloque.datos.datos_len = fread(objBloque.datos.datos_val, 1, TAM_MAX_BLOQUE_ARCHIVO, file);
		//el campo dest_offset almacena la posición desde la cual se realizar la lectura de los 1024 bytes
		objBloque.dest_offset = pos; 
		pos = pos + objBloque.datos.datos_len; 

		int *resultado = enviar_bloque_1_1(&objBloque, clnt);
		if(resultado == (int *) NULL){
			clnt_perror(clnt, "call failed");
			bandera = FALSE; 
		}else{
			cantidadBloques ++; 
		}
		//si el ultimo bloque es menor a 1024, es el ultimo bloque del archivo
	} while (objBloque.datos.datos_len == TAM_MAX_BLOQUE_ARCHIVO);

	free(objBloque.datos.datos_val);
	fclose(file);

	if(bandera == TRUE){
		printf("\n Canción enviar exitosamente a partir de %d bloques", cantidadBloques);
	}else{
		printf("\n Error al enviar la canción");
	}
}

void programa_compartir_canciones_1(char *host){
	CLIENT *clnt;
	int  *result_1;
	char * crear_archivo_1_1_arg;
	int  *result_2;
	bloque1  enviar_bloque_1_1_arg;
	bool_t  *result_3;
	cancion1 objCancion; 
	cancion1  enviar_datos_cancion_1_1_arg;
	cancion1  *result_4;
	char * consultar_cancion_1_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, programa_compartir_canciones, programa_compartir_canciones_version_1, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	//declaramos variable para opcion de cliente 
	int opcion;
	do{

		printf("\n========    Menu    ========= \n");
		printf("\n   1. Ingresar y enviar datos de una canción ");
		printf("\n   2. Consultar canción del servidor ");
		printf("\n   3. Salir ");
		printf("\n============================\n");
	 	scanf("%d", &opcion);  //leemos la opcion del cliente

		switch (opcion){
		case 1:
			/* Pedimos los datos de la cancion  */
			printf("\n Digite el codigo de la cancion: ");
			scanf("%d", &enviar_datos_cancion_1_1_arg.codigoCancion);

			printf("\n Digite el titulo de la cancion: ");
			scanf("%s", enviar_datos_cancion_1_1_arg.titulo);

			printf("\n Digite el autor de la cancion: ");
			scanf("%s", enviar_datos_cancion_1_1_arg.artista);
			do{
			printf("\n Digite el tipo de la canción (mp3, FLAC): ");
			scanf("%s", enviar_datos_cancion_1_1_arg.tipo);
			}while ((strcmp(enviar_datos_cancion_1_1_arg.tipo, "mp3") != 0) && 
			(strcmp(enviar_datos_cancion_1_1_arg.tipo, "FLAC") != 0));

			printf("\n Digite el tamaño de la cancion en mb: ");
			scanf("%d", &enviar_datos_cancion_1_1_arg.tamanioCancion);

			/* Pedimos el nombre del archivo */
			crear_archivo_1_1_arg = (char*)malloc(20*sizeof(char));
			printf("\n Digite el nombre del archivo: ");
			scanf("%s", crear_archivo_1_1_arg);
			//Validación si el archivo existe 
			if (stat(crear_archivo_1_1_arg, &st) < 0){
				printf("\narchivo a enviar no ha sido encontrado");
        		continue; 
    		}
			//validación la extensión del archivo 
			if (strcmp("mp3", get_filename_ext(crear_archivo_1_1_arg)) != 0 && 
			strcmp("FLAC", get_filename_ext(crear_archivo_1_1_arg)) != 0){
				printf("\n El archivo no tiene el formato adecuado\n");
				continue;
			}
			//registramos los datos de la canción si pasa las validaciones 
			result_3 = enviar_datos_cancion_1_1(&enviar_datos_cancion_1_1_arg, clnt);
			if (result_3 == (bool_t *) NULL) {
				clnt_perror (clnt, "call failed");
			}else{
				printf("\n Datos de la canción inviados correctamente.");
			}
			//Enviamos la cancion al servidor si pasa la validaciones
			result_1 = crear_archivo_1_1(&crear_archivo_1_1_arg, clnt);
			if (result_1 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}else{
				printf("\n Archivo vacío creado en el servidor");
				printf("\n Procedimiento a enviar en bloques el archivo");
				enviarArchivoAlServidor(crear_archivo_1_1_arg, clnt);
			}	
			break;

		case 2:
			consultar_cancion_1_1_arg = (char*) malloc(40*sizeof(char));
			printf("\n Digite el titulo de la cancion a buscar: ");
			scanf("%s", consultar_cancion_1_1_arg);

			result_4 = consultar_cancion_1_1(&consultar_cancion_1_1_arg, clnt);
			if (result_4 == (cancion1 *) NULL) {
				printf("\nLo sentimos, la canción no fue encontrada");
				clnt_perror (clnt, "call failed");
			}else{
				printf("\nResultado de la consulta");
				printf("\nCódigo canción: %d", (*result_4).codigoCancion);
				printf("\nTítulo canción: %s", (*result_4).titulo);
				printf("\nArtista canción: %s", (*result_4).artista);
				printf("\nTipo canción: %s", (*result_4).tipo);
				printf("\nTamaño canción: %d", (*result_4).tamanioCancion);
			}
			break;
		}
	} while(opcion != 3);

	result_2 = enviar_bloque_1_1(&enviar_bloque_1_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("\n No se pudo enviar el archivo");	
	}
	result_4 = consultar_cancion_1_1(&consultar_cancion_1_1_arg, clnt);
	if (result_4 == (cancion1 *) NULL) {
		clnt_perror (clnt, "call failed");
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}
/**
 * @brief Rutina para iniciar el programa 
 * 
 * @param argc numero de argumentos 
 * @param argv arreglo de argumentos 
 * @return int retorno. 
 */
int main (int argc, char *argv[]){
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	programa_compartir_canciones_1 (host);
exit (0);
}
