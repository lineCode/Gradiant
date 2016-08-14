#ifndef GRADIENTWINDOW_H
#define GRADIENTWINDOW_H

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>

namespace Ui {
class GradientWindow;
}
class GradientWindow : public QWidget{
    Q_OBJECT

public:
    GradientWindow(QWidget* parent = 0);

private:
    //Labels for lineEdits
    QLabel* hwLabel;
    QLabel* quizLabel;
    QLabel* examLabel;
    QLabel* finalLabel;

    QLineEdit* hwLineEdit;
    QLineEdit* quizLineEdit;
    QLineEdit* examLineEdit;
    QLineEdit* finalLineEdit;

    QGridLayout* mainLayout;


    QPushButton* submitButton;


};

#endif // GRADIENTWINDOW_H
