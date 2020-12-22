#ifndef DOP_H
#define DOP_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>

namespace DOP {
	typedef struct Vector3 {
		std::vector<float> Vector3_x, Vector3_y, Vector3_z;
	} Vector3;

	template<typename A, typename B, typename C, typename D>
	void Vector3_init(A entity, int size, const B& x_, const C& y_, const D& z_) {
		entity->Vector3_x.clear();
		entity->Vector3_y.clear();
		entity->Vector3_z.clear();

		entity->Vector3_x.reserve(size);
		entity->Vector3_y.reserve(size);
		entity->Vector3_z.reserve(size);

		for (int i = 0; i < size; i++)
			entity->Vector3_x.push_back(x_(i));
		for (int i = 0; i < size; i++)
			entity->Vector3_y.push_back(y_(i));
		for (int i = 0; i < size; i++)
			entity->Vector3_z.push_back(z_(i));
	}

	template<typename A, typename B, typename C, typename D>
	void Vector3_Move(A entity, const B& dx, const C& dy, const D& dz) {
		for (int i = 0; i < entity->Vector3_x.size(); i++)
			entity->Vector3_x[i] += dx(i);
		for (int i = 0; i < entity->Vector3_y.size(); i++)
			entity->Vector3_y[i] += dy(i);
		for (int i = 0; i < entity->Vector3_z.size(); i++)
			entity->Vector3_z[i] += dz(i);
	}

	template<typename A, typename B>
	void Vector3_Scale(A entity, const B& amount) {
		for (int i = 0; i < entity->Vector3_x.size(); i++)
			entity->Vector3_x[i] *= amount(i);
		for (int i = 0; i < entity->Vector3_y.size(); i++)
			entity->Vector3_y[i] *= amount(i);
		for (int i = 0; i < entity->Vector3_z.size(); i++)
			entity->Vector3_z[i] *= amount(i);
	}

	typedef struct Quaternion {
		std::vector<float> Quaternion_x, Quaternion_y, Quaternion_z, Quaternion_w;
	} Quaternion;

	template<typename A, typename B, typename C, typename D, typename E>
	void Quaternion_init(A entity, int size, const B& x_, const C& y_, const D& z_, const E& w_) {
		entity->Quaternion_x.clear();
		entity->Quaternion_y.clear();
		entity->Quaternion_z.clear();
		entity->Quaternion_w.clear();

		entity->Quaternion_x.reserve(size);
		entity->Quaternion_y.reserve(size);
		entity->Quaternion_z.reserve(size);
		entity->Quaternion_w.reserve(size);

		for (int i = 0; i < size; i++)
			entity->Quaternion_x.push_back(x_(i));
		for (int i = 0; i < size; i++)
			entity->Quaternion_y.push_back(y_(i));
		for (int i = 0; i < size; i++)
			entity->Quaternion_z.push_back(z_(i));
		for (int i = 0; i < size; i++)
			entity->Quaternion_w.push_back(w_(i));
	}

	typedef struct Entity {
		std::vector<float> Vector3_x, Vector3_y, Vector3_z;
		std::vector<float> Quaternion_x, Quaternion_y, Quaternion_z, Quaternion_w;
		std::vector<std::string> Entity_name;
		std::vector<int> Entity_health;
	} Entity;

	template<typename A, typename B, typename C, typename Vector3A, typename Vector3B, typename Vector3C, typename QuaternionA, typename QuaternionB, typename QuaternionC, typename QuaternionD>
	void Entity_init(A entity, int size, const B& name_, const C& health_, const Vector3A& Vector3_x_, const Vector3B& Vector3_y_, const Vector3C& Vector3_z_, const QuaternionA& Quaternion_x_, const QuaternionB& Quaternion_y_, const QuaternionC& Quaternion_z_, const QuaternionD& Quaternion_w_) {
		Vector3_init(entity, size, Vector3_x_, Vector3_y_, Vector3_z_);
		Quaternion_init(entity, size, Quaternion_x_, Quaternion_y_, Quaternion_z_, Quaternion_w_);

		entity->Entity_name.clear();
		entity->Entity_health.clear();

		entity->Entity_name.reserve(size);
		entity->Entity_health.reserve(size);

		for (int i = 0; i < size; i++)
			entity->Entity_name.push_back(name_(i));
		for (int i = 0; i < size; i++)
			entity->Entity_health.push_back(health_(i));
	}

	typedef struct Person {
		std::vector<float> Vector3_x, Vector3_y, Vector3_z;
		std::vector<float> Quaternion_x, Quaternion_y, Quaternion_z, Quaternion_w;
		std::vector<std::string> Entity_name;
		std::vector<int> Entity_health;
		std::vector<int> Person_age;
	} Person;

	template<typename A, typename B, typename C, typename D, typename Vector3A, typename Vector3B, typename Vector3C, typename QuaternionA, typename QuaternionB, typename QuaternionC, typename QuaternionD>
	void Person_init(A entity, const int size, const B& name_, const C& age_, const D& health_, const Vector3A& Vector3_x_, const Vector3B& Vector3_y_, const Vector3C& Vector3_z_, const QuaternionA& Quaternion_x_, const QuaternionB& Quaternion_y_, const QuaternionC& Quaternion_z_, const QuaternionD& Quaternion_w_) {
		Entity_init(entity, size, name_, health_, Vector3_x_, Vector3_y_, Vector3_z_, Quaternion_x_, Quaternion_y_, Quaternion_z_, Quaternion_w_);

		entity->Person_age.clear();

		entity->Person_age.reserve(size);

		for (int i = 0; i < size; i++)
			entity->Person_age.push_back(age_(i));
	}
}
#endif