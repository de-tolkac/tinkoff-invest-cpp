#include <MarketInstrument.h>

#include <utils.h>

void to_json(Json& j, const MarketInstrument& instr) {
    j = Json {
                {"figi", instr.figi},
                {"ticker", instr.ticker},
                {"isin", instr.isin},
                {"minPriceIncrement", std::to_string(instr.minPriceIncrement)},
                {"lot", std::to_string(instr.lot)},
                {"minQuantity", std::to_string(instr.minQuantity)},
                {"currency", toString(instr.currency)},
                {"name", instr.name},
                {"type", toString(instr.type)}
             };
}

void from_json(const Json& j, MarketInstrument& instr) {
    try {
        j.at("figi").get_to(instr.figi);
        j.at("ticker").get_to(instr.ticker);
        j.at("isin").get_to(instr.isin);
        j.at("name").get_to(instr.name);
        j.at("minPriceIncrement").get_to(instr.minPriceIncrement);
        j.at("lot").get_to(instr.lot);
        j.at("minQuantity").get_to(instr.minQuantity);

        instr.currency = toCurrency(j.at("currency"));
        instr.type = toInstrumentType(j.at("type"));
    }
    catch(std::string error) {
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