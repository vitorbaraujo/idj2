#include "resources.h"
#include "game.h"

unordered_map<string, shared_ptr<SDL_Texture> > Resources::m_image_table;
unordered_map<string, shared_ptr<Mix_Music> > Resources::m_music_table;
unordered_map<string, shared_ptr<Mix_Chunk> > Resources::m_sound_table;

shared_ptr<SDL_Texture> Resources::get_image(string file){
    auto it = m_image_table.find(file);

    if(it != m_image_table.end())
        return it->second;

    SDL_Texture* texture = IMG_LoadTexture(Game::get_instance().get_renderer(), file.c_str());

    if(!texture){
        return nullptr;
    }

    shared_ptr<SDL_Texture> ptr(texture, [](SDL_Texture *t){ SDL_DestroyTexture(t); });
    m_image_table.emplace(file, ptr);

    return ptr;
}

void Resources::clear_images(){
    for(auto it = m_image_table.begin(); it != m_image_table.end(); ++it){
        if(it->second.unique()){
            m_image_table.erase(it);
        }
    }

    m_image_table.clear();
}

shared_ptr<Mix_Music> Resources::get_music(string file){
    auto it = m_music_table.find(file);

    if(it != m_music_table.end())
        return it->second;

    Mix_Music* music = Mix_LoadMUS(file.c_str());

    if(!music){
        return nullptr;
    }

    shared_ptr<Mix_Music> ptr(music, [](Mix_Music* m){ Mix_FreeMusic(m); });
    m_music_table.emplace(file, ptr);

    return ptr;
}

void Resources::clear_music(){
    for(auto it = m_music_table.begin(); it != m_music_table.end(); ++it){
        if(it->second.unique()){
            m_music_table.erase(it);
        }
    }

    m_music_table.clear();
}

shared_ptr<Mix_Chunk> Resources::get_sound(string file){
    auto it = m_sound_table.find(file);

    if(it != m_sound_table.end())
        return it->second;

    Mix_Chunk* sound = Mix_LoadWAV(file.c_str());

    if(!sound){
        return nullptr;
    }

    shared_ptr<Mix_Chunk> ptr(sound, [](Mix_Chunk* c){ Mix_FreeChunk(c); });
    m_sound_table.emplace(file, ptr);

    return ptr;
}

void Resources::clear_sound(){
    for(auto it = m_sound_table.begin(); it != m_sound_table.end(); ++it){
        if(it->second.unique()){
            m_sound_table.erase(it);
        }
    }

    m_sound_table.clear();
}
