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

#include "component.hpp"

namespace engine {
    class State
    {
    public:
        virtual void init() = 0;
        virtual void dispose() = 0;
        
        virtual void pause() = 0;
        virtual void resume() = 0;
        
        virtual void input(Component *comp) = 0;
        virtual void update(Component *comp) = 0;
        virtual void draw(Component *comp) = 0;
        
        void ChangeState(Component *comp, State *state) {
            comp->ChangeState(state);
        }
    protected:
        State() { }
    };
}
