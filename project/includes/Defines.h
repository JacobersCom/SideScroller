#pragma once

constexpr float pi = 3.14159f;

constexpr int screen_W = 800;
constexpr int screen_H = 400;

struct vec2
{
	float x, y;
};

constexpr float ToDegrees(float radins) {return  radins * (180 / pi); }
constexpr float ToRadins(float degrees) { return degrees * (pi / 180); }
