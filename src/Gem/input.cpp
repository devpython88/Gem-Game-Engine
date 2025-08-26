#include "input.hpp"

bool gem::Input::isKeyPressed(int key)
{
    return rl::IsKeyPressed(key);
}

bool gem::Input::isKeyHeld(int key)
{
    return rl::IsKeyDown(key);
}

bool gem::Input::isKeyReleased(int key)
{
    return rl::IsKeyReleased(key);
}

bool gem::Input::isKeyUp(int key)
{
    return rl::IsKeyUp(key);
}



bool gem::Input::isButtonPressed(int button)
{
    return rl::IsMouseButtonPressed(button);
}

bool gem::Input::isButtonHeld(int button)
{
    return rl::IsMouseButtonDown(button);
}

bool gem::Input::isButtonReleased(int button)
{
    return rl::IsMouseButtonReleased(button);
}

bool gem::Input::isButtonUp(int button)
{
    return rl::IsMouseButtonUp(button);
}

gem::Vector2 gem::Input::mousePosition()
{
    return {rl::GetMouseX(), rl::GetMouseY()};
}

gem::Vector2 gem::Input::mouseScrollVector()
{
    return {rl::GetMouseWheelMoveV().x, rl::GetMouseWheelMoveV().y};
}

float gem::Input::mouseScroll()
{
    return rl::GetMouseWheelMove();
}
