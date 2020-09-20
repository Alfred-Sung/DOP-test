#ifndef DOP_H
#define DOP_H

#include <vector>
#include <string>

namespace DOP {
	struct Vector3 {
		float x;
		float y;
		float z;

		Vector3() : x(0), y(0), z(0) {}
		Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
	};

	struct Quaternion {
		float x;
		float y;
		float z;
		float w;

		Quaternion() : x(0), y(0), z(0), w(0) {}
		Quaternion(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
	};

	// Entity and derived class variables are implemented into one struct
	struct Person {
		std::vector<Vector3> position;
		std::vector<Quaternion> rotation;
		std::vector<std::string> name;
		std::vector<int> health;
		std::vector<int> age;
	};
}
#endif