#include <QtDebug>
#include "toolbar.h"

ToolBar::ToolBar(QWidget *parent) : QWidget(parent) {
    layout = new QHBoxLayout(this);

    videosButton = new ToolButton(this);
    videosButton->setCheckable(true);
//    videosButton->setStyleSheet("QPushButton {background-color: darkgreen;}");
    videosButton->setName(QString("Videos"));
    videosButton->setMinimumSize(TOOL_WIDTH, TOOL_HEIGHT);
    videosButton->setActive(true);
    videosButton->setFlat(true);
    videosButton->setIconSize(QSize(40,30));
    videosButton->setIcon(QIcon(":/icons/video.png"));

    connect(videosButton, &ToolButton::selected, this, &ToolBar::toolSelect);


    musicButton = new ToolButton(this);
    musicButton->setCheckable(true);
    musicButton->setName(QString("Music"));
    musicButton->setMinimumSize(TOOL_WIDTH, TOOL_HEIGHT);
    musicButton->setFlat(true);
    musicButton->setIconSize(QSize(40,30));
    musicButton->setIcon(QIcon(":/icons/music.png"));
    connect(musicButton, &ToolButton::selected, this, &ToolBar::toolSelect);


    effectsButton = new ToolButton(this);
    effectsButton ->setCheckable(true);
    effectsButton->setName(QString("Effects"));
    effectsButton->setMinimumSize(TOOL_WIDTH, TOOL_HEIGHT);
    effectsButton->setFlat(true);
    effectsButton->setIconSize(QSize(40,30));
    effectsButton->setIcon(QIcon(":/icons/effects.png"));
    connect(effectsButton, &ToolButton::selected, this, &ToolBar::toolSelect);


    animationsButton = new ToolButton(this);
    animationsButton ->setCheckable(true);
    animationsButton->setName(QString("Animations"));
    animationsButton->setMinimumSize(TOOL_WIDTH, TOOL_HEIGHT);
    animationsButton->setFlat(true);
    animationsButton->setIconSize(QSize(40,30));
    animationsButton->setIcon(QIcon(":/icons/animations.png"));
    connect(animationsButton, &ToolButton::selected, this, &ToolBar::toolSelect);


    textButton = new ToolButton(this);
    textButton ->setCheckable(true);
    textButton->setName(QString("Text"));
    textButton->setMinimumSize(TOOL_WIDTH, TOOL_HEIGHT);
    textButton->setFlat(true);
    textButton->setIconSize(QSize(40,30));
    textButton->setIcon(QIcon(":/icons/text.png"));
    connect(textButton, &ToolButton::selected, this, &ToolBar::toolSelect);


    stickerButton = new ToolButton(this);
    stickerButton ->setCheckable(true);
    stickerButton->setName(QString("Stickers"));
    stickerButton->setMinimumSize(TOOL_WIDTH, TOOL_HEIGHT);
    stickerButton->setFlat(true);
    stickerButton->setIconSize(QSize(40,30));
    stickerButton->setIcon(QIcon(":/icons/sticker.png"));
    connect(stickerButton, &ToolButton::selected, this, &ToolBar::toolSelect);





    layout->addWidget(videosButton);
    layout->addWidget(musicButton);
    layout->addWidget(effectsButton);
    layout->addWidget(textButton);
    layout->addWidget(stickerButton);
    layout->addWidget(animationsButton);

    // Align each widget of the ToolBar layout to the left
    for (int x = 0; x < layout->count(); x++) {
        layout->itemAt(x)->setAlignment(Qt::AlignLeft);
    }

    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

}

void ToolButton::setName(QString n) {
    name = n;
}

void ToolBar::toolSelect(QString name) {


    for (auto button : this->children()) {
        ToolButton *b = dynamic_cast<ToolButton*>(button);

        if (b != nullptr) {
            if (b->isActive() && b->getName() != name) {
                b->toggleActive();
                if (name == "Videos"){
                    videosButton->setStyleSheet("QPushButton {background-color: darkgreen;}");
                    musicButton->setStyleSheet("QPushButton {background-color: black;}");
                    effectsButton->setStyleSheet("QPushButton {background-color: black;}");
                    animationsButton->setStyleSheet("QPushButton {background-color: black;}");
                    textButton->setStyleSheet("QPushButton {background-color: black;}");
                    stickerButton->setStyleSheet("QPushButton {background-color: black;}");
                }else if (name == "Music"){
                    musicButton->setStyleSheet("QPushButton {background-color: darkgreen;}");
                    videosButton->setStyleSheet("QPushButton {background-color: black;}");
                    effectsButton->setStyleSheet("QPushButton {background-color: black;}");
                    animationsButton->setStyleSheet("QPushButton {background-color: black;}");
                    textButton->setStyleSheet("QPushButton {background-color: black;}");
                    stickerButton->setStyleSheet("QPushButton {background-color: black;}");
                }else if (name == "Effects"){
                    effectsButton->setStyleSheet("QPushButton {background-color: darkgreen;}");
                    videosButton->setStyleSheet("QPushButton {background-color: black;}");
                    musicButton->setStyleSheet("QPushButton {background-color: black;}");
                    animationsButton->setStyleSheet("QPushButton {background-color: black;}");
                    textButton->setStyleSheet("QPushButton {background-color: black;}");
                    stickerButton->setStyleSheet("QPushButton {background-color: black;}");
                }else if (name == "Animations"){
                    animationsButton->setStyleSheet("QPushButton {background-color: darkgreen;}");
                    videosButton->setStyleSheet("QPushButton {background-color: black;}");
                    musicButton->setStyleSheet("QPushButton {background-color: black;}");
                    effectsButton->setStyleSheet("QPushButton {background-color: black;}");
                    textButton->setStyleSheet("QPushButton {background-color: black;}");
                    stickerButton->setStyleSheet("QPushButton {background-color: black;}");
                }else if (name == "Text"){
                    textButton->setStyleSheet("QPushButton {background-color: darkgreen;}");
                    videosButton->setStyleSheet("QPushButton {background-color: black;}");
                    musicButton->setStyleSheet("QPushButton {background-color: black;}");
                    effectsButton->setStyleSheet("QPushButton {background-color: black;}");
                    animationsButton->setStyleSheet("QPushButton {background-color: black;}");
                    stickerButton->setStyleSheet("QPushButton {background-color: black;}");
                }else if (name == "Stickers"){
                    stickerButton->setStyleSheet("QPushButton {background-color: darkgreen;}");
                    videosButton->setStyleSheet("QPushButton {background-color: black;}");
                    musicButton->setStyleSheet("QPushButton {background-color: black;}");
                    effectsButton->setStyleSheet("QPushButton {background-color: black;}");
                    animationsButton->setStyleSheet("QPushButton {background-color: black;}");
                    textButton->setStyleSheet("QPushButton {background-color: black;}");
                }
            }
        }
    }
    emit toolSelectSignal(name);
    emit toolnumSignal(clicked);

}

void ToolButton::select() {

    if(isChecked() ){
       this->setStyleSheet("QPushButton {background-color: darkgreen;}");
    }
    else {
       this->setStyleSheet("QPushButton {background-color: red;}");
    }

    this->setActive(true);
    emit selected(name);
}

