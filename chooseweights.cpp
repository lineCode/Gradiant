#include "chooseweights.h"
#include "ui_chooseweights.h"

ChooseWeights::ChooseWeights(QStringList gStringList, QWidget *parent) : QDialog(parent), ui(new Ui::ChooseWeights), gradeCategoriesModel(new QStringListModel), weightsModel(new QStringListModel)
{
    ui->setupUi(this);
    gradesStringList = gStringList;
    ui->gradesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->weightsList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < gStringList.size(); i++) {
        weightsStringList.append("");
    }

    ui->gradesList->setModel(gradeCategoriesModel);
    gradeCategoriesModel->setStringList(gradesStringList);

    ui->weightsList->setModel(weightsModel);
    weightsModel->setStringList(weightsStringList);

    ui->gradeLabel->setText(gradesStringList.at(0));
}

ChooseWeights::~ChooseWeights()
{
    delete ui;
    delete gradeCategoriesModel;
    delete weightsModel;
    delete newEnterGradesWindow;
}

void ChooseWeights::on_gradesList_clicked(const QModelIndex &index)
{
    ui->gradeLabel->setText(gradesStringList.at(index.row()));
    ui->gradeLabelInput->setText(weightsStringList.at(index.row()));
    ui->gradeLabelInput->setFocus();
}

void ChooseWeights::on_weightsList_clicked(const QModelIndex &index)
{
    on_gradesList_clicked(index);
}



void ChooseWeights::on_pushButton_clicked()
{
    QString userInputText = ui->gradeLabelInput->text();
    bool userTextIsDouble = true;

    //If user has inserted weight text, insert weight text into weightsStringList
    if (userInputText != "" && weightsStringList.size() < 20) {
        userInputText.toDouble(&userTextIsDouble);
        if (!userTextIsDouble) {
            QMessageBox::critical(this, "Error", "Must enter numeric weight. (e.g. 25, 33, .25, .33)\n\"" + userInputText + "\" is not numeric");
        } else {
            for (int i = 0; i < gradesStringList.size(); i++) {
                if (ui->gradeLabel->text() == gradesStringList.at(i)) {
                    weightsStringList.removeAt(i);
                    weightsStringList.insert(i, ui->gradeLabelInput->text());

                    if (i == gradesStringList.size() - 1) {
                        ui->gradeLabel->setText(gradesStringList.at(0));
                        ui->gradeLabelInput->setText(weightsStringList.at(0));
                    } else {
                        ui->gradeLabel->setText(gradesStringList.at(i + 1));
                        ui->gradeLabelInput->setText(weightsStringList.at(i + 1));
                    }
                    break;
                }
            }
        }
    }
        weightsModel->setStringList(weightsStringList);
        //ui->gradeLabelInput->clear();
}

void ChooseWeights::on_doneButton_clicked()
{
    bool listContainsAllNumbers = true;

    double currentWeight = 0.0;
    double sum = 0.0;

    std::vector<double> weightsVector(weightsStringList.size());



    for (int i = 0; i < gradesStringList.size(); i++) {
        currentWeight = weightsStringList.at(i).toDouble(&listContainsAllNumbers);
        if (!listContainsAllNumbers) {
            QMessageBox::critical(this, "Error", "All grade categories must have weights.\n\"" + gradesStringList.at(i) + "\" does not have a weight value.");
            break;
        } else {
            weightsVector.at(i) = currentWeight;
            sum += currentWeight;
        }
    }


    if(listContainsAllNumbers) {
        if(!(sum == 1 || sum == 100)) {
            //callibrate weights
            for (int i = 0; i < (int)weightsVector.size(); ++i) {
                weightsStringList.removeAt(i);
                weightsStringList.insert(i, QString::number(weightsVector.at(i) / sum));
            }
        }
        close();
        newEnterGradesWindow = new EnterGradesWindow(gradesStringList, weightsStringList);
        newEnterGradesWindow->show();
    }


}




