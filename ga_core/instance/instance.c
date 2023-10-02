/* Operations */
#define PY_SSIZE_T_CLEAN    
#include <Python.h>


static PyMethodDef SortingMethods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef ga_instance_module = {
    PyModuleDef_HEAD_INIT,
    "_ga_instance",
    "common sorting algorithms",
    -1,
    SortingMethods
};

PyMODINIT_FUNC PyInit__ga_instance(void) {
    return PyModule_Create(&ga_instance_module);
}