#include "Grid.hpp"

// static methods

int Grid::getElementCountFromSize(Vector2Int count) { return count._x * count._y; }

// constructors and destructors

Grid::Grid() { }

Grid::Grid(
    float size,
    Vector2 pos,
    Vector2Int count_xy
) {
    _pos = pos;
    _count_xy = count_xy;
    _size = size;
    _elem_count = (count_xy._x * count_xy._y);
}

Grid::~Grid() {}

// public methods

int Grid::getIndexFromRealPos(Vector2 pos) {
    pos = (pos-_pos) / _size;
    return getIndex( Vector2Int(pos) );
}

Vector2 Grid::getClosestPosition(Vector2 pos) {
    int index = getIndexFromRealPos(pos);

    int x = index / _count_xy._y;
    int y = index % _count_xy._y;

    return ( Vector2(x, y) * _size ) + _pos;
}

// private methods

int Grid::getIndex(Vector2Int pos) {
    int index = (pos._x * _count_xy._y) + pos._y;
    if(index < 0) { return 0; }
    if(index > _elem_count) { return _elem_count-1; }
    return index;
}

PoolVector2Array Grid::getAllPositions() {
    PoolVector2Array positions = PoolVector2Array();

    for(int x=0; x<_count_xy._x; x++) {
        for(int y=0; y<_count_xy._y; y++) {

            Vector2 pos = (Vector2(x, y) * _size) + _pos;
            positions.append(pos);

        }
    }

    return positions;
}