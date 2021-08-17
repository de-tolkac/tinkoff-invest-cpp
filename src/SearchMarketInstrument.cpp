#include <SearchMarketInstrument.h>

#include <utils.h>
#include <iostream>

void to_json(Json& j, const SearchMarketInstrument& instrument) {
    j = Json {
                {"figi", instrument.figi},
                {"ticker", instrument.ticker},
                {"name", instrument.name},
                {"lot", std::to_string(instrument.lot)},
                {"type", toString(instrument.type)}
             };

    if (instrument.isin) {
        j.push_back({"isin", *instrument.isin});
    }

    if (instrument.minPriceIncrement) {
        j.push_back({"minPriceIncrement", std::to_string(*instrument.minPriceIncrement)});
    }

    if (instrument.currency) {
        j.push_back({"currency", toString(*instrument.currency)});
    }
}

void from_json(const Json& j, SearchMarketInstrument& instrument) {
    try {
        j.at("figi").get_to(instrument.figi);
        j.at("ticker").get_to(instrument.ticker);
        j.at("name").get_to(instrument.name);
        j.at("lot").get_to(instrument.lot);
        
        instrument.type = toInstrumentType(j.at("type"));
        
        if (j.contains("isin")) {
            instrument.isin = j["isin"].get<std::string>();
        }
        
        if (j.contains("minPriceIncrement")) {
            instrument.minPriceIncrement = j["minPriceIncrement"].get<double>();
        }
        
        if (j.contains("currency")) {
            instrument.currency = toCurrency(j["currency"]);
        }
    }
    catch(std::string error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to SearchMarketInstrument structure";
        throw message;
    }
}

bool operator==(const SearchMarketInstrument& lhs, const SearchMarketInstrument& rhs) {
    return  lhs.figi == rhs.figi && lhs.ticker == rhs.ticker && lhs.name == rhs.name &&
            lhs.lot == rhs.lot && lhs.type == rhs.type && lhs.isin == rhs.isin &&
            lhs.minPriceIncrement == rhs.minPriceIncrement && lhs.currency == rhs.currency;
}