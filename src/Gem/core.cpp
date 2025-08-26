#include "core.hpp"

void gem::Window::run()
{
    while (!rl::WindowShouldClose()){
        update(rl::GetFrameTime());

        rl::BeginDrawing();
            render();
        rl::EndDrawing();
    }

    dispose();

    rl::CloseAudioDevice();
    rl::CloseWindow();
}