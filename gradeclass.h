#ifndef GRADECLASS_H
#define GRADECLASS_H


#include <QSpinBox>
#include <QLabel>
#include <QObject>

class GradeClass : public QObject
{
    Q_OBJECT

public:
    GradeClass(QSpinBox* gCSpinBox, QLabel* gCLabel, double gCWeight, double gCGradeValue, int gCIndexValue, bool gCValueIsKnown, QObject* parent = 0);
    QSpinBox* getSpinBox();
    QLabel* getLabel();
    double getWeight();
    double getValue();
    int getIndexValue();
    bool isValueKnown();

    ~GradeClass();

public slots:
    void updateValue(int newValue);
    void hideLabelAndSpinBox(QString newString);

signals:
    void readyToRecalculate();
private:
    QSpinBox* gradeClassSpinBox;
    QLabel* gradeClassLable;
    double gradeClassWeight;
    double gradeClassGradeValue;
    int indexValue;
    bool valueIsKnown;

};

#endif // GRADECLASS_H
