#include"console_ui.h"
#include"objects.h"
#include<vector>
#include<linmath/linmath.h>

hall_id add_hall(console console_) {
	int new_id = 0;
	bool not_in_mass = false;
	while (!not_in_mass) {
		not_in_mass = true;
		for (int i = 0; i < console_.HallsCount; i++) 
			if (console_.halls[i].id == new_id) 
				{not_in_mass = false; new id += 1; break;}
	}
	Hall nh = new Hall;
	nh.id = new_id;
	nh.lenght = 1;
	nh.pos = (1, 1);
	nh.direction = (1, 0);
	nh.color = (1, 0, 0);
	console_.halls.push_back(nh);
	std::string s = std::to_string(new_id);
	char const* pchar = s.c_str();   
	console_.addlog_("::id -> " + pchar)
	console_.HallsCount += 1;
	return nh;
}
void edit_hall(console console_, hall_id id_) {
	console.SetCommandMode = "editinghall";
	console.EditingId = id_;
	std::string _id_ = id.id;
	console_.addlog_("::editing " + _id_)
}
void delete_hall(console console_, hall_id id_) {
	console_.halls.pop_back(id_.id);
	console_.HallsCount -= 1;
}
void draw_hall(Hall* hall_)	{
	*hall_->draw = true;
};

void hall_set_direction(Hall* hall_, int new_dir) {
	std::map<int, vec2> m_;
	m_[0] = (1, 0);
	m_[1] = (0, 1);
	m_[2] = (-1, 0);
	m_[3] = (0, -1);
	*hall_->direction = m_[new_dir];
}
void hall_set_pos(Hall* hall_, int pos) { *hall_->pos = pos; }
void hall_set_color(Hall* hall_, color new_color) { *hall_->color = new_color; }



void add_room() {}
void edit_room(room_id id) {}
void delete_room() {}

void errorcolorcode() {
	std::cout << "Color code ERROR!" << std::endl;
	addlog_("::error, wrong color code");
}