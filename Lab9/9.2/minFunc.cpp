#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0)
    {
        return nullptr;
    }
    if (arrSize == 1)
    {
        return arr;
    }
    const int* rec = min(arr, arrSize - 1);
    if (arr[arrSize - 1] < *rec) // last element comparison
    {
        return arr + arrSize - 1;
    }
    else
    {
        return rec;
    }

}

