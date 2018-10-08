#define LIBRE -1
#define OCUPADO 1
#define MAX_DIRECTORES 500
#define TAM_NOMBRE_DIRECTOR 51
#define TAM_PAIS_DIRECTOR 101

/**< 1.0 */

typedef struct
{
    char nombre[TAM_NOMBRE_DIRECTOR];
    eFecha nacimiento;
    char paisDeOrigen[TAM_PAIS_DIRECTOR];
    int estado;
}eDirector;

/** \brief Muestra una estrucura del tipo eDirector.
 *
 * \param director eDirector La estructura a mostrar.
 * \return void
 *
 */
void mostrar_eDirector(eDirector director);

/** \brief Pone la bandera estado en el valor ilogico para indicar que todos los elementos del array estan libres.
 *
 * \param listado[] eDirector El array a iniciar.
 * \param cantidad int Tamanio del array.
 * \param ilogico int El numero a tomar para indicar que el estado es libre.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int iniciar_eDirector(eDirector listado[], int cantidad, int ilogico);

/** \brief Solicita al usuario que ingrese un director en una posicion libre del array si la hay.
 *
 * \param listado[] eDirector El array donde se ingresa el elemento.
 * \param cantidad int Tamanio del array.
 * \return int Devuelve 0 si se realizo el alta o -1 en caso de error (puntero NULL o cantidad < 1) o que el array este lleno.
 *
 */
int alta_eDirector(eDirector listado[], int cantidad);

/** \brief Da de baja un elemento director, mostrandolo y preguntando al usuario si quiere eliminarlo, poniendo su estado en libre.
 *
 * \param listado[] eDirector El array donde se busca la posicion.
 * \param cantidad int Tamanio del array.
 * \param indice int La posicion del elemento.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int baja_eDirector(eDirector listado[], int cantidad, int indice);

/** \brief Busca una posicion libre del array y devuelve su indice.
 *
 * \param listado[] eDirector El array donde se busca la posicion.
 * \param cantidad int Tamanio del array.
 * \param ilogico int Valor que indica que el estado es libre.
 * \return int Devuelve el indice del elemento, -1 en caso de error, o -2 en caso
 * de que no existan posiciones libres.
 *
 */
int buscarLibre_eDirector(eDirector listado[], int cantidad, int ilogico);

/** \brief Muestra todos los elementos del array con estado ocupado.
 *
 * \param listado[] eDirector El array donde se buscan los elementos.
 * \param cantidad int Tamanio del array.
 * \return int Devuelve 0 si se realizo o -1 en caso de error(puntero NULL o cantidad < 1).
 *
 */
int mostrarListado_eDirector(eDirector listado[], int cantidad);

/** \brief Cuenta el total de los elementos con estado ocupado.
 *
 * \param listado[] eDirector El array donde se buscan los elementos.
 * \param cantidad int Tamanio del array.
 * \return int Devuelve el numero de altas o -1 en caso de error(puntero NULL o cantidad < 1).
 *
 */
int contarAltas_eDirector(eDirector listado[], int cantidad);

/** \brief Busca el nombre de un director y devuelve su indice.
 *
 * \param listado[] eDirector El array donde se busca la el nombre.
 * \param cantidad int Tamanio del array.
 * \param nombreDirector[] char El nombre a buscar.
 * \return int Devuelve el indice de la posicion del director, -1 en caso de error(puntero NULL o cantidad < 1) o -2
 * si el nombre no fue encontrado.
 *
 */
int buscarNombre_eDirector(eDirector listado[], int cantidad, char nombreDirector[]);

int ordenarPorNombre_eDirector(eDirector listado[], int cantidad, int orden);
