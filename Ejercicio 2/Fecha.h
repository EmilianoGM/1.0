#define ANIO_ACTUAL 2018

/**< 1.0 */

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

/** \brief Solicita una fecha al usuario y la devuelve.
 *
 * \param void
 * \return eFecha
 *
 */
eFecha pedir_eFecha(void);

/** \brief Muestra la fecha.
 *
 * \param fecha eFecha Es la fecha a mostrar.
 * \return void
 *
 */
void mostrar_eFecha(eFecha fecha);
