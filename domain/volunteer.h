//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_VOLUNTEER_H
#define VOLUNTEERINGOOPEXAM_VOLUNTEER_H
#include <string>
#include <vector>

class Volunteer {
private:
    std::string name;
    std::string email;
    std::vector<std::string> interests; // list of interests
    std::string department;
public:
    Volunteer()=default;
    Volunteer(const std::string& name, const std::string& email, const std::vector<std::string>& interests, const std::string& department);
    std::string getName() const;
    std::string getEmail() const;
    std::vector<std::string> getInterests() const;
    std::string getDepartment() const;
    void setDepartment(const std::string& department);
    bool isUnassigned() const;
    ~Volunteer()=default;

};



#endif //VOLUNTEERINGOOPEXAM_VOLUNTEER_H
