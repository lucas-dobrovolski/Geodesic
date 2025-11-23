#include <memory>

#include "Window.hpp"

class App {
public:
    App();
    ~App();

    void run();

private:
    bool init();
    void mainLoop();
    void shutdown();

    void initImGui();
    void shutdownImGui();

    Window* m_window;
};
