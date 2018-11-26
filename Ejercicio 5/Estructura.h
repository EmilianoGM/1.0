#define MAX_NOMBRE 128
#define MAX_DIRECCION 128
typedef struct
{
    int id;
    char nombre[MAX_NOMBRE];
    char direccion[MAX_DIRECCION];
    int horasTrabajadas;
    int sueldo;
}eEmpleado;

/** \brief Constructor
 *
 * \param void
 * \return void
 *
 */
eEmpleado* eEmpleado_nuevo(void);

eEmpleado* eEmpleado_nuevoParametrizado(char* idStr, char* nombreStr, char* direccionStr, char* horasTrabajadasStr, char* sueldoStr);

/** \brief Elimina de la memoria.
 *
 * \param this eEmpleado*
 * \return void
 *
 */
void eEmpleado_eliminar(eEmpleado* this);


/** \brief Establece el id.
 *
 * \param this eEmpleado*
 * \param id int
 * \return int
 *
 */
int eEmpleado_setId(eEmpleado* this,int id);

 /** \brief Devuelve el id.
 *
 * \param this eEmpleado*
 * \param id int*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int eEmpleado_getId(eEmpleado* this,int* id);

/** \brief Establece el nombre.
 *
 * \param this eEmpleado*
 * \param nombre char*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int eEmpleado_setNombre(eEmpleado* this,char* nombre);

/** \brief Devuelve el nombre.
 *
 * \param this eEmpleado*
 * \param nombre char*
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int eEmpleado_getNombre(eEmpleado* this,char* nombre);

int eEmpleado_getDireccion(eEmpleado* this, char* direccion);

int eEmpleado_setDireccion(eEmpleado* this, char* direccion);

int eEmpleado_setHorasTrabajadas(eEmpleado* this,int horasTrabajadas);

int eEmpleado_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas);

int eEmpleado_setSueldo(eEmpleado* this,int sueldo);

int eEmpleado_getSueldo(eEmpleado* this,int* sueldo);

int eEmpleado_print(eEmpleado* this);

int eEmpleado_compararNombre(void* this, void* thisDos);

int eEmpleado_calcularSueldo(void* this);
