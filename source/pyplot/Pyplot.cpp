//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Pyplot.hpp"
#include "generic/PythonCalls.hpp"

#include <iostream>

namespace cxxplot {

	template<class inputType>
	Pyplot<inputType>::Pyplot() { };

	template<class inputType>
	Pyplot<inputType>::~Pyplot() { };

	template<class inputType>
	void
	Pyplot<inputType>::set_xlabel(std::string const& label, std::map<std::string, std::string> const& args)
	{
		xlabel = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "xlabel");

		PyObject* py_label = PyUnicode_FromString(label.c_str());

		PyObject* label_args = PyTuple_New(1);
		PyTuple_SetItem(label_args, 0, py_label);

		PyObject* kwargs = PyDict_New();
		for (auto const& v:args) {
			PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
		}

		PyObject_Call(xlabel, label_args, kwargs);
	}

	template<class inputType>
	void
	Pyplot<inputType>::set_ylabel(std::string const& label, std::map<std::string, std::string> const& args)
	{
		ylabel = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "ylabel");

		PyObject* py_label = PyUnicode_FromString(label.c_str());

		PyObject* label_args = PyTuple_New(1);
		PyTuple_SetItem(label_args, 0, py_label);

		PyObject* kwargs = PyDict_New();
		for (auto const& v:args) {
			PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
		}

		PyObject_Call(ylabel, label_args, kwargs);

	}

	template<class inputType>
	void
	Pyplot<inputType>::show_plot()
	{
		show = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "show");

		PyObject* res = PyObject_CallObject(show, NULL);
		if (res) Py_DECREF(res);
	}

	template<class inputType>
	void
	Pyplot<inputType>::savefig(std::string const& fname)
	{
		PyObject* savefig = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "savefig");

		PyObject* py_fname = PyUnicode_FromString(fname.c_str());

		PyObject* savefig_args = PyTuple_New(1);
		PyTuple_SetItem(savefig_args, 0, py_fname);

		PyObject* kwargs = PyDict_New();
		PyObject_Call(savefig, savefig_args, kwargs);
	}

	template<class inputType>
	void Pyplot<inputType>::set_xlim(double x_min, double x_max)
	{
		set_x_or_y_lim(x_min, x_max, "xlim");
	}

	template<class inputType>
	void Pyplot<inputType>::set_ylim(double y_min, double y_max)
	{
		set_x_or_y_lim(y_min, y_max, "ylim");
	}

	template<class inputType>
	void Pyplot<inputType>::set_x_or_y_lim(double min_value, double max_value, std::string lim_type)
	{
		PyObject* lim = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, lim_type);

		PyObject* lim_args = PyTuple_New(2);
		PyTuple_SetItem(lim_args, 0, Py_BuildValue("d", min_value));
		PyTuple_SetItem(lim_args, 1, Py_BuildValue("d", max_value));

		PyObject* kwargs = PyDict_New();
		PyObject* result = PyObject_Call(lim, lim_args, kwargs);
		if (result == NULL)
			std::cout << "Failed to call " << lim_type << "!" <<std::endl;
		Py_DECREF(result);
	}

	template
	class Pyplot<int>;
	template
	class Pyplot<float>;
	template
	class Pyplot<double>;
}
