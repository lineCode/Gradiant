#ifndef ENTERGRADESWINDOW_H
#define ENTERGRADESWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include <QString>
#include <QMessageBox>
#include <resultswindow.h>

namespace Ui {
class EnterGradesWindow;
}

class EnterGradesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterGradesWindow(QStringList gStringList, QStringList wStringList, QWidget *parent = 0);
    ~EnterGradesWindow();

private slots:
    void on_enterGradeButton_clicked();
    void on_gradesList_clicked(const QModelIndex &index);
    void on_doneButton_clicked();

    void on_gradeValuesList_clicked(const QModelIndex &index);

private:
    Ui::EnterGradesWindow *ui;

    QStringListModel* gradeCategoriesModel;
    QStringList gradesStringList;

    QStringListModel* gradeValuesModel;
    QStringList gradeValuesStringList;

    QStringList weightsStringList;

    ResultsWindow* newResultsWindow;
};

#endif // ENTERGRADESWINDOW_H
