#include <Prender/Prender.cc>

using namespace PTk;

/* String */

String::String(char *text)
{
    this->len = strlen(text);
    this->str = (char *)malloc(this->len);
    strncpy(this->str, text, this->len);
};

void String::operator=(char *text)
{
    this->len = strlen(text);
    this->str = (char *)malloc(this->len);
    strncpy(this->str, text, this->len);
};

char &String::operator[](size_t idx)
{
    if(idx > this->len)
        return this->str[this->len];
    return this->str[idx];
};

size_t String::getlength() const
{
    return this->len;
};

/* UI */

Node::Node(Node *parent, bool parentIsRoot)
{
    if(this->parent == nullptr)
        delete this;
    
    this->parent = parent;

    if(parentIsRoot)
    {
        this->root = (Root *)parent;
    };

    this->parentIsRoot = parentIsRoot;
};

Node *Node::getParent()
{
    return this->parent;
};

Root *Node::getUIRoot()
{
    return this->root;
};

Root::Root(unsigned w = 320, unsigned h = 200, const char *title = "", bool resizable = true)
{
    this->w = w;
    this->h = h;
    this->winData = (void *)new Prender::Window();
    if(!createWindow(w, h, title, resizable, (Prender::Window &)this->winData))
        delete this;
    this->parentIsRoot = true;
    this->parent = this;
    this->root = this;
};

bool Root::getInvis()
{
    return this->invis;
};

bool Root::setInvis(bool invis)
{
    if(invis != this->invis) {
        ((Prender::Window *)winData)->toggleInvis();
    };
    this->invis = invis;

    return true;
};

const unsigned (&Root::getSize())[2]
{
    return {this->w, this->h};
};

bool Root::setSize(unsigned w, unsigned h)
{
    ((Prender::Window *)winData)->setSize(w, h);
    this->w = w;
    this->h = h;
    return true;
};

void Root::setTitle(String &title)
{
    char *str = (char *)malloc(title.getlength());
    for(size_t i = 0; i != title.getlength(); i++)
        str[i] = title[i];
    ((Prender::Window *)winData)->setTitle(str);
    this->title = new String(str);
};

String &Root::getTitle()
{
    char *str = (char *)malloc(this->title->getlength());
    for(size_t i = 0; i != this->title->getlength(); i++)
        str[i] = (*this->title)[i];
    return *(new String(str));
};