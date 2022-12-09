#include "raylib.h"
#include "Level.h"

#include <stack>

enum class State
{
    MAIN_MENU,
    GAME
};

std::stack <State> states;





//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 512;
    const int screenHeight = 512;

    //Image Bee = LoadImage("beePlayer1.png");
    //SetWindowIcon(Bee);

    InitWindow(screenWidth, screenHeight, "Bee Game");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    Level level;
    level.game_init();
    
    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        //Texture2D LoadTexture("beePlayer1.png");
        
        

        level.level_update();
        level.level_render();
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}