#include "DOP.h"
#include "OOP.h"
#include "modified_DOP.h"

#include <iostream>
#include <chrono>
#include <string>
#include <functional>

using namespace std::chrono;

void Test_DOP() {
	auto t1 = high_resolution_clock::now();

	DOP::Person* vec = new DOP::Person();

	DOP::Person_init(vec, 1000000, [](int i)->std::string { return ""; }, [](int i)->int { return 100; }, [](int i)->int { return 20; }, [](int i)->float { return i % 100; }, [](int i)-> float { return i / 100; }, [](int i)->float { return 0; }, [](int i)-> float { return 0; }, [](int i)-> float { return 0; }, [](int i)-> float { return 0; }, [](int i)-> float { return 0; });

	DOP::Vector3_Move(vec, [](int i)->float { return 1; }, [](int i)->float { return 2; }, [](int i)->float { return 3; });
	DOP::Vector3_Move(vec, [](int i)->float { return -1; }, [](int i)->float { return -2; }, [](int i)->float { return -3; });

	auto t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	std::cout << "DOP: " << duration << " ms\n";

	delete vec;
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
	std::cout << "end\n";
	std::cin.get();
	return 0;
}