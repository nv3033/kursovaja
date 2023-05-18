#include <linmath/linmath.h>
struct hall_id{
    int id;}; 

struct room_id{
    int id;};

struct _color_ {
	float r; float g; float b;};



class Hall
{
public:
	Hall() = default;
	//Hall(hall_id id_, vec2 pos_, int lenght_, vec2 direction_, bool draw_) {
	//	id = id_;
	//	pos = pos_;
	//	lenght = lenght
	//};
	~Hall();

	hall_id id;
	vec2 pos;
	int lenght;
	int direction;
	bool draw = false;
	_color_ color;

private:

};

Hall::~Hall()
{
}


class Room
{
public:
	Room() = default;
	~Room();

	room_id id;
	vec2 pos1;
	vec2 pos2;
	bool draw = false;
	_color_ color;

private:

};

Room::~Room()
{
}