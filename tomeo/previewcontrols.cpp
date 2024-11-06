#include "previewcontrols.h"

PreviewControls::PreviewControls(QWidget *parent) : QWidget(parent) {
    layout = new QHBoxLayout(this);

    undoButton = new QPushButton(this);
    undoButton->setStyleSheet(QString("background-color: darkgreen"));
    undoButton->setFlat(true);
    undoButton->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    undoButton->setIconSize(QSize(40,30));
    undoButton->setIcon(QIcon(":/icons/undo.png"));

    stateButton = new QPushButton(this);
    stateButton->setStyleSheet(QString("background-color: darkgreen"));
    stateButton->setFlat(true);
    stateButton->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    stateButton->setIconSize(QSize(40,30));
    stateButton->setIcon(QIcon(":/icons/pause.png"));

    backButton = new QPushButton(this);
    backButton ->setStyleSheet(QString("background-color: darkgreen"));
    backButton ->setFlat(true);
    backButton ->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    backButton ->setIconSize(QSize(40,30));
    backButton ->setIcon(QIcon(":/icons/skip-to-start.png"));

    redoButton = new QPushButton(this);
    redoButton ->setStyleSheet(QString("background-color: darkgreen"));
    redoButton ->setFlat(true);
    redoButton ->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    redoButton ->setIconSize(QSize(40,30));
    redoButton ->setIcon(QIcon(":/icons/redo.png"));


    layout->addWidget(undoButton);

    QWidget *leftSpacer = new QWidget(this);
    layout->addWidget(leftSpacer);
    layout->addWidget(stateButton);
    layout->addWidget(backButton);
    QWidget *rightSpacer = new QWidget(this);
    layout->addWidget(rightSpacer);
    layout->addWidget(redoButton);



    // Connect our buttons+signals to their slots when the mouse click on the button is released
    connect(stateButton, &QPushButton::released, this, &PreviewControls::stateButtonClicked);
    connect(backButton, &QPushButton::released, this, &PreviewControls::backButtonClicked);
    connect(undoButton, &QPushButton::released, this, &PreviewControls::undoButtonClicked);
    connect(redoButton, &QPushButton::released, this, &PreviewControls::redoButtonClicked);

    layout->setMargin(0);
    setLayout(layout);
}
// Slots and signals
void PreviewControls::stateButtonClicked() {
    // If our video is playing, switch the play icon out for a pause icon
    isPlaying = !isPlaying;  // Reverse the play state of the video
    emit stateButtonSignal();
//    stateButton->setIcon(QIcon(":/icons/play.png"));
    if(isPlaying == false){
        stateButton->setIcon(QIcon(":/icons/play.png"));
    }
    else if(isPlaying == true){
        stateButton->setIcon(QIcon(":/icons/pause.png"));
    }
}
void PreviewControls::changeIcon(QMediaPlayer::State state){
    if(state == QMediaPlayer::PausedState){
        stateButton->setIcon(QIcon(":/icons/play.png"));
    }
    else if(state == QMediaPlayer::PlayingState){
        stateButton->setIcon(QIcon(":/icons/pause.png"));
    }
}

void PreviewControls::backButtonClicked() {
    emit backButtonSignal();
}

void PreviewControls::undoButtonClicked() {
    emit undoButtonSignal();
}

void PreviewControls::redoButtonClicked() {
    emit redoButtonSignal();
}



