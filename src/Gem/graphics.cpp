#include "graphics.hpp"


const gem::Color gem::Colors::Red       = {255, 0,   0,   255};
const gem::Color gem::Colors::Green     = {0,   255, 0,   255};
const gem::Color gem::Colors::Blue      = {0,   0,   255, 255};
const gem::Color gem::Colors::Yellow    = {255, 255, 0,   255};
const gem::Color gem::Colors::Magenta   = {255, 0,   255, 255};
const gem::Color gem::Colors::Cyan      = {0,   255, 255, 255};
const gem::Color gem::Colors::White     = {255, 255, 255, 255};
const gem::Color gem::Colors::Black     = {0,   0,   0,   255};
const gem::Color gem::Colors::Gray      = {128, 128, 128, 255};
const gem::Color gem::Colors::Orange    = {255, 165, 0,   255};
const gem::Color gem::Colors::Purple    = {128, 0,   128, 255};
const gem::Color gem::Colors::Brown     = {165, 42,  42,  255};
const gem::Color gem::Colors::Pink      = {255, 192, 203, 255};
const gem::Color gem::Colors::Lime      = {0,   255, 0,   255};
const gem::Color gem::Colors::Navy      = {0,   0,   128, 255};
const gem::Color gem::Colors::Teal      = {0,   128, 128, 255};
const gem::Color gem::Colors::Olive     = {128, 128, 0,   255};
const gem::Color gem::Colors::Maroon    = {128, 0,   0,   255};
const gem::Color gem::Colors::Silver    = {192, 192, 192, 255};
const gem::Color gem::Colors::Gold      = {255, 215, 0,   255};
const gem::Color gem::Colors::SkyBlue   = {135, 206, 235, 255};
const gem::Color gem::Colors::Violet    = {238, 130, 238, 255};
const gem::Color gem::Colors::Indigo    = {75,  0,   130, 255};
const gem::Color gem::Colors::Beige     = {245, 245, 220, 255};
const gem::Color gem::Colors::Mint      = {189, 252, 201, 255};
const gem::Color gem::Colors::Coral     = {255, 127, 80,  255};
const gem::Color gem::Colors::Salmon    = {250, 128, 114, 255};
const gem::Color gem::Colors::Chocolate = {210, 105, 30,  255};
const gem::Color gem::Colors::Crimson   = {220, 20,  60,  255};
const gem::Color gem::Colors::Turquoise = {64,  224, 208, 255};
const gem::Color gem::Colors::Azure     = {240, 255, 255, 255};
const gem::Color gem::Colors::Lavender  = {230, 230, 250, 255};
const gem::Color gem::Colors::Ivory     = {255, 255, 240, 255};
const gem::Color gem::Colors::Peach     = {255, 218, 185, 255};
const gem::Color gem::Colors::Wheat     = {245, 222, 179, 255};

void gem::Graphics::clear(Color color)
{
    rl::ClearBackground(color);
}

void gem::Graphics::rectangle(Vector2 position, Vector2 size, Color color)
{
    rl::DrawRectangle(position.x, position.y, size.x, size.y, color);
}

void gem::Graphics::rectangle(Rectangle rect)
{
    rl::DrawRectanglePro(rect, rect.origin(), rect.angle(), rect.color());
}

void gem::Graphics::rectangleLines(Vector2 position, Vector2 size, Color color)
{
    rl::DrawRectangleLines(position.x, position.y, size.x, size.y, color);
}

void gem::Graphics::rectangleStroke(Vector2 position, Vector2 size, float thickness, Color fillColor, Color strokeColor)
{
    rl::DrawRectangle(position.x - (thickness / 2), position.y - (thickness / 2), size.x + thickness, size.y + thickness, strokeColor);
    rl::DrawRectangle(position.x, position.y, size.x, size.y, fillColor);
}

void gem::Graphics::circle(Vector2 center, float radius, Color color)
{
    rl::DrawCircle(center.x, center.y, radius, color);
}

void gem::Graphics::circleLines(Vector2 center, float radius, Color color)
{
    rl::DrawCircleLines(center.x, center.y, radius, color);
}

void gem::Graphics::ellipse(Vector2 center, Vector2 radius, Color color)
{
    rl::DrawEllipse(center.x, center.y, radius.x, radius.y, color);
}

void gem::Graphics::ellipseLines(Vector2 center, Vector2 radius, Color color)
{
    rl::DrawEllipseLines(center.x, center.y, radius.x, radius.y, color);
}

void gem::Graphics::poly(Vector2 center, float radius, int sides, float rot, Color color)
{
    rl::DrawPoly(center, sides, radius, rot, color);
}

void gem::Graphics::polyLines(Vector2 center, float radius, int sides, float rot, Color color)
{
    rl::DrawPolyLines(center, sides, radius, rot, color);
}

void gem::Graphics::text(Vector2 position, const std::string &text, int fontSize, Color color, int spacing, float angle)
{
    rl::DrawTextPro(rl::GetFontDefault(), text.c_str(), position, rl::Vector2{0, 0}, angle, fontSize, spacing, color);
}
