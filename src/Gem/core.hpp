#pragma once
#include "math.hpp"
#include <string>


namespace gem {
    class Graphics;

    class Window {
        private:
        Vector2 m_Size;
        std::string m_Title;

        public:
        Window(): Window("Gem"){}
        Window(const std::string& title): Window(title, {640, 480}){}
        Window(const std::string& title, Vector2 size): m_Title(title), m_Size(size){
            rl::InitWindow(size.x, size.y, title.c_str());
            rl::InitAudioDevice();
        }

        virtual void update(float deltaTime){}
        virtual void render(){}
        virtual void dispose(){}

        void run();

        Vector2 size() const { return m_Size; }
        void setSize(const Vector2 &Size) { m_Size = Size; }

        std::string title() const { return m_Title; }
        void setTitle(const std::string &Title) { m_Title = Title; }
    };
}

