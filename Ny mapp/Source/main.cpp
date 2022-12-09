#include "raylib.h"
#include "Level.h"

#include <stack>

enum class State
{
    MAIN_MENU,
    GAME
};

std::stack <State> states;

void update(Level* level)
{
    if (IsKeyPressed(KEY_HOME))
    {
        states.pop();
    }

    level->level_update();
}

void render(Level* level)
{
    level->level_render();
}

void game_frame(Level* level)
{
    update(level);
    render(level);
}

void main_menu_frame()
{
    
    DrawText("Bee Game", 110, 64, 64, WHITE);
    DrawText("Press Enter to start", 80, 128, 32, WHITE);
    
    if (IsKeyPressed(KEY_ENTER))
    {
        states.push(State::GAME);
    }
}


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
        
        State current_state = states.top();

        switch (current_state)
        {

            case State::MAIN_MENU:
                main_menu_frame();
            break;
            case State::GAME:
                game_frame(&level);
            break;
        }

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