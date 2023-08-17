//
// Created by Steve Wheeler on 17/08/2023.
//

#pragma once

#include "Block.hpp"
#include <string>


class SandBlock: public Block 
{
public:
    SandBlock(Rectangle rect);
    void Move(std::string nextGridKey, int newPosX, int newPosY) override;
    void Update() override;
};
