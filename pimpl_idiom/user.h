#ifndef _USER_H_
#define _USER_H_

#include <memory>
#include <string>

using namespace std;

class User {
public:
	User();
	~User();

public:
	int  getSalary();
	void setSalary(int);

private:
	User(const User& other);
	User& operator=(User& other);

private:
	class Impl;

	unique_ptr<Impl> pimpl;
};

#endif
// _USER_H_
