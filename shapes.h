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
	explicit Shape(ShapeType type) : type_(type) {
		point_.x = 0;
		point_.y = 0;
		size_.height = 0;
		size_.width = 0;
	}

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


		/*auto a = size_.height;
		auto b = size_.width;
		auto c = texture_.get()->GetSize().height;
		auto d = texture_.get()->GetSize().width;*/

		for (int y = point_.y, y_t = 0; y < size_.height + point_.y; ++y, ++y_t) {
			if (y < 0 ) {
				continue;
			}
			for (int x = point_.x, x_t = 0; x < size_.width + point_.x; ++x, ++x_t) {
				if (x < 0 ) {
					continue;
				}
				if (type_ == ShapeType::ELLIPSE) {
					if (IsPointInEllipse({ x_t,y_t }, size_)) {
						if (texture_.get() == nullptr) {
							image[y][x] = '.';
						}
						else {
							image[y][x] = texture_.get()->GetPixelColor({ x_t, y_t });
						}
					}
					else {
						continue;
					}
				}
				else {
					if (texture_.get() == nullptr) {
						image[y][x] = '.';
					}
					else {
						image[y][x] = texture_.get()->GetPixelColor({ x_t, y_t });
					}
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