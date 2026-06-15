//
// Created by Maria on 14/06/2026.
//

#include "department.h"
#include <sstream>

Department::Department(const std::string &name, const std::string &description):name{name},description{description} {
}

std::string Department::getName() const {
    return name;
}

std::string Department::getDescription() const {
    return description;
}

int Department::getDescriptionNrOfWords() const {
    std::stringstream ss(description);
    std::string word;
    int count=0;
    while (ss>>word) {
        count++;
    }
    return count;
}
