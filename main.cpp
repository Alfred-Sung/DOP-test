#include "DOP.h"
#include "OOP.h"

#include <iostream>
#include <chrono>
#include <string>

using namespace std::chrono;

void Test_DOP() {
	auto t1 = high_resolution_clock::now();

	DOP::Person vec;

#pragma region Initialization
	vec.name.reserve(1000000);
	for (int i = 0; i < vec.name.capacity(); i++)
		vec.name.push_back("");

	vec.health.reserve(1000000);
	for (int i = 0; i < vec.health.capacity(); i++)
		vec.health.push_back(100);

	vec.age.reserve(1000000);
	for (int i = 0; i < vec.age.capacity(); i++)
		vec.age.push_back(0);

	vec.position.reserve(1000000);
	for (int i = 0; i < vec.position.capacity(); i++)
		vec.position.push_back(DOP::Vector3(i % 100, i / 100, 0));

	vec.position.reserve(1000000);
	for (int i = 0; i < vec.rotation.capacity(); i++)
		vec.rotation.push_back(DOP::Quaternion());
#pragma endregion

#pragma region Method Implementation
	for (int i = 0; i < 10; i++) {
		for (int i = 0; i < 1000000; i++) {
			vec.position[i].x += 1;
			vec.position[i].y += 2;
			vec.position[i].z += 3;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int i = 0; i < 1000000; i++) {
			vec.position[i].x += -1;
			vec.position[i].y += -2;
			vec.position[i].z += -3;
		}
	}
#pragma endregion

	auto t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	std::cout << "DOP: " << duration << " ms\n";

	vec.name.clear();
	vec.health.clear();
	vec.age.clear();
	vec.position.clear();
	vec.rotation.clear();
}

void Test_OOP() {
	auto t1 = high_resolution_clock::now();

	std::vector<OOP::Person> vec;

	vec.reserve(1000000);
	for (int i = 0; i < vec.capacity(); i++)
		vec.push_back(OOP::Person("", 100, 20, OOP::Vector3(i % 100, i / 100, 0), OOP::Quaternion()));

	for (int i = 0; i < 10; i++) {
		for (auto ptr : vec)
			ptr.position.Move(1, 2, 3);
	}

	for (int i = 0; i < 10; i++) {
		for (auto ptr : vec)
			ptr.position.Move(-1, -2, -3);
	}

	auto t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	std::cout << "OOP: " << duration << " ms\n";

	vec.clear();
}

int main() {
	for (int i = 0; i < 10; i++) {
		Test_OOP();
		Test_DOP();
	}

	std::cin.get();
	return 0;
}