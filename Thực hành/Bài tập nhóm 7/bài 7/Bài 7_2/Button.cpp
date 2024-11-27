#include "Button.h"
#include <iostream>

Button::Button(const std::string& name, const Color& textColor, const Color& bgColor)
    : Component(name, textColor, bgColor) {}

void Button::display() const {
    std::cout << "Button: " << name << " Text Color: ("
              << textColor.getRed() << ", " << textColor.getGreen()
              << ", " << textColor.getBlue() << ") Background Color: ("
              << backgroundColor.getRed() << ", " << backgroundColor.getGreen()
              << ", " << backgroundColor.getBlue() << ")" << std::endl;
}

