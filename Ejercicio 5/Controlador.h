/** \brief Carga los datos desde el archivo (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pListaLinkeada LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_cargarTxt(char* path, LinkedList* pListaLinkeada);

/** \brief Carga los datos desde el archivo (modo binario).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pListaLinkeada LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
 int controlador_cargarBinario(char* path, LinkedList* pListaLinkeada);

 /** \brief Parsea desde un archivo en modo texto.
 *
 * \param pArchivo FILE*
 * \param pListaLinkeada LinkedList*
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_txt(FILE* pArchivo, LinkedList* pListaLinkeada);

/** \brief Parsea desde un archivo en modo binario.
 *
 * \param pArchivo FILE*
 * \param pListaLinkeada LinkedList*
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_binario(FILE* pArchivo, LinkedList* pListaLinkeada);

 /** \brief Agrega.
 *
 * \param pListaLinkeada LinkedList* Lista linkeada a la cual se agrega el dato.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_altaGenerica(LinkedList* pListaLinkeada);

/** \brief Modificar datos. Pide un id al usuario para buscar el dato a modificar.
 *
 * \param pListaLinkeada LinkedList* Lista linkeada donde se obtiene el dato.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_modificarGenerica(LinkedList* pListaLinkeada);

/** \brief Elimina un dato. Pide un id al usuario para buscar el dato a eliminar.
 *
 * \param pListaLinkeada LinkedList* Lista linkeada donde se obtiene el dato.
 * \return Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_bajaGenerica(LinkedList* pListaLinkeada);

/** \brief Genera un nuevo id.
 *
 * \param pListaLinkeada LinkedList*
 * \return int Retorna el id o -1 en caso de ERROR o puntero NULL
 *
 */
int controlador_nuevoId(LinkedList* pListaLinkeada);

/** \brief Busca el id de un dato en el LinkedList y devuelve el indice de su posicion.
 *
 * \param pListaLinkeada LinkedList*  Lista linkeada donde se obtiene el dato.
 * \param id_aBuscar int Id a buscar.
 * \return int Devuelve -1 (ERROR) si el puntero de la lista es NULL o el id no existe y el indice (OK) si lo encuentra.
 *
 */
int controlador_buscarId(LinkedList* pListaLinkeada, int id_aBuscar);

/** \brief Listar datos. Imprime todos los datos en la lista linkeada a la pantalla.
 *
 * \param pListaLinkeada LinkedList* Lista linkeada donde se obtienen los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_printLinkedListGenerica(LinkedList* pListaLinkeada);

/** \brief Clona la lista linkeada, la ordena segun el criterio, la muestra en pantalla y se elimina sin modificar la original.
 *
 * \param pListaLinkeada LinkedList* Lista linkeada donde se obtienen los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_ordenarGenerica(LinkedList* pListaLinkeada);

/** \brief Clona la lista linkeada, la filtra segun el criterio, la muestra en pantalla y se elimina sin modificar la original.
 *
 * \param pListaLinkeada LinkedList*
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_filtrarGenerica(LinkedList* pListaLinkeada);


int controlador_informes(LinkedList* pListaLinkeada);

/** \brief Guarda los datos en el archivo (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pListaLinkeada LinkedList* Lista linkeada donde se obtienen los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_guardarTxt(char* path , LinkedList* pListaLinkeada);

/** \brief Guarda los datos en el archivo(modo binario).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pListaLinkeada LinkedList* Lista linkeada donde se obtienen los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controlador_guardarBinario(char* path , LinkedList* pListaLinkeada);
