//
// Created by Maria on 14/06/2026.
//

#include "service.h"
#include <algorithm>
Service::Service(Repo &repo):repo{repo} {
}

const std::vector<Department> & Service::getAllDepartments() const {
    return repo.getAllDepartments();
}

const std::vector<Volunteer> & Service::getAllVolunteers() const {
    return repo.getAllVolunteers();
}

std::vector<Volunteer> Service::getVolunteersForDepartment(const std::string &departmentName) const {
    std::vector<Volunteer> result;
    auto volunteers=repo.getAllVolunteers();
    for (const auto& v:volunteers) {
        if (v.getDepartment()==departmentName)
            result.push_back(v);
    }
    std::sort(result.begin(),result.end(),[](const Volunteer& a, const Volunteer& b) {
        return a.getName() < b.getName();
    });
    return result;
}

std::vector<Volunteer> Service::getUnassignedVolunteers() const {
    std::vector<Volunteer> result;
    auto volunteers=repo.getAllVolunteers();
    for (const auto& v: volunteers) {
        if (v.isUnassigned()) {
            result.push_back(v);
        }
    }
    return result;
}
