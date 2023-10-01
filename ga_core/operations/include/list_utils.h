#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <Python.h>

int swap_PyObject(PyObject* arr, int i, int j);
int partition(PyObject* arr, int low, int high);

#endif