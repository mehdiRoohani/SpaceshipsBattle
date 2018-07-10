#pragma once
#include <iostream>
#include "Texture.h"

class Screen{

protected:
    Texture image;
    float x;
public:
    Screen();
    void Show();
};
