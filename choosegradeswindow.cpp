#include "choosegradeswindow.h"
#include "ui_choosegradeswindow.h"

chooseGradesWindow::chooseGradesWindow(QWidget *parent) : QDialog(parent), ui(new Ui::chooseGradesWindow), gradeCategoriesModel(new QStringListModel)
{
    ui->setupUi(this);
    this->setWindowTitle("Enter Categories");
    ui->gradesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->gradesList->setModel(gradeCategoriesModel);
    gradeCategoriesModel->setStringList(gradesStringList);
}

chooseGradesWindow::~chooseGradesWindow()
{
    delete ui;
    delete gradeCategoriesModel;
}

void chooseGradesWindow::on_addButton_clicked()
{
    QString userInputText = ui->inputText->text();

    if (userInputText != "") {
        if(gradesStringList.contains(userInputText)) {
            QMessageBox::critical(this, "Error", "Cannot enter duplicate categories. \n\"" + userInputText + "\"" + " is already a category.");
        } else if(gradesStringList.size() >= 20) {
            QMessageBox::critical(this, "Error", "Cannot enter 20 or more categories.\nDelete categories to make space.");
        } else {
            gradesStringList.append(ui->inputText->text());
            gradeCategoriesModel->setStringList(gradesStringList);
        }

        ui->inputText->clear();
    }
}

void chooseGradesWindow::on_deleteButton_clicked()
{

    QModelIndex currentSelection;
    currentSelection = ui->gradesList->currentIndex();

    if (currentSelection.row() >= 0 && currentSelection.row() < gradesStringList.size()) {
        gradesStringList.removeAt(currentSelection.row());
        gradeCategoriesModel->setStringList(gradesStringList);
    }
}

void chooseGradesWindow::on_doneButton_clicked()
{
    if (gradesStringList.size() <= 1) {
        QMessageBox::information(this, "Error", "Must insert at least two grade categories");
    } else {
        close();
        chooseWeightsWindow = new ChooseWeights(gradesStringList);
        chooseWeightsWindow->show();
    }
}
