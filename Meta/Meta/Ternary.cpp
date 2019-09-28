#pragma once

#include "BinInt/BinInt.cpp"

namespace Meta {
	
	template<typename B, typename T1, typename T2>
	struct Ternary;

	template<typename T1, typename T2>
	struct Ternary<BinInt::False, T1, T2> {
		using type = T2;
	};

	template<typename T1, typename T2>
	struct Ternary<BinInt::True, T1, T2> {
		using type = T1;
	};

}