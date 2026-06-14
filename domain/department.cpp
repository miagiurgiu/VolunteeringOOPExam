//
// Created by Maria on 14/06/2026.
//

#include "department.h"

Department::Department(const std::string &name, const std::string &description):name{name},description{description} {
}

std::string Department::getName() const {
    return name;
}

std::string Department::getDescription() const {
    return description;
}
