//
// Created by Maria on 14/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_departmentWindow.h" resolved

#include "departmentwindow.h"
#include "ui_departmentWindow.h"


departmentWindow::departmentWindow(Service& service, QWidget *parent) :QWidget(parent), ui(new Ui::departmentWindow), service{service} {
    ui->setupUi(this);
    service.registerObserver(this);
    populateList();
}

departmentWindow::~departmentWindow() {
    service.unregisterObserver(this);
    delete ui;
}

void departmentWindow::update()
{
    populateList();
}

void departmentWindow::populateList() {
    ui->departmentsListWidget->clear();
    auto departments=service.getDepartmentsWithVolunteerCount();
    for (const auto& pair:departments) {
        auto departmentName=pair.first.getName();
        auto count=pair.second;
        ui->departmentsListWidget->addItem(QString::fromStdString(departmentName+": "+std::to_string(count))+ " volunteers");
    }
}
