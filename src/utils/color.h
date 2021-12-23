//
// Created by Hai Pham on 22.12.2021.
//

#ifndef COLOR_H
#define COLOR_H

class Color
{
private:
    int _red;
    int _green;
    int _blue;
    int _alpha;

public:
    Color(int red, int green, int blue, int alpha);
    Color();
    int Red();
    int Green();
    int Blue();
    int Alpha();
};

#endif //COLOR_H
