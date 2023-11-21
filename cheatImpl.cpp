#include "cheat.h"

std::unique_ptr<Vars> cheat::vars(new Vars);
std::unique_ptr<Visuals> cheat::visuals(new Visuals);
std::unique_ptr<Menu> cheat::menu(new Menu);