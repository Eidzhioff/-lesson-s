#include  <stdio.h >
#include <windows.h>
#include <locale.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *head = NULL;

void push(Node **head,int data){
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp -> value = data;
    tmp -> next = (*head);
    (*head) = tmp;
}

int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

Node* getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}


void pushBack(Node *head, int value) {
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}


int popBack(Node **head) {
    Node *front = NULL;
    Node *rear = NULL;
    if (!head) {
        exit(-1);
    }
    if (!(*head)) {
        exit(-1);
    }

    front = *head;
    while (front->next) {
        rear = front;
        front = front->next;
    }

    if (rear == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(front->next);
        rear->next = NULL;
    }
}


void remove_stack(Node **head) {
    Node* prev = NULL;
    while ((*head) != NULL) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
    if ((*head) != NULL){
        free(*head);
        }
}


void is_empty(Node *head){
if (head == NULL){
        printf("Stack is empty");
    }
else{
    return -1;
}
}

void view(Node *head) {
    is_empty(head);
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void serch(Node *head, int n) {
    int c = 0;
    int flag = 0;
    while (head) {
        c+=1;
        if(head->value == n){
            printf("This element have index: %d\n", c);
            flag = 1;
        }
        head = head->next;
    }
    if (flag != 1){
        printf("The element is not on the stack\n");
    }

}

void main(){
    int number, i;
    printf("Commands:\n");
    printf("Enter the number 1 to create the first element\n");
    printf("Enter the number 2 to add an element to the end\n");
    printf("Enter number 3 to remove the element from the end\n");
    printf("Enter the number 4 to see the stack\n");
    printf("Enter 5 to remove the stack\n");
    printf("Enter 6 to find the number on the stack\n");
    printf("Enter 7 to exit\n");
    while(i<2){
        printf("Enter the command ");
        scanf("%d",&number);
        switch(number){
        case 1:{
            int ans;
            printf("Enter  the number ");
            scanf("%d",&ans);
            push(&head,ans);
            break;
        }
        case 2:{
            int ans;
            printf("Enter  the number ");
            scanf("%d",&ans);
            pushBack(head,ans);
            break;
        }
        case 3:{
            printf("Element remove\n");
            popBack(&head);
            break;
        }
        case 4:{
            view(head);
            break;
        }
        case 5:{
            printf("Stack remove\n");
            remove_stack(&head);
            break;
        }
        case 6:{
            int ans;
            printf("Enter  the number ");
            scanf("%d",&ans);
            serch(head,ans);
            break;
        }
        case 7:{
            return -1;
        }
        }
    }

}
