#pragma once

#include "BinInt.cpp"
#include "BinInt.xor.cpp"
#include "BinInt.and.cpp"
#include "BinInt.is_null.cpp"
#include "BinInt.shift.cpp"

namespace Meta::BinInt {
	
	namespace AddInternals {

		template<typename T1, typename T2, typename Remaining>
		struct Loop;

		template<typename T1, typename T2>
		struct Loop<T1, T2, void> {
			using type = T1;
		};

		template<typename T1, typename T2, template<typename> typename T3, typename T3Arg>
		struct Loop<T1, T2, T3<T3Arg>> {
			using xor = typename Xor<T1, T2>::type;
			using and = typename And<T1, T2>::type;
			using shifted = typename ShiftLeftOne<and>::type;
			using type = typename Loop<xor, shifted, T3Arg>::type;
		};
	}

	template<typename T1, typename T2>
	struct Add {
		using lengthen = Lengthen<T1, T2>;
		using type = typename AddInternals::Loop<typename lengthen::type1, typename lengthen::type2, typename lengthen::type2>::type;
	};
}