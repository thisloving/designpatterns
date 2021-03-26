#include "user.h"
#include <iostream>

using namespace std;

class User::Impl {
public:
	Impl();
	~Impl();

public:
	int  getSalary();
	void setSalary(int);

private:
	int salary;
};

User::Impl::Impl() :
	salary(0)
{}

User::Impl::~Impl()
{}

int User::Impl::getSalary() {
	return salary;
}

void User::Impl::setSalary(int value) {
	salary = value;
}

/////////////////////////////////////////
User::User() :
	pimpl(new Impl())	
{
}

User::~User()
{}

int User::getSalary() {
	return pimpl->getSalary();
}

void User::setSalary(int value) {
	pimpl->setSalary(value);
}
