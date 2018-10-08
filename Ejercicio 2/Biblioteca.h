/**< 1.0 */

/** \brief Solicita un numero entero al usuario y lo devuelve.
 *
 * \param mensaje[] char Es el mensaje mostrado al solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso de ingreso invalido o fuera del rango.
 * \param minimo int El numero minimo aceptado inclusive.
 * \param maximo int El numero maximo aceptado inclusive.
 * \return int Retorna el numero ingresado.
 *
 */
int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);

/** \brief Solicita un numero decimal al usuario y lo devuelve.
 *
 * \param mensaje[] char  Es el mensaje mostrado al solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso de ingreso invalido o fuera del rango.
 * \param minimo float El numero minimo aceptado inclusive.
 * \param maximo float El numero maximo aceptado inclusive.
 * \return float Retorna el numero decimal ingresado.
 *
 */
float pedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo);

/** \brief  Solicita al usuario un array de solo caracteres alfabeticos o espacio.
 *
 * \param arrayLetras[] char El array a introducir la respuesta.
 * \param tamanio int El tamanio maximo de caracteres a introducir.
 * \param mensaje[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje a mostrar en caso de error.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int pedirArrayLetrasConEspacio(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

/** \brief Solicita al usuario un array de solo caracteres alfanumericos o espacio.
 *
 * \param arrayAlfanumerica[] char El array a introducir la respuesta.
 * \param tamanio int El tamanio maximo de caracteres a introducir.
 * \param mensaje[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje a mostrar en caso de error.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int pedirArrayAlfanumericaConEspacio(char arrayAlfanumerica[], int tamanio, char mensaje[], char mensajeError[]);

/** \brief Solicita al usuario una respuesta SI o NO y la devuelve.
 *
 * \param mensaje[] char Mensaje a mostrar.
 * \return char Devuelve n para NO y s para SI.
 *
 */
char pedirRespuestaSN(char mensaje[]);

/** \brief Comprueba si un array de char forma un numero entero.
 *
 * \param cadenaNumerica[] char La cadena de caracteres a evaluar.
 * \param tamanio int El largo de la cadena misma.
 * \return int Devuelve 1 si lo es y 0 si NO lo es.
 *
 */
int comprobarArrayNumericaEntero(char cadenaNumerica[], int tamanio);

/** \brief Capitaliza un array con palabras, poniendo en mayuscula la primer letra despues de cada espacio
 *en mayuscula y el resto en minuscula.
 *
 * \param arrayLetras[] char Array a capitalizar.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL).
 *
 */
int capitalizarArrayLetras(char arrayLetras[]);

/** \brief Ordena un array numerico de menor a mayor.
 *
 * \param arrayNumerica[] int El array a ordenar
 * \param tamanio int Tamanio del array.
 * \return void
 *
 */
void ordenarArrayNumerica(int arrayNumerica[],int tamanio);
