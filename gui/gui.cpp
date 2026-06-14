//
// Created by Maria on 14/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(Service& service, const Department& department, QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},department{department} {
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(department.getName())); // each window to have the department's name
    ui->descriptionLabel->setText(QString::fromStdString(department.getDescription()));
    populateList();
}

GUI::~GUI() {
    delete ui;
}

void GUI::populateList() {
    ui->volunteersList->clear();
    ui->unassignedVolunteersList->clear();

    auto departmentVolunteers=service.getVolunteersForDepartment(department.getName());
    for (const auto& v: departmentVolunteers) {
        ui->volunteersList->addItem(QString::fromStdString(v.getName()));
    }

    auto unassignedVolunteers=service.getUnassignedVolunteers();
    for (const auto& v:unassignedVolunteers) {
        ui->unassignedVolunteersList->addItem(QString::fromStdString(v.getName()));
    }
}
