#include <raylib.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>

#define GRIDSIZE 16

struct Block
{
    Rectangle rect;
    Color color;
};

enum GridTypes
{
    EMPTY,
    SAND,
    WATER
};

std::vector<Block*> sandVec;
std::vector<Block*> waterVec;
std::map<std::string, GridTypes> gridSquares;
bool canMove;
double timer;
constexpr double moveThreshold = 0.05;
constexpr int screenWidth = 640;
constexpr int screenHeight = 480;

std::string GetGridKey(int x, int y)
{
    return std::to_string(x) + std::string("-") + std::to_string(y);
}

void InitGrid()
{
    for (int i = 0; i < screenWidth/GRIDSIZE; ++i) 
    {
        for (int j = 0; j < screenHeight/GRIDSIZE; ++j) 
        {
            std::string  key = GetGridKey(i * GRIDSIZE, j * GRIDSIZE);
            std::cout << key << std::endl; 
            gridSquares[key] = EMPTY;
        }
    }
}

void MoveSandPiece(Block* sand, int newPosX, int newPosY, std::string nextGridKey)
{
    std::string currentGridKey = GetGridKey(sand->rect.x, sand->rect.y);
    gridSquares[currentGridKey] = EMPTY;
    gridSquares[nextGridKey] = SAND;
    sand->rect.x = newPosX;
    sand->rect.y = newPosY;
}


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitGrid();

    InitWindow(screenWidth, screenHeight, "Noita Rip Off");
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
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
        
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            float x, y;
            x = ((int)GetMousePosition().x / GRIDSIZE) * GRIDSIZE;
            y = ((int)GetMousePosition().y / GRIDSIZE) * GRIDSIZE;
            std::string currentGridKey = GetGridKey(x, y);
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if (gridSquares[currentGridKey] == EMPTY)
                {
                    Block* sand = new Block();
                    sand->color = ORANGE;
                    gridSquares[currentGridKey] = SAND;
                    sand->rect = (Rectangle) { .x = x, .y = y, .width = GRIDSIZE, .height = GRIDSIZE };
                    sandVec.push_back(sand);
                }
            } else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
            {
                if (gridSquares[currentGridKey] != EMPTY)
                {
                    gridSquares[currentGridKey] = EMPTY;
                }
            }
        }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        for (Block* sand : sandVec) 
        {
            if (gridSquares[GetGridKey(sand->rect.x, sand->rect.y)] == EMPTY)
            {
                // TODO: Find a way of deleting this.
                continue;
            }
            DrawRectangle(sand->rect.x, sand->rect.y, sand->rect.width, sand->rect.height, sand->color);
            if (!canMove) continue;
            
            // First, try to move down.
            int newPosY = sand->rect.y + GRIDSIZE;
            if (newPosY > screenHeight - GRIDSIZE || newPosY < 0) continue;
            std::string nextGridKey = GetGridKey(sand->rect.x, newPosY);
            if (gridSquares[nextGridKey] == EMPTY)
            {
                MoveSandPiece(sand, sand->rect.x, newPosY, nextGridKey);
            }
            else
            {
                int leftX = sand->rect.x - GRIDSIZE; 
                int rightX = sand->rect.x + GRIDSIZE;
                std::string leftKey = GetGridKey(leftX, newPosY);
                std::string rightKey = GetGridKey(rightX, newPosY);
                bool leftPossible = gridSquares[leftKey] == EMPTY && leftX > 0;
                bool rightPossible = gridSquares[rightKey] == EMPTY && rightX < screenWidth - GRIDSIZE;
                if (leftPossible && rightPossible)
                {
                    int rand = GetRandomValue(0, 10);
                    int newX = rand % 2 == 0 ? leftX : rightX;
                    MoveSandPiece(sand, newX, newPosY, GetGridKey(newX, newPosY));
                }
                else if (leftPossible)
                {
                    MoveSandPiece(sand, leftX, newPosY, GetGridKey(leftX, newPosY));
                }
                else if (rightPossible)
                {
                    MoveSandPiece(sand, rightX, newPosY, GetGridKey(rightX, newPosY));
                }
            }
        }

        //DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    for (Block* sand : sandVec) 
    {
        delete sand;
    }
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}