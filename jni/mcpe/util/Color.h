#pragma once

#include <cmath>

class Color {
public:
	float red, green, blue, alpha;

	Color(){}
	Color(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a) {};
	Color(unsigned int color, bool ignoreAlpha) {
		if (ignoreAlpha) {
			alpha = 1.0f;
			red = (float) (color >> 16 & 255) / 255.0F;
			green = (float) (color >> 8 & 255) / 255.0F;
			blue = (float) (color & 255) / 255.0F;
		}
		else {
			alpha = (float) (color >> 24 & 255) / 255.0F;
			red = (float) (color >> 16 & 255) / 255.0F;
			green = (float) (color >> 8 & 255) / 255.0F;
			blue = (float) (color & 255) / 255.0F;
		}
	}

	unsigned int toARGB() const;
	unsigned int toABGR() const;

	static Color fromHSB(float, float, float);

	static Color average(Color colorA, Color colorB, float percentage) {
		float opposite = 1.0F - percentage;
		//Gamma correction

		float averageR = (float) sqrt((colorA.red * colorA.red) * (opposite) + (colorB.red * colorB.red) * (percentage));
		float averageG = (float) sqrt((colorA.green * colorA.green) * (opposite) + (colorB.red * colorB.green) * (percentage));
		float averageB = (float) sqrt((colorA.blue * colorA.blue) * (opposite) + (colorB.red * colorB.blue) * (percentage));
		float averageA = colorA.alpha * opposite + colorB.alpha * percentage;
		
		return Color(averageR, averageG, averageB, averageA);
	}

	static Color WHITE;
	static Color GREY;
	static Color BLACK;
	static Color RED;
	static Color GREEN;
	static Color BLUE;
	static Color YELLOW;
	static Color ORANGE;
	static Color PURPLE;
	static Color CYAN;
	static Color NIL;
	static Color SHADE_DOWN;
	static Color SHADE_UP;
	static Color SHADE_NORTH_SOUTH;
	static Color SHADE_WEST_EAST;

};

