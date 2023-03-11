#include  <stdio.h >
#include <string.h>

int randomArray(int n){
    /*Array Memory Allocation*/
    int a[n];
    int i;
    for(i=0;i<n;i++){
    /*We set random numbers in the range n from 0 to 100*/
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }



    printf("\n");

    char str[]="";
    printf("Choose a sorting method\n");
    printf("Selection sort - sel\n");
    printf("Insertion sort - ins\n");
    scanf("%s",str);
    /*Implementation of selection sort*/
    if (strcmp(str,"sel") == 0){
        int x,y;
        int min;
        int save;
        for (x = 0; x < n-1; x++){
            min=x;
            for (y=x+1;y<n;y++){
            /*Compare neighboring elements*/
                if(a[y]<a[min]){
                    min = y;
                }
            }
            /*swap them*/
            save=a[x];
            a[x]=a[min];
            a[min]=save;
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
}

int main(){
    randomArray(100);
    return 0;
}
