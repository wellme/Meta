
#pragma once


namespace Meta::BinInt {

	template<typename T>
	struct BinIntTrue;

	template<typename T>
	struct BinIntFalse;

	template<>
	struct BinIntTrue<void> {
		static constexpr int value = -1;
	};

	template<>
	struct BinIntFalse<void> {
		static constexpr int value = 0;
	};

	template<typename T>
	struct BinIntTrue {
		static constexpr int value = 1 | (T::value << 1);
	};

	template<typename T>
	struct BinIntFalse {
		static constexpr int value = T::value << 1;
	};

	using False = BinIntFalse<void>;
	using Zero = False;

	using True = BinIntTrue<BinIntFalse<void>>;
	using One = True;

}