#ifndef TIMELINE_H
#define TIMELINE_H

/*
 * Position of the QSlider can control the position in time units
 * that the video is at
 */

// https://doc.qt.io/qt-6/qslider.html
#include <QSlider>

#include "video.h"

// Wrapper for a QSlider with custom slots
class Timeline : public QSlider {
    Q_OBJECT
public:
    explicit Timeline(Qt::Orientation orientation, QWidget *parent = nullptr);

public slots:
    void videoLoaded();
    void durationChanged(qint64 duration);
    void sliderChanged(qint64 value);
};

#endif // TIMELINE_H
