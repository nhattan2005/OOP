#ifndef COLOR_H
#define COLOR_H

class Color {
private:
    int red, green, blue; // RGB values
public:
    Color(int r = 0, int g = 0, int b = 0);
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    void setColor(int r, int g, int b);
    bool isComplementary(const Color& other) const;
};

#endif // COLOR_H
