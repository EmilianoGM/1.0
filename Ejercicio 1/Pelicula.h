#define MAX_PELICULAS 500
#define TAM_TITULO_PELICULA 51
#define TAM_NACIONALIDAD_PELICULA 101

typedef struct
{
    char titulo[TAM_TITULO_PELICULA];
    int anio;
    char nacionalidad[TAM_NACIONALIDAD_PELICULA];
    char director[TAM_NOMBRE_DIRECTOR];
    int identificador;
    int estado;
}ePelicula;

/** \brief Muestra una estrucura del tipo ePelicula.
 *
 * \param pelicula ePelicula a estructura a mostrar.
 * \return void
 *
 */
void mostrar_ePelicula(ePelicula pelicula);

void agregarValoresDePrueba(ePelicula listadoPeliculas[], eDirector listadoDirectores[]);

/** \brief Pone la bandera estado en el valor ilogico para indicar que todos los elementos del array estan libres.
 *
 * \param listado[] ePelicula El array a iniciar.
 * \param cantidad int Tamanio del array.
 * \param ilogico int El numero a tomar para indicar que el estado es libre.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int iniciar_ePelicula(ePelicula listado[], int cantidad, int ilogico);

/** \brief Solicita al usuario que ingrese una pelicula en una posicion libre del array si la hay, controlando que
 * el nombre del director ingresado haya sido agregado previamente.
 *
 * \param listado[] ePelicula El array donde se ingresa el elemento.
 * \param cantidad int Tamanio del array.
 * \param listadoDirectores[] eDirector El array de directores a comparar para encontrar el nombre.
 * \param cantidadDirectores int Tamanio del array de directores.
 * \return int Devuelve 0 si se realizo el alta o -1 en caso de error (puntero NULL o cantidad < 1), que el array este lleno
 * o que el nombre del director no haya sido ingresado previamente.
 *
 */
int alta_ePelicula(ePelicula listado[], int cantidad, eDirector listadoDirectores[], int cantidadDirectores);

/** \brief Da de baja un elemento pelicula, mostrandolo y preguntando al usuario si quiere eliminarlo, poniendo su estado en libre.
 *
 * \param listado[] ePelicula  El array donde se busca la posicion.
 * \param cantidad int Tamanio del array.
 * \param indice int La posicion del elemento.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int baja_ePelicula(ePelicula listado[], int cantidad, int indice);

/** \brief Mofica un elemento pelicula dado por su indice, segun la opcion introducida(titulo, anio, nacionalidad o director);
 * si se modifica el nombre del director valida que este haya sido introducido previamente.
 *
 * \param listado[] ePelicula  ePelicula El array donde se busca la posicion.
 * \param cantidad int Tamanio del array.
 * \param listadoDirectores[] eDirector El array de directores a comparar para encontrar el nombre.
 * \param cantidadDirectores int Tamanio del array de directores.
 * \param opcion int La opcion brindada por el usuario para cambiar un campo determinado.
 * \param indice int La posicion del elemento.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1) o
 * que el nombre del director no haya sido ingresado previamente.
 *
 */
int modificar_ePelicula(ePelicula listado[], int cantidad, eDirector listadoDirectores[], int cantidadDirectores, int opcion, int indice);

/** \brief Muestra todos los elementos del array con estado ocupado.
 *
 * \param listado[] ePelicula El array donde se buscan los elementos.
 * \param cantidad int Tamanio del array.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int mostrarListado_ePelicula(ePelicula listado[], int cantidad);

/** \brief Busca una posicion libre del array y devuelve su indice.
 *
 * \param listado[] ePelicula El array donde se busca la posicion.
 * \param cantidad int Tamanio del array.
 * \param ilogico int Valor que indica que el estado es libre.
 * \return int Devuelve el indice del elemento, -1 en caso de error, o -2 en caso
 * de que no existan posiciones libres.
 *
 */
int buscarLibre_ePelicula(ePelicula listado[], int cantidad, int ilogico);

/** \brief Genera un id nuevo, tomando todos los ids existentes si los hay y devolviendo uno consecutivo inmediato
 *respecto al id que no tenga uno.
 *
 * \param listado[] ePelicula El array donde se recogen los ids.
 * \param cantidad int Tamanio del array.
 * \return int Devuelve el nuevo id o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int generarId_ePelicula(ePelicula listado[], int cantidad);

/** \brief Genera un array numerico con todos los ids existentes ordenados de menor a mayor;
 *
 * \param listado[] ePelicula  El array donde se recogen los ids.
 * \param cantidad int Tamanio del array.
 * \param listaDeIds[] int Array donde se guarda el array con los ids:
 * \param cantidadDeIds int Tamanio del array que recive los ids.
 * \return int Devuelve 0 si se realizo o -1 en caso de error (puntero NULL o cantidad < 1).
 *
 */
int generarListaOrdenadaDeIds_ePelicula(ePelicula listado[], int cantidad, int listaDeIds[], int cantidadDeIds);

/** \brief  Cuenta el total de los elementos con estado ocupado.
 *
 * \param listado[] ePelicula El array donde se buscan los elementos.
 * \param cantidad int Tamanio del array.
 * \return int Devuelve el numero de altas o -1 en caso de error(puntero NULL o cantidad < 1).
 *
 */
int contarAltas_ePelicula(ePelicula listado[], int cantidad);

/** \brief  Busca una pelicula por id y devuelve su indice.
 *
 * \param listado[] ePelicula El array donde se busca el indice.
 * \param cantidad int Tamanio del array.
 * \param id int El id a buscar.
 * \return int Devuelve el indice de la pelicula, -1 en caso de error(puntero NULL o cantidad < 1) o -2
 * si el indice no fue encontrado.
 *
 */
int buscarPorId_ePelicula(ePelicula listado[], int cantidad, int id);
