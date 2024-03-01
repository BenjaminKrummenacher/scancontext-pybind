#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "scancontext/Scancontext.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(pyscancontext, m) {
    m.doc() = "Scan Context for LiDAR place recognition";
    m.attr("__version__") = PROJECT_VERSION;

    py::class_<SCManager>(m, "SCManager")
        .def(py::init<>())
        .def(py::init<int, int, double, int, double>(), py::arg("pc_num_ring_val"), py::arg("pc_num_sector_val"),
        py::arg("pc_max_radius_val"), py::arg("num_candidates_from_tree_val"), py::arg("search_ratio_val"))
        .def("print_parameters", &SCManager::printParameters, py::return_value_policy::copy)
        .def("scd_distance", &SCManager::distanceBtnScanContext, py::return_value_policy::copy)
        .def("make_scancontext", &SCManager::makeScancontext, py::return_value_policy::copy)
        .def("construct_tree", &SCManager::constructTree, py::return_value_policy::copy)
        .def("add_scancontext", &SCManager::saveScancontextAndKeys, py::return_value_policy::copy)
        .def("add_node", &SCManager::makeAndSaveScancontextAndKeys, py::return_value_policy::copy)
        .def("find_similar", &SCManager::makeScancontextAndFindSimilar, py::return_value_policy::copy)
        .def("detect_loop", &SCManager::detectLoopClosureID, py::return_value_policy::copy);
}
