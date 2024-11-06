#include "videoselector.h"

VideoSelector::VideoSelector(std::vector<Video*> v, QWidget *parent) : QWidget(parent) {
    layout = new QHBoxLayout(this);
    layout->setMargin(24);
    layout->setAlignment(Qt::AlignVCenter);

    for (auto video : v) {
        auto thumbnail = new VideoThumbnail(this);
        thumbnail->setFixedSize(100, THUMB_HEIGHT);

        thumbnail->init(video);
        videos.push_back(thumbnail);
        layout->addWidget(thumbnail);

        // Connect the button to the common slot/signal interface
        connect(thumbnail, &VideoThumbnail::selected, this, &VideoSelector::videoSelect);
    }

    setLayout(layout);
}

void VideoSelector::videoSelect(Video *video) {
    emit videoSelectSignal(video);
    emit nameSelectSignal(*(video->getName()));
}

void VideoThumbnail::init(Video *video) {
    thumbnailVideo = video;
    setIcon(*(video->getThumbnail()));
    setText(*(video->getName()));
}

void VideoThumbnail::select() {
    emit selected(thumbnailVideo);
}
