#include <iostream>
#include "Meta/BinInt/BinInt.cpp"
#include "Meta/BinInt/BinInt.add.cpp"
#include "Meta/BinInt/BinInt.xor.cpp"
#include "Meta/BinInt/BinInt.reverse.cpp"
#include "Meta/BinInt/BinInt.lengthen.cpp"

using namespace Meta::BinInt;


void main() {
	using n1 = BinIntTrue<void>;
	using n2 = BinIntTrue<BinIntFalse<void>>;

	using result = Lengthen<n1, n2>::type1;

	printf("%d + %d = %d\n", n1::value, n2::value, result::value);
}
