#pragma once
#include <vector>
#include <memory>
#include "FieldObject.h"

class WindowTab;//forward-declaring class WindowTab to resolve circular-dependency issue

class ObjectsField
{
private:
	WindowTab* windowTab;
	Vector2f origin;
	Vector2f pos;
	Vector2f size;
	float scale;
public:
	std::vector<std::shared_ptr<FieldObject>> objects;
	int Distance(FieldObject* first, FieldObject* second);
	void DrawAll();
	ObjectsField(WindowTab* window);
	~ObjectsField();
};

