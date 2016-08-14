#include "startmenu.h"
#include "ui_startmenu.h"

StartMenu::StartMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Gradiant");

}

StartMenu::~StartMenu()
{
    delete ui;
    delete chooseCategories;
}

void StartMenu::on_startButton_clicked()
{
    close();
    chooseCategories = new chooseGradesWindow();
    chooseCategories->show();
}
