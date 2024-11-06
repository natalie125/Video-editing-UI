#ifndef PROJECTCONTROLS_H
#define PROJECTCONTROLS_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include "button_exit.h"
#include "button_upload.h"


#include "dynamiclabel.h"

#include "constants.h"
using namespace Constants;

class ProjectControls : public QWidget {
    Q_OBJECT
public:
    explicit ProjectControls(QWidget *parent = nullptr);
    DynamicLabel *videoName;


private:
    QLayout *layout;


    button_exit *exitButton;
    button_upload *exportButton;


private slots:
    void exitButtonClicked();
    void exportButtonClicked();


signals:
    void exitButtonSignal();
    void exportButtonSignal();
};

#endif // PROJECTCONTROLS_H
