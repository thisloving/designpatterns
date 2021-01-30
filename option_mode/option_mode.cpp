#include <functional>
#include <string>
#include <iostream>

struct Person {
	int id;
	std::string name;
};

std::ostream& operator<< (std::ostream& out, const Person& p) {
	return out << p.id << "\t" << p.name;
}

using OptionFunc = std::function<void(Person&)>;

template <typename ...OptionFunc>
Person CreatePerson(OptionFunc&& ...opts) {
	Person person = Person{0, ""};

	(std::forward<OptionFunc>(opts)(person), ...);
	return std::move(person);
}

OptionFunc WithID(int id) {
	return [id](Person& opts) {
		opts.id = id;
	};
}

OptionFunc WithName(const std::string& name) {
	return [name](Person& opts) {
		opts.name = name;
	};
}

int main()
{
	auto p = CreatePerson(WithID(123));
	std::cout << p << std::endl;

	p = CreatePerson(WithName("tom"));
	std::cout << p << std::endl;

	p = CreatePerson(WithID(123), WithName("tom"));
	std::cout << p << std::endl;

	p = CreatePerson(WithName("tom"), WithID(123));
	std::cout << p << std::endl;

	return 0;
}

// g++ -std=c++20 -g option_mode.cpp -o option_mode
