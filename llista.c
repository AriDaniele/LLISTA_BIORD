#include <stdio.h>
#include <stdlib.h>
#include "llista.h"


Llista LLISTA_crea(){
    Llista l;
    l.pri = (Node *)malloc(sizeof(Node));
    if (l.pri == NULL)
    {
        printf("Error!\n");
    }else{
        l.pri -> ant = NULL;
        l.ult = (Node *)malloc(sizeof(Node));
        if (l.ult == NULL)
        {
            printf("Error!\n");
            free(l.pri);
            l.pri = NULL;
        }else{
            l.ult -> seg = NULL;
            l.ult -> ant = l.pri;
            l.pri -> seg = l.ult;
            l.pdi = l.ult;
        }
    }
    return l;
}


void LLISTA_insereixOrdenat(Llista *l, Element e){
    Node *aux;
    int control = 0;
    if (l -> pdi -> ant == NULL)
    {
        printf("Error!\n");
    }else{
        aux = (Node*)malloc(sizeof(Node));
        if (aux == NULL)
        {
            printf("Error!\n");
        }else{
            LLISTA_vesInici(l);
            while(control == 0){
                if(l -> pdi == l -> ult){
                    control = 1;
                }else{
                    if(l -> pdi -> e > e){
                        control = 1;
                    }else{
                        LLISTA_avanca(l);
                    }
                }
            }
            aux -> e = e;
      			aux -> seg = l -> pdi;
      			aux -> ant = l -> ant;
      			l -> pdi -> ant -> seg = aux;
      			l -> pdi -> ant = aux;
        }
    }
}


Element LLISTA_consulta(Llista l){
    Element e = -1;
    if (l.pdi != l.pri && l.pdi != l.ult)
    {
        e = l.pdi -> e;
    }
    return e;
}


void LLISTA_esborra(Llista *l){
    Node *aux;
    if (l -> pdi != l -> pri && l -> pdi != l -> ult)
    {
        aux = l -> pdi;
        l -> pdi -> ant -> seg = l -> pdi -> seg;
        l -> pdi -> seg -> ant = l -> pdi -> ant;
        l -> pdi = l -> pdi -> seg;
        free(aux);
        aux = NULL;
    }
}


void LLISTA_avanca(Llista *l){
    if (l -> pdi -> seg != NULL)
    {
        l -> pdi = l -> pdi -> seg;
    }

}


void LLISTA_retrocedeix(Llista *l){
    if (l -> pdi -> ant != NULL)
    {
        l -> pdi = l -> pdi -> ant;
    }
}


void LLISTA_vesInici(Llista *l){
    l -> pdi = l -> pri -> seg;
}


void LLISTA_vesFi(Llista *l){
    l -> pdi = l -> ult -> ant;
}


int LLISTA_inici(Llista l){
    return l.pdi == l.pri;
}


int LLISTA_fi(Llista l){
    return l.pdi == l.ult;
}


int LLISTA_buida(Llista  l){
    return l.pri -> seg == l.ult;
}


void LLISTA_destrueix(Llista *l){
    Node *aux;
    while(l -> pri != NULL){
        aux = l -> pri;
        l -> pri = l -> pri -> seg;
        free(aux);
    }
    l -> pdi = NULL;
    l -> pri = NULL;
    l -> ult = NULL;
}
