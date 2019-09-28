#pragma once

#include "BinInt.cpp"
#include "BinInt.simplify.cpp"
#include "BinInt.xor.cpp"
#include "BinInt.and.cpp"

namespace Meta::BinInt {
	
	template<typename T1, typename T2>
	struct Add;

	template<typename T1>
	struct Add<T1, BinIntFalse<void>> {
		using type = T1;
	};

	template<typename T1, typename T2>
	struct Add {
		using xor = typename Xor<T1, T2>::type;
		using and = typename And<T1, T2>::type;
		using shifted = BinIntFalse<and>;
		using simplified = typename Simplify<shifted>::type;
		using type = typename Add<xor, simplified>::type;
	};
}