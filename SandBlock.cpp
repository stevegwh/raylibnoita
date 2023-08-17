//
// Created by Steve Wheeler on 17/08/2023.
//

#include "SandBlock.hpp"
#include "Grid.hpp"
#include "Constants.hpp"

SandBlock::SandBlock(Rectangle rect) : Block(rect) 
{
    gridType = SAND;
    color = ORANGE;
}

void SandBlock::Update() 
{   
    Grid* grid = Grid::GetInstance();
    // First, try to move down.
    int newPosY = rect.y + GRIDSIZE;
    if (newPosY > screenHeight - GRIDSIZE || newPosY < 0) return;
    std::string nextGridKey = Grid::GetGridKey(rect.x, newPosY);
    if (!grid->gridSquares.count(nextGridKey) || grid->gridSquares[nextGridKey]->gridType != SAND)
    {
        Move(nextGridKey, rect.x, newPosY);
    }
    else
    {
        // If it can't move down, try to move either right or left.
        int leftX = rect.x - GRIDSIZE;
        int rightX = rect.x + GRIDSIZE;
        std::string leftKey = Grid::GetGridKey(leftX, newPosY);
        std::string rightKey = Grid::GetGridKey(rightX, newPosY);
        bool leftPossible = grid->gridSquares.count(leftKey) ?  grid->gridSquares[leftKey]->gridType == WATER : leftX >= 0;
        bool rightPossible = grid->gridSquares.count(rightKey) ? grid->gridSquares[rightKey]->gridType == WATER : rightX <= 
                screenWidth - GRIDSIZE;
        if (leftPossible && rightPossible)
        {
            int rand = GetRandomValue(0, 10);
            int newX = rand % 2 == 0 ? leftX : rightX;
            Move(Grid::GetGridKey(newX, newPosY), newX, newPosY);
        }
        else if (leftPossible)
        {
            Move(Grid::GetGridKey(leftX, newPosY), leftX, newPosY);
        }
        else if (rightPossible)
        {
            Move(Grid::GetGridKey(rightX, newPosY), rightX, newPosY);
        }
    }
}

void SandBlock::Move(std::string nextGridKey, int newPosX, int newPosY)
{
    std::string currentGridKey = Grid::GetGridKey(rect.x, rect.y);
    Grid* grid = Grid::GetInstance();

    if (grid->gridSquares.count(nextGridKey))
    {
        if (grid->gridSquares[nextGridKey]->gridType == WATER)
        {
            grid->gridSquares[currentGridKey] = grid->gridSquares[nextGridKey];
            grid->gridSquares[currentGridKey]->rect.x = rect.x;
            grid->gridSquares[currentGridKey]->rect.y = rect.y;
        }
        else
        {
            grid->gridSquares.erase(currentGridKey);
        }
    }
    else
    {
        grid->gridSquares.erase(currentGridKey);
    }
    grid->gridSquares[nextGridKey] = this;
    rect.x = newPosX;
    rect.y = newPosY;

}
