#include "gradeclass.h"

GradeClass::GradeClass(QSpinBox *gCSpinBox, QLabel *gCLabel, double gCWeight, double gCGradeValue, int gCIndexValue, bool gCValueIsKnown, QObject* parent):
    gradeClassSpinBox(gCSpinBox),
    gradeClassLable(gCLabel),
    gradeClassWeight(gCWeight),
    gradeClassGradeValue(gCGradeValue),
    indexValue(gCIndexValue),
    valueIsKnown(gCValueIsKnown),
    QObject(parent)
{

}

GradeClass::~GradeClass() {
    delete gradeClassSpinBox;
    delete gradeClassLable;
}

QSpinBox* GradeClass::getSpinBox() {
    return this->gradeClassSpinBox;
}

QLabel* GradeClass::getLabel() {
    return this->gradeClassLable;
}

double GradeClass::getWeight() {
    return this->gradeClassWeight;
}

double GradeClass::getValue() {
    return this->gradeClassGradeValue;
}

int GradeClass::getIndexValue() {
    return this->indexValue;
}

bool GradeClass::isValueKnown() {
    return this->valueIsKnown;
}

void GradeClass::updateValue(int newValue) {
    this->gradeClassGradeValue = newValue;
    emit readyToRecalculate();
}

void GradeClass::hideLabelAndSpinBox(QString newString) {
    if (newString == gradeClassLable->text()) {
        this->gradeClassSpinBox->setDisabled(true);
        this->gradeClassLable->setDisabled(true);
    } else if(!this->valueIsKnown){
        this->gradeClassSpinBox->setDisabled(false);
        this->gradeClassLable->setDisabled(false);
        this->gradeClassSpinBox->clearFocus();
    }

    emit readyToRecalculate();

}


