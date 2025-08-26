#include "Gem/core.hpp"
#include "Gem/graphics.hpp"
#include "Gem/input.hpp"

class Game : public gem::Window {
    public:

    gem::Rectangle rect = gem::Rectangle({100, 100}, {50, 50}, gem::Colors::SkyBlue);

    Game(): Window("My Game", {800, 600}){
        rect.usePivotPreset(gem::Pivot::Center);
    }
    
    void update(float delta) override {
        rect.forward(100.0f);
        rect.lookAt(gem::Input::mousePosition());
        rect.update(delta);
        rect.resetVelocity();
    }

    void render() override {
        gem::Graphics::clear(gem::Colors::Wheat);
        gem::Graphics::rectangle(rect);
        gem::Graphics::text({0, 0}, "Hello!", 24, gem::Colors::Black);
    }
};

int main(int argc, char const *argv[])
{
    Game game;
    game.run();
    return 0;
}
