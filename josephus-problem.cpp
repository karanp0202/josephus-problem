#include <iostream>
#include <vector>

struct soldier {
	int id;
	bool isAlive;
};

int byLogic(int count) {
	std::vector<soldier> list;

	for (int i = 0; i < count; i++)list.push_back({ i + 1, true });

	while (list.size() > 1) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i].isAlive) {
				if (i != list.size() - 1) {
					// std::cout << "now soldier at " << list[i].id << " going to kill " << list[i + 1].id << std::endl;
					list[i + 1].isAlive = false;
				}
				else {
					// std::cout << "now soldier at " << list[i].id << " going to kill " << list[0].id << std::endl;
					list[0].isAlive = false;
				}
			}
		}
		for (int i = list.size() - 1; i >= 0; i--) {
			if (!list[i].isAlive) {
				// std::cout << "now we have removed ! " << list[i].id << std::endl;
				list.erase(list.begin() + i);
			}
		}
		list.shrink_to_fit();
		std::cout << "now we shrinked to half and size is " << list.size() << std::endl;
	}
	return list[0].id;
}

int bySecq(int count) {
	int alive = 0;
	for (int i = 1; i <= count; i++) {
		if (alive + 2 <= i)alive += 2;
		else alive = 1;
	}
	return alive;
}

int main() {

	int count = 524288;

	//std::cout << "Count : ";
	//std::cin >> count;

	std::cout << "answer by logic : " << byLogic(count) << std::endl;
	std::cout << "answer by trick : " << bySecq(count) << std::endl;
}