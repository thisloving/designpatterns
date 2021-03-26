#include "user.h"
#include <iostream>

using namespace std;

int main() 
{
	User user;
	user.setSalary(10);
	int salary = user.getSalary();
	cout << salary << endl;
}
