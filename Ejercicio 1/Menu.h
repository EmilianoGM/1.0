/** \brief Imprime el menu principal en pantalla.
 *
 * \param void
 * \return void
 *
 */
void mostrarMenuPrincipal(void);

/** \brief Imprime el menu listar en pantalla.
 *
 * \param void
 * \return void
 *
 */
void mostrarMenuListar(void);

/** \brief Solicita al usuario una opcion del menu principal.
 *
 * \param void
 * \return int
 *
 */
int menuPrincipal(void);

void menuAltaPelicula(ePelicula listadoPeliculas[], int cantidadPeliculas, eDirector listadoDirectores[], int cantidadDirectores);

/** \brief Solicita un id al usuario para dar de baja una pelicula.
 *
 * \param listadoPeliculas[] ePelicula
 * \param cantidadPeliculas int
 * \return void
 *
 */
void menuBajaPelicula(ePelicula listadoPeliculas[], int cantidadPeliculas);

/** \brief Solicita un id al usuario para modificar una pelicula, valida que se encuentre en el array
 * de peliculas, y solicita una opcion del campo a modificar.
 *
 * \param listadoPeliculas[] ePelicula El array donde se busca el id.
 * \param cantidadPeliculas int Tamanio del array.
 * \param listadoDirectores[] eDirector El array de directores para comprobar el nombre en caso de que se modifique.
 * \param cantidadDirectores int Tamanio del array de directores.
 * \return void
 *
 */
void menuModificarPelicula(ePelicula listadoPeliculas[], int cantidadPeliculas, eDirector listadoDirectores[], int cantidadDirectores);

/** \brief Solicita al usurio un nombre de un director, valida que este se encuentre en el array
 * de directores y lo da de baja junto con todas las peliculas en las que se incluya el nombre.
 *
 * \param listadoDirectores[] eDirector El array donde se busca el nombre.
 * \param cantidadDirectores int Tamanio del array.
 * \param listadoPeliculas[] ePelicula El array de peliculas a modificar en caso exitoso.
 * \param cantidadPeliculas int Tamanio del array.
 * \return void
 *
 */
void menuBajaDirector(eDirector listadoDirectores[], int cantidadDirectores, ePelicula listadoPeliculas[], int cantidadPeliculas);

void menuDirectorConCantidad(ePelicula listadoPeliculas[], int cantidadPeliculas, eDirector listadoDirectores[], int cantidadDirectores);

/** \brief Solicita al usuario una opcion para mostrar datos en pantalla segun indique.
 *
 * \param listadoPeliculas[] ePelicula Array de peliculas.
 * \param cantidadPeliculas int Tamanio del array de peliculas.
 * \param listadoDirectores[] eDirector Array de directores.
 * \param cantidadDirectores int Tamanio del array de directores.
 * \return void
 *
 */
void menuListar(ePelicula listadoPeliculas[], int cantidadPeliculas, eDirector listadoDirectores[], int cantidadDirectores);
