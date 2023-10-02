#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include "include/operations/list_utils.h"


// swipe items on i-th and j-th positions
int swap_PyObject(PyObject* arr, int i, int j) {
    PyObject* temp = PyList_GetItem(arr, i);
    
    PyList_SetItem(arr, i, PyList_GetItem(arr, j));
    PyList_SetItem(arr, j, temp);
    
    Py_DECREF(temp);

    return 0;
}


// int* convert_to_double(PyObject* arr, int size) {
//     int array_copy[size];

//     for (int index = 0; index < size; index++) {
//         PyObject *item;
//         item = PyList_GetItem(arr, index);
//         if (!PyFloat_Check(item))
//             PyErr_SetString(PyExc_TypeError, "Array elements must be of float type.");
//             return NULL;
//         array_copy[index] = PyFloat_AsDouble(item);
//     }

//     return array_copy;
// }


PyObject *makelist(int array[], size_t size) {
    PyObject *l = PyList_New(size);
    for (size_t i = 0; i != size; ++i) {
        PyList_SET_ITEM(l, i, PyLong_FromLong(array[i]));
    }
    return l;
}
