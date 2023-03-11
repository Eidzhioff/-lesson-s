#include  <stdio.h >
#include <string.h>
#include <time.h>


/*I don't know what to explain here, it seems so clear*/
int search(int random, int a[], int n){
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (random < a[middle])
            high = middle - 1;
        else if (random > a[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}




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





    char str[40]="";
    int random;
    random = rand()%100;
    int fun_ran;
    fun_ran = search(random,a,n);




    printf("Choose a sorting method\n");
    printf("Selection sort - selection\n");
    printf("Insertion sort - insertion\n");
    scanf("%s",str);




    /*Implementation of selection sort*/
    if (strcmp(str,"selection") == 0){
        double time_spent = 0.0;
        int x,y;
        int min;
        int save;

        /*Start time*/
        clock_t begin = clock();

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
        printf("\n");

        /*End time*/
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("The elapsed time is %f seconds \n", time_spent);



        /*found our Element*/
        if (fun_ran != -1){
            printf("Element %d ,The index of the element is %d\n",random, fun_ran);
        }
        else
            printf("The element %d isn't found!\n",random);
    }






    /*Implementation of Insertion sort*/
    else if (strcmp(str,"insertion") == 0){
        double time_spent = 0.0;
        int j;
        int save;

        /*Start time*/
        clock_t begin = clock();

        for (i=1;i<n;i++){
            for (j=i;j>0 && a[j-1]>a[j];j--){
                save = a[j-1];
                a[j-1]=a[j];
                a[j]=save;
            }
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");

        /*End time*/
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("The elapsed time is %f seconds \n", time_spent);

        /*found our Element*/
        if (fun_ran != -1){
            printf("Element %d ,The index of the element is %d\n",random, fun_ran);
        }
        else
            printf("The element %d isn't found!\n",random);
    }
    else
        printf("Error, Incorrect input\n");


    printf("\n");



}

int main(){
    randomArray(1000);
    return 0;
}
