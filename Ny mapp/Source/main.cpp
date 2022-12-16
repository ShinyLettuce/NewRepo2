#include "raylib.h"
#include "Level.h"
#include "Media.h"

#include <stack>
#include <iostream>

enum class State
{
    MAIN_MENU,
    GAME,
    WIN_SCREEN
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

    DrawText("Press Del to retry", 32, 448, 24, BLACK);
    DrawText("Press Home to return to main menu", 32, 480, 24, BLACK);
}

void load_level(Level* level, int player_position)
{
    level->level_order = player_position;
    level->level_init();
    states.push(State::GAME);
    std::cout << level->level_order << std::endl;
}

void main_menu_frame(Level* level)
{        
    level->level_render();
    level->level_update();
    DrawText("Bee Game", 110, 64, 64, WHITE);
    DrawText("Move to 1-6", 160, 128, 32, WHITE);
    DrawText("to start a level", 128, 160, 32, WHITE);
    DrawText("1", 92, 208, 32, BLACK);
    DrawText("2", 156, 208, 32, WHITE);
    DrawText("3", 220, 208, 32, BLACK);
    DrawText("4", 284, 208, 32, WHITE);
    DrawText("5", 348, 208, 32, BLACK);
    DrawText("6", 412, 208, 32, WHITE);
    if (level->playerBee.position.y == 3)
    {
        load_level(level, (int)level->playerBee.position.x);
    }
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

    Image beeIcon;

    beeIcon = LoadImage("BeeGameIcon.png");

    InitWindow(screenWidth, screenHeight, "Bee Game");
    SetWindowIcon(beeIcon);
    
    Media initial_media;
    initial_media.init_media();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    Level level;
    level.images = initial_media;
    level.media_loading();
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
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}