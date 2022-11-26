#ifndef PRENDER_HH_
#define PRENDER_HH_

#include <SDL2/SDL.h>
#include <PTk/PTk.hh>

namespace PTk
{
    namespace Prender {
        extern bool sdlWasStarted;
        
        class Window {
        public:
            SDL_Window *window;
            SDL_Surface *surface;
            SDL_Renderer *renderer;
            SDL_Surface *setIcon(Pixel *data, unsigned w, unsigned h);
            bool setTitle(const char *data);
            bool setSize(Uint32 w, Uint32 h);
            bool toggleResizable();
            bool toggleUnresizable();
            bool toggleInvis();
            bool toggleVis();
        };

        bool createWindow(Uint32 w, Uint32 h, 
                        const char *title, bool resize, 
                        Window &window);
    };
} // namespace PTk


#endif // PRENDER_HH_