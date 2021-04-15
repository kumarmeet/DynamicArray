#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int capacity;
    int lastIndex;
    int *p;
} DynamicArray;

int menu();
void printMetaData(DynamicArray *arr);
DynamicArray* createArray(int);
void appendItem(DynamicArray*, int);
void insertItem(DynamicArray*, int, int);
void deleteItem(DynamicArray*, int);
int getItem(DynamicArray*, int);
int isEmpty(DynamicArray*);
int isFull(DynamicArray*);
int countItems(DynamicArray*);
void editItems(DynamicArray*, int, int);
void searchItem(DynamicArray*, int);
void doubleArray(DynamicArray*);
void halfArray(DynamicArray*);

int main()
{
    int value, index;
    DynamicArray *arr;
    arr=createArray(4);

    while(1)
    {
        system("cls");
        printMetaData(arr);
        switch(menu())
        {
        case 1:
            printf("\nAppend Item");
            printf("\nEnter value - >");
            scanf("%d",&value);
            appendItem(arr,value);
            break;
        case 2:
            printf("\nInsert Item");
            printf("\nEnter index number ->");
            scanf("%d",&index);
            printf("\nEnter value ->");
            scanf("%d",&value);
            insertItem(arr,index,value);
            break;
        case 3:
            printf("\nDelete Item");
            printf("\nEnter index number ->");
            scanf("%d",&index);
            deleteItem(arr,index);
            break;
        case 4:
            printf("\nGet Item");
            printf("\nEnter index number ->");
            scanf("%d",&index);
            printf("\n%d",getItem(arr,index));
            break;
        case 5:
            printf("\nSearch Item");
            printf("\nEnter value number ->");
            scanf("%d",&value);
            searchItem(arr, value);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nPlease enter correct choice");
            break;
        }
        getch();
    }

    return 0;
}

void printMetaData(DynamicArray *arr)
{
    int i;
    printf("Is Empty? -> %s\n", isEmpty(arr) ? "Yes" : "No"); //this line occurring logical error | correct this
    printf("Total values in array -> %d\n",countItems(arr));
    printf("Array Capacity -> %d\n", arr->capacity);
    for(i = 0 ; i <= arr->lastIndex; i++)
        printf("%d ",arr->p[i]);
}

int menu()
{
    int ch;

    printf("\n1.Append Item");
    printf("\n2.Insert Item");
    printf("\n3.Delete Item");
    printf("\n4.Get Item");
    printf("\n5.Search Item");
    printf("\n6.Exit");
    printf("\nEnter Your choice -> ");
    scanf("%d",&ch);

    return ch;
}
