#ifndef _LLISTA_H_
#define _LLISTA_H_

typedef int Element;
typedef struct N{
    Element e;
    struct N *seg;
    struct N *ant;
}Node;

typedef struct{
    Node *pri;
    Node *ult;
    Node *pdi;
}Llista;


Llista LLISTA_crea();
void LLISTA_insereixOrdenat(Llista *l, Element e);
Element LLISTA_consulta(Llista l);
void LLISTA_esborra(Llista *l);
void LLISTA_avanca(Llista *l);
void LLISTA_retrocedeix(Llista *l);
void LLISTA_vesInici(Llista *l);
void LLISTA_vesFi(Llista *l);
int LLISTA_inici(Llista l);
int LLISTA_fi(Llista l);
int LLISTA_buida(Llista l);
void LLISTA_destrueix(Llista *l);

#endif

