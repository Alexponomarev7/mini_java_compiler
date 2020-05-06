//
// Created by Alexey A. Ponomarev on 06.05.2020.
//

#ifndef COMPILER_LOCATION_H
#define COMPILER_LOCATION_H


#include <parser/location.hh>

class Location {
public:
    static Location* GetInstance();

    yy::location GetLocation() const;

    yy::location SetLocation(yy::location loc);

private:
    Location() = default;

    static Location* state_;
    yy::location loc_;
};


#endif //COMPILER_LOCATION_H
