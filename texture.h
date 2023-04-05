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
		if (p.y < (int)image_.size() && p.x < (int)image_[0].size()) {
			return image_[p.y][p.x];
		}
		else
		{
			return '.';
		}
	}

private:
	Image image_; // vector<string> = y-x
};