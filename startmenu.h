#ifndef STARTMENU_H
#define STARTMENU_H

#include <QDialog>
#include <QApplication>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include "choosegradeswindow.h"

namespace Ui {
class StartMenu;
}

class StartMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = 0);
    ~StartMenu();

private slots:
    void on_startButton_clicked();

private:
    Ui::StartMenu *ui;
    chooseGradesWindow* chooseCategories;
};

#endif // STARTMENU_H
