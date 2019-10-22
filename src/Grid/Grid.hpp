#ifndef GRID_H
#define GRID_H

#include <functional>

#include "QuadrantField/Vector2Int.hpp"
#include "Vector2.hpp"
#include "TextureRect.hpp"
#include "ImageTexture.hpp"
#include "Image.hpp"

using namespace godot;

// caller_object_pointer, element_pointer, position
typedef std::function<void( void*, void*, Vector2 )> GridCallback;

class Grid {
public:
private:
    int _elem_count;
    int _total_mem_size;
    int _elem_mem_size;
    float _size;
    Vector2 _pos;
    Vector2Int _count;

    void* _element_data;
public:
    static int getElementCountFromSize(Vector2Int count);
    
    Grid();
    Grid(void* caller_object, int elem_mem_size, float size, Vector2 pos, Vector2Int count, GridCallback callback );
    ~Grid();

    void* getClosestElement(Vector2 pos);

    /**
     * iterates through all indices determined by _count
     * */
    void iterate(void* caller_object, GridCallback callback);

    Vector2 getClosestPosition(Vector2 pos);
    Vector2 getPositionFromIndex(int index);

private:
    void* getElementAt(Vector2 pos);

    // when input-position is out of bounds, will return highest index
    int getIndex(Vector2Int pos);
    int getIndexFromRealPos(Vector2Int pos);
};




#endif // GRID_H