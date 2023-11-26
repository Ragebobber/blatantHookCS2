#include "sdk.h"

std::unique_ptr<Helpers> sdk::helpers(new Helpers);
std::unique_ptr<Drawer> sdk::drawer(new Drawer);
std::unique_ptr<ClassPointers> sdk::pointers(new ClassPointers);
std::unique_ptr<Math> sdk::math(new Math);
std::unique_ptr<IFactory> sdk::factory(new IFactory);
std::unique_ptr<Init> sdk::init(new Init);