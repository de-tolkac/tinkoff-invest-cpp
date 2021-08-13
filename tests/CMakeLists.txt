cmake_minimum_required(VERSION 3.17)
project(tests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(candle_json_test "")
target_sources(candle_json_test PRIVATE candle_json_test.cpp ../src/Candle.cpp ../src/utils.cpp)
target_link_libraries(candle_json_test PRIVATE gtest_main)


add_executable(currency_position_json_test "")
target_sources(currency_position_json_test PRIVATE currency_position_json_test.cpp ../src/CurrencyPosition.cpp ../src/utils.cpp)
target_link_libraries(currency_position_json_test PRIVATE gtest_main)

add_executable(market_instrument_json_test "")
target_sources(market_instrument_json_test PRIVATE market_instrument_json_test.cpp ../src/MarketInstrument.cpp ../src/utils.cpp)
target_link_libraries(market_instrument_json_test PRIVATE gtest_main)

add_executable(money_amount_json_test "")
target_sources(money_amount_json_test PRIVATE money_amount_json_test.cpp ../src/MoneyAmount.cpp ../src/utils.cpp)
target_link_libraries(money_amount_json_test PRIVATE gtest_main)

enable_testing()

add_test(
  	NAME candle_json_test
  	COMMAND $<TARGET_FILE:candle_json_test>
)

add_test(
  	NAME currency_position_json_test
  	COMMAND $<TARGET_FILE:currency_position_json_test>
)

add_test(
  	NAME market_instrument_json_test
  	COMMAND $<TARGET_FILE:market_instrument_json_test>
)

add_test(
  	NAME money_amount_json_test
  	COMMAND $<TARGET_FILE:money_amount_json_test>
)