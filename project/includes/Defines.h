#pragma once

constexpr float pi = 3.14159f;

constexpr int screen_W = 800;
constexpr int screen_H = 400;

struct vec2
{
	float x, y;

	void zero() { x = 0, y = 0; }
};

constexpr double ToDegrees(float radins) {return  radins * (180 / pi); }
constexpr double ToRadins(float degrees) { return degrees * (pi / 180); }
