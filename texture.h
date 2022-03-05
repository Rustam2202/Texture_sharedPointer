#pragma once
#include "common.h"

class Texture {
public:
	explicit Texture(Image image)
		: image_(std::move(image)) {
	}

	Size GetSize() const {
		// Заглушка. Реализуйте метод самостоятельно
		return { (int)image_[0].size(), (int)image_.size() };
	}

	char GetPixelColor(Point p) const {
		//(void)p;
		// Заглушка. Реализуйте метод самостоятельно
		return image_[p.y][p.x];
	}

private:
	Image image_; // vector<string> = y-x
};