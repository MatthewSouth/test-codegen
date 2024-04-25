#include <vector>

// class with method that does silly things on potential nullptr
class foo
{
public:
	foo()
		: p{ nullptr }
	{
	}

	auto method() -> int
	{
		++p;
		*p = 37;
		return *p;
	}

	int* p;
};



// function that takes potential nullptr
auto f(int* i) -> int
{ 
	int g = *i; 
	return g; 
}


int main(int argc, char* argv[])
{
	// out of bounds
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
	for (int i = 0; i != numbers.size(); ++i) {
		if (numbers[i] == 3) {
			numbers.erase(numbers.begin() + i);
		}
	}

	// in-scope null pointer
	int* s = nullptr;
	++s;
	*s = 37;

	// nested null pointer
	foo _foo;
	auto _foo_result = _foo.method();


	// pass nullptr into function
	f(nullptr);
}