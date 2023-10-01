#include <Python.h>
#include <stdio.h>
#include "include/list_utils.h"
#include "include/sorting.h"


PyObject* bubble_sort(PyObject* self, PyObject* args) {
    PyObject* arr;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &arr)) {
        return NULL;
    }

    int size = PyList_Size(arr);
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (PyList_GetItem(arr, j) > PyList_GetItem(arr, j+1)) {
                swap_PyObject(arr, j, j+1);
            }
        }
    }

    return arr;
}

PyObject* quick_sort(PyObject* self, PyObject* args) {
    PyObject* arr;
    int low, high;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &arr)) {
        return NULL;
    }

    low = 0;
    high = PyList_Size(arr);
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    PyList_SetItem(arr, ++top, low);
    PyList_SetItem(arr, ++top, high);
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        high = PyList_GetItem(arr, top--);
        low = PyList_GetItem(arr, top--);;
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, low, high);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > low) {
            PyList_SetItem(arr, ++top, low);
            PyList_SetItem(arr, ++top, p-1);
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < high) {
            PyList_SetItem(arr, ++top, p+1);
            PyList_SetItem(arr, ++top, high);
        }
    }

    return arr;
}
