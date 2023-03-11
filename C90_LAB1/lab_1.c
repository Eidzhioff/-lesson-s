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

/*Implementation of Insertion sort*/
void insertion(int a[],int n){
        int x,y;
        int i;
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
}
/*Implementation of Selection sort*/
void selection(int a[],int n){
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
}

int main(){
    int n = 1000;/*Choice Array range*/
    int a[n];
    int i;
    printf("Our Array, with %d Elements: \n",n);
    for(i=0;i<n;i++){
    /*We set random numbers in the range n from 0 to 100*/
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }
    printf("\n");

    char str[40]="";
    printf("Choose a sorting method\n");
    printf("Selection sort - selection\n");
    printf("Insertion sort - insertion\n");
    scanf("%s",str);

    if (strcmp(str,"selection") == 0){
        double time_spent = 0.0;

        /*Start time*/
        clock_t begin = clock();

        selection(a,n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        /*End time*/
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("The elapsed time is %f seconds \n", time_spent);
    }
    else if (strcmp(str,"insertion") == 0){
        double time_spent = 0.0;

        /*Start time*/
        clock_t begin = clock();

        insertion(a,n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        /*End time*/
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("The elapsed time is %f seconds \n", time_spent);
    }
    else
        printf("Error, Incorrect input\n");



    /*Generate random element*/
    int random;
    random = rand()%100;
    int fun_ran;
    fun_ran = search(random,a,n);


    /*found our Element*/
    if (fun_ran != -1){
        printf("Element %d ,The index of the element is %d\n",random, fun_ran);
    }
    else
        printf("The element %d isn't found!\n",random);


    return 0;
}
