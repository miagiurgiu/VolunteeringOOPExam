//
// Created by Maria on 14/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_DEPARTMENTWINDOW_H
#define VOLUNTEERINGOOPEXAM_DEPARTMENTWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class departmentWindow; }
QT_END_NAMESPACE

class departmentWindow : public QWidget {
Q_OBJECT

public:
    explicit departmentWindow(QWidget *parent = nullptr);
    ~departmentWindow() override;

private:
    Ui::departmentWindow *ui;
};


#endif //VOLUNTEERINGOOPEXAM_DEPARTMENTWINDOW_H
