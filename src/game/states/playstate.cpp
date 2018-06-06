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

#include "playstate.hpp"
#include "pausestate.hpp"
#include "menustate.hpp"

namespace game { namespace  states {
    PlayState PlayState::m_PlayState;
    
    void PlayState::init()
    {
        std::cout << "PlayState: Init successful!" << std::endl;
    }
    
    void PlayState::dispose()
    {
        std::cout << "PlayState: Dispose successful!" << std::endl;
    }
    
    void PlayState::pause()
    {
        std::cout << "PlayState: Paused!" << std::endl;
    }
    
    void PlayState::resume()
    {
        std::cout << "PlayState: Resumed!" << std::endl;
    }
    
    void PlayState::input(engine::Component *comp)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event)) if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_SPACE)
                comp->ChangeState(MenuState::getInstance());
            if (event.key.keysym.sym == SDLK_ESCAPE)
                comp->ChangeState(PauseState::getInstance());
        }
    }
    
    void PlayState::update(engine::Component *comp)
    {
        
    }
    
    void PlayState::draw(engine::Component *comp)
    {
        SDL_SetRenderDrawColor(comp->getRenderer(), 0, 254, 0, 255);
    }
} }
