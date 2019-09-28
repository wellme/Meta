#pragma once

#include "BinInt.cpp"
#include "BinInt.not.cpp"

namespace Meta::BinInt {

	template<typename T1, typename T2>
	struct Xor;

	template<typename T>
	struct Xor<BinIntFalse<void>, BinIntTrue<T>> {
		using type = BinIntFalse<void>;
	};

	template<typename T>
	struct Xor<BinIntFalse<void>, BinIntFalse<T>> {
		using type = BinIntFalse<T>;
	};

	template<typename T>
	struct Xor<BinIntTrue<void>, BinIntTrue<T>> {
		using type = BinIntFalse<typename Not<T>::type>;
	};

	template<typename T>
	struct Xor<BinIntTrue<void>, BinIntFalse<T>> {
		using type = BinIntTrue<typename Not<T>::type>;
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

	template<typename T1, typename T2>
	struct Xor {
		using type = typename Xor<T2, T1>::type;
	};
}