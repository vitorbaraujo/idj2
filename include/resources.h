#ifndef RESOURCES_H
#define RESOURCES_H

#include "SDL2/SDL_image.h"

#include <iostream>
#include <unordered_map>
#include <memory> // shared_ptr

using std::string;
using std::unordered_map;
using std::shared_ptr;

class Resources {
    private:
        static unordered_map<string, shared_ptr<SDL_Texture> > image_table;

    public:
        static shared_ptr<SDL_Texture> get_image(string file);
        static void clear_images();

};

#endif
