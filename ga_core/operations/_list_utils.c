#include <Python.h>
#include <stdio.h>
#include "include/list_utils.h"


// swipe items on i-th and j-th positions
int swap_PyObject(PyObject* arr, int i, int j) {
    PyObject* temp = PyList_GetItem(arr, i);
    PyList_SetItem(arr, i, PyList_GetItem(arr, j));
    PyList_SetItem(arr, j, temp);

    return 0;
}

// Partition the array using the last element as the pivot
int partition(PyObject* arr, int low, int high) {
    // Choosing the pivot
    int pivot = PyList_GetItem(arr, high);
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (PyList_GetItem(arr, j) < pivot) {
            // Increment index of smaller element
            i++;
            swap_PyObject(arr, i, j);
        }
    }
    swap_PyObject(arr, i + 1, high);
    return (i + 1);
}
