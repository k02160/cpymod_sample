// mymodule.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

#include "Python.h"

static PyObject *
mymodule_echo(PyObject *self, PyObject *args)
{
	const char *str;

	if (!PyArg_ParseTuple(args, "s", &str)) {
		return NULL;
	}

	printf("%s\n", str);
	return PyLong_FromLong(0);
}

static PyMethodDef MymoduleMethods[] = {
	{"echo",  mymodule_echo, METH_VARARGS,
	 "Echo string."},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef mymodule = {
	PyModuleDef_HEAD_INIT,
	"mymodule",   /* name of module */
	NULL, /* spam_doc, */ /* module documentation, may be NULL */
	-1,       /* size of per-interpreter state of the module,
				 or -1 if the module keeps state in global variables. */
	MymoduleMethods
};

PyMODINIT_FUNC PyInit_mymodule(void)
{
	return PyModule_Create(&mymodule);
}
