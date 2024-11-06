#include "timeline.h"

// https://forum.qt.io/topic/66436/create-a-video-player-slider-seeker-with-qslider/2

Timeline::Timeline(Qt::Orientation orientation, QWidget *parent) : QSlider(orientation, parent) {}

void Timeline::videoLoaded() {
    setMinimum(0);  // Set bounds of slider value range
    setValue(0);
}

void Timeline::durationChanged(qint64 duration) {
    setMaximum(duration);
}

void Timeline::sliderChanged(qint64 value) {
    setValue(value);
}
