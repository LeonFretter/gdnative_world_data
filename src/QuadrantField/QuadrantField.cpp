#include "QuadrantField.hpp"

//constructors

QuadrantField::QuadrantField() {}

QuadrantField::QuadrantField(
    int elem_mem_size,
    float scale,
    Vector2Int initial_count,
    QuadrantCallbackWrapper init_callback_wrapper
) {
    _scale = scale;

    int index = 0;

    for(int x=-1; x<2; x+=2) {
        for(int y=-1; y<2; y+=2) {

            Vector2Int multiplicators = Vector2Int(x, y);
            Vector2Int offset = Vector2Int(
                x == -1 ? -1 : 0,
                y == -1 ? -1 : 0
            );

            _quadrants[index] = Quadrant(
                elem_mem_size,
                scale,
                multiplicators,
                offset,
                initial_count,
                init_callback_wrapper
            );
            
            index++;

        }
    }
}

//public methods

void* QuadrantField::getClosestFromPosition(Vector2 pos) {

    int x = (int)roundf( pos.x / _scale );
    int y = (int)roundf( pos.y / _scale );

    return getClosest(Vector2Int(x, y));
}

void QuadrantField::loop(QuadrantCallbackWrapper callback) {
    for(int i=0; i<4; i++) {
        _quadrants[i].loopElements(callback);
    }
}

bool QuadrantField::isExistantAtPosition(Vector2 pos) {
    int x = (int)roundf( pos.x / _scale );
    int y = (int)roundf( pos.y / _scale );

    return isExistant(Vector2Int(x, y));
}

Quadrant* QuadrantField::getQuadrants() { return _quadrants; }

std::vector<Vector2> QuadrantField::getAllPositions() {
    for(int i=0; i<4; i++) {

        _quadrants[i].getAllPositions();

    }
}

//private methods

void* QuadrantField::getClosest(Vector2Int pos) {
    int index = getIndex(pos);

    return _quadrants[index].getClosest(pos);
}

int QuadrantField::getIndex(Vector2Int pos) {
    int index=0;

    if(pos._x >= 0) { index += 2; }
    if(pos._y >= 0) { index += 1; }

    return index;
}

bool QuadrantField::isExistant(Vector2Int pos) {
    int index = getIndex(pos);

    return _quadrants[index].isExistant(pos);
}