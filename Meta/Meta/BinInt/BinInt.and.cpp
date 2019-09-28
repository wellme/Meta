#pragma once

#include "BinInt.cpp"

namespace Meta::BinInt {

	template<typename T1, typename T2>
	struct And;

	template<typename T>
	struct And<BinIntFalse<void>, BinIntTrue<T>> {
		using type = BinIntFalse<void>;
	};

	template<typename T>
	struct And<BinIntFalse<void>, BinIntFalse<T>> {
		using type = BinIntFalse<void>;
	};

	template<typename T>
	struct And<BinIntTrue<void>, BinIntTrue<T>> {
		using type = BinIntTrue<T>;
	};

	template<typename T>
	struct And<BinIntTrue<void>, BinIntFalse<T>> {
		using type = BinIntFalse<T>;
	};

	template<typename T1, typename T2>
	struct And<BinIntFalse<T1>, BinIntFalse<T2>> {
		using type = BinIntFalse<typename And<T1, T2>::type>;
	};

	template<typename T1, typename T2>
	struct And<BinIntFalse<T1>, BinIntTrue<T2>> {
		using type = BinIntFalse<typename And<T1, T2>::type>;
	};

	template<typename T1, typename T2>
	struct And<BinIntTrue<T1>, BinIntFalse<T2>> {
		using type = BinIntFalse<typename And<T1, T2>::type>;
	};

	template<typename T1, typename T2>
	struct And<BinIntTrue<T1>, BinIntTrue<T2>> {
		using type = BinIntTrue<typename And<T1, T2>::type>;
	};

	template<typename T1, typename T2>
	struct And {
		using type = typename And<T2, T1>::type;
	};
}