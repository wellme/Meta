#pragma once

#include "BinInt.cpp"

namespace Meta::BinInt {

	namespace Simplifier {
		template<typename T>
		struct Simplifier;

		template<template <typename> typename T>
		struct Simplifier<T<T<void>>> {
			using type = T<void>;
		};

		template<typename T>
		struct Simplifier {
			using type = T;
		};
	}

	template<typename T>
	struct Simplify;

	template<>
	struct Simplify<void> {
		using type = void;
	};

	template<template <typename> typename BinInt, typename T>
	struct Simplify<BinInt<T>> {
		using type = typename Simplifier::Simplifier<BinInt<typename Simplify<T>::type>>::type;
	};

}
