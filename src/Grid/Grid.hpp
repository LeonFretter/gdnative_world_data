#ifndef GRID_H
#define GRID_H

#include "QuadrantField/Vector2Int.hpp"
#include "Vector2.hpp"
#include "PoolArrays.hpp"

using namespace godot;

class Grid {
public:
private:
    int _elem_count;
    float _size;
    Vector2 _pos;
    Vector2Int _count_xy;

    void* _element_data;
public:
    static int getElementCountFromSize(Vector2Int count);
    
    Grid();
    Grid(float size, Vector2 pos, Vector2Int count);
    ~Grid();

    Vector2 getClosestPosition(Vector2 pos);
    Vector2 getPositionFromIndex(int index);
    int getIndexFromRealPos(Vector2 pos);
    PoolVector2Array getAllPositions();

private:
    // when input-position is out of bounds, will return highest index
    int getIndex(Vector2Int pos);
};




#endif // GRID_H