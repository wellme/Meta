
#pragma once
#include "BinInt.cpp"

namespace Meta::BinInt {

	template<typename T>
	struct Not;

	template<>
	struct Not<void> {
		using type = void;
	};

	template<typename T>
	struct Not<BinIntTrue<T>> {
		using type = BinIntFalse<typename Not<T>::type>;
	};

	template<typename T>
	struct Not<BinIntFalse<T>> {
		using type = BinIntTrue<typename Not<T>::type>;
	};
}