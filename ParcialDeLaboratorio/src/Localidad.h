#include "BiblotecaGeneral.h"
#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define BUENOSAIRES 1
#define PROVINCIA 2
#define OTROS 3
typedef struct
{
	int idLocalidad;
	int descripcion;
	char localidad[TamName];
}Localidad;


#endif /* LOCALIDAD_H_ */
