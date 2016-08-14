#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include <QString>
#include <QMessageBox>
#include <QSpinBox>
#include <QVector>
#include <string>
#include <cmath>
#include "gradeclass.h"

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultsWindow(QStringList gStrList, QStringList gValStrList, QStringList wStrList, std::vector<int> blankGradesVector, QWidget *parent = 0);
    ~ResultsWindow();

public slots:
    void calculateGradesNeeded();

private:
    Ui::ResultsWindow *ui;

    //QStringListModel* gradeCategoriesModel;
    QStringList gradesStringList;

    //QStringListModel* gradeValuesModel;
    QStringList gradeValuesStringList;

    //QStringListModel* weightsModel;
    QStringList weightsList;

    QVector<GradeClass*> gradeClassVector;
    QVector<int> knownGradesIndecies;



    QString unknownGrade;
    int unknownGradeIndex;
    double subTotal = 0.0;

};

#endif // RESULTSWINDOW_H
