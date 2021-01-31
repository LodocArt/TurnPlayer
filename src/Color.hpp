#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <ostream>
#include <vector>

namespace Color {
	enum Code {
		colorRed			= 31,
		colorGreen			= 32,
		colorYellow			= 33,
		colorBlue			= 34,
		colorMagenta		= 35,
		colorCyan			= 36,
		colorDefault		= 39,
		colorDarkGray		= 90,
		colorLightRed		= 91,
		colorLightGreen		= 92,
		colorLightYellow	= 93,
		colorLightBlue		= 94,
		colorLightMagenta	= 95,
		colorLightCyan		= 96
	};

	class Modifier {
		Code code;

		public :
			Modifier(Code pCode) : code(pCode) {}
			friend std::ostream &
			operator<<(std::ostream & os, const Modifier & mod) {
				return os<<"\033["<<mod.code<<"m";
			}
	};
}

#endif