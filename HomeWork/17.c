#include  <stdio.h >
#include <windows.h>
#include <locale.h>

int main(void){
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");
  float length1, length2;
  printf("�������, ����������, ��� ����\n");
  scanf("%f",&length1);
  length2 = length1 / 100;
  printf("�����, ��� ���� ���������� %f ��, ��� �� %f �",length1,length2);
  return 0;
}
