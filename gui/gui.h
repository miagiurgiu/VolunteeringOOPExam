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

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(Service& service, const Department& department, QWidget *parent = nullptr);
    ~GUI() override;

private:
    Ui::GUI *ui;
    Service& service;
    Department department; // copy for each window
    void populateList();
};


#endif //VOLUNTEERINGOOPEXAM_GUI_H
