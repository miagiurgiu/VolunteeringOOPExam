//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_SERVICE_H
#define VOLUNTEERINGOOPEXAM_SERVICE_H
#include "../repo/repo.h"


class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo);
    const std::vector<Department>& getAllDepartments() const;
    const std::vector<Volunteer>& getAllVolunteers() const;
    std::vector<Volunteer> getVolunteersForDepartment(const std::string& departmentName) const;
    std::vector<Volunteer> getUnassignedVolunteers() const;
};


#endif //VOLUNTEERINGOOPEXAM_SERVICE_H
