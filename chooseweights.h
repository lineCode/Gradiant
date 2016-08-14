#ifndef CHOOSEWEIGHTS_H
#define CHOOSEWEIGHTS_H

#include <QDialog>
#include <QStringListModel>
#include <QString>
#include <QMessageBox>
#include "entergradeswindow.h"
#include <vector>

namespace Ui {
class ChooseWeights;
}

class ChooseWeights : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseWeights(QStringList gStringList, QWidget *parent = 0);
    ~ChooseWeights();

private slots:
    void on_gradesList_clicked(const QModelIndex &index);
    void on_pushButton_clicked();
    void on_doneButton_clicked();

    void on_weightsList_clicked(const QModelIndex &index);


private:
    Ui::ChooseWeights *ui;
    QStringListModel* gradeCategoriesModel;
    QStringList gradesStringList;

    QStringListModel* weightsModel;
    QStringList weightsStringList;

    EnterGradesWindow* newEnterGradesWindow;
};

#endif // CHOOSEWEIGHTS_H
