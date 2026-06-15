//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_REPO_H
#define VOLUNTEERINGOOPEXAM_REPO_H
#include <vector>
#include <string>
#include "../domain/department.h"
#include "../domain/volunteer.h"


class Repo {
private:
    std::string departmentsFile;
    std::string volunteersFile;
    std::vector<Department> departments;
    std::vector<Volunteer> volunteers;
public:
    Repo(const std::string& departmentsFile, const std::string& volunteersFile);
    void loadDepartments();
    void loadVolunteers();
    const std::vector<Department>& getAllDepartments() const;
    const std::vector<Volunteer>& getAllVolunteers() const;
    void addVolunteer(const Volunteer& v);
};



#endif //VOLUNTEERINGOOPEXAM_REPO_H
