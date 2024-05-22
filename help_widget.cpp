#include "help_widget.h"
#include "ui_help_widget.h"

help_widget::help_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help_widget)
{
    ui->setupUi(this);
}

help_widget::~help_widget()
{
    delete ui;
}
