#pragma once
#include "rlnamespace.hpp"
#include "math.hpp"

namespace gem {
    class Input {
        public:

        constexpr static int A = rl::KEY_A;
        constexpr static int B = rl::KEY_B;
        constexpr static int C = rl::KEY_C;
        constexpr static int D = rl::KEY_D;
        constexpr static int E = rl::KEY_E;
        constexpr static int F = rl::KEY_F;
        constexpr static int G = rl::KEY_G;
        constexpr static int H = rl::KEY_H;
        constexpr static int I = rl::KEY_I;
        constexpr static int J = rl::KEY_J;
        constexpr static int K = rl::KEY_K;
        constexpr static int L = rl::KEY_L;
        constexpr static int M = rl::KEY_M;
        constexpr static int N = rl::KEY_N;
        constexpr static int O = rl::KEY_O;
        constexpr static int P = rl::KEY_P;
        constexpr static int Q = rl::KEY_Q;
        constexpr static int R = rl::KEY_R;
        constexpr static int S = rl::KEY_S;
        constexpr static int T = rl::KEY_T;
        constexpr static int U = rl::KEY_U;
        constexpr static int V = rl::KEY_V;
        constexpr static int W = rl::KEY_W;
        constexpr static int X = rl::KEY_X;
        constexpr static int Y = rl::KEY_Y;
        constexpr static int Z = rl::KEY_Z;

        constexpr static int Space = rl::KEY_SPACE;
        constexpr static int Enter = rl::KEY_ENTER;
        constexpr static int Escape = rl::KEY_ESCAPE;
        constexpr static int Tab = rl::KEY_TAB;
        constexpr static int Backspace = rl::KEY_BACKSPACE;
        constexpr static int Delete = rl::KEY_DELETE;
        constexpr static int Insert = rl::KEY_INSERT;
        constexpr static int Home = rl::KEY_HOME;
        constexpr static int End = rl::KEY_END;
        constexpr static int PageUp = rl::KEY_PAGE_UP;
        constexpr static int PageDown = rl::KEY_PAGE_DOWN;

        constexpr static int Left = rl::KEY_LEFT;
        constexpr static int Right = rl::KEY_RIGHT;
        constexpr static int Up = rl::KEY_UP;
        constexpr static int Down = rl::KEY_DOWN;

        constexpr static int Function1 = rl::KEY_F1;
        constexpr static int Function2 = rl::KEY_F2;
        constexpr static int Function3 = rl::KEY_F3;
        constexpr static int Function4 = rl::KEY_F4;
        constexpr static int Function5 = rl::KEY_F5;
        constexpr static int Function6 = rl::KEY_F6;
        constexpr static int Function7 = rl::KEY_F7;
        constexpr static int Function8 = rl::KEY_F8;
        constexpr static int Function9 = rl::KEY_F9;
        constexpr static int Function10 = rl::KEY_F10;
        constexpr static int Function11 = rl::KEY_F11;
        constexpr static int Function12 = rl::KEY_F12;

        constexpr static int Number0 = rl::KEY_ZERO;
        constexpr static int Number1 = rl::KEY_ONE;
        constexpr static int Number2 = rl::KEY_TWO;
        constexpr static int Number3 = rl::KEY_THREE;
        constexpr static int Number4 = rl::KEY_FOUR;
        constexpr static int Number5 = rl::KEY_FIVE;
        constexpr static int Number6 = rl::KEY_SIX;
        constexpr static int Number7 = rl::KEY_SEVEN;
        constexpr static int Number8 = rl::KEY_EIGHT;
        constexpr static int Number9 = rl::KEY_NINE;

        constexpr static int LeftShift = rl::KEY_LEFT_SHIFT;
        constexpr static int RightShift = rl::KEY_RIGHT_SHIFT;
        constexpr static int LeftControl = rl::KEY_LEFT_CONTROL;
        constexpr static int RightControl = rl::KEY_RIGHT_CONTROL;
        constexpr static int LeftAlt = rl::KEY_LEFT_ALT;
        constexpr static int RightAlt = rl::KEY_RIGHT_ALT;
        constexpr static int LeftSuper = rl::KEY_LEFT_SUPER;
        constexpr static int RightSuper = rl::KEY_RIGHT_SUPER;

        constexpr static int CapsLock = rl::KEY_CAPS_LOCK;
        constexpr static int ScrollLock = rl::KEY_SCROLL_LOCK;
        constexpr static int NumLock = rl::KEY_NUM_LOCK;
        constexpr static int PrintScreen = rl::KEY_PRINT_SCREEN;
        constexpr static int Pause = rl::KEY_PAUSE;

        constexpr static int Comma = rl::KEY_COMMA;
        constexpr static int Period = rl::KEY_PERIOD;
        constexpr static int Slash = rl::KEY_SLASH;
        constexpr static int Semicolon = rl::KEY_SEMICOLON;
        constexpr static int Apostrophe = rl::KEY_APOSTROPHE;
        constexpr static int LeftBracket = rl::KEY_LEFT_BRACKET;
        constexpr static int RightBracket = rl::KEY_RIGHT_BRACKET;
        constexpr static int Backslash = rl::KEY_BACKSLASH;
        constexpr static int Minus = rl::KEY_MINUS;
        constexpr static int Equal = rl::KEY_EQUAL;
        constexpr static int Grave = rl::KEY_GRAVE;

        static bool isKeyPressed(int key);
        static bool isKeyHeld(int key);
        static bool isKeyReleased(int key);
        static bool isKeyUp(int key);

        static bool isButtonPressed(int button);
        static bool isButtonHeld(int button);
        static bool isButtonReleased(int button);
        static bool isButtonUp(int button);

        static Vector2 mousePosition();
        static Vector2 mouseScrollVector();
        static float mouseScroll();
    };
};