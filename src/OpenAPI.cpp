#include <tinvest/OpenAPI.h>
#include <UrlLib.h>
#include <utils.h>

#include <nlohmann/json.hpp>
#include <cpr/cpr.h> 

#include <string>

using Json = nlohmann::json;

SandboxRestClient::SandboxRestClient(char* _token) 
    : token(_token)
{}

SandboxRestClient::SandboxRestClient(std::string& _token) 
    : token(_token)
{}

SandboxRestClient::~SandboxRestClient() { }

std::tuple<SandboxAccount, Error> SandboxRestClient::Register(BrokerAccountType t) {
    cpr::Response response = cpr::Post(cpr::Url{URL::Sandbox::Register},
                               cpr::Body{"{\"brokerAccountType\": \"" + toString(t) + "\"}"},
                               cpr::Bearer{token},
                               cpr::VerifySsl{false});
    
    Json json = Json::parse(response.text);
    
    if (response.status_code == 200) {
        return  {
                    SandboxAccount(toBrokerAccountType(json["payload"]["brokerAccountType"].get<std::string>()), 
                                    json["payload"]["brokerAccountId"].get<std::string>()), 
                    {"", "Ok"}
                };
    } else if (response.status_code == 500) {
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

    Json json = Json::parse(response.text);
    if (response.status_code == 500) {
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

    Json json = Json::parse(response.text);
    if (response.status_code == 500) {
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

    Json json = Json::parse(response.text);
    if (response.status_code == 500) {
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

    Json json = Json::parse(response.text);
    if (response.status_code == 500) {
        return {json["payload"]["message"], json["payload"]["code"]};
    } else if (response.status_code != 200) {
        return {"Invalid Response", "Error"};
    }
    return {"", "Ok"};
}