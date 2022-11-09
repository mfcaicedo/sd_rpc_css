/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _INTERFACE2_H_RPCGEN
#define _INTERFACE2_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define TAM_MAX_NOM_ARCHIVO 128
#define TAM_MAX_BLOQUE_ARCHIVO 1024

struct bloque2 {
	char *nombreArchivo;
	struct {
		u_int datos_len;
		char *datos_val;
	} datos;
	int size;
	int dest_offset;
};
typedef struct bloque2 bloque2;


#define programa_compartir_canciones2 0x20000002
#define programa_compartir_canciones_version_2 2

#if defined(__STDC__) || defined(__cplusplus)
#define crear_archivo_2 1
extern  int * crear_archivo_2_2(char **, CLIENT *);
extern  int * crear_archivo_2_2_svc(char **, struct svc_req *);
#define enviar_bloque_2 2
extern  int * enviar_bloque_2_2(bloque2 *, CLIENT *);
extern  int * enviar_bloque_2_2_svc(bloque2 *, struct svc_req *);
extern int programa_compartir_canciones_2_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define crear_archivo_2 1
extern  int * crear_archivo_2_2();
extern  int * crear_archivo_2_2_svc();
#define enviar_bloque_2 2
extern  int * enviar_bloque_2_2();
extern  int * enviar_bloque_2_2_svc();
extern int programa_compartir_canciones_2_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_bloque2 (XDR *, bloque2*);
extern  bool_t xdr_bloque2 (XDR *, bloque2*);

#else /* K&R C */
extern bool_t xdr_bloque2 ();
extern bool_t xdr_bloque2 ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_INTERFACE2_H_RPCGEN */
