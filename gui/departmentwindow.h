//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_DEPARTMENTWINDOW_H
#define VOLUNTEERINGOOPEXAM_DEPARTMENTWINDOW_H

#include <QWidget>
#include "../domain/observer.h"
#include "../service/service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class departmentWindow; }
QT_END_NAMESPACE

class departmentWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit departmentWindow(Service& service, QWidget *parent = nullptr);
    ~departmentWindow() override;
    void update() override;

private:
    Ui::departmentWindow *ui;
    Service& service;
    void populateList();
};


#endif //VOLUNTEERINGOOPEXAM_DEPARTMENTWINDOW_H
