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

std::pair<SandboxAccount, Error> SandboxRestClient::Register(BrokerAccountType t) const {
    std::pair<SandboxAccount, Error> result;

    cpr::Response response = cpr::Post(cpr::Url{URL::Sandbox::Register},
                               cpr::Body{"{\"brokerAccountType\": \"" + toString(t) + "\"}"},
                               cpr::Bearer{token},
                               cpr::VerifySsl{false});
    
    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);
            
            result.first = json.at("payload").get<SandboxAccount>();
            result.second.code = "Ok";
        }
        catch(std::string& error) {
            result.second.message = error;
            result.second.code = "Error";
        }
        catch(...) {
            result.second.message = "Invalid Response";
            result.second.code = "Error";
        }
        
        return result;
    } else if (response.status_code == 500) {
        try {
            Json json = Json::parse(response.text);
            
            result.second.message = json.at("payload").at("message");
            result.second.code = json.at("payload").at("code");
        }
        catch(std::string& error) {
            result.second.message = error;
            result.second.code = "Error";
        }
        catch(...) {
            result.second.message = "Invalid Response";
            result.second.code = "Error";
        }

        return result;
    } 

    result.second.message = "Invalid Response";
    result.second.code = "Error";

    return result;
}

Error SandboxRestClient::SetCurrencyBalance(std::string id, Currency cur, double val) const {
    Error result;

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
        try {
            Json json = Json::parse(response.text);

            result.message = json.at("payload").at("message");
            result.code = json.at("payload").at("code");
        }
        catch(std::string& error) {
            result.message = error;
            result.code = "Error";
        }
        catch(...) {
            result.message = "Invalid Response";
            result.code = "Error";
        }
        
        return result;
    } else if (response.status_code != 200) {
        result.code = "Error";
        result.message = "Invalid Response";
        
        return result;
    }
    
    result.code = "Ok";

    return result;
}

Error SandboxRestClient::SetPositionsBalance(std::string id, std::string figi, double val) const {
    Error result;

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
        try {
            Json json = Json::parse(response.text);

            result.message = json.at("payload").at("message");
            result.code = json.at("payload").at("code");
        }
        catch(std::string& error) {
            result.message = error;
            result.code = "Error";
        }
        catch(...) {
            result.message = "Invalid Response";
            result.code = "Error";
        }

        return result;
    } else if (response.status_code != 200) {
        result.code = "Error";
        result.message = "Invalid Response";
        
        return result;
    }

    result.code = "Ok";

    return result;
}

Error SandboxRestClient::Remove(std::string id) const {
    Error result;

    std::string url = URL::Sandbox::Remove;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Post(cpr::Url{url},
                                        cpr::Bearer{token},
                                        cpr::VerifySsl{false});

    if (response.status_code == 500) {
        try {
            Json json = Json::parse(response.text);

            result.message = json.at("payload").at("message");
            result.code = json.at("payload").at("code");
        }
        catch(std::string& error) {
            result.message = error;
            result.code = "Error";
        }
        catch(...) {
            result.message = "Invalid Response";
            result.code = "Error";
        }

        return result;
    } else if (response.status_code != 200) {
        result.code = "Error";
        result.message = "Invalid Response";
        
        return result;
    }

    result.code = "Ok";

    return result;
}

Error SandboxRestClient::Clear(std::string id) const {
    Error result;

    std::string url = URL::Sandbox::Clear;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Post(cpr::Url{url},
                                        cpr::Bearer{token},
                                        cpr::VerifySsl{false});

    if (response.status_code == 500) {
        try {
            Json json = Json::parse(response.text);

            result.message = json.at("payload").at("message");
            result.code = json.at("payload").at("code");
        }
        catch(std::string& error) {
            result.message = error;
            result.code = "Error";
        }
        catch(...) {
            result.message = "Invalid Response";
            result.code = "Error";
        }

        return result;
    } else if (response.status_code != 200) {
        result.code = "Error";
        result.message = "Invalid Response";
        
        return result;
    }

    result.code = "Ok";

    return result;
}

// Orders
std::pair<OrderList, Error> SandboxRestClient::Orders(std::string id) const {
    return RestProvider::Orders(URL::Sandbox::Orders, id);
}

std::pair<PlacedOrder, Error> SandboxRestClient::LimitOrder(std::string id, std::string figi, int lots, OperationType operation, double price) const {
    return RestProvider::LimitOrder(URL::Sandbox::OrdersLimitOrder, id, figi, lots, operation, price);
}

std::pair<PlacedOrder, Error> SandboxRestClient::MarketOrder(std::string id, std::string figi, int lots, OperationType operation) const {
    return RestProvider::MarketOrder(URL::Sandbox::OrdersMarketOrder, id, figi, lots, operation);
}

Error SandboxRestClient::OrderCancel(std::string id, std::string orderId) const {
    return RestProvider::OrderCancel(URL::Sandbox::OrdersCancel, id, orderId);
}

// Portfolio
std::pair<PortfolioInfo, Error> SandboxRestClient::Portfolio(std::string id) const {
    return RestProvider::Portfolio(URL::Sandbox::Portfolio, URL::Sandbox::PortfolioCurrencies, id);
}

std::pair<PortfolioPositionList, Error> SandboxRestClient::PortfolioPositions(std::string id) const {
    return RestProvider::PortfolioPositions(URL::Sandbox::Portfolio, id);
}

std::pair<CurrencyPositionList, Error> SandboxRestClient::PortfolioCurrencies(std::string id) const {
    return RestProvider::PortfolioCurrencies(URL::Sandbox::PortfolioCurrencies, id);
}

// Market
std::pair<MarketInstrumentList, Error> SandboxRestClient::Stocks() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketStocks);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::Bonds() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketBonds);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::ETFs() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketETFs);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::Currencies() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketCurrencies);
}

std::pair<OrderBook, Error> SandboxRestClient::Orderbook(std::string figi, int depth) const {
    return RestProvider::Orderbook(URL::Sandbox::MarketOrderbook, figi, depth);
}

std::pair<CandleList, Error> SandboxRestClient::Candles(std::string figi, time_t& from, time_t& to, CandleInterval interval) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from_str, to_str, interval);
}

std::pair<CandleList, Error> SandboxRestClient::Candles(std::string figi, std::string from, std::string to, CandleInterval interval) const {
    return RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from, to, interval);
}

std::pair<SearchMarketInstrument, Error> SandboxRestClient::GetIntsrumentByFIGI(std::string figi) const {
    return RestProvider::GetIntsrumentByFIGI(URL::Sandbox::MarketSearchByFigi, figi);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::GetInstrumentByTicker(std::string ticker) const {
    return RestProvider::GetInstrumentByTicker(URL::Sandbox::MarketSearchByTicker, ticker);
}

// Operations
std::pair<OperationList, Error> SandboxRestClient::Operations(std::string id, std::string figi, time_t from, time_t to) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Operations(URL::Sandbox::Operations, id, figi, from_str, to_str);
}

std::pair<OperationList, Error> SandboxRestClient::Operations(std::string id, std::string figi, std::string from, std::string to) const {
    return RestProvider::Operations(URL::Sandbox::Operations, id, figi, from, to);
}

// User
std::pair<UserAccountList, Error> SandboxRestClient::Accounts() const {
    return RestProvider::Accounts(URL::Sandbox::UserAccounts);
}