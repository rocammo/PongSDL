/*
 * This file is part of PongSDL.
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
#include <vector>
#include <SDL2/SDL.h>

#define FPS 60

namespace engine {
    class State;
    class Component
    {
    private:
        const char *title;
        int width, height;
        int x, y;
        bool fullscreen;
        
        bool running = false;
        
        SDL_Window *window;
        SDL_Renderer *renderer;
    public:
        Component(const char *title, int width, int height, bool fullscreen);
        ~Component();
        void start();
        void stop();
        void run();
    private:
        bool init();
        void tick();
        void render();
        void cleanup();
    public:
        void ChangeState(State *state);
        void PushState(State *state);
        void PopState(State *state);
    private:
        std::vector<State *> states;
    public:
        SDL_Renderer* getRenderer() { return renderer; }
    };
}
