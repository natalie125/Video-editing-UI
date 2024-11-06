#include "previewer.h"

Previewer::Previewer(QWidget *parent) : QVideoWidget(parent) {
    player = new QMediaPlayer(this);
    player->setVideoOutput(this);

    undo = new QStack<Pair*>();
    redo = new QStack<Pair*>();

    connect(player, &QMediaPlayer::stateChanged, this, &Previewer::mediaStateChanged);

    connect(player, &QMediaPlayer::positionChanged, this, &Previewer::previewPositionChanged);

    // https://www.appsloveworld.com/cplus/100/284/qmediaplayer-duration-returns-0-always
    connect(player, &QMediaPlayer::durationChanged, this, [&](qint64 dur) {
        emit durationChangeSignal(dur);
    });


}

void Previewer::playVideo(Video *v) {
    player->setMedia(*v->getPath());
    player->play();
    player->setNotifyInterval(player->duration());
    video = v;
    undo->clear();
    redo->clear();
    emit mediaChangedSignal(player->position());
}

void Previewer::mediaStateChanged(QMediaPlayer::State state) {
    // Loop indefinitely

    if (player->mediaStatus() == QMediaPlayer::EndOfMedia) {
        player->setPosition(0);
        player->play();
    }
    // Or resume play
    else if (state == QMediaPlayer::State::StoppedState){
        player->play();

    }

}

void Previewer::toggleState() {
    if (player->state() == QMediaPlayer::State::PausedState) {
        player->play();

    }
    else{
        player->pause();
    }
}

void Previewer::toStart() {
    player->setPosition(0);

}

void Previewer::previewPositionChanged(qint64 position) {
    emit videoProgressedSignal(position);
}

void Previewer::timelinePositionChanged(qint64 position) {
    player->setPosition(position);
}

void Previewer::saveHue() {
    Pair *entry = new Pair;
    entry->action = "hue";
    entry->previous = hue();
    undo->push(entry);
}

void Previewer::saveSaturation() {
    Pair *entry = new Pair;
    entry->action = "saturation";
    entry->previous = saturation();
    undo->push(entry);
}

void Previewer::saveContrast() {
    Pair *entry = new Pair;
    entry->action = "contrast";
    entry->previous = contrast();
    undo->push(entry);
}

void Previewer::saveBrightness() {
    Pair *entry = new Pair;
    entry->action = "brightness";
    entry->previous = brightness();
    undo->push(entry);
}

void Previewer::undoClicked() {
    if (!undo->isEmpty()) {
        auto entry = undo->pop();
        qDebug() << entry->previous;

        if (entry->action == "hue")
            setHue(entry->previous);

        else if (entry->action == "saturation")
            setSaturation(entry->previous);

        else if (entry->action == "brightness")
            setBrightness(entry->previous);

        else if (entry->action == "contrast")
            setContrast(entry->previous);

        redo->push(entry);
    }
    player->setPosition(player->position()-4000);

}

void Previewer::redoClicked() {
    if (!redo->isEmpty()) {
        auto entry = redo->pop();
        qDebug() << entry->previous;

        if (entry->action == "hue")
            setHue(entry->previous);

        else if (entry->action == "saturation")
            setSaturation(entry->previous);

        else if (entry->action == "brightness")
            setBrightness(entry->previous);

        else if (entry->action == "contrast")
            setContrast(entry->previous);

        undo->push(entry);
    }
    player->setPosition(player->position()+4000);
}
