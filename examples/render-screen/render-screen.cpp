#include <iostream>

#include "Engine.hpp"
#include "Events.hpp"

std::vector<std::string> fill_args(int argc, char* argv[]) {
    std::vector<std::string> args;
    for (auto i = 1; i < argc; i++) {
        args.push_back(std::string(argv[i]));
    }
    return args;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "Windows.h"
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
	int argc = 0;
	char* argv[1];
#else
int main(int argc, char* argv[]) {
#endif
    IdeaEngine::Engine engine(fill_args(argc, argv));
    engine.initialize();
    
    // Initialize event handler
    GameEvent *ge = new GameEvent("events", &engine);

    engine.event()->subscribe(ge);
    return engine.run();
}
