#include "button_exit.h"


button_exit::button_exit(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    this->setIconSize(QSize(40,30));
    this->setIcon(QIcon(":/icons/close.png"));
    makeConnections();
}

void button_exit::exit(){

    label = new QLabel("Are you sure to close this app?");
    exit_widget->setWindowTitle("exit");
    exit_widget->setMinimumSize(250,100);


    QHBoxLayout *buttons = new QHBoxLayout();
    closeButton -> setText("close");
    cancelButton-> setText("cancel");
    buttons->addWidget(closeButton);
    buttons->addWidget(cancelButton);

    QVBoxLayout *container = new QVBoxLayout();
    container->addWidget(label);
    container->addLayout(buttons);
    exit_widget->setLayout(container);
    exit_widget->show();
}
void button_exit::close(){
    ::exit(1);
}

void button_exit::cancel(){
    exit_widget->close();
}


void button_exit::makeConnections(){
    connect(this,SIGNAL(clicked()),this,SLOT(exit()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
}
