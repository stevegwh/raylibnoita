#include <raylib.h>
#include <vector>
#include <string>
#include "Grid.hpp"
#include "Block.hpp"
#include "SandBlock.hpp"
#include "Constants.hpp"
#include "WaterBlock.hpp"


std::vector<Block*> blockVec;
bool canMove;
double timer;


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Noita Rip Off");
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------
    // Main game loop
    Grid* grid = Grid::GetInstance();
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        timer += GetFrameTime();
        if (timer > moveThreshold)
        {
            timer = 0;
            canMove = true;
        }
        else
        {
            canMove = false;
        }
        
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT)
        || IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            float x, y;
            x = ((int)GetMousePosition().x / GRIDSIZE) * GRIDSIZE;
            y = ((int)GetMousePosition().y / GRIDSIZE) * GRIDSIZE;
            std::string currentGridKey = Grid::GetGridKey(x, y);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if (!Grid::GetInstance()->gridSquares.count(currentGridKey))
                {
                    SandBlock* block = new SandBlock((Rectangle) { .x = x, .y = y, .width = GRIDSIZE, 
                                                                   .height = GRIDSIZE });
                    blockVec.push_back(block);
                    grid->gridSquares[currentGridKey] = block;
                }
            } 
//            else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
//            {
//                if (grid->gridSquares.count(currentGridKey))
//                {
//                    grid->gridSquares.erase(currentGridKey);
//                }
//            }
            else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
            {
                if (!Grid::GetInstance()->gridSquares.count(currentGridKey))
                {
                    WaterBlock* block = new WaterBlock((Rectangle) { .x = x, .y = y, .width = GRIDSIZE, 
                                                                     .height = GRIDSIZE });
                    blockVec.push_back(block);
                    grid->gridSquares[currentGridKey] = block;
                }
            }
        }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < blockVec.size(); ++i) 
        {
            Block* block = blockVec[i];
            if (!grid->gridSquares.count(Grid::GetGridKey(block->rect.x, block->rect.y)))
            {
                delete block;
                blockVec[i] = *(--blockVec.end());
                blockVec.erase(--blockVec.end());
                --i;
                continue;
            }
            block->Draw();
            if (!canMove) continue;
            block->Update();
        }
        
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    for (Block* block : blockVec) 
    {
        delete block;
    }
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}