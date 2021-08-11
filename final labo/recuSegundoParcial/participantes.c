#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "participantes.h"

static int isValidId(char* cadena);
static int isValidNombre(char* nombre,int longitud);
static int isValidCate(char* nombre,int longitud);
static int isValidTiempo(char* cadena);
static int isValidPromedio(char* cadena);


/**
 * brief construye una bicicleta en memoria
 * return retorna el puntero a la bicicleta creado
 */
eParticipantes* participantes_new()
{
	eParticipantes* auxiliar;
	auxiliar=(eParticipantes*)malloc(sizeof(eParticipantes));
	return auxiliar;
}

/**
 * brief carga los datos ingresados por parametros en un puntero bicicleta
 * param idStr, id a cargar en el puntero bicicleta
 * param nombreStr,nombre a cargar en el puntero bicicleta
 * param tipoStr,tipo a cargar en el puntero bicicleta
 * param tiempoStr, tiempo a cargar en el puntero bicicleta
 * return retorno el puntero de bicicleta cargado
 */
eParticipantes* participantes_newParametrosTxt(char* idStr,char* nombreStr,char* cateStr,char* tiempoStr,char* promedioStr)
{
	eParticipantes* pPart;
	pPart=participantes_new();

		if(pPart!=NULL && idStr!=NULL && nombreStr !=NULL && cateStr != NULL && tiempoStr != NULL && promedioStr != NULL )
		{
			if(setIdTxt(pPart,idStr)==-1 ||
			   setNombre(pPart, nombreStr)==-1 ||
			   setCate(pPart, cateStr)==-1 ||
			   setTiempoTxt(pPart, tiempoStr)==-1 ||
               setPromedioTxt(pPart, promedioStr)==-1 )
			 {
				participantes_delete(pPart);
				pPart=NULL;
			 }
		}
		return pPart;
}

/**
 * brief carga los datos ingresados por parametros en un puntero bicicleta
 * param id, id a cargar en el puntero bicicleta
 * param nombre,nombre a cargar en el puntero bicicleta
 * param tipo,tipo a cargar en el puntero bicicleta
 * param tiempo, tiempo a cargar en el puntero bicicleta
 * return retorno el puntero de bicicleta cargado
 */
eParticipantes* participantes_newParametros(int id,char* nombre,char* cate,float tiempo,float promedio)
{
	eParticipantes* pPart;
	pPart=participantes_new();

	if(pPart!=NULL && id>=0 && nombre!=NULL && cate!=NULL && tiempo>=0  && promedio>=0)
	{
		if(setId(pPart,id)==-1 ||
		   setNombre(pPart, nombre)==-1 ||
		   setCate(pPart, cate)==-1 ||
		   setTiempo(pPart, tiempo)==-1 ||
           setPromedio(pPart, promedio)==-1)
		 {
			participantes_delete(pPart);
			pPart=NULL;
		 }
	}
	return pPart;
}

/**
 * brief libera una bicicleta de la memoria
 */
void participantes_delete(eParticipantes* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

/**
 * brief recibe un id  lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param id, es el id a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int setId(eParticipantes* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}

/**
 * brief le asigna el valor del id del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param id,puntero cargado con el valor del id del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int getId(eParticipantes*this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
	   *id=this->id;
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un id en texto lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param id, es el id a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int setIdTxt(eParticipantes* this,char* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		if(isValidId(id))
		{
			this->id=atoi(id);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del id del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param id,puntero cargado con el valor del id del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int getIdTxt(eParticipantes* this,char* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
       sprintf(id,"%d",this->id);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un nombre lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param nombre, es el nombre a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int setNombre(eParticipantes* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(isValidNombre(nombre,NOMBRE_TAM))
		{
			strcpy(this->nombre,nombre);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del nombre del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param nombre,puntero cargado con el valor del nombre del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int getNombre(eParticipantes* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un tipo lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param tipo, es el tipo a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int setCate(eParticipantes* this,char* categoria)
{
	int retorno=-1;
	if(this!=NULL && categoria!=NULL)
	{
		if(isValidCate(categoria,CATE_TAM))
		{
			strcpy(this->categoria,categoria);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del tipo del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param tipo,puntero cargado con el valor del tipo del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int getCate(eParticipantes* this,char* categoria)
{
	int retorno=-1;
	if(this!=NULL && categoria!=NULL)
	{
		strcpy(categoria,this->categoria);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un tiempo,lo verifica y lo cargar en el PunteroBici
 * param this, es un PunteroBici
 * param tiempo, es el tiempo a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int setTiempo(eParticipantes* this,float tiempo)
{
	int retorno=-1;
	if(this!=NULL && tiempo>=0)
	{
		retorno=0;
		this->tiempo=tiempo;
	}
	return retorno;
}

/**
 * brief le asigna el valor del tiempo del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param tiempo,puntero cargado con el valor del tiempo del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int getTiempo(eParticipantes* this,float* tiempo)
{
	int retorno=-1;
	if(this!=NULL && tiempo!=NULL)
	{
	   retorno=0;
	  *tiempo=this->tiempo;
	}
	return retorno;
}

/**
 * brief recibe un tiempo en texto,lo verifica y lo carga en el PunteroBici
 * param this, es un PunteroBici
 * param tiempo, es el tiempo a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int setTiempoTxt(eParticipantes* this,char* tiempo)
{
	int retorno=-1;
	float auxTiempo;
	if(this!=NULL && tiempo!=NULL)
	{
		if(isValidTiempo(tiempo))
		{
			auxTiempo= atof(tiempo);
			if(auxTiempo>=0)
			{
				this->tiempo=auxTiempo;
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del tiempo del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param tiempo,puntero cargado con el valor del tiempo del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int getTiempoTxt(eParticipantes* this,char* tiempo)
{
	int retorno=-1;
	if(this!=NULL && tiempo!=NULL)
	{
	   sprintf(tiempo,"%f",this->tiempo);
		retorno=0;
	}
	return retorno;
}

int setPromedio(eParticipantes* this,float promedio)
{
	int retorno=-1;
	if(this!=NULL && promedio>=0)
	{
		retorno=0;
		this->promedio=promedio;
	}
	return retorno;
}

int getPromedio(eParticipantes* this,float* promedio)
{
	int retorno=-1;
	if(this!=NULL && promedio!=NULL)
	{
	   retorno=0;
	  *promedio=this->promedio;
	}
	return retorno;
}

int setPromedioTxt(eParticipantes* this,char* promedio)
{
	int retorno=-1;
	float auxPromedio;
	if(this!=NULL && promedio!=NULL)
	{
		if(isValidPromedio(promedio))
		{
			auxPromedio= atof(promedio);
			if(auxPromedio>=0)
			{
				this->promedio=auxPromedio;
				retorno=0;
			}
		}
	}
	return retorno;
}

int getPromedioTxt(eParticipantes* this,char* promedio)
{
	int retorno=-1;
	if(this!=NULL && promedio!=NULL)
	{
	   sprintf(promedio,"%f",this->promedio);
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Verifica si el nombre ingresado es un nombre valido
 * \param nombre Cadena de caracteres a ser analizada
 * \param longitud Es la longitud del array resultado
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
static int isValidNombre(char* nombre,int longitud)
{
	int i=0;
	int retorno = 1;

	if(nombre != NULL && longitud > 0)
	{
		for(i=0 ; nombre[i] != '\0' && i < longitud; i++)
		{
			if((nombre[i] < 'A' || nombre[i] > 'Z' ) && (nombre[i] < 'a' || nombre[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si el tipo ingresado es un tipo valido
 * \param nombre Cadena de caracteres a ser analizada
 * \param longitud Es la longitud del array resultado
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
static int isValidCate(char* nombre,int longitud)
{
	int i=0;
	int retorno = 1;

	if(nombre != NULL && longitud > 0)
	{
		for(i=0 ; nombre[i] != '\0' && i < longitud; i++)
		{
			if((nombre[i] < 'A' || nombre[i] > 'Z' ) && (nombre[i] < 'a' || nombre[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 *\brief verifica si la cadena ingresada es numerica entera
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidId(char* cadena)
{
	int retorno=1;
	int i=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i] >'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/**
 *\brief verifica si la cadena ingresada es flotante
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidTiempo(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorPuntos=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i] >'9')
			{
				if(cadena[i]=='.' && contadorPuntos==0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno=0;
				    break;
				}
			}
		}
	}
	return retorno;
}

/**
 *\brief verifica si la cadena ingresada es flotante
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidPromedio(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorPuntos=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i] >'9')
			{
				if(cadena[i]=='.' && contadorPuntos==0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno=0;
				    break;
				}
			}
		}
	}
	return retorno;
}

int cmpCatePromedio(void* a, void* b)
{
    int retorno=0;
    eParticipantes* enduro1;
    eParticipantes* enduro2;
    if(a!=NULL && b!=NULL)
    {
       enduro1=(eParticipantes*)a;
       enduro2=(eParticipantes*)b;

       if(strcmp(enduro1->categoria,enduro2->categoria) > 0)
        {
            retorno = 1;
        }
        else if(strcmp(enduro1->categoria,enduro2->categoria) < 0)
        {
            retorno = -1;
        }
        else if(strcmp(enduro1->categoria,enduro2->categoria) == 0)
        {
            if(enduro1->promedio > enduro2->promedio)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}


int filterMx1(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eParticipantes*)pElement)->categoria,"MX1"))
     {
         retorno=1;
     }
     return retorno;
 }

int filterMx2(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eParticipantes*)pElement)->categoria,"MX2"))
     {
         retorno=1;
     }
     return retorno;
 }


int filterMx3(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eParticipantes*)pElement)->categoria,"MX3"))
     {
         retorno=1;
     }
     return retorno;
 }

int filterSuper(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eParticipantes*)pElement)->categoria,"SUPER_ATV"))
     {
         retorno=1;
     }
     return retorno;
 }

 /** \brief Asigna un tiempo aleatorio al elemento
  *
  * \param pElement void* puntero al elemento al cual se le va a cargar un tiempo aleatorio
  * \return Retorna el puntero al elemento con el tiempo aleatorio cargado
  *
  */
void* valorPromedio(void* pElement)
 {
    int numero;
    int min1=1;
    int min2=6;
    int min3=8;

    int max1=6;
    int max2=8;
    int max3=10;



    if( ((eParticipantes*)pElement)->tiempo < 15 )
    {
        numero= rand() % (max1 - min1 +1 ) + min1;
        ((eParticipantes*)pElement)->promedio= numero;
    }
    else if( ((eParticipantes*)pElement)->tiempo > 15 && ((eParticipantes*)pElement)->tiempo <20 )
    {
        numero= rand() % (max2 - min2 +1 ) + min2;
        ((eParticipantes*)pElement)->promedio= numero;
    }
    else if( ((eParticipantes*)pElement)->tiempo > 20 )
    {
        numero= rand() % (max3 - min3 +1 ) + min3;
        ((eParticipantes*)pElement)->promedio= numero;
    }


    return pElement;
 }

 /*
 void* valorVacunas(void* pElement)
 {
    int numero;
    int numero2;
    int numero3;
    int maxVac1=60;
    int maxVac2=40;

    int min=1;

    numero= rand() % (maxVac1 - min +1 ) + min;
    ((ePais*)pElement)->vac1dosis= numero;

    numero2= rand() % (maxVac2 - min +1 ) + min;
    ((ePais*)pElement)->vac2dosis= numero2;

    numero3=100-(numero+numero2);

    ((ePais*)pElement)->sinVacunar= numero3;

    return pElement;
 }
*/




