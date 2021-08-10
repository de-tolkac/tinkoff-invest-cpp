#include <RestProvider.h>
#include <UrlLib.h>

// Orders
std::pair<std::vector<Order>, Error> RestProvider::Orders(const char* url, std::string& id) {
}

std::pair<PlacedLimitOrder, Error> RestProvider::LimitOrder(const char* url, std::string& id, std::string& figi, int lots, OperationType operation, double price) {

}

std::pair<PlacedMarketOrder, Error> RestProvider::MarketOrder(const char* url, std::string& id, std::string& figi, int lots, OperationType operation) {
}

Error RestProvider::OrderCancel(const char* url, std::string& id, std::string& orderId) {
}


// Portfolio
std::pair<PortfolioInfo, Error> RestProvider::Portfolio(const char* url1, const char* url2, std::string& id) {
}

std::pair<std::vector<PortfolioPosition>, Error> RestProvider::PortfolioPositions(const char* url, std::string& id) {
}

std::pair<std::vector<CurrencyPosition>, Error> RestProvider::PortfolioCurrencies(const char* url, std::string& id) {
}


// Market
std::pair<std::vector<MarketInstrument>, Error> RestProvider::Stocks(const char* url) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::Bonds(const char* url) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::ETFs(const char* url) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::Currencies(const char* url) {
}

std::pair<OrderBook, Error> RestProvider::Orderbook(const char* url, std::string& figi, int depth) {
}

std::pair<std::vector<Candle>, Error> RestProvider::Candles(const char* url, std::string& figi, time_t& from, time_t& to, CandleInterval& interval) {
}

std::pair<SearchMarketInstrument, Error> RestProvider::GetIntsrumentByFIGI(const char* url, std::string& figi) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::GetInstrumentByTicker(const char* url, std::string& ticker) {
}


// Operations
std::pair<std::vector<Operation>, Error> RestProvider::Operations(const char* url, std::string& id, std::string& figi, time_t& from, time_t& to) {
}


// User
std::pair<std::vector<UserAccount>, Error> RestProvider::Accounts(const char* url) {
}