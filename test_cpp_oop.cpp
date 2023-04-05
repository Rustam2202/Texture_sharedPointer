#include "canvas_oop.h"
#include "tests.h"

void TestCppOop() {
	Canvas_OOP canvas(Size{ 77, 17 });

	canvas.AddEllipse({ 2, 1 }, { 30, 15 }, MakeTextureCheckers({ 100, 100 }, 'c', 'C'));
	canvas.AddEllipse({ 8, 4 }, { 30, 9 }, MakeTextureSolid({ 100, 100 }, ' '));

	canvas.AddRectangle({ 54, 7 }, { 22, 3 }, MakeTextureSolid({ 100, 100 }, '+'));
	canvas.AddRectangle({ 30, 7 }, { 22, 3 }, MakeTextureSolid({ 100, 100 }, '+'));
	canvas.AddRectangle({ 62, 3 }, { 6, 11 }, MakeTextureSolid({ 100, 100 }, '+'));
	canvas.AddRectangle({ 38, 3 }, { 6, 11 }, MakeTextureSolid({ 100, 100 }, '+'));

	std::stringstream output;
	canvas.Print(output);
	std::cout << output.str();
}