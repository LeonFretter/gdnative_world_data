#include <stdint.h>
#include <stdexcept>

#include "Grid.hpp"

// static methods

int Grid::getElementCountFromSize(Vector2Int count) { return count._x * count._y; }

// constructors and destructors

Grid::Grid() { _element_data = malloc(1); }

Grid::Grid(
    void* caller_object,
    int elem_mem_size,
    float size,
    Vector2 pos,
    Vector2Int count,
    GridCallback callback
) {
    int size_remainder = elem_mem_size % 4;
    if(elem_mem_size < 4 || size_remainder != 0) {
        throw std::invalid_argument("Memory size of element must be greater than 4");
    }

    _elem_mem_size = elem_mem_size;
    _pos = pos;
    _count = count;
    _size = size;
    _elem_count = (count._x * count._y);

    _total_mem_size = elem_mem_size * (count._x * count._y);

    _element_data = malloc(_total_mem_size);

    iterate(caller_object, callback);
}

Grid::~Grid() {
    free(_element_data);
}

// public methods

void* Grid::getClosestElement(Vector2 pos) {
    pos = (pos-_pos) / _size;
    
    return getElementAt(pos);
}


void Grid::iterate(void* caller_object, GridCallback callback) {
    for(int x=0; x<_count._x; x++) {
        for(int y=0; y<_count._y; y++) {

            Vector2 pos = Vector2(x, y);

            void* element = getElementAt(pos);

            int i=0;
            if(element != nullptr) {
                // Godot::print(Vector2(i, i));
                i++;
                callback(caller_object, element, pos * _size);
            }
        }
    }
}

int Grid::getIndexFromRealPos(Vector2Int pos) {
    pos = (pos-_pos) / _size;
    return getIndex( Vector2Int(pos) );
}

Vector2 Grid::getClosestPosition(Vector2 pos) {
    int index = getIndexFromRealPos(pos);

    int x = index / _count._y;
    int y = index % _count._y;

    return ( Vector2(x, y) * _size ) + _pos;
}

// private methods

void* Grid::getElementAt(Vector2 pos) {
    int index = getIndex(Vector2Int(pos));

    //cast so that pointer-arithmetic can be used
    int data_cast = (intptr_t)_element_data;

    int offset = (index * _elem_mem_size) / sizeof(int);

    return (void*) ( data_cast + offset );
}

int Grid::getIndex(Vector2Int pos) {
    int index = (pos._x * _count._y) + pos._y;
    if(index > _elem_count) { return _elem_count-1; }
    return index;
}
