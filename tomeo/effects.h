#ifndef EFFECTS_H
#define EFFECTS_H

#include <QWidget>
#include <QSlider>
#include <QLayout>

#include "previewer.h"

// Wrapper for a QSlider with custom slots
class EffectSlider : public QSlider {
    Q_OBJECT
public:
    explicit EffectSlider(Qt::Orientation orientation, QWidget *parent = nullptr);
};

class Effects : public QWidget {
    Q_OBJECT
public:
    explicit Effects(Previewer *preview, QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QSlider *hue;
    QSlider *saturation;
    QSlider *brightness;
    QSlider *contrast;

signals:

};

#endif // EFFECTS_H
