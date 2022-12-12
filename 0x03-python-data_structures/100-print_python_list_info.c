#include <Python.h>
#include <listobject.h>

void print_python_list_info(PyObject *p)
{
    // Get the size and allocated size of the Python list
    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    // Print the size and allocated size of the Python list
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", allocated);

    // Iterate over the elements of the Python list and print their type
    for (int i = 0; i < size; i++)
    {
        PyObject *element = PyList_GetItem(p, i);
        printf("Element %d: %s\n", i, Py_TYPE(element)->tp_name);
    }
}

