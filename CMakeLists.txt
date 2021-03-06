cmake_minimum_required(VERSION 3.17)
project(tinvest)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

include_directories(./include ./src)

include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG f4622efcb59d84071ae11404ae61bd821c1c344b)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git GIT_TAG 391786c6c3abdd3eeb993a3154f1f2a4cfe137a0)
FetchContent_MakeAvailable(json)

set(
    SOURCE_FILES
    ./src/SandboxRestClient.cpp
    ./src/utils.cpp
    ./src/RestClient.cpp
    ./src/RestProvider.cpp
    ./src/Order.cpp
    ./src/PlacedOrder.cpp
    ./src/MoneyAmount.cpp
    ./src/Candle.cpp
    ./src/CurrencyPosition.cpp
    ./src/MarketInstrument.cpp
    ./src/Operation.cpp
    ./src/OperationTrade.cpp
    ./src/OrderBook.cpp
    ./src/OrderResponse.cpp
    ./src/PortfolioPosition.cpp
    ./src/SandboxAccount.cpp
    ./src/SearchMarketInstrument.cpp
    ./src/UserAccount.cpp
)

add_library(tinvest SHARED ${SOURCE_FILES})
target_link_libraries(tinvest PRIVATE cpr::cpr PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(./examples)
add_subdirectory(./tests)