#pragma once
#include <linmath/linmath.h>
#include <string>
#include <glad/glad.h>


class Wall
{
public:
	struct wall_id {
		int id;
	};
	struct _color_ {
		GLfloat r; GLfloat g; GLfloat b;
	};

	Wall() = default;
	~Wall();

	wall_id id;
	vec2 pos1;
	std::string name;
	vec2 pos2;
	bool draw = false;
	_color_ color;
	
	 Wall::Wall(wall_id id_, float pos1x_, float pos1y_, float pos2x_, float pos2y_, bool draw_) {
		id = id_;
		pos1[0] = pos1x_;
		pos1[1] = pos1y_;
		pos2[0] = pos1x_;
		pos2[1] = pos1y_;
		draw = draw_;
	};
private:

};

Wall::~Wall()
{
}