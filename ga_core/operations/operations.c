/* Operations */
#define PY_SSIZE_T_CLEAN    
#include <Python.h>
#include <stdio.h>
#include "include/operations/sorting.h"


static PyMethodDef SortingMethods[] = {
    {"bubble_sort", bubble_sort, METH_VARARGS, "bubble sort algorithm"},
    {"select_sort", select_sort, METH_VARARGS, "selection sort algorithm"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef ga_operations_module = {
    PyModuleDef_HEAD_INIT,
    "_ga_operations",
    "common sorting algorithms",
    -1,
    SortingMethods
};

PyMODINIT_FUNC PyInit__ga_operations(void) {
    return PyModule_Create(&ga_operations_module);
}