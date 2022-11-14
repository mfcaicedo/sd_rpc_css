const MAXNOM = 50;
/*Declaracion de la estructura que permite almacenar los datos de una cancion*/
struct datos_calculados{
    char fecha_hora[MAXNOM];
    int cantidad_canciones_mp3;
	int cantidad_canciones_FLAC;
	int espacio_total_canciones;
};

/*Definicion de las operaciones que se pueden realizar*/
program programa_compartir_canciones3 {
	version programa_compartir_canciones_version_3 {
		void enviar_notificacion(datos_calculados objdatosCalculados)=1;		
	}=3;
}=0x20000003;
