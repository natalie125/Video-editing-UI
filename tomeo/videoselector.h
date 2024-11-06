#ifndef VIDEOSELECTOR_H
#define VIDEOSELECTOR_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>
#include <QLayout>

#include "video.h"
#include "constants.h"
using namespace Constants;

/*
 * Pretty much a reorganised version of original TheButton class but
 * uses QToolButton so that we can easily put the video's name under it.
 */
class VideoThumbnail : public QToolButton {
    Q_OBJECT
public:
    VideoThumbnail(QWidget *parent) : QToolButton(parent) {
        setIconSize(QSize(parent->width(), 55));
        setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(this, SIGNAL(released()), this, SLOT(select()));
    }

    ~VideoThumbnail() {
        delete thumbnailVideo;
    }

    void init(Video *v);

private:
    Video *thumbnailVideo;

private slots:
    void select();

signals:
    void selected(Video*);
};

class VideoSelector : public QWidget {
    Q_OBJECT
public:
    explicit VideoSelector(std::vector<Video*> videos, QWidget *parent = nullptr);

    ~VideoSelector() {
        for (auto t : videos)
            delete t;
    }

private:
    QLayout *layout;
    std::vector<QToolButton*> videos;

/*
 *  All thumbnail clicks pass through these so we dont have to connect arbitrary
 *  amounts of video thumbnails to the previewer
 */
private slots:
    void videoSelect(Video*);

signals:
    void videoSelectSignal(Video*);
    void nameSelectSignal(QString);
};

#endif // VIDEOSELECTOR_H
