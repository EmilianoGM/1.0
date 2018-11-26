#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int cont = 0;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        while(cont < nodeIndex)
        {
            cont++;
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pAuxPreviousNode = NULL;
    Node* pAuxNextNode = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNode = (Node *)malloc(sizeof(Node));
        if(pNode != NULL)
        {
            pNode->pElement = pElement;
            if(nodeIndex == 0)
            {
                pAuxPreviousNode = getNode(this, nodeIndex);
                this->pFirstNode = pNode;
                pNode->pNextNode = pAuxPreviousNode;
            } else
            {
                pAuxPreviousNode = getNode(this, (nodeIndex - 1));
                if(pAuxPreviousNode->pNextNode != NULL)
                {
                    pAuxNextNode = pAuxPreviousNode->pNextNode;
                }
                pAuxPreviousNode->pNextNode = pNode;
                pNode->pNextNode = pAuxNextNode;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice;
    if(this != NULL)
    {
        indice = ll_len(this);
        if(indice > -1)
        {
            if((addNode(this, indice, pElement)) == 0)
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int
 * \return void* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxNode = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pAuxNode = getNode(this, index);
        if(pAuxNode != NULL && pAuxNode->pElement != NULL)
        {
            returnAux = pAuxNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pAuxNode = getNode(this, index);
        if(pAuxNode != NULL)
        {
            pAuxNode->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pAuxNode = NULL;
    Node* pAuxPreviousNode = NULL;
    Node* pAuxNextNode = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pAuxNode = getNode(this, index);
        if(pAuxNode != NULL)
        {
            if(index == 0)
            {
                if(ll_len(this) == 1)
                {
                    this->pFirstNode = NULL;
                    returnAux = 0;
                }else
                {
                    pAuxNextNode = getNode(this, index + 1);
                    this->pFirstNode = pAuxNextNode;
                    returnAux = 0;
                }
            } else
            {
                pAuxPreviousNode = getNode(this, index - 1);
                if(pAuxNode->pNextNode != NULL)
                {
                    pAuxNextNode = getNode(this, index + 1);
                    pAuxPreviousNode->pNextNode = pAuxNextNode;
                    returnAux = 0;
                } else
                {
                    pAuxPreviousNode->pNextNode = NULL;
                    returnAux = 0;
                }
            }
            if(returnAux == 0)
            {
                this->size--;
                free(pAuxNode);
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* pAuxNode = NULL;
    Node* pAuxPreviousNode = NULL;
    int indice;
    if(this != NULL)
    {
        for(indice = ll_len(this) - 1; indice > 0; indice--)
        {
            pAuxPreviousNode = getNode(this, indice - 1);
            pAuxNode = pAuxPreviousNode->pNextNode;
            pAuxPreviousNode->pNextNode = NULL;
            free(pAuxNode);
        }
        pAuxNode = this->pFirstNode;
        this->pFirstNode = NULL;
        this->size = 0;
        free(pAuxNode);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(ll_clear(this) == 0)
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode = NULL;
    int indice;
    if(this != NULL)
    {
        for(indice = 0; indice < ll_len(this); indice++)
        {
            pAuxNode = getNode(this, indice);
            if(pAuxNode->pElement == pElement)
            {
                returnAux = indice;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        } else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        if(addNode(this, index, pElement) == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pAuxNode = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pAuxNode = getNode(this, index);
        if(pAuxNode != NULL)
        {
            returnAux = pAuxNode->pElement;
            ll_remove(this, index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice;
    if(this != NULL)
    {
        indice = ll_indexOf(this, pElement);
        if(indice > -1)
        {
            returnAux = 1;
        } else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* pAuxNode = NULL;
    int indice;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(indice = 0; indice < ll_len(this2); indice++)
        {
            pAuxNode = getNode(this2, indice);
            if(ll_contains(this, pAuxNode->pElement) != 1)
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pAuxNode = NULL;
    if(this != NULL && from >= 0 && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(;from < to; from++)
            {
                pAuxNode = getNode(this, from);
                ll_add(cloneArray, pAuxNode->pElement);
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    Node* pNode = NULL;
    Node* pNodeDos = NULL;
    void* pAuxElement = NULL;
    int indice;
    int j;
    if(this != NULL && ll_len(this) > 1 && (order == 0 || order == 1) && (*pFunc) != NULL)
    {
          if(order == 1)
          {
            for(indice = 0; indice < ll_len(this) - 1; indice++)
            {
                pNode = getNode(this, indice);
                if(pNode->pElement == NULL)
                {
                    continue;
                }
                for(j = indice + 1; j < ll_len(this); j++)
                {
                    pNodeDos = getNode(this, j);
                    if(pNodeDos->pElement == NULL)
                    {
                        continue;
                    }
                    if((*pFunc)(pNode->pElement, pNodeDos->pElement) == 1)
                    {
                        pAuxElement = pNode->pElement;
                        pNode->pElement = pNodeDos->pElement;
                        pNodeDos->pElement = pAuxElement;
                    }
                }
            }
            returnAux = 0;
          }
          if(order == 0)
          {
            for(indice = 0; indice < ll_len(this) - 1; indice++)
            {
                pNode = getNode(this, indice);
                if(pNode->pElement == NULL)
                {
                    continue;
                }
                for(j = indice + 1; j < ll_len(this); j++)
                {
                    pNodeDos = getNode(this, j);
                    if(pNodeDos->pElement == NULL)
                    {
                        continue;
                    }
                    if((*pFunc)(pNode->pElement, pNodeDos->pElement) == -1)
                    {
                        pAuxElement = pNode->pElement;
                        pNode->pElement = pNodeDos->pElement;
                        pNodeDos->pElement = pAuxElement;
                    }
                }
            }
            returnAux = 0;
        }
    }
    return returnAux;
}



/** \brief Crea y retorna una nueva lista con los elementos filtrados, utilizando la funcion criterio, de la lista recibida como parametro.
 *
 * \param this LinkedList* Puntero a la lista
 * \param (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna (NULL) Error si el puntero a la lista o el puntero a funcion son NULL
 *                             (Puntero a la nueva lista) Si OK
 */

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* cloneArray = NULL;
    Node* pAuxNode = NULL;
    int indice;
    if(this != NULL && (*pFunc) != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(indice = 0; indice < ll_len(this); indice++)
            {
                pAuxNode = getNode(this, indice);
                if(pAuxNode->pElement == NULL)
                {
                    continue;
                }
                if((*pFunc)(pAuxNode->pElement) == 1)
                {
                    ll_add(cloneArray, pAuxNode->pElement);
                }
            }
        }
    }
    return cloneArray;
}

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    Node* pAuxNode = NULL;
    int retorno = -1;
    int indice;
    if(this != NULL && (*pFunc) != NULL)
    {
        for(indice = 0; indice < ll_len(this); indice++)
        {
            pAuxNode = getNode(this, indice);
            (*pFunc)(pAuxNode->pElement);
        }
        retorno = 0;
    }
    return retorno;
}
