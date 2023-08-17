//
// Created by Steve Wheeler on 17/08/2023.
//

#pragma once

#include <raylib.h>
#include <string>

enum GridTypes
{
    EMPTY,
    SAND,
    WATER
};

class Block {
public:
    Block(Rectangle rect) : rect(rect) {};
    virtual ~Block() { };
    Rectangle rect;
    Color color;
    GridTypes gridType;
    virtual void Move(std::string nextGridKey, int newPosX, int newPosY) = 0;
    virtual void Update() = 0;
    virtual void Draw()
    {
        DrawRectangle(rect.x, rect.y, rect.width, rect.height, color);
    }
    
};

