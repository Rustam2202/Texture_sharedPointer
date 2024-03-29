#pragma once
//#include "shapes.h"
#include "shapes_oop.h"

#include <iostream>
#include <map>
#include <string_view>

// �����, �� ������� ����������� ������
class Canvas_OOP {
public:
	using ShapeId = size_t;

	explicit Canvas_OOP(Size size)
		: size_(size) {
	}

	void SetSize(Size size) {
		size_ = size;
	}

	ShapeId AddEllipse(Point position, Size size, std::shared_ptr<Texture> texture) {
		auto shape = std::make_unique <Ellipse>();
		shape->SetPosition(position);
		shape->SetSize(size);
		shape->SetTexture(std::move(texture));
		return InsertShape(std::move(shape));
	}

	ShapeId AddRectangle(Point position, Size size, std::shared_ptr<Texture> texture) {
		auto shape = std::make_unique <Rectangle>();
		shape->SetPosition(position);
		shape->SetSize(size);
		shape->SetTexture(std::move(texture));
		return InsertShape(std::move(shape));
	}

	// ������� ������ � �������� id
	void RemoveShape(ShapeId id) {
		shapes_.erase(GetShapeNodeById(id));
	}

	// �������� ���������� ������
	void MoveShape(ShapeId id, Point position) {
		GetShapeNodeById(id)->second->SetPosition(position);
	}

	// �������� ������� ������
	void ResizeShape(ShapeId id, Size size) {
		GetShapeNodeById(id)->second->SetSize(size);
	}

	// ���������� ���������� �����
	int GetShapesCount() const {
		return static_cast<int>(shapes_.size());
	}

	// ����� ����������� ������ � �����
	void Print(std::ostream& output) const {
		using namespace std::literals;

		Image image(size_.height, std::string(size_.width, ' '));

		for (const auto& [id, shape] : shapes_) {
			shape->Draw(image);
		}

		output << '#' << std::string(size_.width, '#') << "#\n"sv;
		for (const auto& line : image) {
			output << '#' << line << "#\n"sv;
		}
		output << '#' << std::string(size_.width, '#') << "#\n"sv;
	}

private:
	using Shapes = std::map<ShapeId, std::unique_ptr<Shape_OOP>>;

	Shapes::iterator GetShapeNodeById(ShapeId id) {
		auto it = shapes_.find(id);
		if (it == shapes_.end()) {
			throw std::out_of_range("No shape with given ID");
		}
		return it;
	}
	ShapeId InsertShape(std::unique_ptr<Shape_OOP> shape) {
		shapes_[current_id_] = std::move(shape);
		return current_id_++;
	}

	Size size_ = {};
	ShapeId current_id_ = 0;
	Shapes shapes_;
};