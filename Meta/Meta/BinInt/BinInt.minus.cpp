
#pragma once
#include "BinInt.cpp"

namespace Meta::BinInt {

	template<typename T>
	struct Minus;

	template<>
	struct Minus<void> {
		using type = void;
	};
}