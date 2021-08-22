#include <RestProvider.h>
#include <UrlLib.h>
#include <utils.h>

#include <nlohmann/json.hpp>
#include <cpr/cpr.h> 

#include <string>
#include <iostream>

using Json = nlohmann::json;

RestProvider::RestProvider(char* _token)
    : token(_token)
{}

RestProvider::RestProvider(std::string& _token)
    : token(_token)
{}

template<typename T>
void RestProvider::handleStatusCode500(std::pair<T, Error>& result, std::string& response) const {
    try {
        Json json = Json::parse(response);
        
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
}

void RestProvider::handleStatusCode500(Error& result, std::string& response) const {
    try {
        Json json = Json::parse(response);
        
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
}

// Orders
std::pair<std::vector<Order>, Error> RestProvider::Orders(const char* _url, std::string& id) const {
    std::pair<std::vector<Order>, Error> result;

    std::string url = _url;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Get(cpr::Url{url},
                                      cpr::Bearer{token},
                                      cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);

            result.first = json.at("payload").get<std::vector<Order>>();
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
        handleStatusCode500(result, response.text);

        return result;
    }

    result.second.message = "Invalid Response";
    result.second.code = "Error";

    return result;
}

std::pair<PlacedOrder, Error> RestProvider::LimitOrder(const char* _url, std::string& id, std::string& figi, int lots, OperationType operation, double price) const {
    std::pair<PlacedOrder, Error> result;

    std::string url = _url;
    url += "?figi=";
    url += figi;
    if (id.length()) {
        url += "&brokerAccountId=";
        url += id;
    }

    std::string body = "{\"lots\": ";
    body += std::to_string(lots);
    body += ", \"operation\": \"";
    body += toString(operation);
    body += "\", \"price\": ";
    body += std::to_string(price);
    body += "}";

    cpr::Response response = cpr::Post(cpr::Url{url},
                                      cpr::Body{body},
                                      cpr::Bearer{token},
                                      cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);

            result.first = json.at("payload").get<PlacedOrder>();
            result.second.code = "Ok";
        }
        catch(std::string& error) {
            result.second.message = error;
            result.second.code = "Error";
        }
        catch(...) {
            result.second.message = "Invalid Response. It is impossible to parse JSON";
            result.second.code = "Error";
        }

        return result;
    } else if (response.status_code == 500) {
        handleStatusCode500(result, response.text);
        
        return result;
    }

    result.second.message = "Invalid response";
    result.second.code = "Error";

    return result;
}

std::pair<PlacedOrder, Error> RestProvider::MarketOrder(const char* _url, std::string& id, std::string& figi, int lots, OperationType operation) const {
    std::pair<PlacedOrder, Error> result;

    std::string url = _url;
    url += "?figi=";
    url += figi;
    if (id.length()) {
        url += "&brokerAccountId=";
        url += id;
    }

    std::string body = "{\"lots\": ";
    body += std::to_string(lots);
    body += ", \"operation\": \"";
    body += toString(operation);
    body += "\"}";

    cpr::Response response = cpr::Post(cpr::Url{url},
                                      cpr::Body{body},
                                      cpr::Bearer{token},
                                      cpr::VerifySsl{false});

    
    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);

            result.first = json.at("payload").get<PlacedOrder>();
            result.second.code = "Ok";
        }
        catch(std::string& error) {
            result.second.message = error;
            result.second.code = "Error";
        }
        catch(...) {
            result.second.message = "Invalid Response. It is impossible to parse JSON";
            result.second.code = "Error";
        }

        return result;
    } else if (response.status_code == 500) {
        handleStatusCode500(result, response.text);
        
        return result;
    }

    result.second.message = "Invalid response";
    result.second.code = "Error";

    return result;
}

Error RestProvider::OrderCancel(const char* _url, std::string& id, std::string& orderId) const {
    Error result;

    std::string url = _url;
    url += "?orderId=";
    url += orderId;
    if (id.length()) {
        url += "&brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Post(cpr::Url{url},
                                      cpr::Bearer{token},
                                      cpr::VerifySsl{false});

    if (response.status_code == 200) {
        result.code = "Ok";

        return result;
    } else if (response.status_code == 500) {
        handleStatusCode500(result, response.text);
        
        return result;
    }

    result.message = "Invalid response";
    result.code = "Error";

    return result;
}


// Portfolio
std::pair<PortfolioInfo, Error> RestProvider::Portfolio(const char* url1, const char* url2, std::string& id) const {
    std::pair<PortfolioInfo, Error> result;

    auto [positions, err1] = RestProvider::PortfolioPositions(url1, id);
    if (err1) {
        result.second = err1;

        return result;
    }

    auto [currencies, err2] = RestProvider::PortfolioCurrencies(url2, id);
    if (err2) {
        result.second = err2;

        return result;
    }

    result.first.positions = positions;
    result.first.currencies = currencies;
    result.second.code = "Ok";

    return result;
}

std::pair<std::vector<PortfolioPosition>, Error> RestProvider::PortfolioPositions(const char* _url, std::string& id) const {
    std::pair<std::vector<PortfolioPosition>, Error> result;

    std::string url = _url;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Get(cpr::Url{url},
                                      cpr::Bearer{token},
                                      cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);

            result.first = json.at("payload").at("positions").get<std::vector<PortfolioPosition>>();
            result.second.code = "Ok";
        }
        catch(std::string& error) {
            result.second.message = error;
            result.second.code = "Error";
        }
        catch(...) {
            result.second.message = "Invalid Response. It is impossible to parse JSON";
            result.second.code = "Error";
        }

        return result;
    } else if (response.status_code == 500) {
        handleStatusCode500(result, response.text);
        
        return result;
    }

    result.second.message = "Invalid response";
    result.second.code = "Error";

    return result;
}

std::pair<std::vector<CurrencyPosition>, Error> RestProvider::PortfolioCurrencies(const char* _url, std::string& id) const {
    std::pair<std::vector<CurrencyPosition>, Error> result;

    std::string url = _url;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Get(cpr::Url{url},
                                      cpr::Bearer{token},
                                      cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);

            result.first = json.at("payload").at("currencies").get<std::vector<CurrencyPosition>>();
            result.second.code = "Ok";
        }
        catch(std::string& error) {
            result.second.message = error;
            result.second.code = "Error";
        }
        catch(...) {
            result.second.message = "Invalid Response. It is impossible to parse JSON";
            result.second.code = "Error";
        }

        return result;
    } else if (response.status_code == 500) {
        handleStatusCode500(result, response.text);
        
        return result;
    }

    result.second.message = "Invalid response";
    result.second.code = "Error";

    return result;
}


// Market
std::pair<std::vector<MarketInstrument>, Error> RestProvider::Stocks(const char* url) const {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::Bonds(const char* url) const {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::ETFs(const char* url) const {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::Currencies(const char* url) const {
}

std::pair<OrderBook, Error> RestProvider::Orderbook(const char* url, std::string& figi, int depth) const {
}

std::pair<std::vector<Candle>, Error> RestProvider::Candles(const char* url, std::string& figi, time_t& from, time_t& to, CandleInterval& interval) const {
}

std::pair<SearchMarketInstrument, Error> RestProvider::GetIntsrumentByFIGI(const char* url, std::string& figi) const {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::GetInstrumentByTicker(const char* url, std::string& ticker) const {
}


// Operations
std::pair<std::vector<Operation>, Error> RestProvider::Operations(const char* url, std::string& id, std::string& figi, time_t& from, time_t& to) const {
}


// User
std::pair<std::vector<UserAccount>, Error> RestProvider::Accounts(const char* url) const {
}