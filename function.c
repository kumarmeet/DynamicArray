typedef struct
{
    int capacity;
    int lastIndex;
    int *p;
} DynamicArray;

//dynamically reduce double memory reallocated when element is less than capacity
halfArray(DynamicArray *arr)
{
    arr->p = realloc(arr->p, (arr->capacity / 2) * sizeof(int));
    arr->capacity /= 2;
}

//dynamically double memory reallocated when capacity is full
void doubleArray(DynamicArray *arr)
{
    arr->p = realloc(arr->p, (arr->capacity * 2) * sizeof(int));
    arr->capacity *= 2;
    arr->lastIndex += 1;
}

void deleteItem(DynamicArray *arr, int index)
{
    int i;
    if(index < 0 || index > arr->lastIndex)
        printf("\nInvalid Index");
    else if(countItems(arr) <= arr->capacity / 2)
    {
        halfArray(arr);
    }
    else
    {
        for(i = index; i <= arr->lastIndex; i++)
            arr->p[i] = arr->p[i+1];
        arr->lastIndex -= 1;
    }
}

DynamicArray* createArray(int cap)
{
    DynamicArray *arr;
    arr = (DynamicArray*) malloc(sizeof(DynamicArray));
    arr->capacity = cap;
    arr->lastIndex = -1;
    arr->p = (int*) malloc(sizeof(int) * cap);
    return arr;
}

void insertItem(DynamicArray *arr, int index, int value)
{
    int i;
    if(index < 0 || index > arr->lastIndex + 1)
        printf("\nInvalid Index");
    else if(arr->lastIndex + 1 == arr->capacity)
        doubleArray(arr);
    else
    {
        for(i = arr->lastIndex; i >= index; i--)
            arr->p[i+1] = arr->p[i];
        arr->p[index] = value;
        arr->lastIndex += 1;
    }
}

void appendItem(DynamicArray *arr, int value)
{
    if(arr->lastIndex + 1 == arr->capacity)
    {
        doubleArray(arr);
        arr->p[arr->lastIndex] = value;
    }
    else
    {
        arr->lastIndex += 1;
        arr->p[arr->lastIndex] = value;
    }
}

void searchItem(DynamicArray *arr, int value)
{
    int i, found = 0;
    if(arr->lastIndex < 0)
        printf("\nNo item found");
    else
        for(i = 0; i <= arr->lastIndex; i++)
            if(value == arr->p[i])
            {
                found = 1;
                break;
            }

    if(found == 1)
        printf("%d has in items", value);
    else
        printf("%d has not in items", value);
}

void editItems(DynamicArray *arr, int index, int value)
{
    if(index < 0 || index > arr->lastIndex)
        printf("\nInvalid Index");
    else
        arr->p[index] = value;
}

int countItems(DynamicArray *arr)
{
    return arr->lastIndex + 1;
}

int isFull(DynamicArray *arr)
{
    if(arr->lastIndex + 1 == arr->capacity)
        return 1;
    return 0;
}

int isEmpty(DynamicArray *arr)
{
    if(arr->lastIndex == -1)
        return 1;
    return 0;
}

int getItem(DynamicArray *arr, int index)
{
    if(index < 0 || index > arr->lastIndex)
        return 0;

    return arr->p[index];
}
