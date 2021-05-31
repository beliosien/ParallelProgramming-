#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Display
{
private:
    SDL_Window* m_window;
    SDL_GLContext m_glcontext;
    bool m_isClosed;


public:
    Display(int width, int height, const std::string& title);
    ~Display();

    void Update();
    bool IsClosed();
};



#endif // DISPLAY_H