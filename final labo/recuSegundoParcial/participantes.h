#ifndef PARTICIPANTES_H_INCLUDED
#define PARTICIPANTES_H_INCLUDED
#define NOMBRE_TAM 128
#define CATE_TAM 128
typedef struct
{
    int id;
    char nombre[NOMBRE_TAM];
    char categoria[CATE_TAM];
    float tiempo;
    float promedio;

}eParticipantes;

eParticipantes* participantes_new();
eParticipantes* participantes_newParametrosTxt(char* idStr,char* nombreStr,char* cateStr,char* tiempoStr,char* promedioStr);
eParticipantes* participantes_newParametros(int id,char* nombre,char* cate,float tiempo,float promedio);
void participantes_delete(eParticipantes* this);

int setId(eParticipantes* this,int id);
int getId(eParticipantes*this,int* id);
int setIdTxt(eParticipantes* this,char* id);//texto
int getIdTxt(eParticipantes* this,char* id);//texto

int setNombre(eParticipantes* this,char* nombre);
int getNombre(eParticipantes* this,char* nombre);

int setCate(eParticipantes* this,char* categoria);
int getCate(eParticipantes* this,char* categoria);

int setTiempo(eParticipantes* this,float tiempo);
int getTiempo(eParticipantes* this,float* tiempo);
int setTiempoTxt(eParticipantes* this,char* tiempo);//texto
int getTiempoTxt(eParticipantes* this,char* tiempo);//texto


int setPromedio(eParticipantes* this,float promedio);
int getPromedio(eParticipantes* this,float* promedio);
int setPromedioTxt(eParticipantes* this,char* promedio);//texto
int getPromedioTxt(eParticipantes* this,char* promedio);//texto

int cmpCatePromedio(void* a, void* b);

int filterMx1(void* pElement);
int filterMx2(void* pElement);
int filterMx3(void* pElement);
int filterSuper(void* pElement);

void* valorPromedio(void* pElement);


#endif // PARTICIPANTES_H_INCLUDED
