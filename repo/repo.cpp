//
// Created by Maria on 14/06/2026.
//

#include "repo.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Repo::Repo(const std::string& departmentsFile, const std::string &volunteersFile):departmentsFile{departmentsFile},volunteersFile{volunteersFile} {
    loadDepartments();
    loadVolunteers();
}

void Repo::loadDepartments() {
    std::ifstream fin(departmentsFile);
    if (!fin.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string name;
        std::string description;
        std::getline(ss,name,',');
        std::getline(ss,description,',');

        auto trim = [](std::string& s) {// Removes leading spaces and tabs
            s.erase(0, s.find_first_not_of(" \t"));// Finds the last character that isn't a space/tab
            size_t end = s.find_last_not_of(" \t");// Removes everything after that character (trailing spaces)
            if (end != std::string::npos)
                s.erase(end +1);
        };

        trim(name);
        trim(description);
        departments.emplace_back(name,description);
    }
    fin.close();
}

void Repo::loadVolunteers() {
    std::ifstream fin(volunteersFile);
    if (!fin.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string name,email,interestsList,department;
        std::getline(ss,name,'|');
        std::getline(ss,email,'|');
        std::getline(ss,interestsList,'|');
        std::getline(ss,department,'|');

        auto trim = [](std::string& s) {// Removes leading spaces and tabs
            s.erase(0, s.find_first_not_of(" \t"));// Finds the last character that isn't a space/tab
            size_t end = s.find_last_not_of(" \t");// Removes everything after that character (trailing spaces)
            if (end != std::string::npos)
                s.erase(end +1);
        };

        trim(name);
        trim(email);
        trim(interestsList);
        trim(department);

        std::vector<std::string> interests;
        std::stringstream listStream(interestsList);
        std::string interest;
        while (std::getline(listStream,interest,',')) {
            trim(interest);
            if (!interest.empty())
                interests.push_back(interest);
        }
        volunteers.emplace_back(name,email,interests,department);
    }
    fin.close();
}


const std::vector<Department> & Repo::getAllDepartments() const {
    return departments;
}

const std::vector<Volunteer> & Repo::getAllVolunteers() const {
    return volunteers;
}
