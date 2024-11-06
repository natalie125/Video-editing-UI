#ifndef VIDEO_H
#define VIDEO_H

#include <QFile>
#include <QFileInfo>
#include <QUrl>
#include <QIcon>

/*
 *  Wrapper for video information. Every video has:
 *      - its absolute URL path
 *      - its thumbnail
 *      - a name
 */
class Video {
public:
    Video(QUrl *url, QIcon *thumb) : url(url), thumb(thumb) {
        auto videoFile = url->toLocalFile();
        QFile file(videoFile);
        QFileInfo info(videoFile);
        name = new QString(info.baseName());
    }

    ~Video() {
        delete url;
        delete thumb;
        delete name;
    }

    QString *getName() { return name; }
    QIcon *getThumbnail() { return thumb; }
    QUrl *getPath() { return url; }

private:
    QUrl *url;
    QIcon *thumb;
    QString *name;
};

#endif // VIDEO_H
