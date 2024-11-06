#include "button_upload.h"

button_upload::button_upload(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    this->setIconSize(QSize(40,30));
    this->setIcon(QIcon(":/icons/export.png"));
    makeConnections();
}

void button_upload::share(){
    QWidget *share_widget = new QWidget();
    share_widget->setWindowTitle("export");
    QHBoxLayout *shareIconLayout = new QHBoxLayout();

    tiktok->setFlat(true);
    tiktok->setIcon(QIcon(":/icons/tiktok.svg"));
    tiktok->setMinimumSize(100,100);
    tiktok->setIconSize(QSize(100,100));

    youtube->setFlat(true);
    youtube->setIcon(QIcon(":/icons/youtube.svg"));
    youtube->setMinimumSize(100,100);
    youtube->setIconSize(QSize(100,100));
    shareIconLayout->addWidget(tiktok);
    shareIconLayout->addWidget(youtube);
    share_widget->setLayout(shareIconLayout);
    share_widget->show();
}

void button_upload::openTiktok(){
    QDesktopServices::openUrl(QUrl("https://www.tiktok.com"));
}

void button_upload::openYoutube(){
    QDesktopServices::openUrl(QUrl("https://www.youtube.com"));
}

void button_upload::makeConnections(){
    connect(this,SIGNAL(clicked()),this,SLOT(share()));
    connect(tiktok,SIGNAL(clicked()),this,SLOT(openTiktok()));
    connect(youtube,SIGNAL(clicked()),this,SLOT(openYoutube()));
}
