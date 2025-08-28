#include "Gem/core.hpp"
#include "Gem/graphics.hpp"
#include "Gem/input.hpp"

class Game : public gem::Window {
    public:
    gem::TextureManager manager;

    Game(): Window("My Game", {800, 600}){
        Uint8 pixels[] = {
            255, 0, 0, 255,
            0, 255, 0, 255,
            0, 0, 255, 255,
            255, 255, 0, 255
        };

        manager.loadEmbeddedRaw("ball", pixels, 2, 2);
    }
    
    void update(float delta) override {
    }

    void render() override {
        gem::Graphics::clear(gem::Colors::Wheat);
        gem::Graphics::texture(
            manager.getTexture("ball"),
            {100, 100},
            gem::Colors::NoTint,
            {10.0f, 10.0f}
        );
    }

    void dispose() override {
        manager.unloadAll(); // unloadTexture is available
    }
};

int main(int argc, char const *argv[])
{
    Game game;
    game.run();
    return 0;
}
