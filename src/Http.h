#pragma once

#include <Error.h>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <utility>

namespace ti {

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
            nlohmann::json json = nlohmann::json::parse(response.text);

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
        nlohmann::json json = nlohmann::json::parse(response.text);
        
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
        nlohmann::json json = nlohmann::json::parse(response.text);
        
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
            nlohmann::json json = nlohmann::json::parse(response.text);

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
        nlohmann::json json = nlohmann::json::parse(response.text);
        
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



template<typename T>
inline void handlePostRequest(T& result, Error& error, const char* url, const char* jsonAt, const std::string& token, std::string& body, cpr::Parameters& params) {
    cpr::Response response = cpr::Post(cpr::Url{url},
                                       params,
                                       cpr::Body{body},
                                       cpr::Bearer{token},
                                       cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            nlohmann::json json = nlohmann::json::parse(response.text);

            if (!strlen(jsonAt)) {
                result = json.at("payload").get<T>();
                error.code = "Ok";
            } else {
                result = json.at("payload").at(jsonAt).get<T>();
                error.code = "Ok";
            }
        }
        catch(std::string& err) {
            error.message = err;
            error.code = "Error";
        }
        catch(...) {
            error.message = "Invalid Response. It is impossible to parse JSON";
            error.code = "Error";
        }

        return;
    }

    try {
        nlohmann::json json = nlohmann::json::parse(response.text);
        
        error.message = json.at("payload").at("message");
        error.code = json.at("payload").at("code");
    }
    catch(std::string& err) {
        error.message = err;
        error.code = "Error";
    }
    catch(...) {
        error.message = "Invalid Response";
        error.code = "Error";
    }
    
    return;
}


inline void handlePostRequest(Error& error, const char* url, const char* jsonAt, const std::string& token, std::string& body, cpr::Parameters& params) {
    cpr::Response response = cpr::Post(cpr::Url{url},
                                       params,
                                       cpr::Body{body},
                                       cpr::Bearer{token},
                                       cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            error.code = "Ok";
        }
        catch(std::string& err) {
            error.message = err;
            error.code = "Error";
        }
        catch(...) {
            error.message = "Invalid Response. It is impossible to parse JSON";
            error.code = "Error";
        }

        return;
    }

    try {
        nlohmann::json json = nlohmann::json::parse(response.text);
        
        error.message = json.at("payload").at("message");
        error.code = json.at("payload").at("code");
    }
    catch(std::string& err) {
        error.message = err;
        error.code = "Error";
    }
    catch(...) {
        error.message = "Invalid Response";
        error.code = "Error";
    }
    
    return;
}

template<typename T>
inline void handleGetRequest(T& result, Error& error, const char* url, const char* jsonAt, const std::string& token, cpr::Parameters& params) {
    cpr::Response response = cpr::Get(cpr::Url{url},
                                       params,
                                       cpr::Bearer{token},
                                       cpr::VerifySsl{false});

    if (response.status_code == 200) {
        try {
            nlohmann::json json = nlohmann::json::parse(response.text);

            if (!strlen(jsonAt)) {
                result = json.at("payload").get<T>();
                error.code = "Ok";
            } else {
                result = json.at("payload").at(jsonAt).get<T>();
                error.code = "Ok";
            }
        }
        catch(std::string& err) {
            error.message = err;
            error.code = "Error";
        }
        catch(...) {
            error.message = "Invalid Response. It is impossible to parse JSON";
            error.code = "Error";
        }

        return;
    }

    try {
        nlohmann::json json = nlohmann::json::parse(response.text);
        
        error.message = json.at("payload").at("message");
        error.code = json.at("payload").at("code");
    }
    catch(std::string& err) {
        error.message = err;
        error.code = "Error";
    }
    catch(...) {
        error.message = "Invalid Response";
        error.code = "Error";
    }
    
    return;
}

}