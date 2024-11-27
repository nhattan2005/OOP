#include "Label.h"
#include <iostream>

Label::Label(const std::string& name, const Color& textColor, const Color& bgColor)
    : Component(name, textColor, bgColor) {}

void Label::display() const {
    std::cout << "Label: " << name << " Text Color: ("
              << textColor.getRed() << ", " << textColor.getGreen()
              << ", " << textColor.getBlue() << ") Background Color: ("
              << backgroundColor.getRed() << ", " << backgroundColor.getGreen()
              << ", " << backgroundColor.getBlue() << ")" << std::endl;
}
