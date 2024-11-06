#ifndef PREVIEWER_H
#define PREVIEWER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QStack>


#include "video.h"
//#include "previewcontrols.h"

struct Pair {
    QString action;
    int previous;
};

class Previewer : public QVideoWidget {
    Q_OBJECT
public:
    explicit Previewer(QWidget *parent = nullptr);

public slots:
    void playVideo(Video *video);
    void toStart();  // Return to the start of the preview
    void mediaStateChanged(QMediaPlayer::State state);
    void toggleState();


    void changeHue(int value)        { setHue(value); qDebug() << value; };
    void changeSaturation(int value) { setSaturation(value); qDebug() << value; };
    void changeBrightness(int value) { setBrightness(value); qDebug() << value; };
    void changeContrast(int value)   { setContrast(value); qDebug() << value; };

    // Items to exchange between undo/redo stacks
    void saveHue();
    void saveSaturation();
    void saveBrightness();
    void saveContrast();

    void undoClicked();
    void redoClicked();

    // Timeline related
    void previewPositionChanged(qint64 position);
    void timelinePositionChanged(qint64 position);

signals:
    void durationChangeSignal(qint64 duration);
    void videoProgressedSignal(qint64 newPosition);
    void mediaChangedSignal(qint64 duration);
    void stateChanged(QMediaPlayer::State state);

private:
    QMediaPlayer *player;
    Video *video;
    QStack<Pair*> *undo;
    QStack<Pair*> *redo;
};

#endif // PREVIEWER_H
