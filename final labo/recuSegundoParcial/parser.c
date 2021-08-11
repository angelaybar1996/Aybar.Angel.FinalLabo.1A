#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/** \brief Parsea los datos de las bicicletas desde el archivo data.csv (modo texto).
 *
 * \param pFile, puntero del archivo que se va a cargar en el linkedList
 * \param pArrayListBici puntero de la lista de bicicletas
 * \param auxId es el buffer donde se va a cargar en un principio el id obtenido del archivo
 * \param auxNombre es el buffer donde se va a cargar en un principio el nombre obtenido del archivo
 * \param auxTipo es el buffer donde se va a cargar en un principio las horas obtenido del archivo
 * \param auxTiempo es el buffer donde se va a cargar en un principio el sueldo obtenido del archivo
 * \return retorno -1(ERROR) 0 (EXITO)
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayList,char auxId[],char auxNombre[],char auxCate[],char auxTiempo[],char auxPromedio[])
{

	eParticipantes* pPart;
	int retorno=-1;

	do
	{
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxCate,auxTiempo,auxPromedio)==5)
		{
			pPart= participantes_newParametrosTxt(auxId, auxNombre, auxCate, auxTiempo, auxPromedio);
			if(pPart!=NULL)
			{
				ll_add(pArrayList, pPart);
			}
		}

	}while(!feof(pFile));
	retorno=0;

    return retorno;
}
