#ifndef OOP_H
#define OOP_H

#include <vector>
#include <string>

namespace OOP {
	struct Vector3 {
		float x;
		float y;
		float z;

		Vector3() : x(0), y(0), z(0) {}
		Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

		void Move(float dx, float dy, float dz) {
			x += dx;
			y += dy;
			z += dz;
		}

		void Scale(float amount) {
			x *= amount;
			y *= amount;
			z *= amount;
		}
	};

	struct Quaternion {
		float x;
		float y;
		float z;
		float w;

		Quaternion() : x(0), y(0), z(0), w(0) {}
		Quaternion(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
	};

	struct Entity {
		Vector3 position;
		Quaternion rotation;
		std::string name;
		int health;

		Entity(std::string name_, int health_, Vector3 position_, Quaternion rotation_) : name(name_), health(health_), position(position_), rotation(rotation_) {}
	};

	struct Person : Entity {
		int age;

		Person(std::string name_, int health_, int age_, Vector3 position_, Quaternion rotation_) : age(age_), Entity(name_, health_, position_, rotation_) {}
	};
}

#endif