#ifndef DYNAMICLABEL_H
#define DYNAMICLABEL_H

#include <QWidget>
#include <QLabel>

class DynamicLabel : public QLabel {
    Q_OBJECT
public:
    explicit DynamicLabel(QWidget *parent = nullptr) { setParent(parent); }

public slots:
    void changeText(QString text) {
        setText(text);
    }
};

#endif // DYNAMICLABEL_H
