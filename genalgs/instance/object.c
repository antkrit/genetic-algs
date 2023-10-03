/* Operations */
#define PY_SSIZE_T_CLEAN    
#include <Python.h>
#include <include/instance/object.h>


PyMODINIT_FUNC
PyInit__ga_instance(void)
{
    PyObject *m;
    if (PyType_Ready(&GABaseInstanceType) < 0)
        return NULL;

    m = PyModule_Create(&_ga_instance);
    if (m == NULL)
        return NULL;

    Py_INCREF(&GABaseInstanceType);
    if (PyModule_AddObject(m, "GABaseInstance", (PyObject *) &GABaseInstanceType) < 0) {
        Py_DECREF(&GABaseInstanceType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}