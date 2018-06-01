/*
 * This file is part of Pong.
 * Copyright (C) 2018 Rodrigo Casamayor.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FPS 60

namespace pong { namespace graphics {
    
    class Window
    {
    private:
        const char *title;
        int width, height;
        int x, y;
        
        bool running;
        
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
    public:
        Window(const char *title, int width, int height);
        ~Window();
        void start();
        void stop();
        void run();
    private:
        bool init();
        void tick();
        void render() const;
        void cleanup() const;
    };
    
} }
