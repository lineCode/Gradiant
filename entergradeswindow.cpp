#include "entergradeswindow.h"
#include "ui_entergradeswindow.h"

EnterGradesWindow::EnterGradesWindow(QStringList gStringList, QStringList wStringList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterGradesWindow),
    gradeCategoriesModel(new QStringListModel),
    gradeValuesModel(new QStringListModel),
    weightsStringList(wStringList)
{
    ui->setupUi(this);
    this->setWindowTitle("Enter Grades");
    gradesStringList = gStringList;
    ui->gradesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->gradeValuesList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < gStringList.size(); ++i) {
        gradeValuesStringList.append("");
    }

    ui->gradesList->setModel(gradeCategoriesModel);
    gradeCategoriesModel->setStringList(gradesStringList);

    ui->gradeValuesList->setModel(gradeValuesModel);
    gradeValuesModel->setStringList(gradeValuesStringList);

    ui->gradeLabel->setText(gradesStringList.at(0));
}

EnterGradesWindow::~EnterGradesWindow()
{
    delete ui;
    delete gradeCategoriesModel;
    delete gradeValuesModel;
}

void EnterGradesWindow::on_enterGradeButton_clicked()
{
    QString userInputText = ui->gradeLabelInput->text();
    bool userTextIsDouble = true;
    userInputText.toDouble(&userTextIsDouble);

    //If user has inserted grade text, insert grade text into gradeValuesStringList
    //If user entered nothing, insert blank text
    //Give user error when he does not enter blank or numeric entery
    if (ui->gradeLabelInput->text() == "" || userTextIsDouble) {
        for (int i = 0; i < gradesStringList.size(); i++) {
            if (ui->gradeLabel->text() == gradesStringList.at(i)) {
                gradeValuesStringList.removeAt(i);
                gradeValuesStringList.insert(i, ui->gradeLabelInput->text());

                if (i == gradesStringList.size() - 1) {
                    ui->gradeLabel->setText(gradesStringList.at(0));
                    ui->gradeLabelInput->setText(gradeValuesStringList.at(0));
                } else {
                    ui->gradeLabel->setText(gradesStringList.at(i + 1));
                    ui->gradeLabelInput->setText(gradeValuesStringList.at(i + 1));
                }
                break;
            }
        }
    }
    else {
        QMessageBox::critical(this, "Error", "Must insert blank or numeric grade.\n\"" + userInputText + "\" is not blank or numeric.");
    }
        gradeValuesModel->setStringList(gradeValuesStringList);
}

void EnterGradesWindow::on_gradesList_clicked(const QModelIndex &index)
{
    ui->gradeLabel->setText(gradesStringList.at(index.row()));
    ui->gradeLabelInput->setText(gradeValuesStringList.at(index.row()));
    ui->gradeLabelInput->setFocus();
}

void EnterGradesWindow::on_gradeValuesList_clicked(const QModelIndex &index)
{
    on_gradesList_clicked(index);
}

void EnterGradesWindow::on_doneButton_clicked()
{
    int numberOfBlankGrades = 0;
    std::vector<int> blankGradeIndicies;

    bool oneGradeBlank = false;

    for (int i = 0; i < gradeValuesStringList.size(); ++i) {
        if(gradeValuesStringList.at(i) == "") {
            oneGradeBlank = true;
            ++numberOfBlankGrades;
            blankGradeIndicies.push_back(i);
        }
    }

    if (oneGradeBlank) {
        close();
        newResultsWindow = new ResultsWindow(gradesStringList, gradeValuesStringList, weightsStringList, blankGradeIndicies);
        newResultsWindow->show();
    } else {
        QMessageBox::critical(this, "Error", "Must leave at least one grade empty.");
    }
}


