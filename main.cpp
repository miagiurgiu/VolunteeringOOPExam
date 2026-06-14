//
// Created by Maria on 14/06/2026.
//
#include "../domain/department.h"
#include "../service/service.h"
#include "../gui/gui.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    Repo repo{"../departments.txt","../volunteers.txt"};
    Service service{repo};
    std::vector<GUI*> windows;
    for (const auto& d:service.getAllDepartments()) { // as many windows as departments
        GUI* gui=new GUI{service, d};
        gui->show();
        windows.push_back(gui);
    }
    return app.exec();
}