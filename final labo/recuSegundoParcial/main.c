#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "participantes.h"
#include "parser.h"
#include "utn.h"

int main()
{
    srand(time(NULL));
    int opcion;
    char path[50];
    char path2[50];
    int flag5=0;
    LinkedList* lista = ll_newLinkedList();

    do{
    	if(utn_getNumero(&opcion,
			 "\n---------------------\n"
			 "CARRERA OFF-ROAD\n"
			 "---------------------\n"
			 "\n1. Cargar archivo"
			 "\n2. Imprimir lista"
			 "\n3. Asignar promedios"
			 "\n4. Filtrar por tipo"
			 "\n5. Mostrar posiciones"
			 "\n6. Guardar posiones"
			 "\n7. Salir\n\n"
			 "Ingrese opcion:",
			 "Opcion no valida",1,7,10)==0)
       {
			switch(opcion)
			{
				case 1:
                    ll_clear(lista);
                    printf("\nIngrese nombre del archivo(enduro.csv):");
                    fflush(stdin);
                    gets(path);
                    if(!controller_loadFromText(path,lista))
                    {
                        printf("\nDatos cargados del archivo texto exitosamente");
                    }
				break;
				case 2:
				    if(ll_len(lista) > 0 )
					{
						controller_Listar(lista);
					}
					else
					{
						printf("\nPrimero debe cargar un archivo");
					}
			    break;
				case 3:
				    if(!strcmp(path,"enduro.csv"))
					{
						if(!controller_asignarPromedios(lista))
						{
							printf("\nAsignacion de promedios exitosa");
							controller_Listar(lista);
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo enduro.csv");
					}
			   break;
				case 4:
				    if(!strcmp(path,"enduro.csv"))
					{
						if(!controller_filtrarPorTipo(lista))
						{
							printf("\nOpcion finalizada");
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo enduro.csv");
					}
			   break;
				case 5:
					if(!strcmp(path,"enduro.csv") && flag5==0 )
					{
						if(!controller_sortEnduro(lista))
						{
							printf("\nOrdenamiento enduro exitosa");
							controller_Listar(lista);
							flag5=1;
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo enduro.csv");
					}
			   break;
				case 6:
                    if(!strcmp(path,"enduro.csv") && flag5==1)
					{
					    printf("\nIngrese nombre del archivo que desea guardar:");
                        fflush(stdin);
                        gets(path2);
						if(!controller_saveAsText(path2,lista))
						{
							printf("\nDatos guardados en archivo de texto exitosamente");
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo enduro.csv y entrar a la opcion 5");
					}
			}
       }
    }while(opcion != 7);

     ll_deleteLinkedList(lista);

    return 0;
}

