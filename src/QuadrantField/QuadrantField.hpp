#ifndef QUADRANT_FIELD_H
#define QUADRANT_FIELD_H

#include <functional>

#include "Vector2.hpp"
#include "Vector2Int.hpp"
#include "Array.hpp"
#include "Quadrant.hpp"
#include "QuadrantCallback.hpp"

using namespace godot;

class QuadrantField {
public:
private:
    float _scale;
    Quadrant _quadrants[4];
public:
    QuadrantField();
    QuadrantField(
        int elem_mem_size,
        float scale,
        Vector2Int initial_count,
        QuadrantCallbackWrapper init_callback
    );
    
    void* getClosestFromPosition(Vector2 pos);
    
    void loop(QuadrantCallbackWrapper callback);

    bool isExistantAtPosition(Vector2 pos);

    Quadrant* getQuadrants();

    std::vector<Vector2> getAllPositions();
private:
    void* getClosest(Vector2Int pos);
    
    int getIndex(Vector2Int pos);
    
    bool isExistant(Vector2Int index);
};


#endif // QUADRANT_FIELD_H