#pragma once
#include "canvas.h"
#include "shapes.h"
#include "shapes_oop.h"

#include <cassert>
#include <iostream>
#include <sstream>

inline std::unique_ptr<Texture> MakeTextureCheckers(Size size, char pixel1, char pixel2) {
    Image image(size.height, std::string(size.width, pixel1));

    for (int i = 0; i < size.height; ++i) {
        for (int j = 0; j < size.width; ++j) {
            if ((i + j) % 2 != 0) {
                image[i][j] = pixel2;
            }
        }
    }

    return std::make_unique<Texture>(move(image));
}

inline std::unique_ptr<Texture> MakeTextureSolid(Size size, char pixel) {
    Image image(size.height, std::string(size.width, pixel));
    return std::make_unique<Texture>(move(image));
}

void TestCow();
void TestCpp();
void TestCppOop();