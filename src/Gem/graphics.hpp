#pragma once
#include "math.hpp"
#include <cstdint>
#include <cmath>
#include <string>


using Uint8  = uint8_t;
using Uint16 = uint16_t;
using Uint32 = uint32_t;
using Uint64 = uint64_t;
using Int8   = int8_t;
using Int16  = int16_t;
using Int32  = int32_t;
using Int64  = int64_t;

namespace gem {
    struct Color {
        Uint8 r;
        Uint8 g;
        Uint8 b;
        Uint8 a;

        operator rl::Color(){
            return rl::Color{r, g, b, a};
        }
    };

    class Colors {
        public:
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Magenta;
        static const Color Cyan;
        static const Color White;
        static const Color Black;
        static const Color Gray;
        static const Color Orange;
        static const Color Purple;
        static const Color Brown;
        static const Color Pink;
        static const Color Lime;
        static const Color Navy;
        static const Color Teal;
        static const Color Olive;
        static const Color Maroon;
        static const Color Silver;
        static const Color Gold;
        static const Color SkyBlue;
        static const Color Violet;
        static const Color Indigo;
        static const Color Beige;
        static const Color Mint;
        static const Color Coral;
        static const Color Salmon;
        static const Color Chocolate;
        static const Color Crimson;
        static const Color Turquoise;
        static const Color Azure;
        static const Color Lavender;
        static const Color Ivory;
        static const Color Peach;
        static const Color Wheat;
    };

    
    
    class Object {
        protected:
        Vector2 m_Position  = { 0, 0 };
        Vector2 m_Origin    = { 0, 0 };
        Vector2 m_Size      = { 0, 0 };
        Vector2 m_Velocity  = { 0, 0 };
        float m_Angle       = 0.0f;
        bool m_Visible      = true;
        bool m_CanCollide   = true;

    public:

        Object() = default;
        Object(const Vector2& Position, const Vector2& Size): m_Position(Position), m_Size(Size){}
        
        virtual Vector2 position() { return m_Position + m_Origin; }
        virtual Vector2 positionRaw() const { return m_Position; }
        virtual void setPosition(const Vector2 &Position) { m_Position = Position; }
 
        virtual void setX(float x){ setPosition({ x, m_Position.y }); }
        virtual void setY(float y){ setPosition({ m_Position.x, y }); }
 
        virtual Vector2 origin() const { return m_Origin; }
        virtual void setOrigin(const Vector2 &Origin) { m_Origin = Origin; }
        virtual void usePivotPreset(PivotPreset preset) { m_Origin = m_Size * preset; }
 
        virtual Vector2 size() const { return m_Size; }
        virtual void setSize(const Vector2 &Size) { m_Size = Size; }
 
        virtual void setWidth(float width){ setSize({ width, m_Size.y }); }
        virtual void setHeight(float height){ setSize({ m_Size.x, height }); }
 
        virtual Vector2 velocity() const { return m_Velocity; }
        virtual void setVelocity(const Vector2 &Velocity) { m_Velocity = Velocity; }
        virtual void resetVelocity(){ m_Velocity.set(0.0f); }
        virtual void move(const Vector2 &delta){ m_Velocity.x += delta.x; m_Velocity.y += delta.y; }
 
        virtual float angle() const { return m_Angle; }
        virtual void setAngle(float Angle) { m_Angle = Angle; }
        virtual void rotate(float rotateDelta){ m_Angle += rotateDelta; }

        virtual void forward(float units){
            float radians = m_Angle * DEG2RAD;
            float dx = cosf(radians) * units;
            float dy = sinf(radians) * units;

            setVelocity({dx, dy});
        }

        virtual bool visible() const { return m_Visible; }
        virtual void setVisible(bool Visible) { m_Visible = Visible; }
 
        virtual bool canCollide() const { return m_CanCollide; }
        virtual void setCanCollide(bool CanCollide) { m_CanCollide = CanCollide; }

        virtual void update(float delta) {
            m_Position = m_Position + (m_Velocity * Vector2{delta, delta});
        }

        virtual Vector2 hitSize(){
            return {m_Size.x, m_Size.y};
        }

        virtual void lookAt(Vector2 point){
            float dx = point.x - position().x;
            float dy = point.y - position().y;

            double angleRad = atan2(dy, dx);
            setAngle(angleRad * RAD2DEG);
        }

        virtual bool intersects(Object& other){
            Vector2 size1 = hitSize();
            Vector2 size2 = other.hitSize();

            Vector2 pos1 = position();
            Vector2 pos2 = other.position();

            return pos1.x + size1.x > pos2.x &&
                pos1.x < pos2.x + size2.x &&
                pos1.y + size1.y >  pos2.y &&
                pos1.y < pos2.y + size2.y;
        }
    };
    
    class Rectangle : public Object {
        protected:
        Color m_Color = Colors::Black;

        public:
        Rectangle() = default;
        Rectangle(const Vector2& Position, const Vector2& Size, const Color& color_): Object(Position, Size), m_Color(color_){}
            

        Color color() const { return m_Color; }
        void setColor(const Color &Color) { m_Color = Color; }

        operator rl::Rectangle(){
            return rl::Rectangle{m_Position.x, m_Position.y, m_Size.x, m_Size.y};
        }
    };

    class Graphics {
        private:

        public:

        static void clear(Color color);
        static void rectangle(Vector2 position, Vector2 size, Color color);
        static void rectangle(Rectangle rect);
        static void rectangleLines(Vector2 position, Vector2 size, Color color);
        static void rectangleStroke(Vector2 position, Vector2 size, float thickness, Color fillColor, Color strokeColor);

        static void circle(Vector2 center, float radius, Color color);
        static void circleLines(Vector2 center, float radius, Color color);
        static void ellipse(Vector2 center, Vector2 radius, Color color);
        static void ellipseLines(Vector2 center, Vector2 radius, Color color);

        static void poly(Vector2 center, float radius, int sides, float rot, Color color);
        static void polyLines(Vector2 center, float radius, int sides, float rot, Color color);

        static void text(Vector2 position, const std::string& text, int fontSize, Color color, int spacing = 1, float angle = 0.0f);
    };
}