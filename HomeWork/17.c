#include  <stdio.h >
#include <windows.h>
#include <locale.h>

int main(void){
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");
  float length1, length2;
  printf("¬ведите, пожалуйста, ваш рост\n");
  scanf("%f",&length1);
  length2 = length1 / 100;
  printf("Ћарри, ваш рост составл€ет %f см, или же %f м",length1,length2);
  return 0;
}
