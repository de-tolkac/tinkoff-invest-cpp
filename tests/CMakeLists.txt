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

add_executable(operation_json_test "")
target_sources(operation_json_test PRIVATE operation_json_test.cpp ../src/Operation.cpp ../src/OperationTrade.cpp ../src/MoneyAmount.cpp ../src/utils.cpp)
target_link_libraries(operation_json_test PRIVATE gtest_main)

add_executable(operation_trade_json_test "")
target_sources(operation_trade_json_test PRIVATE operation_trade_json_test.cpp ../src/OperationTrade.cpp ../src/utils.cpp)
target_link_libraries(operation_trade_json_test PRIVATE gtest_main)

add_executable(order_json_test "")
target_sources(order_json_test PRIVATE order_json_test.cpp ../src/Order.cpp ../src/utils.cpp)
target_link_libraries(order_json_test PRIVATE gtest_main)

add_executable(order_response_json_test "")
target_sources(order_response_json_test PRIVATE order_response_json_test.cpp ../src/OrderResponse.cpp)
target_link_libraries(order_response_json_test PRIVATE gtest_main)

add_executable(order_book_json_test "")
target_sources(order_book_json_test PRIVATE order_book_json_test.cpp ../src/OrderBook.cpp ../src/utils.cpp ../src/OrderResponse.cpp)
target_link_libraries(order_book_json_test PRIVATE gtest_main)

add_executable(placed_limit_order_json_test "")
target_sources(placed_limit_order_json_test PRIVATE placed_limit_order_json_test.cpp ../src/PlacedLimitOrder.cpp ../src/utils.cpp ../src/MoneyAmount.cpp)
target_link_libraries(placed_limit_order_json_test PRIVATE gtest_main)

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

add_test(
  	NAME operation_json_test
  	COMMAND $<TARGET_FILE:operation_json_test>
)

add_test(
  	NAME operation_trade_json_test
  	COMMAND $<TARGET_FILE:operation_trade_json_test>
)

add_test(
  	NAME order_json_test
  	COMMAND $<TARGET_FILE:order_json_test>
)

add_test(
  	NAME order_response_json_test
  	COMMAND $<TARGET_FILE:order_response_json_test>
)

add_test(
  	NAME order_book_json_test
  	COMMAND $<TARGET_FILE:order_book_json_test>
)

add_test(
  	NAME placed_limit_order_json_test
  	COMMAND $<TARGET_FILE:placed_limit_order_json_test>
)