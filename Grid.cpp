//
// Created by Steve Wheeler on 17/08/2023.
//
#include "Grid.hpp"

Grid* Grid::instance_= nullptr;;

/**
 * Static methods should be defined outside the class.
 */
Grid *Grid::GetInstance()
{
    if(instance_ == nullptr)
    {
        instance_ = new Grid();
    }
    return instance_;
}