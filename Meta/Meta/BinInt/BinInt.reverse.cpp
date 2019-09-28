#pragma once

#include "BinInt.cpp"

namespace Meta::BinInt {

	namespace Reverser {
		template<typename T1, typename T2>
		struct Reverser;

		template<typename T2>
		struct Reverser<void, T2> {
			using type = T2;
		};

		template<typename T, template<typename> typename T1, typename T2>
		struct Reverser<T1<T>, T2> {
			using type = typename Reverser<T, T1<T2>>::type;
		};
	}

	template<typename T>
	struct Reverse {
		using type = typename Reverser::Reverser<T, void>::type;
	};
}