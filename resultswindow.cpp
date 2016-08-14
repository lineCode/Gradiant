#include "resultswindow.h"
#include "ui_resultswindow.h"

ResultsWindow::ResultsWindow(QStringList gStrList, QStringList gValStrList, QStringList wStrList, std::vector<int> blankGradesVector, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultsWindow),
    gradesStringList(gStrList),
    gradeValuesStringList(gValStrList),
    weightsList(wStrList)
{
    ui->setupUi(this);

    bool madeToDouble = false;

    //Set a, b, and c line to 'Read only'
    ui->aGradeLine->setReadOnly(true);
    ui->bGradeLine->setReadOnly(true);
    ui->cGradeLine->setReadOnly(true);

    //Fill grade class vector with all grades entered
    for (int i = 0; i < (int)gradesStringList.size(); ++i) {
        QSpinBox* newSpinBox = new QSpinBox();
        newSpinBox->setMaximum(120);
        newSpinBox->setValue(70);


        QLabel* newLabel = new QLabel();
        newLabel->setText(gradesStringList.at(i));

        double newWeight = weightsList.at(i).toDouble(&madeToDouble);

        double newGradeValue;
        gradeValuesStringList.at(i).toDouble(&madeToDouble);

        if (!madeToDouble) {
            newGradeValue = 70.0;
        } else {
            newGradeValue = gradeValuesStringList.at(i).toDouble(&madeToDouble);
        }

        bool knownGrade = true;
        for (int j = 0; j < (int)blankGradesVector.size(); ++j) {
            if (i == blankGradesVector.at(j)) {
                knownGrade = false;
                break;
            }
        }

        GradeClass* newGradeClass = new GradeClass(newSpinBox, newLabel, newWeight, newGradeValue, i, knownGrade);
        connect(newSpinBox, SIGNAL(valueChanged(int)), newGradeClass, SLOT(updateValue(int)));
        connect(newGradeClass, SIGNAL(readyToRecalculate()), this, SLOT(calculateGradesNeeded()));
        connect(ui->unknownGradeCB, SIGNAL(currentTextChanged(QString)), newGradeClass, SLOT(hideLabelAndSpinBox(QString)));

        gradeClassVector.push_back(newGradeClass);

        //If the grade value is not known, add a row to the unknown form
        if (!knownGrade && blankGradesVector.size() > 1) {
            ui->gradeCategoryFormLayout->addRow(newGradeClass->getLabel(), newGradeClass->getSpinBox());
        }
    }


    //Fill up unknownGradeCombo box with unknown grades
    for (int i = 0; i < (int)blankGradesVector.size(); ++i) {
        ui->unknownGradeCB->addItem(gradesStringList.at(blankGradesVector.at(i)));
    }
    //ui->unknownGradeCB->setCurrentIndex(1);
    ui->unknownGradeCB->setCurrentIndex(0);


    calculateGradesNeeded();

}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::calculateGradesNeeded() {
    bool convertedToDouble = false;

    //Figure out what the value of unkown grade must be to receive a 90, 80, and 70 overall
    subTotal = 0.0;
    unknownGrade = ui->unknownGradeCB->currentText();

    //Calculate the grades subtotal, excluding the unknown grade currently selected by the combo box
    for (int i = 0; i < gradeClassVector.size(); ++i) {
        if (gradeClassVector.at(i)->getLabel()->text() != unknownGrade) {
            subTotal += gradeClassVector.at(i)->getValue() * gradeClassVector.at(i)->getWeight();
        }
    }

    double gradeNeededForA = 0.0;
    double gradeNeededForB = 0.0;
    double gradeNeededForC = 0.0;

    gradeNeededForA = (90.0 - subTotal) / weightsList.at(gradeClassVector.at(0)->getIndexValue()).toDouble(&convertedToDouble);
    gradeNeededForB = (80.0 - subTotal) / weightsList.at(gradeClassVector.at(0)->getIndexValue()).toDouble(&convertedToDouble);
    gradeNeededForC = (70.0 - subTotal) / weightsList.at(gradeClassVector.at(0)->getIndexValue()).toDouble(&convertedToDouble);

    if (gradeNeededForA < 0) {
        gradeNeededForA = 0.00;
    }

    if (gradeNeededForB < 0) {
        gradeNeededForB = 0.00;
    }

    if (gradeNeededForC < 0) {
        gradeNeededForC = 0.00;
    }

    std::string gNeededForAString = std::to_string(gradeNeededForA);
    std::string gNeededForBString = std::to_string(gradeNeededForB);
    std::string gNeededForCString = std::to_string(gradeNeededForC);


    ui->aGradeLine->setText(QString::fromStdString(gNeededForAString).mid(0,5));
    ui->bGradeLine->setText(QString::fromStdString(gNeededForBString).mid(0,5));
    ui->cGradeLine->setText(QString::fromStdString(gNeededForCString).mid(0,5));


}

