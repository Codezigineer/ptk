#include <Prender/Prender.hh>

using namespace PTk;
using namespace Prender;

bool createWindow(Uint32 w, Uint32 h, 
                  Uint32 x, Uint32 y,
                  const char *title,
                  Window &window)
{
    if(!sdlWasStarted)
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
            return false;
        else
            sdlWasStarted = true;
    
    if(w == 0 || h == 0)
        return false;
    window.window = SDL_CreateWindow(title == nullptr ? "" : title, x, y, w, h, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    if(!window.window)
        return false;
    window.renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);
    if(!window.renderer)
        return false;
    window.surface = SDL_GetWindowSurface(window.window);
};

SDL_Surface *Window::setIcon(Pixel *icon, unsigned w, unsigned h)
{
    SDL_Surface *sicon = SDL_CreateRGBSurfaceFrom((void *)icon, 0, w, h, 32, 0, 0, 0, 0);
    SDL_SetWindowIcon(this->window, sicon);
    return sicon;
};

bool Window::toggleInvis()
{
    SDL_HideWindow(this->window);
    return true;
};

bool Window::toggleVis()
{
    SDL_ShowWindow(this->window);
    return true;
};

bool Window::setTitle(const char *data)
{
    SDL_SetWindowTitle(this->window, data);
    return true;
};

bool Window::setSize(unsigned w, unsigned h)
{
    SDL_SetWindowSize(this->window, w, h);
    return true;
};

bool Window::toggleResizable()
{
    SDL_SetWindowResizable(this->window, (SDL_bool)1);
    return true;
};

bool Window::toggleUnresizable()
{
    SDL_SetWindowResizable(this->window, (SDL_bool)0);
    return true;
};