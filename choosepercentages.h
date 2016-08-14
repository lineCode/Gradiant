#ifndef CHOOSEPERCENTAGES_H
#define CHOOSEPERCENTAGES_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class ChoosePercentages;
}

class ChoosePercentages : public QDialog
{
    Q_OBJECT

public:
    explicit ChoosePercentages(QStringList catList, QWidget *parent = 0);
    ~ChoosePercentages();

private:
    Ui::ChoosePercentages *ui;
    QStringList categoryList;
};

#endif // CHOOSEPERCENTAGES_H
