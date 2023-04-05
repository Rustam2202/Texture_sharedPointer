#pragma once
#include "texture.h"

#include <memory>

//enum class ShapeType { RECTANGLE, ELLIPSE };

class Shape_OOP {
public:
	explicit Shape_OOP() {
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

		void SetTexture(std::shared_ptr<Texture> texture)  {	}

		void Draw(Image& image) const  {	}

protected:
	//	 ShapeType type_;
	Point point_;
	Size size_;
	//	std::shared_ptr<Texture> texture_;
};

class Rectangle : public Shape_OOP {
public:
	void Draw(Image& image) const {
		for (int y = point_.y, y_t = 0; (y < (int)image.size()) && (y < size_.height + point_.y); ++y, ++y_t) {
			if (y < 0) {
				continue;
			}
			for (int x = point_.x, x_t = 0; (x < (int)image[0].size()) && (x < size_.width + point_.x); ++x, ++x_t) {
				if (x < 0) {
					continue;
				}
				if (texture_.get() == nullptr) {
					image[y][x] = '.';
				}
				else {
					image[y][x] = texture_.get()->GetPixelColor({ x_t, y_t });
				}
			}
		}
	}

	void SetTexture(std::shared_ptr<Texture> texture) {
		texture_ = texture;
	}
private:
	std::shared_ptr<Texture> texture_;
};

class Ellipse : public Shape_OOP {
public:
	void Draw(Image& image) const {
		for (int y = point_.y, y_t = 0; (y < (int)image.size()) && (y < size_.height + point_.y); ++y, ++y_t) {
			if (y < 0) {
				continue;
			}
			for (int x = point_.x, x_t = 0; (x < (int)image[0].size()) && (x < size_.width + point_.x); ++x, ++x_t) {
				if (x < 0) {
					continue;
				}
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
		}
	}

	void SetTexture(std::shared_ptr<Texture> texture) {
		texture_ = texture;
	}
private:
	std::shared_ptr<Texture> texture_;
};