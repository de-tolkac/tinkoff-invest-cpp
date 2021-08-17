#include <MarketInstrument.h>

#include <utils.h>

void to_json(Json& j, const MarketInstrument& instr) {
    j = Json {
                {"figi", instr.figi},
                {"ticker", instr.ticker},
                {"lot", std::to_string(instr.lot)},
                {"name", instr.name},
                {"type", toString(instr.type)}
             };

    if (instr.isin) {
        j.push_back({"isin", *instr.isin});
    }

    if (instr.minPriceIncrement) {
        j.push_back({"minPriceIncrement", *instr.minPriceIncrement});
    }

    if (instr.minQuantity) {
        j.push_back({"minQuantity", *instr.minQuantity});
    }

    if (instr.currency) {
        j.push_back({"minQuantity", toString(*instr.currency)});
    }
}

void from_json(const Json& j, MarketInstrument& instr) {
    try {
        j.at("figi").get_to(instr.figi);
        j.at("ticker").get_to(instr.ticker);
        j.at("name").get_to(instr.name);
        j.at("lot").get_to(instr.lot);

        instr.type = toInstrumentType(j.at("type"));

        if (j.contains("isin")) {
            instr.isin = j["isin"];
        }

        if (j.contains("minPriceIncrement")) {
            instr.minPriceIncrement = j["minPriceIncrement"].get<double>();
        }

        if (j.contains("minQuantity")) {
            instr.minQuantity = j["minQuantity"].get<int>();
        }

        if (j.contains("currency")) {
            instr.currency = toCurrency(j.at("currency"));
        }
    }
    catch(std::string& error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to MarketInstrument structure";
        throw message;
    }
}

bool operator==(const MarketInstrument& lhs, const MarketInstrument& rhs) {
    return  lhs.figi == rhs.figi && lhs.ticker == rhs.ticker && 
            lhs.isin == rhs.isin && lhs.name == rhs.name &&
            lhs.minPriceIncrement == rhs.minPriceIncrement &&
            lhs.lot == rhs.lot && lhs.minQuantity == rhs.minQuantity &&
            lhs.currency == rhs.currency && lhs.type == rhs.type;
}