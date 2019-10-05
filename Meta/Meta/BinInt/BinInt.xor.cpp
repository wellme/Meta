#pragma once

#include "BinInt.cpp"
#include "BinInt.not.cpp"
#include "BinInt.lengthen.cpp"

namespace Meta::BinInt {

	namespace XorInternals {

		template<typename T1, typename T2>
		struct Xor;

		template<>
		struct Xor<void, void> {
			using type = void;
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

	template<typename T1, typename T2>
	struct Xor {
		using lengthener = Lengthen<T1, T2>;
		using type = typename XorInternals::Xor<typename lengthener::type1, typename lengthener::type2>::type;
	};

}