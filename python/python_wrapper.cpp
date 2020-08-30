#include <pybind11/pybind11.h>
#include "gameapplication.h"

namespace py = pybind11;

PYBIND11_MODULE(xo_app, m)
{
    py::enum_<Player>(m, "Player")
        .value("X_Player", Player::X_Player)
        .value("O_Player", Player::O_Player)
        .value("NONE", Player::None)
        .export_values();

    py::class_<Coordinates>(m, "Coordinates")
        .def(py::init<COORD_INDEX, COORD_INDEX, COORD_INDEX>());

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
        .def("exist", &GameApplication::exist)
        .def("get_player_to_move", &GameApplication::getPlayerToMove)
        .def("get_board", &GameApplication::getBoard);
}
