//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//

#include <QApplication>
#include <QDesktopServices>
#include <QImageReader>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include <QtCore/QFileInfo>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QFileIconProvider>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

#include "tomeo.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
//    app.setStyleSheet("QPushButton::setDown(true) { background-color: darkgreen }" );
    if (argc < 2) {
        const int result = QMessageBox::information (
                        NULL,
                        QString("Tomeo wants your videos!"),
                        QString("Add a command line argument to a \"quoted\" file location")
                    );
        exit(-1);
    }

    auto loc = QString::fromStdString(std::string(argv[1]));
    QDir dir(loc);

    if (!dir.exists()) {
        const int result = QMessageBox::information (
                        NULL,
                        QString("Tomeo is confused!"),
                        QString("That directory does not exist!")
                    );
        exit(-1);
    }

    // Start the video editor app with the provided directory.
    // Note: Tomeo is just a subclassed QMainWindow - our main window widget
    auto tomeo = new Tomeo(dir);
    tomeo->setWindowTitle("Tomeo");
    tomeo->setFixedSize(320, 500);
    tomeo->show();

    return app.exec();
}
