#pragma once
#include"../../UI/UIElement/RectangleShapeView.h"

namespace GamePlay {
namespace Collection {
using namespace UI::UIElement;
struct Stick {
int data;
RectangleShapeView* stickView;

Stick() {};
Stick(int data) {
	this->data = data;
	stickView = new RectangleShapeView();

}

~Stick() {
	delete(stickView);
}
};
}
}