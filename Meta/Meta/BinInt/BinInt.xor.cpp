#pragma once

#include "BinInt.cpp"

namespace Meta::BinInt {

	template<typename T1, typename T2>
	struct Xor;

	template<>
	struct Xor<void, void> {
		using type = void;
	};

	template<typename T>
	struct Xor<T, void> {
		using type = T;
	};

	template<typename T>
	struct Xor<void, T> {
		using type = T;
	};


	template<typename T1, typename T2>
	struct Xor<BinIntFalse<T1>, BinIntFalse<T2>> {
		using type = BinIntFalse<typename Xor<T1, T2>::type>;
	};

	template<typename T1, typename T2>
	struct Xor<BinIntFalse<T1>, BinIntTrue<T2>> {
		using type = BinIntTrue<typename Xor<T1, T2>::type>;
	};

	template<typename T1, typename T2>
	struct Xor<BinIntTrue<T1>, BinIntFalse<T2>> {
		using type = BinIntTrue<typename Xor<T1, T2>::type>;
	};

	template<typename T1, typename T2>
	struct Xor<BinIntTrue<T1>, BinIntTrue<T2>> {
		using type = BinIntFalse<typename Xor<T1, T2>::type>;
	};
}