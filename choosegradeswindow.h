#ifndef CHOOSEGRADESWINDOW_H
#define CHOOSEGRADESWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include <QString>
#include "chooseweights.h"

namespace Ui {
class chooseGradesWindow;
}

class chooseGradesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit chooseGradesWindow(QWidget *parent = 0);
    ~chooseGradesWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_doneButton_clicked();

private:
    Ui::chooseGradesWindow *ui;
    QStringListModel* gradeCategoriesModel;
    QStringList gradesStringList;

    ChooseWeights* chooseWeightsWindow;
};

#endif // CHOOSEGRADESWINDOW_H
