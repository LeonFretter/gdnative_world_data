#include <new>

#include "GD_QuadrantField.h"

using namespace godot;

struct Test {
    TextureRect* _canvas_item;
    Vector2 _pos;
};

void GD_QuadrantField::_register_methods() {
    //register methods
    // register_method("_process", &GD_QuadrantField::_process);
    register_method("_ready", &GD_QuadrantField::_ready);
    register_method("getClosestPosition", &GD_QuadrantField::getClosestPosition);

    //register properties
    register_property<GD_QuadrantField, Vector2>("initial-count", &GD_QuadrantField::_initial_count, Vector2(5, 5));
    register_property<GD_QuadrantField, float>("size", &GD_QuadrantField::_size, 1.0f);
}

void GD_QuadrantField::init_callback(void* me_void, void* data, Vector2 pos) {
    new(data) Test();
    Test* test = static_cast<Test*>(data);
    GD_QuadrantField* me = static_cast<GD_QuadrantField*>(me_void);

    test->_canvas_item = TextureRect::_new();
    
    ImageTexture* tex = ImageTexture::_new();
    Image* image = Image::_new();
    Color color = Color(1, 0, 0);

    image->create(8, 8, false, Image::FORMAT_RGBA8);
    image->fill(color);

    tex->create_from_image(image);
    test->_canvas_item->set_texture(tex);

    test->_canvas_item->set_position(pos);
    me->add_child(test->_canvas_item);
    test->_pos = pos;
}


GD_QuadrantField::GD_QuadrantField() {}
GD_QuadrantField::~GD_QuadrantField() {}

void GD_QuadrantField::_init() {
    //init exported members
    _initial_count = Vector2(4, 4);
    _size = 1.0;
}

void GD_QuadrantField::_ready() {
    Vector2Int initial_count = Vector2Int(_initial_count);

    QuadrantCallbackWrapper callback_wrapper = {};
    callback_wrapper._callback = init_callback;
    callback_wrapper._caller = this;

    _quadrant_field = QuadrantField(
        sizeof(Test),
        _size,
        initial_count,
        callback_wrapper
    );
}

Vector2 GD_QuadrantField::getClosestPosition(Vector2 pos) {
    void* found = _quadrant_field.getClosestFromPosition(pos);
    Test* test = (Test*)(found);
    Vector2 found_pos = test->_pos;

    return found_pos;
}

Array GD_QuadrantField::getAllPositions() {
    _quadrant_field.getAllPositions();
}