#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "include/operations/list_utils.h"
#include "include/operations/sorting.h"


int* _bubble_sort(int array[], int n) {
    int i, j;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    return array;
}

int* _selection_sort(int array[], int n) {
    int i, j, min_element;
    
    for (i = 0; i < n-1; i++) {
        min_element = i;
        for (j = i+1; j < n; j++){
            if (array[j] < array[min_element]) {
                min_element = j;
                int temp = array[min_element];
                array[min_element] = array[i];
                array[i] = temp;
            }
        }
    }
    
    return array;
}

// bubble sort python wrapper
PyObject* bubble_sort(PyObject* self, PyObject* args) {
    PyObject* arr;
    int* array_copy, size;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &arr)) {
        return NULL;
    }

    size = PyObject_Length(arr);
    if (size < 0) {
        PyErr_SetString(PyExc_ValueError, "Object has no lentgh.");
        return  NULL;
    }

    array_copy = (int *) malloc(sizeof(int *) * size);
    if (array_copy == NULL) {
        PyErr_NoMemory();
    }

    for (int index = 0; index < size; index++) {
        PyObject* item = PyList_GetItem(arr, index);
        if (!PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "Array elements must be of int type.");
            return NULL;
        }
        array_copy[index] = PyLong_AsLong(item);
    }
    array_copy = _bubble_sort(array_copy, size);
    return makelist(array_copy, size);
}


// selection sort python wrapper
PyObject* select_sort(PyObject* self, PyObject* args) {
    PyObject* arr;
    int* array_copy, size;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O", &arr)) {
        return NULL;
    }

    size = PyObject_Length(arr);
    if (size < 0) {
        PyErr_SetString(PyExc_ValueError, "Object has no lentgh.");
        return  NULL;
    }

    array_copy = (int *) malloc(sizeof(int *) * size);
    if (array_copy == NULL) {
        PyErr_NoMemory();
    }

    for (int index = 0; index < size; index++) {
        PyObject* item = PyList_GetItem(arr, index);
        if (!PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "Array elements must be of int type.");
            return NULL;
        }
        array_copy[index] = PyLong_AsLong(item);
    }
    array_copy = _selection_sort(array_copy, size);
    return makelist(array_copy, size);
}
