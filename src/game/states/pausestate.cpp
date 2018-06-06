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

#include "pausestate.hpp"
#include "playstate.hpp"

namespace game { namespace  states {
    PauseState PauseState::m_PauseState;
    
    void PauseState::init()
    {
        std::cout << "PauseState: Init successful!" << std::endl;
    }
    
    void PauseState::dispose()
    {
        std::cout << "PauseState: Dispose successful!" << std::endl;
    }
    
    void PauseState::pause()
    {
        std::cout << "PauseState: Paused!" << std::endl;
    }
    
    void PauseState::resume()
    {
        std::cout << "PauseState: Resumed!" << std::endl;
    }
    
    void PauseState::input(engine::Component *comp)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event)) if (event.type == SDL_KEYUP)
            if (event.key.keysym.sym == SDLK_ESCAPE)
                comp->ChangeState(PlayState::getInstance());
    }
    
    void PauseState::update(engine::Component *comp)
    {
        
    }
    
    void PauseState::draw(engine::Component *comp)
    {
        SDL_SetRenderDrawColor(comp->getRenderer(), 254, 127, 0, 255);
    }
} }
