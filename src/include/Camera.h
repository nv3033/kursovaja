#include <vector>
#include <map>
#include "objectss.h"
#include "graphics_editor.h"
#include <linmath/linmath.h>
#include "stb_image.h"

struct qvectors {
	vec2 bl, ul, br, ur;
};

//static void DrawUp(qvectors& qv, std::vector<Wall> Halls_, int HallsCount) {
//	qv.bl[0] = (Halls_[HallsCount].pos[0] - 1) / 1280 * 20;
//	qv.bl[1] = (Halls_[HallsCount].pos[1] - 1) / 720 * 20;
//
//	qv.ul[0] = (Halls_[HallsCount].pos[0] - 1) / 1280 * 20;
//	qv.ul[1] = (Halls_[HallsCount].pos[1] + Halls_[HallsCount].lenght + 1) / 720 * 20;
//
//	qv.br[0] = (Halls_[HallsCount].pos[0] + 1) / 1280 * 20;
//	qv.br[1] = (Halls_[HallsCount].pos[1] - 1) / 720 * 20;
//
//	qv.ur[0] = (Halls_[HallsCount].pos[0] + 1) / 1280 * 20;
//	qv.ur[1] = (Halls_[HallsCount].pos[1] + Halls_[HallsCount].lenght + 1) / 720 * 20;
//}

class Camera
{
public:
	Camera() = default;
	~Camera(); 

    float rt = 1;

    void Camera::scale(float* p, float s) {
        for (int i = 0; i < 24; i++) {
            if (i % 3 == 0)
                p[i] = p[i] * s;
            if (i % 3 == 1)
                p[i] = p[i] * s;
        }
    }

    void Camera::rotatez(float* p, float angle) {
        for (int i = 0; i < 24; i++) {
            if (i % 3 == 0)
                p[i] = cos(angle) * p[i] - sin(angle) * p[i + 1];
            if (i % 3 == 1)
                p[i] = cos(angle) * p[i] + sin(angle) * p[i - 1];
        }
    }
    void Camera::rotatey(float* p, float angle) {
        for (int i = 0; i < 24; i++) {
            if (i % 3 == 0)
                p[i] = cos(angle) * p[i] - sin(angle) * p[i + 2];
            if (i % 3 == 2)
                p[i] = cos(angle) * p[i] + sin(angle) * p[i - 2];
        }
    }

    void Camera::translatex(float* p, float s) {
        for (int i = 0; i < 24; i++) {
            if (i % 3 == 0)
                p[i] = p[i] + s;
        }
    }
    void Camera::translatey(float* p, float s) {
        for (int i = 0; i < 24; i++) {
            if (i % 3 == 2)
                p[i] = p[i] + s;
        }
    }

    float* Camera::perspective(float* p) {
        float ret_p[24];
        for (int i = 0; i < 24; i++) {
            if (i % 3 == 0)
                ret_p[i] = p[i] / p[i + 2];
            if (i % 3 == 1)
                ret_p[i] = p[i] / p[i + 1];
            if (i % 3 == 2)
                ret_p[i] = 1;
        }
        return ret_p;
    }
private:

};



Camera::~Camera()
{
}