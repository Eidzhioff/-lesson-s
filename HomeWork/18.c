#include  <stdio.h >
#include <windows.h>
#include <locale.h>
#include <string.h>
int main(void){
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");
  char name[40], surname[40];
  printf("¬ведите ваше им€\n");
  scanf("%s",&name);
  printf("¬ведите вашу фамилию\n");
  scanf("%s",&surname);
  printf("%s %s\n",name,surname);
  printf("%*d %*d\n",strlen(name),strlen(name),strlen(surname),strlen(surname));
  printf("%s %s\n",name,surname);
  printf("%-*d %-*d",strlen(name),strlen(name),strlen(surname),strlen(surname));
  return 0;
}
