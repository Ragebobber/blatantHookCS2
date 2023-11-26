#pragma once

namespace sdk {
	extern std::unique_ptr<Helpers> helpers;
	extern std::unique_ptr<Drawer> drawer;
	extern std::unique_ptr<ClassPointers> pointers;
	extern std::unique_ptr<Math> math;
	extern std::unique_ptr<IFactory> factory;
	extern std::unique_ptr<Init> init;
}