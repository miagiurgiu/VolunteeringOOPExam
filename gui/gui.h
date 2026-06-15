//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_GUI_H
#define VOLUNTEERINGOOPEXAM_GUI_H

#include <QWidget>
#include "../repo/repo.h"
#include "../service/service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget,public Observer {
Q_OBJECT

public:
    explicit GUI(Service& service, const Department& department, QWidget *parent = nullptr);
    ~GUI() override;
    void update() override; // required by observer

private:
    Ui::GUI *ui;
    Service& service;
    Department department; // copy for each window

    void populateList();
    void repopulateUnassignedList();
    void connectSignalsAndSlots();
    void addVolunteer();
    void topVolunteers();
};


#endif //VOLUNTEERINGOOPEXAM_GUI_H
