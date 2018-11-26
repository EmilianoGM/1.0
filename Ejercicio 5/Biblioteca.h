/** \brief Solicita un numero entero al usuario.
 *
 * \param pEntero int* Puntero donde se recibe el numero.
 * \param mensaje[] char Es el mensaje mostrado al solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso de ingreso invalido o fuera del rango.
 * \param minimo int  El numero minimo aceptado inclusive.
 * \param maximo int El numero maximo aceptado inclusive.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
 int pedirEntero(int* pEntero, char mensaje[], char mensajeError[], int minimo, int maximo);

/** \brief Solicita un numero flotante al usuario.
 *
 * \param pEntero int* Puntero donde se recibe el numero.
 * \param mensaje[] char Es el mensaje mostrado al solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso de ingreso invalido o fuera del rango.
 * \param minimo int  El numero minimo aceptado inclusive.
 * \param maximo int El numero maximo aceptado inclusive.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int pedirFlotante(float* pNumero, char mensaje[], char mensajeError[], float minimo, float maximo);

/** \brief Pide al usuario un string de caracteres alfabeticos unicamente.
 *
 * \param arrayLetras[] char Array donde se recibe el string.
 * \param tamanio int Dimension del array.
 * \param mensaje[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje a mostrar en caso de que los datos recibidos no sean validos.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int pedirString_caracteresAlfabeticos(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

int pedirString_NumeroEnteroPositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

int pedirString_NumeroFlotantePositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

/** \brief
 *
 * \param arrayLetras[] char
 * \param tamanio int
 * \param mensaje[] char
 * \param mensajeError[] char
 * \return int
 *
 */
int pedirString_caracteresAlfabeticosEspaciados(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[]);

/** \brief Comprueba si el string recibido tiene solo caracteres numericos positivos.
 *
 * \param cadenaNumerica[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarString_numeroEnteroPositivo(char cadenaNumerica[], int tamanio);

/** \brief Comprueba si el string recibido forma un numero entero.
 *
 * \param cadenaNumerica[] char Array a evaluar.
 * \param tamanio int Dimension del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarString_numeroEntero(char cadenaNumerica[], int tamanio);

/** \brief Comprueba si el string recibido forma un numero flotante.
 *
 * \param cadenaNumerica[] char Array a evaluar.
 * \param tamanio int Dimension del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarString_numeroFlotante(char cadenaNumerica[], int tamanio);

int comprobarString_numeroFlotantePositivo(char cadenaNumerica[], int tamanio);


/** \brief  Comprueba si el string recibido tiene unicamente caracteres alfabeticos.
 *
 * \param stringLetras[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarString_caracteresAlfabeticos(char stringLetras[], int tamanio);

/** \brief  Comprueba si el string recibido tiene unicamente caracteres alfabeticos o espacio.
 *
 * \param stringLetras[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarString_caracteresAlfabeticosEspaciados(char stringLetras[], int tamanio);

/** \brief Solicita al usuario una respuesta SI o NO y la devuelve en un unico caracter.
 *
 * \param mensaje[] char Mensaje a mostrar.
 * \return char Devuelve 'n' para NO y 's' para SI.
 *
 */
char pedirRespuestaSN(char mensaje[]);

