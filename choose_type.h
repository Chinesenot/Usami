#ifndef CHOOSE_TYPE_H
#define CHOOSE_TYPE_H

#include <QWidget>
#include <QComboBox>
#include "widget.h"

class choose_type : public QComboBox
{
    Q_OBJECT
public:
    explicit choose_type(QComboBox *parent = nullptr);

private:

signals:

public slots:
};

#endif // CHOOSE_TYPE_H
