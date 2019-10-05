#pragma once

#include "BinInt.cpp"

namespace Meta::BinInt {

	template<typename T1, typename T2>
	struct Lengthen;

	template<template <typename> typename T1, template <typename> typename T2>
	struct Lengthen<T1<void>, T2<void>> {
		using type1 = T1<void>;
		using type2 = T2<void>;
	};

	template<typename T, template <typename T> typename T1, template <typename> typename T2>
	struct Lengthen<T1<void>, T2<T>> {
		using lengthener = Lengthen<T1<void>, T>;
		using type1 = T1<typename lengthener::type1>;
		using type2 = T2<typename lengthener::type2>;
	};

	template<typename T, template <typename T> typename T1, template <typename> typename T2>
	struct Lengthen<T1<T>, T2<void>>  {
		using lengthener = Lengthen<T, T2<void>>;
		using type1 = T1<typename lengthener::type1>;
		using type2 = T2<typename lengthener::type2>;
	};

	template<typename T1Arg, typename T2Arg, template <typename T1Arg> typename T1, template <typename T2Arg> typename T2>
	struct Lengthen<T1<T1Arg>, T2<T2Arg>> {
		using lengthener = Lengthen<T1Arg, T2Arg>;
		using type1 = T1<typename lengthener::type1>;
		using type2 = T2<typename lengthener::type2>;
	};
}