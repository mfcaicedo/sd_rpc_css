/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _INTERFACE1_H_RPCGEN
#define _INTERFACE1_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define TAM_MAX_NOM_ARCHIVO 128
#define TAM_MAX_BLOQUE_ARCHIVO 1024
#define MAXNOM 20

struct cancion1 {
	int codigoCancion;
	char titulo[MAXNOM];
	char artista[MAXNOM];
	char tipo[MAXNOM];
	int tamanioCancion;
};
typedef struct cancion1 cancion1;

struct bloque1 {
	char *nombreArchivo;
	struct {
		u_int datos_len;
		char *datos_val;
	} datos;
	int size;
	int dest_offset;
};
typedef struct bloque1 bloque1;


#define programa_compartir_canciones 0x20000001
#define programa_compartir_canciones_version_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define crear_archivo_1 1
extern  int * crear_archivo_1_1(char **, CLIENT *);
extern  int * crear_archivo_1_1_svc(char **, struct svc_req *);
#define enviar_bloque_1 2
extern  int * enviar_bloque_1_1(bloque1 *, CLIENT *);
extern  int * enviar_bloque_1_1_svc(bloque1 *, struct svc_req *);
#define enviar_datos_cancion_1 3
extern  bool_t * enviar_datos_cancion_1_1(cancion1 *, CLIENT *);
extern  bool_t * enviar_datos_cancion_1_1_svc(cancion1 *, struct svc_req *);
#define consultar_cancion_1 4
extern  cancion1 * consultar_cancion_1_1(char **, CLIENT *);
extern  cancion1 * consultar_cancion_1_1_svc(char **, struct svc_req *);
extern int programa_compartir_canciones_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define crear_archivo_1 1
extern  int * crear_archivo_1_1();
extern  int * crear_archivo_1_1_svc();
#define enviar_bloque_1 2
extern  int * enviar_bloque_1_1();
extern  int * enviar_bloque_1_1_svc();
#define enviar_datos_cancion_1 3
extern  bool_t * enviar_datos_cancion_1_1();
extern  bool_t * enviar_datos_cancion_1_1_svc();
#define consultar_cancion_1 4
extern  cancion1 * consultar_cancion_1_1();
extern  cancion1 * consultar_cancion_1_1_svc();
extern int programa_compartir_canciones_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_cancion1 (XDR *, cancion1*);
extern  bool_t xdr_bloque1 (XDR *, bloque1*);
extern  bool_t xdr_bloque1 (XDR *, bloque1*);

#else /* K&R C */
extern bool_t xdr_cancion1 ();
extern bool_t xdr_bloque1 ();
extern bool_t xdr_bloque1 ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_INTERFACE1_H_RPCGEN */
