#pragma once
#include "rlnamespace.hpp"

namespace gem {
    struct Vector2 {
        float x;
        float y;

        operator rl::Vector2(){
            return rl::Vector2{x, y};
        }

        Vector2 operator+(Vector2& v){
            return { x + v.x, y + v.y };
        }
        
        Vector2 operator-(Vector2& v){
            return { x - v.x, y - v.y };
        }
        
        Vector2 operator*(Vector2& v){
            return { x * v.x, y * v.y };
        }
        
        Vector2 operator/(Vector2& v){
            return { x / v.x, y / v.y };
        }

        Vector2 operator+(Vector2&& v){
            return { x + v.x, y + v.y };
        }
        
        Vector2 operator-(Vector2&& v){
            return { x - v.x, y - v.y };
        }
        
        Vector2 operator*(Vector2&& v){
            return { x * v.x, y * v.y };
        }
        
        Vector2 operator/(Vector2&& v){
            return { x / v.x, y / v.y };
        }
        
        float xy() { return x + y; }
        float area() { return x * y; }

        void set(float v){ x = v; y = v; }
    };

    using PivotPreset = Vector2;

    class Pivot {
        public:

        constexpr static PivotPreset Center         = {0.5f, 0.5f};
        constexpr static PivotPreset CenterRight    = {1.0f, 0.5f};
        constexpr static PivotPreset CenterLeft     = {0.0f, 0.5f};
        constexpr static PivotPreset TopRight       = {1.0f, 0.0f};
        constexpr static PivotPreset TopLeft        = {0.0f, 0.0f};
        constexpr static PivotPreset TopMiddle      = {0.5f, 0.0f};
        constexpr static PivotPreset BottomRight    = {1.0f, 1.0f};
        constexpr static PivotPreset BottomLeft     = {0.0f, 1.0f};
        constexpr static PivotPreset BottomMiddle   = {0.5f, 1.0f};
    };
}