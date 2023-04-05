#include "canvas_oop.h"
#include "tests.h"

void TestCppOop() {
	Canvas_OOP canvas(Size{ 77, 17 });

	canvas.AddEllipse({ 2, 1 }, { 30, 15 }, MakeTextureCheckers({ 100, 100 }, 'c', 'C'));
	canvas.AddEllipse({ 8, 4 }, { 30, 9 }, MakeTextureSolid({ 100, 100 }, ' '));

	// Горизонтальные чёрточки плюсов
	auto h1 = canvas.AddRectangle({ 54, 7 }, { 22, 3 }, MakeTextureSolid({ 100, 100 }, '+'));
	canvas.DuplicateShape(h1, { 30, 7 });

	// Вертикальные чёрточки плюсов
	auto v1 = canvas.DuplicateShape(h1, { 62, 3 });
	canvas.ResizeShape(v1, { 6, 11 });
	canvas.DuplicateShape(v1, { 38, 3 });

	std::stringstream output;
	canvas.Print(output);
	std::cout << output.str();
}