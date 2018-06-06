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

#include "menustate.hpp"
#include "playstate.hpp"

namespace game { namespace  states {
    MenuState MenuState::m_MenuState;
    
    void MenuState::init()
    {
        std::cout << "MenuState: Init successful!" << std::endl;
    }
    
    void MenuState::dispose()
    {
        std::cout << "MenuState: Dispose successful!" << std::endl;
    }
    
    void MenuState::pause()
    {
        std::cout << "MenuState: Paused!" << std::endl;
    }
    
    void MenuState::resume()
    {
        std::cout << "MenuState: Resumed!" << std::endl;
    }
    
    void MenuState::input(engine::Component *comp)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event)) if (event.type == SDL_KEYUP)
            if (event.key.keysym.sym == SDLK_SPACE)
                comp->ChangeState(PlayState::getInstance());
    }
    
    void MenuState::update(engine::Component *comp)
    {
        
    }
    
    void MenuState::draw(engine::Component *comp)
    {
        SDL_SetRenderDrawColor(comp->getRenderer(), 0, 127, 127, 255);
    }
} }
