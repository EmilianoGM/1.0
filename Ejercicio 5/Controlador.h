int controlador_cargarEmpleados(char* path, LinkedList* pListaLinkeada);

int parser_txtSinSueldo(FILE* pArchivo, LinkedList* pListaLinkeada);

int controlador_printLinkedListeEmpleado(LinkedList* pListaLinkeada);

int controlador_ordenareEmpleado(LinkedList* pListaLinkeada);

int controlador_generarSueldo(LinkedList* pListaLinkeada);

float controlador_promedioSueldo(LinkedList* pListaLinkeada);

/*
int controlador_filtrareEmpleado(LinkedList* pListaLinkeada)
{
    int opcion;
    LinkedList* pAuxListaLinkeada = NULL;
    if(pListaLinkeada != NULL)
    {
        opcion = menuFiltrar();
        switch(opcion)
        {
            case 1:
                pAuxListaLinkeada = ll_filter(pListaLinkeada, eEmpleado_filtrarNombre);
                if(pAuxListaLinkeada != NULL)
                {
                    printf("Lista de datos filtrada por nombre\n");
                    controlador_printLinkedListeEmpleado(pAuxListaLinkeada);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 2:
                pAuxListaLinkeada = ll_filter(pListaLinkeada, eEmpleado_filtrarEntero);
                if(pAuxListaLinkeada != NULL)
                {
                    printf("Lista de datos filtrada por cantidad de horas trabajadas\n");
                    controlador_printLinkedListeEmpleado(pAuxListaLinkeada);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 3:
                pAuxListaLinkeada = ll_filter(pListaLinkeada, eEmpleado_filtrarFlotante);
                if(pAuxListaLinkeada != NULL)
                {
                    printf("Lista de datos filtrada por flotante\n");
                    controlador_printLinkedListeEmpleado(pAuxListaLinkeada);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 4:
                printf("\nLista no filtrada\n");
                break;
        }
        ll_deleteLinkedList(pAuxListaLinkeada);
        return 0;
    }
    return 1;
}
*/
int controlador_guardarTxtSueldos(char* path , LinkedList* pListaLinkeada, float promedio);
