#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "include/operations/list_utils.h"


// swipe items on i-th and j-th positions
int swap_PyObject(PyObject* arr, int i, int j) {
    PyObject* temp = PyList_GetItem(arr, i);
    
    PyList_SetItem(arr, i, PyList_GetItem(arr, j));
    PyList_SetItem(arr, j, temp);
    
    Py_DECREF(temp);

    return 0;
}


PyObject *makelist(int array[], size_t size) {
    PyObject *l = PyList_New(size);
    for (size_t i = 0; i != size; ++i) {
        PyList_SET_ITEM(l, i, PyLong_FromLong(array[i]));
    }
    return l;
}
