#include <PortfolioPosition.h>

#include <utils.h>

void to_json(Json& j, const PortfolioPosition& position) {
    j = Json {
                {"figi", position.figi},
                {"ticker", position.ticker},
                {"name", position.name},
                {"instrumentType", toString(position.instrumentType)},
                {"balance", std::to_string(position.balance)},
                {"lots", std::to_string(position.lots)}
            };

    if (position.isin) {
        j.push_back(*position.isin);
    }

    if (position.blocked) {
        j.push_back(std::to_string(*position.blocked));
    }

    if (position.expectedYield) {
        j.push_back(*position.expectedYield);
    }

    if (position.averagePositionPrice) {
        j.push_back(*position.averagePositionPrice);
    }

    if (position.averagePositionPriceNoNkd) {
        j.push_back(*position.averagePositionPriceNoNkd);
    }
}

void from_json(const Json& j, PortfolioPosition& position) {
    try {
        j.at("figi").get_to(position.figi);
        j.at("ticker").get_to(position.ticker);
        j.at("name").get_to(position.name);
        position.instrumentType = toInstrumentType(j.at("instrumentType"));
        j.at("balance").get_to(position.balance);
        j.at("lots").get_to(position.lots);

        if (j.contains("isin")) {
            position.isin = j["isin"].get<std::string>();
        }

        if (j.contains("blocked")) {
            position.blocked = j["blocked"].get<double>();
        }

        if (j.contains("expectedYield")) {
            position.expectedYield = j["expectedYield"].get<MoneyAmount>();
        }

        if (j.contains("averagePositionPrice")) {
            position.averagePositionPrice = j["averagePositionPrice"].get<MoneyAmount>();
        }

        if (j.contains("averagePositionPriceNoNkd")) {
            position.averagePositionPriceNoNkd = j["averagePositionPriceNoNkd"].get<MoneyAmount>();
        }

    }
    catch(std::string error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to PortfolioPosition structure";
        throw message;
    }
}

bool operator==(const PortfolioPosition& lhs, const PortfolioPosition& rhs) {
    return  lhs.figi == rhs.figi && lhs.ticker == rhs.ticker && lhs.name == rhs.name &&
            lhs.instrumentType == rhs.instrumentType && lhs.balance == rhs.balance &&
            lhs.lots == rhs.lots && lhs.isin == rhs.isin && lhs.blocked == rhs.blocked &&
            lhs.expectedYield == rhs.expectedYield && lhs.averagePositionPrice == rhs.averagePositionPrice &&
            lhs.averagePositionPriceNoNkd == rhs.averagePositionPriceNoNkd;
}