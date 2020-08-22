#include <pybind11/pybind11.h>
#include "gameapplication.h"

namespace py = pybind11;

PYBIND11_MODULE(xo_app, m)
{
    py::class_<GameApplication>(m, "GameApplication")
        .def(py::init<>())
        .def("init", &GameApplication::init)
        .def("create_new_game", &GameApplication::createNewGame)
        .def("set_new_move", &GameApplication::setNewMove)
        .def("release_game", &GameApplication::releaseGame)
        .def("finalize", &GameApplication::finalize)
        .def("finished", &GameApplication::finished)
        .def("started", &GameApplication::started)
        .def("result", &GameApplication::result)
        .def("get_moves", &GameApplication::getMoves)
        .def("get_win_coords", &GameApplication::getWinCoords)
        .def("exist", &GameApplication::exist);
}
