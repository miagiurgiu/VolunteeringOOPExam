//
// Created by Maria on 14/06/2026.
//

#include "volunteer.h"

Volunteer::Volunteer(const std::string &name, const std::string &email, const std::vector<std::string> &interests,
    const std::string &department):name{name},email{email},interests{interests},department{department} {
}

std::string Volunteer::getName() const {
    return name;
}

std::string Volunteer::getEmail() const {
    return email;
}

std::vector<std::string> Volunteer::getInterests() const {
    return interests;
}

std::string Volunteer::getDepartment() const {
    return department;
}

void Volunteer::setDepartment(const std::string &department) {
    this->department=department;
}

bool Volunteer::isUnassigned() const {
    return department.empty();
}
