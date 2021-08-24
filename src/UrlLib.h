#pragma once

namespace ti {

namespace URL {
    namespace Sandbox {
        // Sandbox
        constexpr char Register[]             = "https://api-invest.tinkoff.ru/openapi/sandbox/sandbox/register";
        constexpr char CurrenciesBalance[]    = "https://api-invest.tinkoff.ru/openapi/sandbox/sandbox/currencies/balance";
        constexpr char PositionsBalance[]     = "https://api-invest.tinkoff.ru/openapi/sandbox/sandbox/positions/balance";
        constexpr char Remove[]               = "https://api-invest.tinkoff.ru/openapi/sandbox/sandbox/remove";
        constexpr char Clear[]                = "https://api-invest.tinkoff.ru/openapi/sandbox/sandbox/clear";

        // Orders
        constexpr char Orders[]               = "https://api-invest.tinkoff.ru/openapi/sandbox/orders";
        constexpr char OrdersLimitOrder[]     = "https://api-invest.tinkoff.ru/openapi/sandbox/orders/limit-order";
        constexpr char OrdersMarketOrder[]    = "https://api-invest.tinkoff.ru/openapi/sandbox/orders/market-order";
        constexpr char OrdersCancel[]         = "https://api-invest.tinkoff.ru/openapi/sandbox/orders/cancel";
    
        // Portfolio
        constexpr char Portfolio[]            = "https://api-invest.tinkoff.ru/openapi/sandbox/portfolio";
        constexpr char PortfolioCurrencies[]  = "https://api-invest.tinkoff.ru/openapi/sandbox/portfolio/currencies";

        // Market
        constexpr char MarketStocks[]         = "https://api-invest.tinkoff.ru/openapi/sandbox/market/stocks";
        constexpr char MarketBonds[]          = "https://api-invest.tinkoff.ru/openapi/sandbox/market/bonds";
        constexpr char MarketETFs[]           = "https://api-invest.tinkoff.ru/openapi/sandbox/market/etfs";
        constexpr char MarketCurrencies[]     = "https://api-invest.tinkoff.ru/openapi/sandbox/market/currencies";
        constexpr char MarketOrderbook[]      = "https://api-invest.tinkoff.ru/openapi/sandbox/market/orderbook";
        constexpr char MarketCandles[]        = "https://api-invest.tinkoff.ru/openapi/sandbox/market/candles";
        constexpr char MarketSearchByFigi[]   = "https://api-invest.tinkoff.ru/openapi/sandbox/market/search/by-figi";
        constexpr char MarketSearchByTicker[] = "https://api-invest.tinkoff.ru/openapi/sandbox/market/search/by-ticker";

        // Operations
        constexpr char Operations[]           = "https://api-invest.tinkoff.ru/openapi/sandbox/operations";

        // User
        constexpr char UserAccounts[]         = "https://api-invest.tinkoff.ru/openapi/sandbox/user/accounts";
    }

    namespace Production {
        // Orders
        constexpr char Orders[]               = "https://api-invest.tinkoff.ru/openapi/orders";
        constexpr char OrdersLimitOrder[]     = "https://api-invest.tinkoff.ru/openapi/orders/limit-order";
        constexpr char OrdersMarketOrder[]    = "https://api-invest.tinkoff.ru/openapi/orders/market-order";
        constexpr char OrdersCancel[]         = "https://api-invest.tinkoff.ru/openapi/orders/cancel";
    
        // Portfolio
        constexpr char Portfolio[]            = "https://api-invest.tinkoff.ru/openapi/portfolio";
        constexpr char PortfolioCurrencies[]  = "https://api-invest.tinkoff.ru/openapi/portfolio/currencies";

        // Market
        constexpr char MarketStocks[]         = "https://api-invest.tinkoff.ru/openapi/market/stocks";
        constexpr char MarketBonds[]          = "https://api-invest.tinkoff.ru/openapi/market/bonds";
        constexpr char MarketETFs[]           = "https://api-invest.tinkoff.ru/openapi/market/etfs";
        constexpr char MarketCurrencies[]     = "https://api-invest.tinkoff.ru/openapi/market/currencies";
        constexpr char MarketOrderbook[]      = "https://api-invest.tinkoff.ru/openapi/market/orderbook";
        constexpr char MarketCandles[]        = "https://api-invest.tinkoff.ru/openapi/market/candles";
        constexpr char MarketSearchByFigi[]   = "https://api-invest.tinkoff.ru/openapi/market/search/by-figi";
        constexpr char MarketSearchByTicker[] = "https://api-invest.tinkoff.ru/openapi/market/search/by-ticker";

        // Operations
        constexpr char Operations[]           = "https://api-invest.tinkoff.ru/openapi/operations";

        // User
        constexpr char UserAccounts[]         = "https://api-invest.tinkoff.ru/openapi/user/accounts";
    }
}

}