#include <Candle.h>

#include <utils.h>

#include <ctime>


using Json = nlohmann::json;

namespace ti {

void to_json(Json& j, const Candle& candle) {
    j = Json {
                {"figi", candle.figi},
                {"interval", to_string(candle.interval)},
                {"o", candle.openPrice},
                {"c", candle.closePrice},
                {"h", candle.highPrice},
                {"l", candle.lowPrice},
                {"v", candle.volume},
                {"time", toString(candle.time)}
             };
}

void from_json(const Json& j, Candle& candle) {
    try {
        j.at("figi").get_to(candle.figi);
        candle.interval = toCandleInterval(j.at("interval"));
        j.at("o").get_to(candle.openPrice);
        j.at("c").get_to(candle.closePrice);
        j.at("h").get_to(candle.highPrice);
        j.at("l").get_to(candle.lowPrice);
        j.at("v").get_to(candle.volume);

        candle.time = toDate(j.at("time"));
    }
    catch(std::string& error) {
        throw error;   
    }
    catch(...) {        
        std::string message = "Impossible to parse JSON to Candle structure";
        throw message;
    }
}


bool operator==(const Candle& lhs, const Candle& rhs) {
    return  lhs.figi == rhs.figi && lhs.interval == rhs.interval &&
            lhs.openPrice == rhs.openPrice && lhs.closePrice == rhs.closePrice &&
            lhs.highPrice == rhs.highPrice && lhs.lowPrice == rhs.lowPrice &&
            lhs.volume == rhs.volume && lhs.time == rhs.time;
}

}