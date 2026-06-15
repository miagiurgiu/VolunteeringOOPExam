//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_SERVICE_H
#define VOLUNTEERINGOOPEXAM_SERVICE_H
#include "../repo/repo.h"
#include "../domain/subject.h"

class Service:public Subject {
private:
    Repo& repo;
public:
    Service(Repo& repo);
    const std::vector<Department>& getAllDepartments() const;
    const std::vector<Volunteer>& getAllVolunteers() const;
    std::vector<Volunteer> getVolunteersForDepartment(const std::string& departmentName) const;
    std::vector<Volunteer> getUnassignedVolunteers() const;
    void addVolunteer(const std::string& name, const std::string& email, const std::string& interestsText);
    double computeScore(const Volunteer& volunteer, const Department& currentDepartment) const;
    std::vector<Volunteer> getTopVolunteers(Department currentDepartment) const;
    void assignVolunteerToDepartment(const std::string& volunteerName, const std::string& departmentName);
};


#endif //VOLUNTEERINGOOPEXAM_SERVICE_H
