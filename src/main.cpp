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

#include "engine/component.hpp"
#include "game/states/menustate.hpp"

int main(int argc, char** args)
{
    std::cout << "==== DEBUG MODE ====" << std::endl;
    
    using namespace engine;
    Component game("Pong!", 640, 480, false);
    game.ChangeState(game::states::MenuState::getInstance());
    game.start();
    
    return(0);
}
