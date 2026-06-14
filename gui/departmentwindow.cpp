//
// Created by Maria on 14/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_departmentWindow.h" resolved

#include "departmentwindow.h"
#include "ui_departmentWindow.h"


departmentWindow::departmentWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::departmentWindow) {
    ui->setupUi(this);
}

departmentWindow::~departmentWindow() {
    delete ui;
}
