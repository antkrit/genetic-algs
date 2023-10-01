/* Operations */
#include <Python.h>
#include <stdio.h>
#include "include/sorting.h"

static PyMethodDef SortingMethods[] = {
    {"bubble_sort", bubble_sort, METH_VARARGS, "bubble sort algorithm"},
    {"quick_sort", quick_sort, METH_VARARGS, "quick sort algorithm"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef operations_module = {
    PyModuleDef_HEAD_INIT,
    "operations",
    "common sorting algorithms",
    -1,
    SortingMethods
};

PyMODINIT_FUNC PyInit_operations(void) {
    return PyModule_Create(&operations_module);
}