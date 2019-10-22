#ifndef QUADRANT_H
#define QUADRANT_H

#include <functional>
#include <Vector2.hpp>

#include "Vector2Int.hpp"
#include "QuadrantCallback.hpp"

using namespace godot;

class Quadrant {
private:
    int _elem_mem_size;
    float _scale;
    Vector2Int _multiplicators;
    Vector2Int _offset;
    std::vector< std::vector<void*> > _elements;
public:
    Quadrant();
    Quadrant(
        int elem_mem_size,
        float scale,
        Vector2Int multiplicators,
        Vector2Int offset,
        Vector2Int initial_count,
        QuadrantCallbackWrapper init_callback
    );
    
    void* getClosest(Vector2Int pos);

    void loopElements(QuadrantCallbackWrapper callback);
    void add(Vector2Int pos, QuadrantCallbackWrapper init_callback);

    bool isExistant(Vector2Int pos);

    Vector2 getPosition(Vector2Int index);

    std::vector<Vector2> getAllPositions();
};


#endif //QUADRANT_H