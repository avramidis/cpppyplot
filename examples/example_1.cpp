//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include <iostream>
#include "pyplot/Plot.hpp"

int
main()
{
    std::cout << "Running example_1" << std::endl;

    std::cout << "Call plt1" << std::endl;
//    cpppyplot::Graph graph_1;
//    std::vector<double> vector{1 ,2, 3, 4};
//    graph_1.vector_2_numpy(vector);

    cpppyplot::Plot plot_1;

    std::vector<double> x{1.0, 2.0};
    std::vector<double> y{2.0, 3.0};

    std::vector<std::pair<std::string, std::string>> args;
    args.emplace_back("color", "r");
    args.emplace_back("marker", "o");

    plot_1.draw(x, y, args);


//    {
//        std::cout << "Call plt2" << std::endl;
//        cpppyplot::Plot plt2;
//        plt2.draw();
//    }

//    PyObject *matplotlib, *plot, *show, *show_fun, *pValue;
//
//    Py_Initialize();
//    PyRun_SimpleString("import sys\n"
//                       "sys.argv.append('')\n"
//                       "print(sys.argv)\n");
//
//    matplotlib = PyImport_ImportModule("matplotlib.pyplot");
//    if (matplotlib == NULL) {
//        return -1;
//    }
//
//    plot = PyObject_GetAttrString(matplotlib, "plot");
//    if (plot == NULL)
//        return -2;
//
//    if (PyCallable_Check(plot))
//    {
//        std::cout << "Callable!" << std::endl;
//        PyObject_CallObject(plot, NULL);
//    } else
//    {
//        std::cout << "Not callable!" << std::endl;
//        PyErr_Print();
//    }
//
//    show = PyObject_GetAttrString(matplotlib, "show");
//    if (show == NULL)
//        return -2;
//
//    if (PyCallable_Check(show))
//    {
//        std::cout << "Callable!" << std::endl;
//        PyObject_CallObject(show, NULL);
//    } else
//    {
//        std::cout << "Not callable!" << std::endl;
//        PyErr_Print();
//    }
//
//    if (Py_FinalizeEx() < 0) {
//        return 120;
//    }

    return 0;
}