#pragma once
#include "texture.h"

#include <memory>

// Поддерживаемые виды фигур: прямоугольник и эллипс
enum class ShapeType { RECTANGLE, ELLIPSE };

using namespace std;

class Shape {
public:
	// Фигура после создания имеет нулевые координаты и размер,
	// а также не имеет текстуры
	explicit Shape(ShapeType type) : type_(type) {}

	void SetPosition(Point pos) {
		point_ = pos;
	}

	void SetSize(Size size) {
		size_ = size;
	}

	void SetTexture(std::shared_ptr<Texture> texture) {
		texture_ = texture;
	}

	// Рисует фигуру на указанном изображении
	// В зависимости от типа фигуры должен рисоваться либо эллипс, либо прямоугольник
	// Пиксели фигуры, выходящие за пределы текстуры, а также в случае, когда текстура не задана,
	// должны отображаться с помощью символа точка '.'
	// Части фигуры, выходящие за границы объекта image, должны отбрасываться.
	void Draw(Image& image) const {
		//(void)image;
		// Заглушка. Реализуйте метод самостоятельно


		for (string x_axis : image) {
			for (char ch : x_axis) {
				Point p(ch, x_axis);
				if (IsPointInEllipse(p, size_)) {

				}
			}
		}
	}

private:
	ShapeType type_;
	Point point_;
	Size size_;
	shared_ptr<Texture> texture_;
};