//
// Created by Steve Wheeler on 17/08/2023.
//

#pragma once
#include <map>
#include <string>
#include "Block.hpp"

class Grid
{
protected:
    Grid() {}
    static Grid* instance_;
public:
    /**
    * Singletons should not be cloneable.
    */
    Grid(Grid &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Grid &) = delete;

    static Grid *GetInstance();
    
    std::map<std::string, Block*> gridSquares;
    static std::string GetGridKey(int x, int y)
    {
        return std::to_string(x) + std::string("-") + std::to_string(y);
    }
    void PlaceSand(int mouseX, int mouseY);

};

