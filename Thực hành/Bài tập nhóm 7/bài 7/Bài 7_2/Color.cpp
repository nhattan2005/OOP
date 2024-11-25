#include "Color.h"

Color::Color(int r, int g, int b) : red(r), green(g), blue(b) {}

int Color::getRed() const { return red; }
int Color::getGreen() const { return green; }
int Color::getBlue() const { return blue; }

void Color::setColor(int r, int g, int b) {
    red = r;
    green = g;
    blue = b;
}

bool Color::isComplementary(const Color& other) const {
    return (red + other.getRed() == 255) &&
           (green + other.getGreen() == 255) &&
           (blue + other.getBlue() == 255);
}
