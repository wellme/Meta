#pragma once

#include "BinInt.cpp"
#include "BinInt.lengthen.cpp"

namespace Meta::BinInt {

	namespace AndInternals {

		template<typename T1, typename T2>
		struct And;

		template<>
		struct And<void, void> {
			using type = void;
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
	}

	template<typename T1, typename T2>
	struct And {
		using lengthener = Lengthen<T1, T2>;
		using type = typename AndInternals::And<typename lengthener::type1, typename lengthener::type2>::type;
	};
}