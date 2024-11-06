#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QScrollArea>



#include "constants.h"
using namespace Constants;

class ToolButton : public QPushButton {
    Q_OBJECT
public:
    ToolButton(QWidget *parent, bool status = false) : QPushButton(parent) {
        active = status;
        setIconSize(QSize(40, 40));
        connect(this, SIGNAL(released()), this, SLOT(select()));
    }

    void setName(QString n);
    void toggleActive() { active = !active; };
    void setActive(bool status) { active = status; };

    QString getName() { return name; };
    bool isActive() { return active; };

private:
    QString name;
    bool active;

private slots:
    void select();
signals:
    void selected(QString);

};


class ToolBar : public QWidget {
    Q_OBJECT
public:
    explicit ToolBar(QWidget *parent = nullptr);

        bool  clicked=false;
    ~ToolBar() {
        delete stickerButton;
        delete textButton;
        delete animationsButton;
        delete effectsButton;
        delete musicButton;
        delete videosButton;
        delete layout;
    }



private:
    QLayout *layout;
    ToolButton *videosButton;
    ToolButton *musicButton;
    ToolButton *effectsButton;
    ToolButton *animationsButton;
    ToolButton *textButton;
    ToolButton *stickerButton;

private slots:
    void toolSelect(QString);

signals:
    void toolSelectSignal(QString);
    void toolnumSignal(int);

};

#endif // TOOLBAR_H
