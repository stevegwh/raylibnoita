//
// Created by Steve Wheeler on 17/08/2023.
//
#pragma once
#include "Block.hpp"


class WaterBlock : public Block 
{
    Vector2 prevPos;
    int moveCounter;
    int moveThreshold;
public:
    WaterBlock(Rectangle rect);
    void Move(std::string nextGridKey, int newPosX, int newPosY) override;
    void Update() override;
};
