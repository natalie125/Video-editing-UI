#ifndef BUTTON_UPLOAD_H
#define BUTTON_UPLOAD_H
#include <QPushButton>
#include <QWidget>
#include <QLayout>
#include <QDesktopServices>
#include <QUrl>

#include "constants.h"
using namespace Constants;
class button_upload : public QPushButton {
    Q_OBJECT
private:
    QPushButton *tiktok = new QPushButton();
    QPushButton *youtube = new QPushButton();
public:
    button_upload(const QString &text);
    void makeConnections();
public slots:
    void share();

private slots:
    void openTiktok();
    void openYoutube();
};

#endif // BUTTON_UPLOAD_H
