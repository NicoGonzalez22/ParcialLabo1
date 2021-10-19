#ifndef BIBLOTECAGENERAL_H_
#define BIBLOTECAGENERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TamName 51
#define TamNum 10
#define TamCuit 12
/// @fn float CargarFlotante(char[], char[])
/// @brief Pide el ingreso de una cadena de caracteres con un maximo
/// de 10 caracteres, valida el flotante con la funcion ValidarFlotante
/// y si sale todo bien utiliza la funcion atof para convertir la cadena en
/// flotante
///
/// @param mensaje Mensaje que muestra al pedir el flotante
/// @param mensajeError Mensaje que muestra cuando hay algun error
/// @return Retorna el flotante
float CargarFlotante(char mensaje[],char mensajeError[]);

/// @fn int ValidarFlotante(char[])
/// @brief Recibe como parametro una cadena de caracteres
/// y valida con la funcion isdigit si son digitos, tambien da como valido
/// los puntos.
///
/// @param flotante Cadena de caracteres que recibe
/// @return Devuelve 1 si el numero es flotante, 0 si hay algun error o 2 si hay comas (,)
int ValidarFlotante(char flotante[]);

/// @fn int CargarEntero(char[], char[])
/// @brief Pide el ingreso de una cadena de caracteres con un maximo
/// de 10 caracteres, valida el entero con la funcion ValidarEntero
/// y si sale todo bien utiliza la funcion atoi para convertir la cadena en
/// entero
/// @param mensaje Mensaje que muestra al pedir el entero
/// @param mensajeError Mensaje que muestra al haber algun error
/// @return Devuelve el entero
int CargarEntero(char mensaje[],char mensajeError[]);

/// @fn int ValidarEntero(char[])
/// @brief Recibe como parametro una cadena de caracteres
/// y valida con la funcion isdigit si son digitos
///
/// @param numero Cadena de caracteres que recibe
/// @return Devuelve 1 si efectivamente es un numero entero o 0 si hay algun error
int ValidarEntero(char numero[]);

/// @fn char PedirString(char[], char[])
/// @brief Pide una cadena de carecteres
///
/// @param cadena Donde se almacena la cadena de carecteres
/// @param mensaje Mensaje que muestra al pedir la cadena de carecteres
/// @return devuelve la cadena de caracteres
char PedirString(char cadena[],char mensaje[]);

/// @fn void CargarNombreOApellido(char[], char[], char[])
/// @brief 	Se pide que ingrese el nombre o el apellido, utiliza la funcion ValidarNombre para
/// validar que sean solo caracteres
///
/// @param nombre Cadena de caractereces que recibe
/// @param mensaje Mensaje que muestra al pedir el nombre
/// @param mensajeError Mensaje que muestra cuando hay algun error en el nombre ingresado
void CargarNombreOApellido(char nombre[],char mensaje[],char mensajeError[]);
/// @fn int ValidarNombre(char[])
/// @brief Recibe una cadena de caracteres y utiliza la funcion isalpha para validar que los caracteres sean
/// alfabetos
///
/// @param nombre Cadena que recibe la funcion
/// @return Devuelve 1 si toda la cadena son alfabetos o 0 si almenos un caracter no lo es
int ValidarNombre(char nombre[]);

/// @fn int CargarEnteroConMaxYMin(char[], char[], int, int)
/// @brief Pide el ingreso de un numero entero validando un maximo y un minimo,tambien utiliza la funcion
/// ValidarEntero para corroborar que sean numeros los ingresados
///
/// @param mensaje Mensaje que muestra cuando pide el entero
/// @param mensajeError Mensaje que muestra cuando el entero contiene algun error
/// @param min Numero minimo a ingresar
/// @param max Numero maximo a ingresar
/// @return Devuelve el numero entero
int CargarEnteroConMaxYMin(char mensaje[],char mensajeError[],int min,int max);


/// @fn void CargarDireccion(char[], char[], char[])
/// @brief Permite ingresar una direccion con o sin numeros, solo deja ingresar numeros
/// despues de un espacio.
///
/// @param direccion Direccion a ingresar
/// @param mensaje Mensaje que muestra para pedir la direccion
/// @param mensajeError Mensaje que muestra para pedir la direccion
void CargarDireccion(char direccion[],char mensaje[],char mensajeError[]);

/// @fn int ValidarDireccion(char[])
/// @brief Recibe como parametro una cadena de caracteres, valida que sean caracteres y solo permite
/// los numeros despues de un espacio, o que la posicion del array anterior sea un numero
///
/// @param direccion Direccion a validar
/// @return Devuelve 1 si todo lo validado es correcto o 0 si hubo un error o un caracter no permitido
int ValidarDireccion(char direccion[]);

/// @fn int CargarEntero(char[], char[])
/// @brief Pide el ingreso de una cadena de caracteres con un maximo
/// de 10 caracteres, valida el entero con la funcion ValidarEntero
///
/// @param mensaje Mensaje que muestra al pedir el entero
/// @param mensajeError Mensaje que muestra al haber algun error
/// @return Devuelve el entero en cadena de caracteres
void CargarCuit(char entero[],char mensaje[],char mensajeError[]);


/// @fn void CargarNombreOApellido(char[], char[], char[])
/// @brief 	Se pide que ingrese el nombre o el apellido, utiliza la funcion ValidarNombre para
/// validar que sean solo caracteres
///
/// @param nombre Cadena de caractereces que recibe
/// @param mensaje Mensaje que muestra al pedir el nombre
/// @param mensajeError Mensaje que muestra cuando hay algun error en el nombre ingresado
void CargarNombre(char nombre[],char mensaje[],char mensajeError[]);
/// @fn void ImprimirCuatroDatos(char[], char[], char[], char[])
/// @brief Recibe como parametro los cinco Datos a mostrar en la tabla de datos
/// y los muestra
/// @param datoUno Primer Datos
/// @param datoDos Segundo Datos
/// @param datoTres Tercer Datos
/// @param datoCuatro Cuatro Datos
/// @param datoCinco QuintoDato
void ImprimirCincoDatosSinInt(char datoUno[],char datoDos[],char datoTres[],char datoCuatro[],char datoCinco[]);

/// @fn void ImprimirCincoDatos(char[], char[], char[], char[],int)
/// @brief Recibe como parametro los cinco Datos a mostrar en la tabla de datos
/// y los muestra,el ultimo parametro es un int.
/// @param datoUno Primer dato
/// @param datoDos Segundo dato
/// @param datoTres Tercer dato
/// @param datoCuatro Cuatro dato
/// @param datoCinco Quinto dato ()
void ImprimirCincoDatos(char datoUno[],char datoDos[],char datoTres[],char datoCuatro[],int datoCinco);

/// @fn void ImprimirTresDatos(char[], char[], int)
/// @briefRecibe como parametro los tres Datos a mostrar en la tabla de datos
/// y los muestra,el ultimo parametro es un int.
/// @param datoUno PrimerDato
/// @param datoDos	SegundoDato
/// @param datoTres	TercarDato
void ImprimirTresDatos(char datoUno[],char datoDos[],int datoTres);

/// @fn void ImprimirTresDatosSinInt(char[], char[], char[])
/// @briefRecibe como parametro los tres Datos a mostrar en la tabla de datos
/// y los muestra.
/// @param datoUno PrimerDato
/// @param datoDos	SegundoDato
/// @param datoTres	TercarDato
void ImprimirTresDatosSinInt(char datoUno[],char datoDos[],char datoTres[]);

/// @fn void ImprimirCincoDatosPrimeroYUltimoInt(int, char[], char[], char[],int)
/// @brief Recibe como parametro los cinco Datos a mostrar en la tabla de datos
/// y los muestra,el primero y ultimo parametro son int.
/// @param datoUno Primer dato
/// @param datoDos Segundo dato
/// @param datoTres Tercer dato
/// @param datoCuatro Cuatro dato
/// @param datoCinco Quinto dato
void ImprimirCincoDatosPrimeroYUltimoInt(int datoUno,char datoDos[],char datoTres[],char datoCuatro[],int datoCinco);

/// @fn void ImprimirCuatroDatos(char[], char[], char[], char[])
/// @brief Recibe como parametro los cuatro Datos a mostrar en la tabla de datos
/// y los muestra.
/// @param datoUno Primer dato
/// @param datoDos Segundo dato
/// @param datoTres Tercer dato
/// @param datoCuatro Cuatro dato
void ImprimirCuatroDatos(char datoUno[],char datoDos[],char datoTres[],char datoCuatro[]);

/// @fn void ImprimirCuatroDatosPrimeroYUltimoInt(int, char[], int, int)
/// @brief Recibe como parametro los cuatro Datos a mostrar en la tabla de datos
/// y los muestra, el primero y el ultimo son int
/// @param datoUno Primer dato
/// @param datoDos Segundo dato
/// @param datoTres Tercer dato
/// @param datoCuatro Cuatro dato
void ImprimirCuatroDatosPrimeroYUltimoInt(int datoUno,char datoDos[],int datoTres,int datoCuatro);

/// @fn void MinusculaUnaPalabra(char[])
/// @brief recibe como parametro una cadena de caracteres y la transfoma en minuscula
///
/// @param palabra Cadena de caracteres
void MinusculaUnaPalabra(char palabra[]);
#endif /* BIBLOTECAGENERAL_H_ */
