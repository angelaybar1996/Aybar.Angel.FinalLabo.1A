#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "participantes.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayList);
//int controller_loadFromBinary(char* path , LinkedList* pArrayList);
//int controller_addPais(LinkedList* pArrayList,int* pId);
//int controller_editPais(LinkedList* pArrayList,int auxId);
//int controller_removePais(LinkedList* pArrayList,int auxId);
int controller_Listar(LinkedList* pArrayList);
int controller_sortEnduro(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
//int controller_saveAsBinary(char* path , LinkedList* pArrayList);


int controller_filtrarPorTipo(LinkedList* pArrayList);
int controller_asignarPromedios(LinkedList* pArrayList);

#endif /* CONTROLLER_H_ */







