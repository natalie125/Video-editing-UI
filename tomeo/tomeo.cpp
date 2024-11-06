#include <QDirIterator>
#include <QImageReader>
#include <QScrollArea>
#include "button_upload.h"

#include "tomeo.h"

void Tomeo::loadVideos(const QDir dir) {

    // Our directory iterator, qdirIterator 폴더 내부 파일 순회
    QDirIterator it(dir);
    this->setStyleSheet(QString("color: white; background-color: black"));
    while (it.hasNext()) {  // for all files in dir
        QString f = it.next();

        if (f.contains(".")) {
#if defined(_WIN32)
            if (f.contains(".wmv")) {  // windows
#else
            if (f.contains(".mp4") || f.contains("MOV")) {  // mac/linux
#endif
//                qDebug() << f.left(f.length() - 4);
                // translate video file into image file with .png extenion
                QString thumb = f.left(f.length() - 4) + ".png";

                if (QFile(thumb).exists()) { // if a png thumbnail exists

                    QImageReader *imageReader = new QImageReader(thumb);

                    QImage sprite = imageReader->read();  // read the thumbnail
                    if (!sprite.isNull()) {
                         // voodoo to create an icon for the button
                        QIcon *ico = new QIcon(QPixmap::fromImage(sprite));
                         // convert the file location to a generic url
                        QUrl *url = new QUrl(QUrl::fromLocalFile(QFileInfo(f).absoluteFilePath()));

                        // Create a new video object and make it available to the app.
                        auto video = new Video(url, ico);

                        videos.push_back(video);
                    } else {
                        qDebug() << "couldn't read thumbnail for " << f;
                    }
                } else {
                    qDebug() << "skipping " << f << " as it has no thumbnail";
                }
            }
        }
    }

}

Tomeo::Tomeo(const QDir dir) {
    loadVideos(dir);

    // Let the layouts and widgets begin!
    previewer = new Previewer(this);
    previewer->setMaximumWidth(this->width());

    projectControls = new ProjectControls(this);
    previewControls = new PreviewControls(this);

    timeline = new Timeline(Qt::Horizontal, this);
    toolbar = new ToolBar(this);

//    toolbar->setStyleSheet("QPushButton:pressed { background-color: darkgreen }" );


    selector = new VideoSelector(videos, this);
    selector->setStyleSheet(" background-color: darkgreen");

    effects = new Effects(previewer, this);
    effects->setStyleSheet("QPushButton:hover { background-color: darkgreen }" );


    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);

    mainLayout->addWidget(projectControls);
    mainLayout->addWidget(previewer);
    mainLayout->addWidget(timeline);
    mainLayout->addWidget(previewControls);


    QWidget *spacer = new QWidget(this);
    mainLayout->addWidget(spacer);

    activeTool = new DynamicLabel(this);
    activeTool->setText("Videos");  // Initial state
    activeTool->setAlignment(Qt::AlignHCenter);
//    activeTool->setStyleSheet("QPushButton{background-color: black}");

    scrollAreaTools = new QScrollArea;
    scrollAreaTools->setWidget(toolbar);
    scrollAreaTools->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaTools->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scrollAreaSelector = new QScrollArea;
    scrollAreaSelector->setWidget(selector);
    scrollAreaSelector->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaSelector->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scrollAreaEffects = new QScrollArea;
    scrollAreaEffects->setWidget(effects);
    scrollAreaEffects->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaEffects->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mainLayout->addWidget(activeTool);
    mainLayout->addWidget(scrollAreaTools);
    mainLayout->addWidget(scrollAreaSelector);
    mainLayout->addWidget(scrollAreaEffects);
    scrollAreaEffects->hide();

    mainLayout->addStretch();  // Align widgets to top.
    setLayout(mainLayout);

    previewer->playVideo(videos.at(0));
    projectControls->videoName->setText(*(videos.at(0)->getName()));

    connect(previewControls, &PreviewControls::stateButtonSignal, previewer, &Previewer::toggleState);
    connect(previewControls, &PreviewControls::backButtonSignal, previewer, &Previewer::toStart);
    connect(previewControls, &PreviewControls::undoButtonSignal, previewer, &Previewer::undoClicked);
    connect(previewControls, &PreviewControls::redoButtonSignal, previewer, &Previewer::redoClicked);

    connect(previewer, &Previewer::videoProgressedSignal, timeline, &Timeline::sliderChanged);
    connect(previewer, &Previewer::durationChangeSignal, timeline, &Timeline::durationChanged);

    connect(selector, &VideoSelector::videoSelectSignal, previewer, &Previewer::playVideo);
    connect(selector, &VideoSelector::videoSelectSignal, timeline, &Timeline::videoLoaded);
    connect(selector, &VideoSelector::nameSelectSignal, projectControls->videoName, &DynamicLabel::changeText);
    connect(toolbar, &ToolBar::toolSelectSignal, this, &Tomeo::changeActiveTool);

//    connect(toolbar, &ToolBar::toolnumSignal, this, &Tomeo::buttonStateChanged);

    connect(toolbar, &ToolBar::toolSelectSignal, activeTool, &DynamicLabel::changeText);
//    connect(toolbar, &ToolBar::toolSelectSignal, this, &DynamicLabel::changeText);
}

void Tomeo::changeActiveTool(QString name) {
    if (name == "Effects") {
        scrollAreaSelector->hide();
        scrollAreaEffects->show();
    }
    else if (name == "Videos") {
        scrollAreaEffects->hide();
        scrollAreaSelector->show();
    }
    else {
        scrollAreaEffects->hide();
        scrollAreaSelector->hide();  // Features not to implement for proof of concept

    }
}


/*
 * Important! free any Tomeo objects created with new
 */
Tomeo::~Tomeo() {
    for (auto video : videos) {
        delete video;
    }
}
