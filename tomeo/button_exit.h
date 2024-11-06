#ifndef BUTTON_EXIT_H
#define BUTTON_EXIT_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

#include <QWidget>
#include <QLayout>


#include "constants.h"
using namespace Constants;

class button_exit: public QPushButton {
    Q_OBJECT
private:
    QLabel *label;
    QPushButton *closeButton = new QPushButton();
    QPushButton *cancelButton = new QPushButton();
    QWidget *exit_widget = new QWidget();
public:
    button_exit(const QString &text);
    void makeConnections();


private slots:
    void close();
    void cancel();

public slots:
    void exit();

};


#endif // BUTTON_EXIT_H
