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

#include "component.hpp"

#include "state.hpp"

namespace engine {
   Component::Component(const char *title, int width, int height, bool fullscreen)
    : title(title), width(width), height(height), fullscreen(fullscreen)
    {
        this->x = this->y = SDL_WINDOWPOS_CENTERED;
        
        if (!init())
            this->~Component();
    }
    
    Component::~Component() { cleanup(); }
    
    void Component::start()
    {
        if (running) return;
        running = true;
        run();
    }
    
    void Component::stop()
    {
        if (!running) return;
        running = false;
    }
    
    void Component::run()
    {
        int frames = 0;
        
        double unprocessedSeconds = 0;
        long lastTime = SDL_GetTicks() * 1000000;
        double secondsPerTick = 1 / 60.0;
        int tickCount = 0;
        
        while (running) {
            long now = SDL_GetTicks() * 1000000;
            long passedTime = now - lastTime;
            lastTime = now;
            if (passedTime < 0) passedTime = 0;
            if (passedTime > 100000000) passedTime = 100000000;
            
            unprocessedSeconds += passedTime / 1000000000.0;
            
            bool ticked = false;
            while (unprocessedSeconds > secondsPerTick) {
                tick();
                unprocessedSeconds -= secondsPerTick;
                ticked = true;
                
                tickCount++;
                if (tickCount % FPS == 0) {
                    std::cout << "FPS: " << frames << std::endl;
                    lastTime += 1000;
                    frames = 0;
                }
            }
            
            if (ticked) {
                render();
                frames++;
            } else {
                SDL_Delay(1);
            }
        }
    }
    
    bool Component::init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cout << "[ERR] " << SDL_GetError() << std::endl;
            return false;
        } std::cout << "[LOG] " << "Initializing SDL..." << std::endl;
        
        Uint32 win_flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
        window = SDL_CreateWindow(title, x, y, width, height, win_flags);
        if (!window) {
            std::cout << "[ERR] " << SDL_GetError() << std::endl;
            return false;
        } std::cout << "[LOG] " << "Creating window..." << std::endl;
        
        Uint32 render_flags = SDL_RENDERER_ACCELERATED;
        renderer = SDL_CreateRenderer(window, -1, render_flags);
        if (!renderer) {
            std::cout << "[ERR] " << SDL_GetError() << std::endl;
            return false;
        } std::cout << "[LOG] " << "Creating renderer..." << std::endl;
        
        return true;
    }
    
    void Component::tick()
    {
        states.back()->input(this);
        states.back()->update(this);
        
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                stop();
        }
    }
    
    void Component::render()
    {
        states.back()->draw(this);
        
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    
    void Component::cleanup()
    {
        while (!states.empty()) {
            states.back()->dispose();
            states.pop_back();
        }
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
    void Component::ChangeState(State *state)
    {
        // cleanup the current state
        if (!states.empty()) {
            states.back()->dispose();
            states.pop_back();
        }
        
        // store and init the new state
        states.push_back(state);
        states.back()->init();
    }
    
    void Component::PushState(State *state)
    {
        // pause the current state
        if (!states.empty()) {
            states.back()->pause();
        }
        
        // store and init the new state
        states.push_back(state);
        states.back()->init();
    }
    
    void Component::PopState(State *state)
    {
        // cleanup the current state
        if (!states.empty()) {
            states.back()->dispose();
            states.pop_back();
        }
        
        // resume the previous state
        if (!states.empty()) {
            states.back()->resume();
        }
    }
}
