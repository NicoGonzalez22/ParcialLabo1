#include "BiblotecaGeneral.h"
float CargarFlotante(char mensaje[],char mensajeError[])
{
	float flotanteFinal;
	char flotante[TamNum];
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(flotante,mensaje);

		while(strlen(flotante)>TamNum)
		{
			PedirString(flotante,"Ingrese un numero flotante con un maximo de 9 digitos(sin incluir el punto): ");
		}
		while(ValidarFlotante(flotante)==0||ValidarFlotante(flotante)==2)
		{
			if(ValidarFlotante(flotante)==0)
			{
				PedirString(flotante,mensajeError);
			}else
			{
				PedirString(flotante,"Ingrese un numero flotante con '.', no con ',':  ");
			}
		}
		flotanteFinal=atof(flotante);
	}
	return flotanteFinal;
}

int ValidarFlotante(char flotante[])
{
	int i;
	int valido;
	valido=1;
	i=0;
	while(flotante[i]!='\0'&&(valido==1))
	{
		if(isdigit(flotante[i])!=0||flotante[i]=='.')
		{
			valido=1;
		}else
		{
			valido=0;
		}
		if(flotante[i]==',')
		{
			valido=2;
		}

		i++;
	}
	return valido;
}

int CargarEntero(char mensaje[],char mensajeError[])
{
	char entero[TamNum];
	int enterofinal;

	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(entero,mensaje);
		while(strlen(entero)>TamNum)
		{
			PedirString(entero,"Ingrese un numero con un maximo de 10 digitos");
		}
		while(ValidarEntero(entero)==0)
		{
			PedirString(entero,mensajeError);
		}
		enterofinal=atoi(entero);
	}
	return enterofinal;
}

int ValidarEntero(char numero[])
{
	int i=0;
	int valido;
	valido=1;
	while(numero[i]!='\0'&&(valido==1))
	{
		if(isdigit(numero[i])!=0)
		{
			valido=1;
		}else
		{
			valido=0;
		}

		i++;
	}
	return valido;
}

char PedirString(char cadena[],char mensaje[])
{
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%s",cadena);

	return *cadena;
}

void CargarNombreOApellido(char nombre[],char mensaje[],char mensajeError[])
{
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		*nombre=PedirString(nombre,mensaje);

		while(ValidarNombre(nombre)==0)
		{
			*nombre=PedirString(nombre,mensajeError);
		}
	}
}

int ValidarNombre(char nombre[])
{
	int valido;
	int i;
	i=0;
	valido=1;
	while(nombre[i]!='\0'&&(valido==1))
	{
		if(isalpha(nombre[i])!=0||nombre[i]=='ñ')
		{
			valido=1;
		}else
		{
			valido=0;
		}
		i++;
	}
	return valido;
}

int CargarEnteroConMaxYMin(char mensaje[],char mensajeError[],int min,int max)
{
	char entero[TamNum];
	int enterofinal;
	int valido;
	valido=1;
	if(mensaje!=NULL&&mensajeError!=NULL&&min<max)
	{
		while(valido>0)
		{

			PedirString(entero,mensaje);
			while(strlen(entero)>TamNum)
			{
				PedirString(entero,"Ingrese un numero con un maximo de 10 digitos");
			}
			while(ValidarEntero(entero)==0)
			{
				PedirString(entero,mensajeError);
			}
			enterofinal=atoi(entero);
			if(enterofinal<min||enterofinal>max)
			{
				valido=2;
			}else
			{
				valido=0;
			}
		}

	}
	return enterofinal;
}

void CargarNombre(char nombre[],char mensaje[],char mensajeError[])
{
	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		*nombre=PedirString(nombre,mensaje);

		while(ValidarNombre(nombre)==0)
		{
			*nombre=PedirString(nombre,mensajeError);
		}
	}
}


void CargarDireccion(char direccion[],char mensaje[],char mensajeError[])
{
	if(direccion!=NULL&&mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(direccion,mensaje);

		while(ValidarDireccion(direccion)==0)
		{
			PedirString(direccion,mensajeError);
		}
	}

}

int ValidarDireccion(char direccion[])
{
	int validar;
	int i;
	i=0;
	validar=1;
	while(direccion[i]!='\0'&&validar==1)
	{
		if(isalpha(direccion[i])!=0)
		{
			validar=1;
		}else
		{
			if((direccion[i-1]==' '&&isdigit(direccion[i])!=0)||(isdigit(direccion[i-1])!=0&&isdigit(direccion[i])!=0))
			{
				validar=1;
			}
		}
		if((isdigit(direccion[i-1])!=0&&isdigit(direccion[i])==0)||(isdigit(direccion[i-1])==0&&isdigit(direccion[i])!=0))
		{
		validar=0;
		}
		i++;
	}
	return validar;
}

void CargarCuit(char cuit[],char mensaje[],char mensajeError[])
{


	if(mensaje!=NULL&&mensajeError!=NULL)
	{
		PedirString(cuit,mensaje);
		while(strlen(cuit)!=TamCuit-1)
		{
			PedirString(cuit,"Ingrese un cuit de 11 digitos sin guion: ");
		}
		while(ValidarEntero(cuit)==0)
		{
			PedirString(cuit,mensajeError);
		}
	}
}


void ImprimirCincoDatosSinInt(char datoUno[],char datoDos[],char datoTres[],char datoCuatro[],char datoCinco[])
{
	printf("|%15s |%15s |%20s |%15s |%15s |\n",datoUno,datoDos,datoTres,datoCuatro,datoCinco);
}
void ImprimirCincoDatos(char datoUno[],char datoDos[],char datoTres[],char datoCuatro[],int datoCinco)
{
	printf("|%15s |%15s |%20s |%15s |%15d |\n",datoUno,datoDos,datoTres,datoCuatro,datoCinco);
}

void MinusculaUnaPalabra(char palabra[])
{
	int i;
	i=0;
	while(palabra[i]!='\0')
	{
		palabra[i]=tolower(palabra[i]);
	}
}


void ImprimirTresDatosSinInt(char datoUno[],char datoDos[],char datoTres[])
{
	printf("|%15s |%15s |%15s |\n",datoUno,datoDos,datoTres);
}

void ImprimirTresDatos(char datoUno[],char datoDos[],int datoTres)
{
	printf("|%15s |%15s |%15d |\n",datoUno,datoDos,datoTres);
}

void ImprimirCincoDatosPrimeroYUltimoInt(int datoUno,char datoDos[],char datoTres[],char datoCuatro[],int datoCinco)
{
	printf("|%15d |%15s |%20s |%15s |%15d|\n",datoUno,datoDos,datoTres,datoCuatro,datoCinco);
}

void ImprimirCuatroDatos(char datoUno[],char datoDos[],char datoTres[],char datoCuatro[])
{
	printf("|%15s |%15s |%20s |%15s |\n",datoUno,datoDos,datoTres,datoCuatro);
}

void ImprimirCuatroDatosPrimeroYUltimoInt(int datoUno,char datoDos[],int datoTres,int datoCuatro)
{
	printf("|%15d |%15s |%20d |%15d|\n",datoUno,datoDos,datoTres,datoCuatro);
}
