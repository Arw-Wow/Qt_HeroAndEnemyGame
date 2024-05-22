#ifndef HELP_WIDGET_H
#define HELP_WIDGET_H

#include <QWidget>

namespace Ui {
class help_widget;
}

class help_widget : public QWidget
{
    Q_OBJECT

public:
    explicit help_widget(QWidget *parent = nullptr);
    ~help_widget();

private:
    Ui::help_widget *ui;
};

#endif // HELP_WIDGET_H
