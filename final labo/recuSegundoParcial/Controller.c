#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "parser.h"


/**\brief Carga los datos de las bicicletas desde el archivo bicicletas.csv (modo texto).
 * \param path char* es el nombre del archivo
 * \param pArrayListBici LinkedList* el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{

	int retorno=-1;
	FILE* fpArchivo;
	char auxNombre[NOMBRE_TAM];
	char auxCate[CATE_TAM];
	char auxId[100];
	char auxTiempo[100];
	char auxPromedio[100];
	char confirma;

	if(pArrayList!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"r");
		if(fpArchivo==NULL)
        {
            printf("\nEl archivo no existe");
        }
		else
		{
		    retorno=0;
		    if(ll_len(pArrayList)>0)
            {
                printf("\nCuidado se van a sobreescribir los enduros.Confirma?(s / n):");
                fflush(stdin);
                scanf("%c",&confirma);
            }
            if(ll_len(pArrayList)==0 || confirma=='s')
            {
                //ll_clear(pArrayList);
                parser_FromText(fpArchivo, pArrayList, auxId, auxNombre, auxCate, auxTiempo,auxPromedio);
            }
		}
		fclose(fpArchivo);
	}
	return retorno;
}

/** \brief Carga los datos de los paises desde el archivo data.bin (modo binario).
 * \param path char* es el nombre del archivo
 * \param pArrayListPais LinkedList* el puntero de array de paises
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
 /*
int controller_loadFromBinary(char* path , LinkedList* pArrayList)
{
	int retorno=-1;
	FILE* fpArchivo;
	ePais* pElement=NULL;
	char confirma;

	if(pArrayList!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"rb");

		if(fpArchivo==NULL)
		{
		    printf("\nEl archivo no existe);
		}
		else
        {
            retorno=0;
            if(ll_len(pArrayList)>0)
            {
                printf("\nCuidado se van a sobreescribir las bicicletas.Confirma?(s / n):");
                fflush(stdin);
                scanf("%c",&confirma);
            }

            if(ll_len(pArrayList)==0 || confirma=='s')
            {
              ll_clear(pArrayList);
              parser_FromBinary(fpArchivo,pArrayList,pElement);
            }
        }
		fclose(fpArchivo);
	}
	return retorno;
}
*/

/** \brief Alta de paises
 *
 * \param pArrayListPais LinkedList* el puntero de array de paises
 * \param pId, es el id inicial al dar del alta
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_addPais(LinkedList* pArrayList,int* pId)
{
	int retorno=-1;
	ePais* pElement;
	char auxNombre[NOMBRE_TAM];
	float auxVac1dosis;
	float auxVac2dosis;
	float auxSinVacunar;

	if(pArrayList!=NULL && pId!=NULL)
	{
		if(!utn_getCadena(auxNombre,NOMBRE_TAM,"\nIngrese nombre:","\nError,nombre no valido",2) &&
		   !utn_getNumeroFlotante(&auxVac1dosis, "\nIngrese :", "\nError,horas no validas",1, 1000000, 2) &&
		   !utn_getNumeroFlotante(&auxSueldo, "\nIngrese Sueldo:", "\nError,sueldo no valido",1, 1000000, 2) &&
           !utn_getNumeroFlotante(&auxSueldo, "\nIngrese Sueldo:", "\nError,sueldo no valido",1, 1000000, 2))
		{
			pElement=entidad_newParametros(*pId, auxNombre, auxHorasTrabajadas, auxSueldo);
			if(pElement!=NULL)
			{
				ll_add(pArrayList, pElement);
				 (*pId)++;
				 retorno=0;
			}
		}
	}

	return retorno;
}
*/
/** \brief Modifica datos de empleado
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \param auxId, es el id del empleado a ser modificados sus datos
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_editEmployee(LinkedList* pArrayList, int auxId)
{
	int retorno=-1;
	int indiceModificar;
	Employee* pElement;
	int buffer;
	char auxNombre[NOMBRE_TAM];
	float auxHoras;
	float auxSueldo;



	if(pArrayList!=NULL && auxId>=0)
	{
		for(int i=0;i<ll_len(pArrayList);i++)
		{
			pElement=(Employee*)ll_get(pArrayList, i);
			getId(pElement,&buffer);
			if(buffer==auxId)
			{
				indiceModificar=i;
				break;
			}
		}

		if(indiceModificar>=0)
		{
			if(!utn_getCadena(auxNombre,NOMBRE_TAM,"\nIngrese nombre:","\nError,nombre no valido",2) &&
			   !utn_getNumeroFlotante(&auxHoras, "\nIngrese horas trabajadas:", "\nError,horas  no valida",1, 1000000, 2) &&
			   !utn_getNumeroFlotante(&auxSueldo, "\nIngrese sueldo:", "\nError,sueldo  no valido",1, 1000000, 2) )
			{

				setNombre(auxEmpleado, auxNombre);
				setHorasTrabajadas(auxEmpleado, auxHoras);
				setSueldo(auxEmpleado, auxSueldo);

			}
			ll_set(pArrayList, indiceModificar,(Employee*) pElement);
			retorno=0;
		}
	}
	return retorno;
}
*/
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \param auxId, es el id del empleado a ser dado de baja
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_removeEmployee(LinkedList* pArrayList, int auxId)
{
	int retorno=-1;
	int indiceBorrar;
	Employee* pElement;
	int buffer;
	if(pArrayList!=NULL && auxId>=0)
	{
		for(int i=0;i<ll_len(pArrayList);i++)
		{
			pElement=(Employee*)ll_get(pArrayList, i);
			getId(pElement,&buffer);
			if(buffer==auxId)
			{
				indiceBorrar=i;
				break;
			}
		}

		if(indiceBorrar>=0)
		{
			ll_remove(pArrayList, indiceBorrar);
		    retorno=0;
		}
	}

	return retorno;
}
*/

int controller_Listar(LinkedList* pArrayList)
{
	int retorno=-1;
	int i;
	eParticipantes* pPart;
	int auxId;
	char auxNombre[NOMBRE_TAM];
	char auxCate[CATE_TAM];
	float auxTiempo;
	float auxPromedio;

	if(pArrayList!=NULL)
	{
		printf("\n----------LISTA ENDUROS-------------\n");
		for(i=0;i<ll_len(pArrayList);i++)
		{
			pPart=(eParticipantes*)ll_get(pArrayList, i);

			if(!getId(pPart,&auxId) &&
			   !getNombre(pPart,auxNombre) &&
			   !getCate(pPart,auxCate) &&
			   !getTiempo(pPart,&auxTiempo) &&
               !getPromedio(pPart,&auxPromedio))
			{
				printf("ID: %d - Nombre: %s - Categoria: %s - Tiempo: %f - Promedio: %f\n",auxId,auxNombre,auxCate,auxTiempo,auxPromedio);
			}
		}
		retorno=0;
	}

	return retorno;
}

/** \brief Ordenar las bicicletas por tipos y si es del mismo tipo por tiempo
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_sortEnduro(LinkedList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        ll_sort(pArrayList, cmpCatePromedio, 1);//ascendente

    	retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los bicicletas en el archivo data.csv (modo texto).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	eParticipantes* pPart;

	int auxId;
	char auxNombre[NOMBRE_TAM];
	char auxCate[CATE_TAM];
	float auxTiempo;
	float auxPromedio;
	char confirma='s';


	if(pArrayList!=NULL && path!=NULL)
	{
	    fpArchivo=fopen(path,"r");
        if(fpArchivo!=NULL)
        {
           printf("\nCuidado el archivo existe y se va a sobrescribir.Confirma (s / n)?:");
           fflush(stdin);
           scanf("%c",&confirma);
        }
        fclose(fpArchivo);

        if(confirma=='s')
        {
            fpArchivo=fopen(path,"w");
            if(fpArchivo!=NULL)
            {
                retorno=0;
                for(i=0;i<ll_len(pArrayList);i++)
                {
                    pPart=(eParticipantes*)ll_get(pArrayList,i);

                    if(!getId(pPart,&auxId) &&
                       !getNombre(pPart, auxNombre) &&
                       !getCate(pPart,auxCate) &&
                       !getTiempo(pPart, & auxTiempo) &&
                       !getPromedio(pPart, & auxPromedio))
                    {
                        fprintf(fpArchivo,"%d,%s,%s,%f,%f\n",auxId,auxNombre,auxCate,auxTiempo,auxPromedio);
                    }
                }
                fclose(fpArchivo);
            }
        }
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_saveAsBinary(char* path , LinkedList* pArrayList)
{
	int retorno=-1;
	FILE* fpArchivo;
	Employee* pElement;
	char confirma='s';


	if(path!=NULL && pArrayList!=NULL)
	{
	   fpArchivo=fopen(path,"rb");
	   if(fpArchivo !=NULL)
       {
			printf("\nCuidado el archivo existe y se va a sobrescribir.Confirma (s / n)?:");
            fflush(stdin);
            scanf("%c",&confirma);
       }
       fclose(fpArchivo);

       if(confirma='s')
       {
          fpArchivo=fopen(path,"wb");
          if(fpArchivo!=NULL)
          {
                retorno=0;
                for(int i=0;i<ll_len(pArrayList);i++)
                {
                    pElement=(Employee*)ll_get(pArrayList,i);
                    fwrite(pElement,sizeof(Employee),1,fpArchivo);
                }
          }
          fclose(fpArchivo);
       }
	}
	return retorno;
}
*/


/** \brief Busca el id mas grande del pArrayListBici previamente cargado de un archivo
 *  y le suma 1 para que el siguiente id dado de alta sea continuo
 *
 * \param pArrayListBici LinkedList*  el puntero de array de bicicletas
 * \param id, es el id actual a ser actualizado
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int buscarMayorId(LinkedList* pArrayList,int* id)
{
    int retorno=-1;
    eParticipantes* pPart=NULL;
    int mayor;
    if(pArrayList!=NULL)
    {
        for(int i=0;i<ll_len(pArrayList);i++)
        {
            pPart=( eParticipantes*)ll_get(pArrayList,i);
            if(i==0 || pPart->id > mayor)
            {
                getId(pElement, &mayor);
            }
        }
        *id=mayor+1;

        retorno=0;
    }
    return retorno;
}
*/

/** \brief Recibe el linkedlist original y filtra por tipo de bicicleta y crea un nuevo archivo segun tipo
 *
 * \param pArrayListBici LinkedList* puntero linkedList de la lista de bicicletas
 * \return retorna 0(EXITO) -1(ERROR)
 *
 */
int controller_filtrarPorTipo(LinkedList* pArrayList)
{
    int opcion;
    LinkedList* mx1=ll_newLinkedList();
    LinkedList* mx2=ll_newLinkedList();
    LinkedList* mx3=ll_newLinkedList();
    LinkedList* super=ll_newLinkedList();
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        do{
            if(utn_getNumero(&opcion,
                 "\n---------------------\n"
                 "FILTRAR POR TIPO\n"
                 "---------------------\n"
                 "\n1. MX1"
                 "\n2. MX2"
                 "\n3. MX3"
                 "\n4. SUPER_ATV"
                 "\n5. Salir\n\n"
                 "Ingrese opcion:",
                 "Opcion no valida",1,5,3)==0)
           {
                switch(opcion)
                {
                    case 1:
                        mx1=ll_filter(pArrayList,filterMx1);
                        if(!controller_saveAsText("mx1.csv",mx1))
                        {
                            printf("Archivo  mx1.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(mx1);
                    break;
                   case 2:
                        mx2=ll_filter(pArrayList,filterMx2);
                        if(!controller_saveAsText("mx2.csv",mx2))
                        {
                            printf("Archivo  mx2.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(mx2);
                    break;
                    case 3:
                        mx3=ll_filter(pArrayList,filterMx3);
                        if(!controller_saveAsText("mx3.csv",mx3))
                        {
                            printf("Archivo  mx3.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(mx3);
                   break;
                    case 4:
                        super=ll_filter(pArrayList,filterSuper);
                        if(!controller_saveAsText("super.csv",super))
                        {
                            printf("Archivo  super.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(super);
                   break;
                }
           }
        }while(opcion != 5);
         retorno=0;
    }
    return retorno;
}

/** \brief Recibe el LinkedList y le asigna tiempos aleatorios a sus elementos
 *
 * \param pArrayBici LinkedList* puntero LinkedList
 * \return  Retorna -1(ERROR) 0 (EXITO)
 *
 */
int controller_asignarPromedios(LinkedList* pArrayList)
{
    int retorno=-1;
    LinkedList* nuevoLinkedList=ll_newLinkedList();

    if(pArrayList!=NULL)
    {
        nuevoLinkedList=ll_map(pArrayList,valorPromedio);
        pArrayList=nuevoLinkedList;
        retorno=0;
    }

    return retorno;
}


