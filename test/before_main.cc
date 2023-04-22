#include <iostream>

// Some methods to run codes before main

// I. template instantiate
namespace {
	int x = 0;

	template<class T>
	class B {
	public:
		// 3
		B() {
			x = 1;
		}
	private:
		// 2
		static B<T> b;

		// 1
		template<B<T>& b> struct C{};
		using D = C<b>;
	};

	// 2
	template<class T>
	B<T> B<T>::b;

	// 0
	class BB : public B<int> {};
}

// II.
namespace {
	void __attribute__ ((constructor)) premain() {
	    printf("premain()\n");
	}
}

// III. global variable be evaluated
namespace {
	auto& ccout = std::cout << "cout" << std::endl;
}

// IV. static class member be evaluated
namespace {
	class A {
	public:
		A() {
			std::cout << "A" << std::endl;
		}
	private:
		static A a;
	};
	A A::a;
}

int main() {
	std::cout << "in main" << std::endl;
	std::cout << x << std::endl;
}
