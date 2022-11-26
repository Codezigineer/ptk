#ifndef PTK_HH_
#define PTK_HH_

#include <vector>
#include <SDL.h>

#ifndef extends
#define extends : public 
#endif

namespace PTk
{
    typedef Root Root;

    typedef unsigned int Pixel;

    /// @brief Basic string class for PTk.
    class String {
      public:
        String(char *text);

        void operator=(char *text);
        char &operator[](size_t idx);

        size_t getlength() const;
      protected:
        char *str;
        size_t len;
    };

    /// @brief Draw color, used if you want gradients.
    union DrawColor
    {
        /// @brief Gradient type.
        struct Gradient 
        {
            /// @brief type of gradient.
            enum class Type 
            {
                Conic = 0,
                Radial = 1,
                Linear = 2,
            };

            Type type;
            std::vector<double> *stops;
            std::vector<Pixel> *colors;
        };

        Gradient *gradient;
        Pixel color;
    };

    /// @brief UI node for PTk.
    class Node 
    {
      public:
        Node(Node *parent, bool parentIsRoot);
        Node();

        /// @brief Gets PTk root.
        /// @return ^^^
        Root *getUIRoot();
        /// @brief Gets parent node. If the parent is root, then it returns root upcasted.
        /// @return ^^^
        Node *getParent();

        unsigned w;
        unsigned h;

      protected:
        Root *root;
        Node *parent;
        bool parentIsRoot;
    };

    class Root extends Node 
    {
      public:
        Root(unsigned w = 320, unsigned h = 200, const char *title = "", bool resizable = true);
        void setTitle(String &title);
        String &getTitle();
        void setIcon(Pixel *icon, unsigned w, unsigned h);
        bool setInvis(bool invis);
        bool getInvis();
        bool setSize(unsigned w, unsigned h);
        const unsigned (&getSize())[2];
      protected:
        String *title;
        unsigned w;
        unsigned h;
        Pixel *icon;
        SDL_Surface *sicon;
        bool invis;
        void *winData;
    };
}; // namespace PTk

#endif // PTK_HH_