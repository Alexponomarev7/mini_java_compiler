//
// Created by Alexey A. Ponomarev on 06.05.2020.
//

#include "errors.h"
#include "location/location.h"

std::runtime_error runtime_error_location(const std::string& message) {
    auto loc = Location::GetInstance()->GetLocation();

    std::stringstream buffer;
    buffer << "\x1B[36m" <<  loc << ": " << "\033[0m" << message;

    return std::runtime_error(buffer.str());
}
