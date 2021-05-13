

#ifndef UTN_H_
#define UTN_H_
/**
 * @fn int utn_getString(char[], char[], int)
 * @brief Funcion que toma una cadena de caracteres
 *
 * @param resultado de la funcion (variable donde guardo la misma)
 * @param mensaje a mostrar por consola
 * @param tamaño de la cadena de caracteres
 * @return
 */
int utn_getString (char resultado[], char mensaje[], int tam);
/**
 * @fn int utn_getInt(int*, char[], int)
 * @brief Funcion que toma un entero del usuario
 *
 * @param resultado de la funcion (variable donde guardo la misma)
 * @param mensaje a mostrar por consola
 * @param tamaño del entero
 * @return
 */
int utn_getInt(int* resultado, char mensaje[], int tam);
/**
 * @fn int EsUnNumero(char[])
 * @brief
 *
 * @param buffer
 * @return
 */
int EsUnNumero(char buffer[]);
/**
 * @fn int utn_getFloat(float*, char[], int)
 * @brief
 *
 * @param resultado
 * @param mensaje
 * @param tam
 * @return
 */
int utn_getFloat(float* resultado, char mensaje[], int tam);
/**
 * @fn int EsUnFloat(char[])
 * @brief
 *
 * @param buffer
 * @return
 */
int EsUnFloat(char buffer[]);
/**
 * @fn int utn_getNombre(char[], char[], int)
 * @brief
 *
 * @param resultado
 * @param mensaje
 * @param tam
 * @return
 */
int utn_getNombre(char resultado[], char mensaje[], int tam);
/**
 * @fn int EsUnaLetra(char[])
 * @brief
 *
 * @param buffer
 * @return
 */
int EsUnaLetra(char buffer[]);



#endif /* UTN_H_ */
