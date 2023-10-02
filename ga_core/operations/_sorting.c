#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "include/operations/list_utils.h"
#include "include/operations/sorting.h"


PyObject* bubble_sort(PyObject* self, PyObject* args) {
    PyObject* arr;

    /* Parse arguments */
    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &arr)) {
        return NULL;
    }

    int size = PyList_Size(arr);
    if (size < 0) {
        PyErr_SetString(PyExc_ValueError, "Array size cannot be less than 0.");
        return  NULL;
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (PyList_GetItem(arr, j) > PyList_GetItem(arr, j+1)) {
                swap_PyObject(arr, j, j+1);
            }
        }
    }

    return arr;
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
        // if (!PyFloat_Check(item)) {
        //     PyErr_SetString(PyExc_TypeError, "Array elements must be of float type.");
        //     return NULL;
        // }
        array_copy[index] = PyLong_AsLong(item);
    }
    array_copy = _selection_sort(array_copy, size);
    return makelist(array_copy, size);
}
