#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <Python.h>

int swap_PyObject(PyObject* arr, int i, int j);
PyObject *makelist(int array[], size_t size);
// double* convert_to_double(PyObject* arr, int size);

#endif