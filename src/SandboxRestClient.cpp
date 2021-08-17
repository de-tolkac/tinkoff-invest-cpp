#include <SandboxRestClient.h>
#include <UrlLib.h>
#include <utils.h>

#include <nlohmann/json.hpp>
#include <cpr/cpr.h> 

#include <string>

using Json = nlohmann::json;

SandboxRestClient::SandboxRestClient(char* _token) 
    : RestProvider(_token)
    , token(_token)
{}

SandboxRestClient::SandboxRestClient(std::string& _token) 
    : RestProvider(_token)
    , token(_token)
{}

SandboxRestClient::~SandboxRestClient() { }

std::pair<SandboxAccount, Error> SandboxRestClient::Register(BrokerAccountType t) {
    cpr::Response response = cpr::Post(cpr::Url{URL::Sandbox::Register},
                               cpr::Body{"{\"brokerAccountType\": \"" + toString(t) + "\"}"},
                               cpr::Bearer{token},
                               cpr::VerifySsl{false});
    
    if (response.status_code == 200) {
        Json json = Json::parse(response.text);
        return  {
                    SandboxAccount(toBrokerAccountType(json["payload"]["brokerAccountType"].get<std::string>()), 
                                    json["payload"]["brokerAccountId"].get<std::string>()), 
                    {"", "Ok"}
                };
    } else if (response.status_code == 500) {
        Json json = Json::parse(response.text);
        return { SandboxAccount(), {json["payload"]["message"], json["payload"]["code"]} };
    } 

    return {SandboxAccount(), {"Invalid Response", "Error"}};
}

Error SandboxRestClient::SetCurrencyBalance(std::string& id, Currency cur, double val) {
    std::string url = URL::Sandbox::CurrenciesBalance;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    std::string body = "{\"currency\": \"";
    body += toString(cur);
    body += "\", \"balance\": ";
    body += std::to_string(val);
    body += "}";

    cpr::Response response = cpr::Post(cpr::Url{url},
                                        cpr::Body{body},
                                        cpr::Bearer{token},
                                        cpr::VerifySsl{false});

    if (response.status_code == 500) {
        Json json = Json::parse(response.text);
        return {json["payload"]["message"], json["payload"]["code"]};
    } else if (response.status_code != 200) {
        return {"Invalid Response", "Error"};
    }
    return {"", "Ok"};
}

Error SandboxRestClient::SetPositionsBalance(std::string& id, std::string figi, double val) {
    std::string url = URL::Sandbox::PositionsBalance;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    std::string body = "{\"figi\": \"";
    body += figi;
    body += "\", \"balance\": ";
    body += std::to_string(val);
    body += "}";

    cpr::Response response = cpr::Post(cpr::Url{url},
                                        cpr::Body{body},
                                        cpr::Bearer{token},
                                        cpr::VerifySsl{false});

    if (response.status_code == 500) {
        Json json = Json::parse(response.text);
        return {json["payload"]["message"], json["payload"]["code"]};
    } else if (response.status_code != 200) {
        return {"Invalid Response", "Error"};
    }
    return {"", "Ok"};
}

Error SandboxRestClient::Remove(std::string& id) {
    std::string url = URL::Sandbox::Remove;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Post(cpr::Url{url},
                                        cpr::Bearer{token},
                                        cpr::VerifySsl{false});

    if (response.status_code == 500) {
        Json json = Json::parse(response.text);
        return {json["payload"]["message"], json["payload"]["code"]};
    } else if (response.status_code != 200) {
        return {"Invalid Response", "Error"};
    }
    return {"", "Ok"};
}

Error SandboxRestClient::Clear(std::string& id) {
    std::string url = URL::Sandbox::Clear;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Post(cpr::Url{url},
                                        cpr::Bearer{token},
                                        cpr::VerifySsl{false});

    if (response.status_code == 500) {
        Json json = Json::parse(response.text);
        return {json["payload"]["message"], json["payload"]["code"]};
    } else if (response.status_code != 200) {
        return {"Invalid Response", "Error"};
    }
    return {"", "Ok"};
}

// Orders
std::pair<std::vector<Order>, Error> SandboxRestClient::Orders(std::string& id) {
    return RestProvider::Orders(URL::Sandbox::Orders, id);
}

std::pair<PlacedOrder, Error> SandboxRestClient::LimitOrder(std::string id, std::string figi, int lots, OperationType operation, double price) {
    return RestProvider::LimitOrder(URL::Sandbox::OrdersLimitOrder, id, figi, lots, operation, price);
}

std::pair<PlacedOrder, Error> SandboxRestClient::MarketOrder(std::string& id, std::string& figi, int lots, OperationType operation) {
    return RestProvider::MarketOrder(URL::Sandbox::OrdersMarketOrder, id, figi, lots, operation);
}

Error SandboxRestClient::OrderCancel(std::string& id, std::string& orderId) {
    return RestProvider::OrderCancel(URL::Sandbox::OrdersCancel, id, orderId);
}

// Portfolio
std::pair<PortfolioInfo, Error> SandboxRestClient::Portfolio(std::string& id) {
    return RestProvider::Portfolio(URL::Sandbox::Portfolio, URL::Sandbox::PortfolioCurrencies, id);
}

std::pair<std::vector<PortfolioPosition>, Error> SandboxRestClient::PortfolioPositions(std::string& id) {
    return RestProvider::PortfolioPositions(URL::Sandbox::Portfolio, id);
}

std::pair<std::vector<CurrencyPosition>, Error> SandboxRestClient::PortfolioCurrencies(std::string& id) {
    return RestProvider::PortfolioCurrencies(URL::Sandbox::PortfolioCurrencies, id);
}

// Market
std::pair<std::vector<MarketInstrument>, Error> SandboxRestClient::Stocks() {
    return RestProvider::Stocks(URL::Sandbox::MarketStocks);
}

std::pair<std::vector<MarketInstrument>, Error> SandboxRestClient::Bonds() {
    return RestProvider::Bonds(URL::Sandbox::MarketBonds);
}

std::pair<std::vector<MarketInstrument>, Error> SandboxRestClient::ETFs() {
    return RestProvider::ETFs(URL::Sandbox::MarketETFs);
}

std::pair<std::vector<MarketInstrument>, Error> SandboxRestClient::Currencies() {
    return RestProvider::Currencies(URL::Sandbox::MarketCurrencies);
}

std::pair<OrderBook, Error> SandboxRestClient::Orderbook(std::string& figi, int depth) {
    return RestProvider::Orderbook(URL::Sandbox::MarketOrderbook, figi, depth);
}

std::pair<std::vector<Candle>, Error> SandboxRestClient::Candles(std::string& figi, time_t& from, time_t& to, CandleInterval& interval) {
    return RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from, to, interval);
}

std::pair<SearchMarketInstrument, Error> SandboxRestClient::GetIntsrumentByFIGI(std::string& figi) {
    return RestProvider::GetIntsrumentByFIGI(URL::Sandbox::MarketSearchByFigi, figi);
}

std::pair<std::vector<MarketInstrument>, Error> SandboxRestClient::GetInstrumentByTicker(std::string& ticker) {
    return RestProvider::GetInstrumentByTicker(URL::Sandbox::MarketSearchByTicker, ticker);
}

// Operations
std::pair<std::vector<Operation>, Error> SandboxRestClient::Operations(std::string& id, std::string& figi, time_t& from, time_t& to) {
    return RestProvider::Operations(URL::Sandbox::Operations, id, figi, from, to);
}

// User
std::pair<std::vector<UserAccount>, Error> SandboxRestClient::Accounts() {
    return RestProvider::Accounts(URL::Sandbox::UserAccounts);
}