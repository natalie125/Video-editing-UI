#include "effects.h"

EffectSlider::EffectSlider(Qt::Orientation orientation, QWidget *parent) : QSlider(orientation, parent) {}

Effects::Effects(Previewer *preview, QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    layout->setMargin(35);
    layout->setAlignment(Qt::AlignVCenter);

    hue = new EffectSlider(Qt::Horizontal, this);
    hue->setMinimum(-100);
    hue->setMaximum(100);
    hue->setValue(0);
    connect(hue, &EffectSlider::sliderMoved, preview, &Previewer::changeHue);     // User moves slider
    connect(hue, &EffectSlider::sliderPressed, preview, &Previewer::saveHue);     // User starts to move slider - the inital value we can restore
    connect(preview, &Previewer::contrastChanged, hue, &EffectSlider::setValue);  // Change slider value if video effect changes via undo/redo

    saturation = new EffectSlider(Qt::Horizontal, this);
    saturation->setMinimum(-100);
    saturation->setMaximum(100);
    saturation->setValue(0);
    connect(saturation, &EffectSlider::sliderMoved, preview, &Previewer::changeSaturation);
    connect(saturation, &EffectSlider::sliderPressed, preview, &Previewer::saveSaturation);
    connect(preview, &Previewer::contrastChanged, saturation, &EffectSlider::setValue);

    brightness = new EffectSlider(Qt::Horizontal, this);
    brightness->setMinimum(-100);
    brightness->setMaximum(100);
    brightness->setValue(0);
    connect(brightness, &EffectSlider::sliderMoved, preview, &Previewer::changeBrightness);
    connect(brightness, &EffectSlider::sliderPressed, preview, &Previewer::saveBrightness);
    connect(preview, &Previewer::contrastChanged, brightness, &EffectSlider::setValue);

    contrast = new EffectSlider(Qt::Horizontal, this);
    contrast->setMinimum(-100);
    contrast->setMaximum(100);
    contrast->setValue(0);
    connect(contrast, &EffectSlider::sliderMoved, preview, &Previewer::changeContrast);
    connect(contrast, &EffectSlider::sliderPressed, preview, &Previewer::saveContrast);
    connect(preview, &Previewer::contrastChanged, contrast, &EffectSlider::setValue);

    layout->addWidget(hue);
    layout->addWidget(saturation);
    layout->addWidget(brightness);
    layout->addWidget(contrast);

    setLayout(layout);
}
