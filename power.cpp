#include "power.h"
#include "ui_power.h"

power::power(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::power)
{
    ui->setupUi(this);
}

power::~power()
{
    delete ui;
}
