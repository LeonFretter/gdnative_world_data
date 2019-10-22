#include "Quadrant.hpp"

//constructors

Quadrant::Quadrant() {}

Quadrant::Quadrant(
    int elem_mem_size,
    float scale,
    Vector2Int multiplicators,
    Vector2Int offset,
    Vector2Int initial_count,
    QuadrantCallbackWrapper init_callback
) {
    _elem_mem_size = elem_mem_size;
    _scale = scale;
    _multiplicators = multiplicators;
    _offset = offset;

    for(int x=0; x<initial_count._x; x++) {
        _elements.push_back(std::vector<void*>());
        for(int y=0; y<initial_count._y; y++) {
            _elements[x].push_back( malloc(elem_mem_size) );
        }
    }

    loopElements(init_callback);
}

// PUBLIC METHODS

void* Quadrant::getClosest(Vector2Int pos) {

    Godot::print((Vector2) pos);

    Vector2Int index = (pos*_multiplicators) + _offset;

    Godot::print((Vector2)index);

    int surplus_x = (index._x+1) - _elements.size();
    if(surplus_x > 0) { index._x -= surplus_x; }

    int surplus_y = (index._y+1) - _elements[index._x].size();
    if(surplus_y > 0) { index._y -= surplus_y; }

    return _elements[index._x][index._y];
}

void Quadrant::loopElements(QuadrantCallbackWrapper callback_wrapper) {
    for(int x=0; x<_elements.size(); x++) {
        for(int y=0; y<_elements[x].size(); y++) {

            Vector2 pos = getPosition(Vector2Int(x, y));
            callback_wrapper._callback(callback_wrapper._caller, _elements[x][y], pos);
        }
    }
}

void Quadrant::add(Vector2Int pos, QuadrantCallbackWrapper init_callback_wrapper) {
    Vector2Int index = (pos*_multiplicators) + _offset;

    int surplus_x = (index._x+1) - _elements.size();
    for(int i=0; i<surplus_x; i++) {
        _elements.push_back( std::vector<void*>() );
    }

    int surplus_y = (index._y+1) - _elements[index._x].size();
    for(int i=0; i<surplus_y; i++) {
        _elements[index._y].push_back(malloc(_elem_mem_size));
        int newest_index = _elements[index._x].size()-1;
        Vector2 pos = getPosition(Vector2Int(index._x, newest_index));

        init_callback_wrapper._callback(init_callback_wrapper._caller, _elements[index._x][newest_index], pos);
    }
}

bool Quadrant::isExistant(Vector2Int pos) {
    Vector2Int index = (pos*_multiplicators) + _offset;

    if( (index._x+1) > _elements.size() ) { return false; }
    if( (index._y+1) > _elements[index._x].size() ) { return false; }

    return true;
}

Vector2 Quadrant::getPosition(Vector2Int index) {
    return (index-_offset)*_multiplicators * _scale;
}

std::vector<Vector2> Quadrant::getAllPositions() {
    
}