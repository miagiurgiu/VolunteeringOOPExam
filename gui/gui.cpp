//
// Created by Maria on 14/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>
#include <QPushButton>


GUI::GUI(Service& service, const Department& department, QWidget *parent) : QWidget(parent), ui(new Ui::GUI),service{service},department{department} {
    ui->setupUi(this);
    service.registerObserver(this);
    this->setWindowTitle(QString::fromStdString(department.getName())); // each window to have the department's name
    ui->descriptionLabel->setText(QString::fromStdString(department.getDescription()));
    connectSignalsAndSlots();
    update(); // instead of populateList()
}

GUI::~GUI() {
    service.unregisterObserver(this); /// add this in the overriden destructor!
    delete ui;
}

void GUI::update() {
    populateList();
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

void GUI::repopulateUnassignedList() {
    ui->unassignedVolunteersList->clear();
    auto topVolunteers=service.getTopVolunteers(department);
    for (const auto& v: topVolunteers) {
        ui->unassignedVolunteersList->addItem(QString::fromStdString(v.getName()));
    }
}


void GUI::addVolunteer() {
    std::string name=ui->nameLineEdit->text().toStdString(); // retrieve name
    std::string email=ui->emailLineEdit->text().toStdString();
    std::string interests=ui->interestsLineEdit->text().toStdString();
    try {
        service.addVolunteer(name,email,interests);
        ui->nameLineEdit->clear();
        ui->emailLineEdit->clear();
        ui->interestsLineEdit->clear();
        /// populateList(); /// don't call populate list here anymore!
    }
    catch (const std::exception& e) { // CONST!!!
        QMessageBox::critical(this,"ERROR",e.what());
    }
}

void GUI::connectSignalsAndSlots() {
    connect(ui->addButton,&QPushButton::clicked,this,&GUI::addVolunteer);
    connect(ui->topVolunteersButton,&QPushButton::clicked,this,&GUI::repopulateUnassignedList);
}
