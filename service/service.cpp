//
// Created by Maria on 14/06/2026.
//

#include "service.h"
#include <algorithm>
#include <sstream>
#include <stdexcept>

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

void Service::addVolunteer(const std::string &name, const std::string &email, const std::string &interestsText) {
    if (name.empty() || email.empty()) {
        throw std::runtime_error("Empty name/email");
    }
    std::vector<std::string> interests; // parsed interests
    std::stringstream ss{interestsText};
    std::string interest;
    while (std::getline(ss,interest,',')) {
        if (!interest.empty())
            interests.push_back(interest);
    }

    Volunteer volunteer{name,email,interests,""};
    repo.addVolunteer(volunteer);
    notify(); /// for design pattern!!
}

double Service::computeScore(const Volunteer &volunteer, const Department &currentDepartment) const {
    int matches=0;
    auto interests=volunteer.getInterests();
    for (const auto& i:interests) {
        if (currentDepartment.getDescription().find(i)!=std::string::npos) { // we did find matching words
            matches++;
        }
    }
    int nrWords=currentDepartment.getDescriptionNrOfWords();
    if (nrWords==0)
        return 0;
    return matches*1.0/nrWords; // matches/nrWords would be integer division
}

std::vector<Volunteer> Service::getTopVolunteers(Department currentDepartment) const {
    auto volunteers=getUnassignedVolunteers();
    std::vector<std::pair<Volunteer,double>> result;
    std::vector<Volunteer> topVolunteers;
    for (auto v:volunteers) {
        double score=computeScore(v,currentDepartment);
        result.push_back({v,score});
    }
    std::sort(result.begin(),result.end(),[](const auto& a, const auto& b) {
        return a.second>b.second;
    });

    // extract volunteers from pairs -> new vector
    for (const auto& pair: result) {
        topVolunteers.push_back(pair.first);
    }
    if (topVolunteers.size()>3)
        topVolunteers.resize(3);
    return topVolunteers;
}

void Service::assignVolunteerToDepartment(const std::string &volunteerName, const std::string &departmentName) {
    repo.assignVolunteerToDepartment(volunteerName,departmentName);
    notify();
}

std::vector<std::pair<Department, int>> Service::getDepartmentsWithVolunteerCount() const {
    std::vector<std::pair<Department,int>> result;
    auto departments=repo.getAllDepartments();
    for (const auto& d: departments) {
        auto volunteers=getVolunteersForDepartment(d.getName());
        int nr=volunteers.size();
        result.push_back({d,nr});
    }
    std::sort(result.begin(),result.end(),[](const auto& a, const auto& b) {
        return a.second>b.second;
    });
    return result;
}
