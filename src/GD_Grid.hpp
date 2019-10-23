#ifndef GD_GRID_H
#define GD_GRID_H

#include "Godot.hpp"
#include "Node2D.hpp"
#include "Vector2.hpp"
#include "Grid/Grid.hpp"
#include "PoolArrays.hpp"

namespace godot {

    class GD_Grid : public Node2D {
        GODOT_CLASS(GD_Grid, Node2D);
    public:
        int _count_total;
        float _elem_size;
        bool _auto_init;
        Vector2 _count_xy;
    private:
        Grid _grid;
    public:
        static void _register_methods();

        GD_Grid();
        ~GD_Grid();

        void _init();
        void createGrid();
        virtual void _ready();

        int getIndex(Vector2 pos);
        Vector2 getClosestPosition(Vector2 pos);
        PoolVector2Array getAllPositions();
    };


}



#endif // GD_GRID_H