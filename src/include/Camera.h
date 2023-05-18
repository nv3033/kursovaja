
#include <glfw/glfw3.h>
#include <glad/glad.h>
#include <vector>
#include <map>
#include "objects.h"
#include "graphics.h"
#include <linmath/linmath.h>

static void DrawUp(vec2& bl, vec2& ul, vec2& br, vec2& ur, std::vector<Hall> Halls_, int HallsCount) {
	bl[0] = (Halls_[HallsCount].pos[0] - 1) / 1280 * 20;
	bl[1] = (Halls_[HallsCount].pos[1] - 1) / 720 * 20;

	ul[0] = (Halls_[HallsCount].pos[0] - 1) / 1280 * 20;
	ul[1] = (Halls_[HallsCount].pos[1] + Halls_[HallsCount].lenght + 1) / 720 * 20;

	br[0] = (Halls_[HallsCount].pos[0] + 1) / 1280 * 20;
	br[1] = (Halls_[HallsCount].pos[1] - 1) / 720 * 20;

	ur[0] = (Halls_[HallsCount].pos[0] + 1) / 1280 * 20;
	ur[1] = (Halls_[HallsCount].pos[1] + Halls_[HallsCount].lenght + 1) / 720 * 20;
}

class Camera
{
public:
	Camera() = default;
	~Camera(); 
	Quad quad[2];
	void Camera::Init(std::vector<Hall> Halls_, int HallsCount) {
		for (int curhall = 0; curhall < HallsCount + 1; curhall++) {
			_color_ qcolor;
			vec2 bl, ul, br, ur;
			std::cout << Halls_[curhall].pos[0] << " , " << Halls_[curhall].pos[1] << std::endl << std::endl;
			DrawUp(bl, ul, br, ur, Halls_, curhall);
			quad[curhall].Init(Halls_[curhall].color, br, ur, bl, ul);
			std::cout << bl[0] << " , " << bl[1] << std::endl << ul[0] << " , " << ul[1] << std::endl << br[0] << " , " << br[1] << std::endl << ur[0] << " , " << ur[1] << std::endl;
		}
	}
	void Camera::Update(std::vector<Hall> Halls_, int HallsCount) {
		quad[0].draw_quad();
		quad[1].draw_quad();

	}
private:

};



Camera::~Camera()
{
}