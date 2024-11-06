#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include "constants.h"
using namespace Constants;

class PreviewControls : public QWidget {
    Q_OBJECT
public:
    explicit PreviewControls(QWidget *parent = nullptr);

private:
    QLayout *layout;

    QPushButton *stateButton;
    QPushButton *backButton;
    QPushButton *undoButton;
    QPushButton *redoButton;


    bool isPlaying = true;

private slots:
    void stateButtonClicked();
    void backButtonClicked();
    void undoButtonClicked();
    void redoButtonClicked();

    void changeIcon(QMediaPlayer::State);

signals:
    void stateButtonSignal();
    void backButtonSignal();
    void undoButtonSignal();
    void redoButtonSignal();


};

#endif // PLAYBACK_H
