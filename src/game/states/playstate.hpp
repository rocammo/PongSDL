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

#include "state.hpp"

namespace game { namespace  states {
    class PlayState : public engine::State
    {
    public:
        void init();
        void dispose();
        
        void pause();
        void resume();
        
        void input(engine::Component *comp);
        void update(engine::Component *comp);
        void draw(engine::Component *comp);
        
        // Singleton
        static PlayState* getInstance()
        {
            return &m_PlayState;
        }
    protected:
        PlayState() { }
    private:
        static PlayState m_PlayState;
    };
} }
