//
// Created by Steve Wheeler on 17/08/2023.
//

#include "WaterBlock.hpp"
#include "Grid.hpp"
#include "Constants.hpp"

WaterBlock::WaterBlock(Rectangle rect) : Block(rect)
{
    prevPos = (Vector2) { .x = rect.x, .y = rect.y };
    moveCounter = 0;
    moveThreshold = 8;
    gridType = WATER;
    color = BLUE;
}

void WaterBlock::Update() 
{
    Grid* grid = Grid::GetInstance();
    // First, try to move down.
    int newPosY = rect.y + GRIDSIZE;
    if (newPosY > screenHeight - GRIDSIZE || newPosY < 0) return;
    std::string nextGridKey = Grid::GetGridKey(rect.x, newPosY);
    if (!grid->gridSquares.count(nextGridKey))
    {
        moveCounter = 0;
        Move(nextGridKey, rect.x, newPosY);
    }
    else
    {
        if (moveCounter > moveThreshold) return;
        // If it can't move down, try to move either right or left.
        int leftX = rect.x - GRIDSIZE;
        int rightX = rect.x + GRIDSIZE;

        std::string leftKey = Grid::GetGridKey(leftX, rect.y);
        std::string rightKey = Grid::GetGridKey(rightX, rect.y);
        bool leftPossible = !grid->gridSquares.count(leftKey) && leftX >= 0;
        bool rightPossible = !grid->gridSquares.count(rightKey)  && rightX <= screenWidth - GRIDSIZE;
        
        if (leftPossible && rightPossible)
        // Crude wave implementation:
        // If there is no block next to this one "pushing" the wave in a direction, attempt to go diagonally.
        // If not, don't move and wait for another block to push this one.
        {
            std::string diagonalLeftKey = Grid::GetGridKey(leftX, newPosY);
            std::string diagonalRightKey = Grid::GetGridKey(rightX, newPosY);
            bool diagLeftPossible = !grid->gridSquares.count(diagonalLeftKey) && leftX >= 0;
            bool diagRightPossible = !grid->gridSquares.count(diagonalRightKey)  && rightX <= screenWidth - GRIDSIZE;
            if (diagLeftPossible)
            {
                Move(diagonalLeftKey, leftX, newPosY);
            }
            else if (diagRightPossible)
            {
                Move(diagonalRightKey, rightX, newPosY);
            }
        }
        else if (leftPossible)
        {
            Move(leftKey, leftX, rect.y);
        }
        else if (rightPossible)
        {
            Move(rightKey, rightX, rect.y);
        }
    }
}

/*
 * When a valid space is found. What should happen?
 */
void WaterBlock::Move(std::string nextGridKey, int newPosX, int newPosY) 
{
    if ((int)prevPos.x == newPosX && (int)prevPos.y == newPosY) ++moveCounter;
    Grid* grid = Grid::GetInstance();
    std::string currentGridKey = Grid::GetGridKey(rect.x, rect.y);
    grid->gridSquares.erase(currentGridKey);
    grid->gridSquares[nextGridKey] = this;
    prevPos = (Vector2) { .x = (float) rect.x,
            .y = (float) rect.y };
    rect.x = newPosX;
    rect.y = newPosY;
    
}