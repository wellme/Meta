
#pragma once
#include "BinInt.cpp"
#include "BinInt.and.cpp"

namespace Meta::BinInt {

	template<typename T>
	struct IsNull;

	template<typename T>
	struct IsNull<BinIntTrue<T>> {
		using type = False;
	};

	template<>
	struct IsNull<void> {
		using type = True;
	};

	template<typename T>
	struct IsNull<BinIntFalse<T>> {
		using type = typename IsNull<T>::type;
	};
}