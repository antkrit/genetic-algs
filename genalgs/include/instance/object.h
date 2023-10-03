#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "structmember.h"


typedef struct {
    PyObject_HEAD
    PyObject* value;
    double score;
} GABaseInstance;

static void
GABaseInstance_dealloc(GABaseInstance *self)
{
    Py_XDECREF(self->value);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
GABaseInstance_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    GABaseInstance *self;
    self = (GABaseInstance *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->value = PyLong_FromLong(0);
        if (self->value == NULL) {
            Py_DECREF(self);
            return NULL;
        }
        self->score = 0;
    }
    return (PyObject *) self;
}

static int
GABaseInstance_init(GABaseInstance *self, PyObject *args, PyObject *kwds)
{
    static char *kwlist[] = {"value", "score", NULL};
    PyObject *value = NULL, *last = NULL, *tmp;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|Od", kwlist,
                                     &value, &self->score))
        return -1;

    if (value) {
        tmp = self->value;
        Py_INCREF(value);
        self->value = value;
        Py_XDECREF(tmp);
    }

    return 0;
}

static PyMemberDef GABaseInstance_members[] = {
    {"value", T_OBJECT_EX, offsetof(GABaseInstance, value), 0,
     "instance value"},
    {"score", T_DOUBLE, offsetof(GABaseInstance, score), 0,
     "instance score"},
    {NULL}  /* Sentinel */
};

static PyObject *
GABaseInstance_get_score(GABaseInstance *self, PyObject *Py_UNUSED(ignored))
{
    return PyFloat_FromDouble(self->score);
}

static PyMethodDef GABaseInstance_methods[] = {
    {"get_score", (PyCFunction) GABaseInstance_get_score, METH_NOARGS, "Return instance score."},
    {NULL}  /* Sentinel */
};

static PyTypeObject GABaseInstanceType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_ga_instance.GABaseInstance",
    .tp_doc = PyDoc_STR("Base Genetic Algoritghms instance."),
    .tp_basicsize = sizeof(GABaseInstance),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = GABaseInstance_new,
    .tp_init = (initproc) GABaseInstance_init,
    .tp_dealloc = (destructor) GABaseInstance_dealloc,
    .tp_members = GABaseInstance_members,
    .tp_methods = GABaseInstance_methods
};


static PyModuleDef _ga_instance = {
    PyModuleDef_HEAD_INIT,
    .m_name = "_ga_instance",
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};
