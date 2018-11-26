#define MAX_NOMBRE 128

typedef struct
{
    int id;
    char nombre[MAX_NOMBRE];
    int entero;
    float flotante;
}Generica;

/** \brief Constructor
 *
 * \param void
 * \return void
 *
 */
Generica* Generica_nuevo(void);

/** \brief Constructor parametrizado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param enteroStr char*
 * \param flotanteStr char*
 * \return Generica* Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
Generica* Generica_nuevoParametrizado(char* idStr,char* nombreStr,char* enteroStr, char* flotanteStr);

/** \brief Elimina de la memoria.
 *
 * \param this Generica*
 * \return void
 *
 */
void Generica_eliminar(Generica* this);


/** \brief Establece el id.
 *
 * \param this Generica*
 * \param id int
 * \return int
 *
 */
int Generica_setId(Generica* this,int id);

 /** \brief Devuelve el id.
 *
 * \param this Generica*
 * \param id int*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_getId(Generica* this,int* id);

/** \brief Establece el nombre.
 *
 * \param this Generica*
 * \param nombre char*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_setNombre(Generica* this,char* nombre);

/** \brief Devuelve el nombre.
 *
 * \param this Generica*
 * \param nombre char*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_getNombre(Generica* this,char* nombre);

/** \brief Establece el entero.
 *
 * \param this Generica*
 * \param entero int
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_setEntero(Generica* this,int entero);

/** \brief Devuelve el entero.
 *
 * \param this Generica*
 * \param entero int*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_getEntero(Generica* this,int* entero);

/** \brief Establece el flotante.
 *
 * \param this Generica*
 * \param flotante int
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_setFlotante(Generica* this, float flotante);

/** \brief Devuelve el flotante.
 *
 * \param this Generica*
 * \param flotante int*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_getFlotante(Generica* this,float* flotante);

/** \brief Imprime la estrucura en pantalla.
 *
 * \param this Generica*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_print(Generica* this);

/** \brief Compara segun id.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int Generica_compararId(void* this, void* thisDos);

/** \brief Compara segun su nombre.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int Generica_compararNombre(void* this, void* thisDos);

/** \brief Compara segun entero.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int Generica_compararEntero(void* this, void* thisDos);

/** \brief Compara segun flotante.
 *
 * \param this void*
 * \param thisDos void*
 * \return int Retorna 1 si el primero es mayor, 0 si son iguales, o -1 si el primero es menor.
 *
 */
int Generica_compararFlotante(void* this, void* thisDos);

int Generica_filtrarNombre(void* this);

int Generica_filtrarFlotante(void* this);

int Generica_filtrarEntero(void* this);
