/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _INTERFACE3_H_RPCGEN
#define _INTERFACE3_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXNOM 50

struct datos_calculados {
	char fecha_hora[MAXNOM];
	int cantidad_canciones_mp3;
	int cantidad_canciones_FLAC;
	int espacio_total_canciones;
};
typedef struct datos_calculados datos_calculados;

#define programa_compartir_canciones3 0x20000003
#define programa_compartir_canciones_version_3 3

#if defined(__STDC__) || defined(__cplusplus)
#define enviar_notificacion 1
extern  void * enviar_notificacion_3(datos_calculados *, CLIENT *);
extern  void * enviar_notificacion_3_svc(datos_calculados *, struct svc_req *);
extern int programa_compartir_canciones_3_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define enviar_notificacion 1
extern  void * enviar_notificacion_3();
extern  void * enviar_notificacion_3_svc();
extern int programa_compartir_canciones_3_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_datos_calculados (XDR *, datos_calculados*);

#else /* K&R C */
extern bool_t xdr_datos_calculados ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_INTERFACE3_H_RPCGEN */
