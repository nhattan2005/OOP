#include "Component.h"
#include <iostream>

Component::Component(const std::string& n, const Color& textColor, const Color& bgColor)
    : name(n), textColor(textColor), backgroundColor(bgColor) {}

Color Component::getTextColor() const {
    return textColor;
}

Color Component::getBackgroundColor() const {
    return backgroundColor;
}
