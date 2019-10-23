#include "GD_Grid.hpp"

using namespace godot;

// static methods

void GD_Grid::_register_methods() {
    //register methods
    register_method("_ready", &GD_Grid::_ready);
    register_method("createGrid", &GD_Grid::createGrid);
    register_method("getIndex", &GD_Grid::getIndex);
    //TODO: add getCount-method (or as member-variable)
    register_method("getClosestPosition", &GD_Grid::getClosestPosition);
    register_method("getAllPositions", &GD_Grid::getAllPositions);
    
    //register properties
    register_property<GD_Grid, Vector2>("count_xy", &GD_Grid::_count_xy, Vector2(5, 5));
    register_property<GD_Grid, float>("element_size", &GD_Grid::_elem_size, 5.0f);
    register_property<GD_Grid, bool>("auto_init", &GD_Grid::_auto_init, false);
}

// constructors and destructors

GD_Grid::GD_Grid() {}
GD_Grid::~GD_Grid() {}

// public methods

void GD_Grid::_init() {
    //init exported
    _count_xy = Vector2(5, 5);
    _elem_size = 5.0f;
    _auto_init = false;

    //init others
    _count_total = 0;
}

void GD_Grid::_ready() {
    _count_total = Grid::getElementCountFromSize(_count_xy);
    if(_auto_init == true) { createGrid(); }
}

void GD_Grid::createGrid() {
    Vector2 pos = get_position();

    _grid = Grid(
        _elem_size,
        pos,
        Vector2Int(_count_xy)
    );
}

int GD_Grid::getIndex(Vector2 pos) {
    return _grid.getIndexFromRealPos(pos);
}

Vector2 GD_Grid::getClosestPosition(Vector2 pos) {
    return _grid.getClosestPosition(pos);
}

PoolVector2Array GD_Grid::getAllPositions() {
    return _grid.getAllPositions();
}