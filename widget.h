#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QLabel>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void change_way();
    void hide_all();
    void change_type();
    void calculation_result();
    void mix_calculation_result();
    void circulation_choose();
    void clean_all();
private:
    QPushButton calculation,reset;
    QLineEdit tax_1,tax_2,price_1,price_2,area,s_price;
    QLabel tax_11,tax_21,price_11,price_21,area1,s_price1,type1,way1,percent1,years1,how_to_pay1;
    QComboBox type,way,percent,years,how_to_pay;
    QLabel mon_pay,less_mon,borrow,tax,pay,month;
    QLabel l1,l2,l3,l4,l5,l6;

};

#endif // WIDGET_H
