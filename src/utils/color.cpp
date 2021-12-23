//
// Created by Hai Pham on 22.12.2021.
//
#include "color.h"

Color::Color() {}

Color::Color(int red, int green, int blue, int alpha) : _red(red), _green(green), _blue(blue), _alpha(alpha){}

int Color::Red(){
    return _red;
}

int Color::Blue(){
    return _blue;
}

int Color::Green(){
    return _green;
}

int Color::Alpha(){
    return _alpha;
}