#include <iostream>
#include "Meta/BinInt/BinInt.cpp"
#include "Meta/BinInt/BinInt.add.cpp"
#include "Meta/BinInt/BinInt.xor.cpp"
#include "Meta/BinInt/BinInt.reverse.cpp"

using namespace Meta::BinInt;


void main() {
	using n1 = BinIntTrue<BinIntFalse<void>>;
	using n2 = BinIntTrue<BinIntTrue<BinIntFalse<void>>>;

	printf("%d + %d = %d\n", n1::value, n2::value, Add<n1, n2>::type::value);
}
