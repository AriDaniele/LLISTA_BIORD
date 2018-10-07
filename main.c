#include "llista.h"
#include <stdio.h>

int int main() {
  int opcio, i, e;
  char sortir = 'k';
  Llista l;
  l = LLISTA_crea();
  printf("Llista creada\n\n");
  printf("Ara introduirem 5 enters aleatoris a la llista\n");

  e = 4;
  LLISTA_insereixOrdenat(&l,e);
  printf("4 introduit\n");
  e = -3;
  LLISTA_insereixOrdenat(&l,e);
  printf("-3 introduit\n");
  e = 9;
  LLISTA_insereixOrdenat(&l,e);
  printf("9 introduit\n");
  e = 2;
  LLISTA_insereixOrdenat(&l,e);
  printf("2 introduit\n");
  e = 18;
  LLISTA_insereixOrdenat(&l,e);
  printf("18 introduit\n");


  printf("Ara mostrarem tota la llista des de l'inici fins al final (ordre ascendent):\n");
  LLISTA_vesInici(&l);
  i = 1;
  while(!LLISTA_fi(l)){
      printf("Element %d: %d\n",i,LLISTA_consulta(l));
      LLISTA_avanca(&l);
      i++;
  }

  i--;
  printf("\nAra mostrarem tota la llista des del final fins a l'inici (ordre descendent):\n");
  LLISTA_vesFi(&l);
  while(!LLISTA_inici(l)){
      printf("Element %d: %d\n",i,LLISTA_consulta(l));
      LLISTA_retrocedeix(&l);
      i--;
  }

  printf("\nA continuació la llista quedarà esborrada i es sortirà del programa\n");

  LLISTA_destrueix(&l);

  return 0;
}
