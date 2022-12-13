#include "raylib.h"
#include "Level.h"
#include "Images.cpp"

#include <stack>

enum class State
{
    MAIN_MENU,
    GAME,
    WIN_SCREEN
};

enum Levels
{
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5
};

std::stack <State> states;

void update(Level* level)
{
    if (IsKeyPressed(KEY_HOME))
    {
        level->game_init();
        states.pop();
    }

    if (level->isWon)
    {
        states.push(State::WIN_SCREEN);
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

void main_menu_frame(Level* level)
{
    /*
    if (IsKeyPressed(KEY_ENTER))
    {
        level->level_init();
        states.push(State::GAME);
    }
    */
    
    if (IsKeyPressed(KEY_ONE))
    {
        level->level_order = 1;
        level->level_init();
        states.push(State::GAME);
    }
    if (IsKeyPressed(KEY_TWO))
    {
        level->level_order = 2;
        level->level_init();
        states.push(State::GAME);
    }
    if (IsKeyPressed(KEY_THREE))
    {
        level->level_order = 3;
        level->level_init();
        states.push(State::GAME);
    }
    if (IsKeyPressed(KEY_FOUR))
    {
        level->level_order = 4;
        level->level_init();
        states.push(State::GAME);
    }
    if (IsKeyPressed(KEY_FIVE))
    {
        level->level_order = 5;
        level->level_init();
        states.push(State::GAME);
    }

    ClearBackground(BLACK);
    DrawText("Bee Game", 110, 64, 64, WHITE);
    DrawText("Press 1-5 to start", 80, 128, 32, WHITE);

}

void win_screen_frame(Level* level)
{
    ClearBackground(BLACK);
    DrawText("Congratz!", 110, 64, 64, WHITE);
    DrawText("Press Home to go", 100, 128, 32, WHITE);
    DrawText("back to menu", 140, 160, 32, WHITE);

    if (IsKeyPressed(KEY_HOME))
    {
        level->game_init();
        states.pop();
        states.pop();
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
    
    BeginDrawing();
    Media initial_media;
    initial_media.init_media();
    EndDrawing();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    Level level;
    level.images = initial_media;
    level.game_init();
    
    states.push(State::MAIN_MENU);
    

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
                main_menu_frame(&level);
            break;

            case State::GAME:
                game_frame(&level);
            break;

            case State::WIN_SCREEN:
                win_screen_frame(&level);
            break;
        }

        //level.level_update();
        //level.level_render();
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}