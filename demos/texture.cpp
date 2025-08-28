#include "Gem/core.hpp"
#include "Gem/graphics.hpp"
#include "Gem/input.hpp"

class Game : public gem::Window {
    public:
    gem::TextureManager manager;

    Game(): Window("My Game", {800, 600}){
        auto error = manager.loadTexture("ball", "Ball.png");
        if (!error.ok){
            printf("Error: %s\n", error.what); // useful for texture already existing or not being loaded 
        }
    }
    
    void update(float delta) override {
    }

    void render() override {
        gem::Graphics::clear(gem::Colors::Wheat);
        gem::Graphics::texture(
            manager.getTexture("ball"),
            {100, 100}, 
            gem::Colors::NoTint, 
            {3.0f, 3.0f}
        );
        // Optional: tint, scale, angle
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
