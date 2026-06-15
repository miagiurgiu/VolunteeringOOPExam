//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_DEPARTMENT_H
#define VOLUNTEERINGOOPEXAM_DEPARTMENT_H
#include <string>


class Department {
private:
    std::string name;
    std::string description;
public:
    Department()=default;
    Department(const std::string& name, const std::string& description);
    std::string getName() const;
    std::string getDescription() const;
    int getDescriptionNrOfWords() const;
    ~Department()=default;
};



#endif //VOLUNTEERINGOOPEXAM_DEPARTMENT_H
