#include "projectcontrols.h"



ProjectControls::ProjectControls(QWidget *parent) : QWidget(parent) {
    layout = new QHBoxLayout(this);

    exitButton = new button_exit("");
    exitButton->setStyleSheet(QString("background-color: darkgreen"));

    exportButton = new button_upload("");
    exportButton->setStyleSheet(QString("background-color: darkgreen"));
    videoName = new DynamicLabel(this);

    videoName->setAlignment(Qt::AlignCenter);


    // Test
    videoName->setText("Test video");

    layout->addWidget(exitButton);

    QWidget *leftSpacer = new QWidget(this);
    layout->addWidget(leftSpacer);
    layout->addWidget(videoName);
    QWidget *rightSpacer = new QWidget(this);
    layout->addWidget(rightSpacer);
    layout->addWidget(exportButton);

    // Connect our buttons+signals to their slots when the mouse click on the button is released
//    connect(exitButton, &QPushButton::released, this, &ProjectControls::exitButtonClicked);
//    connect(exportButton, &QPushButton::released, this, &ProjectControls::exportButtonClicked);

    layout->setMargin(0);
    setLayout(layout);
}

// Slots and signals
void ProjectControls::exitButtonClicked() {
    // Something, maybe a dialog then quit tomeo

}

void ProjectControls::exportButtonClicked() {
    // Something, maybe a dialog
    emit exportButtonSignal();
}
