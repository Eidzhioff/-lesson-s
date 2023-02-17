#include  <stdio.h >
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <float.h>
int main(void){
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");
    float numf = 1.0/3.0;
    double numd = 1.0/3.0;
    printf("float: %.4f; double: %.4f \n", numf, numd);
    printf("float: %.12f; double: %.12f \n", numf, numd);
    printf("float: %.16f; double: %.16f \n", numf, numd);
    printf("%d %d", FLT_DIG, DBL_DIG);
    getchar();
    return 0;
}
