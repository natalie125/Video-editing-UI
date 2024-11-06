#ifndef TOMEO_H
#define TOMEO_H

#include <QDir>
#include <QWidget>
#include <QLayout>

#include <vector>
#include <iostream>

#include "video.h"
#include "dynamiclabel.h"
#include "previewer.h"
#include "previewcontrols.h"
#include "projectcontrols.h"
#include "timeline.h"
#include "toolbar.h"
#include "videoselector.h"
#include "effects.h"

class Tomeo : public QWidget {
    Q_OBJECT
public:
    /*
     *  Tomeo app instances require a path to some directory which
     *  should contain videos and their thumbnails.
     */
    Tomeo(const QDir dir);
    ~Tomeo();

private:
    // Every tomeo app instance has these members.
    std::vector<Video*> videos;  // The list of videos the app found in dir
    ProjectControls *projectControls;
    Previewer *previewer;
    PreviewControls *previewControls;
    Timeline *timeline;
    DynamicLabel *activeTool;

    ToolBar *toolbar;
    QScrollArea *scrollAreaTools;

    VideoSelector *selector;
    QScrollArea *scrollAreaSelector;

    Effects *effects;
    QScrollArea *scrollAreaEffects;

    QVBoxLayout *mainLayout;

    // Populate tomeo app video access list.
    void loadVideos(const QDir dir);

private slots:

    void changeActiveTool(QString n);

};

#endif // TOMEO_H
