#include "power_warnning.h"
#include "ui_power_warnning.h"

power_warnning::power_warnning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::power_warnning)
{
    ui->setupUi(this);
}

power_warnning::~power_warnning()
{
    delete ui;
}
