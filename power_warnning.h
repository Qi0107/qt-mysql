#ifndef POWER_WARNNING_H
#define POWER_WARNNING_H

#include <QWidget>

namespace Ui {
class power_warnning;
}

class power_warnning : public QWidget
{
    Q_OBJECT

public:
    explicit power_warnning(QWidget *parent = nullptr);
    ~power_warnning();

private:
    Ui::power_warnning *ui;
};

#endif // POWER_WARNNING_H
