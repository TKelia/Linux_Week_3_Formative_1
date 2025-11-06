#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double temperature;
    double humidity;
    double battery;
} SensorData;

static SensorData generate_data() {
    SensorData d;
    d.temperature = 20.0 + (rand() % 1500) / 100.0;
    d.humidity = 30.0 + (rand() % 5000) / 100.0;
    d.battery = 20.0 + (rand() % 8000) / 100.0;
    if (d.battery > 100.0) d.battery = 100.0;
    return d;
}

static PyObject* get_sensor_data(PyObject *self, PyObject *args) {
    SensorData d = generate_data();
    return Py_BuildValue("(ddd)", d.temperature, d.humidity, d.battery);
}

static PyMethodDef SimMethods[] = {
    {"get_sensor_data", get_sensor_data, METH_NOARGS, "Get simulated sensor data"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef simmodule = {
    PyModuleDef_HEAD_INIT,
    "sim",
    "Simple IoT sensor simulation",
    -1,
    SimMethods
};

PyMODINIT_FUNC PyInit_sim(void) {
    srand((unsigned int)time(NULL));
    return PyModule_Create(&simmodule);
}
