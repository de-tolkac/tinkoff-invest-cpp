#pragma once

#include <Error.h>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <utility>
#include <iostream>

using Json = nlohmann::json;

template<typename T>
inline std::pair<T, Error> handlePostRequest(const char* url, const char* jsonAt, const std::string& token, std::string& body, cpr::Parameters& params) {
    std::pair<T, Error> result;

    cpr::Response response = cpr::Post(cpr::Url{url},
                                       params,
                                       cpr::Body{body},
                                       cpr::Bearer{token},
                                       cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);

            if (!strlen(jsonAt)) {
                result.first = json.at("payload").get<T>();
                result.second.code = "Ok";
            } else {
                result.first = json.at("payload").at(jsonAt).get<T>();
                result.second.code = "Ok";
            }
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
    }

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

inline Error handlePostRequest(const char* url, const char* jsonAt, const std::string& token, std::string& body, cpr::Parameters& params) {
    Error result;

    cpr::Response response = cpr::Post(cpr::Url{url},
                                       params,
                                       cpr::Body{body},
                                       cpr::Bearer{token},
                                       cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            result.code = "Ok";
        }
        catch(std::string& error) {
            result.message = error;
            result.code = "Error";
        }
        catch(...) {
            result.message = "Invalid Response. It is impossible to parse JSON";
            result.code = "Error";
        }

        return result;
    }

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
}

template<typename T>
inline std::pair<T, Error> handleGetRequest(const char* url, const char* jsonAt, const std::string& token, cpr::Parameters& params) {
    std::pair<T, Error> result;

    cpr::Response response = cpr::Get(cpr::Url{url},
                                       params,
                                       cpr::Bearer{token},
                                       cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            Json json = Json::parse(response.text);

            if (!strlen(jsonAt)) {
                result.first = json.at("payload").get<T>();
                result.second.code = "Ok";
            } else {
                result.first = json.at("payload").at(jsonAt).get<T>();
                result.second.code = "Ok";
            }
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
    }

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