#include <iostream>

class Singleton {
public:
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}

private:
	Singleton(){}	
	~Singleton() {}
	Singleton(const Singleton&);
	Singleton operator=(const Singleton&);
};

int main()
{
}
