#pragma once

#include "BinInt.cpp"

namespace Meta::BinInt {

	namespace Shifter {

		template<typename T>
		struct TrimLast;

		template<template<typename> typename T>
		struct TrimLast<T<void>> {
			using type = void;
		};

		template<typename TArg, template<typename TArg> typename T>
		struct TrimLast<T<TArg>> {
			using type = T<typename TrimLast<TArg>::type>;
		};

	}

	template<typename T1>
	struct ShiftLeftOne {
		using type = BinIntFalse<typename Shifter::TrimLast<T1>::type>;
	};
}