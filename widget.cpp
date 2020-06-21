#include "widget.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QDebug>
#include <QString>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //type=贷款类别，way=计算方式,percent=按揭成数,years=按揭年数
    type.setParent(this);
    type.addItem("商业贷款");
    type.addItem("公积金贷款");
    type.addItem("组合型贷款");

    way.setParent(this);
    way.addItem("根据面积、单价计算");
    way.addItem("根据贷款总额计算");

    percent.setParent(this);
    percent.addItem("2成");//0
    percent.addItem("2.5成");//1
    percent.addItem("3成");//2
    percent.addItem("3.5成");//3
    percent.addItem("4成");//4
    percent.addItem("4.5成");//5
    percent.addItem("5成");//6
    percent.addItem("5.5成");//7
    percent.addItem("6成");//8
    percent.addItem("6.5成");//9
    percent.addItem("7成");//10
    percent.addItem("7.5成");//11
    percent.addItem("8成");//12
      //type=贷款类别，way=计算方式,percent=按揭成数,years=按揭年数

    years.setParent(this);
    years.addItem("1年");
    years.addItem("2年");
    years.addItem("3年");
    years.addItem("4年");
    years.addItem("5年");
    years.addItem("6年");
    years.addItem("7年");
    years.addItem("8年");
    years.addItem("9年");
    years.addItem("10年");
    years.addItem("11年");
    years.addItem("12年");
    years.addItem("13年");
    years.addItem("14年");
    years.addItem("15年");
    years.addItem("16年");
    years.addItem("17年");
    years.addItem("18年");
    years.addItem("19年");
    years.addItem("20年");
    years.addItem("21年");
    years.addItem("22年");
    years.addItem("23年");
    years.addItem("24年");
    years.addItem("25年");
    years.addItem("26年");
    years.addItem("27年");
    years.addItem("28年");
    years.addItem("29年");
    years.addItem("30年");
       //how_to_pay=还款方式
    how_to_pay.setParent(this);
    how_to_pay.addItem("等额本息");
    how_to_pay.addItem("等额本金");
    //tax_1=商业贷款利率,tax_2=公积金贷款利率,price_1=商业贷款额,price_2=公积金贷款额
    tax_1.setParent(this);
    tax_1.setPlaceholderText("商业贷款利率");
    QDoubleValidator *pDfValidator = new QDoubleValidator(0, 99.99 , 2, &tax_1);
    pDfValidator->setNotation(QDoubleValidator::StandardNotation);
    tax_1.setValidator(pDfValidator);

    tax_2.setParent(this);
    tax_2.setPlaceholderText("公积金贷款利率");
    QDoubleValidator *pDfValidator_2 = new QDoubleValidator(0, 99.99 , 2, &tax_2);
    pDfValidator_2->setNotation(QDoubleValidator::StandardNotation);
    tax_2.setValidator(pDfValidator_2);

    price_1.setParent(this);
    price_1.setPlaceholderText("商业贷款额");
    price_1.setValidator(new QIntValidator(&price_1));
    price_1.setMaxLength(6);

    price_2.setParent(this);
    price_2.setPlaceholderText("公积金贷款额");
    price_2.setValidator(new QIntValidator(&price_2));
    price_2.setMaxLength(6);

    //area=房屋面积，s_price=房屋单价
    area.setParent(this);
    area.setPlaceholderText("房屋面积");
    area.setValidator(new QIntValidator(&area));
    area.setMaxLength(4);

    s_price.setParent(this);
    s_price.setPlaceholderText("房屋单价");
    s_price.setValidator(new QIntValidator(&price_1));
    s_price.setMaxLength(6);

    calculation.setParent(this);
    calculation.setText("开始计算");

    reset.setParent(this);
    reset.setText("全部清空");

    //各类文本框,mon_pay,less_mon,borrow,tax,pay,month,tax_11,tax_21,price_11,price_21,area1,s_price1,type1,way1,percent1,years1,how_to_pay1;
    month.setParent(this);
   month.setText("还款月数");
    month.move(0,340);
    l1.setParent(this);

    l1.move(100,340);
    l1.setText("                         ");

    mon_pay.setParent(this);
    mon_pay.setText("首月月供");
    mon_pay.move(0,370);
    l2.setParent(this);
    l2.move(100,370);
    l2.setText("                         ");

    less_mon.setParent(this);
    less_mon.setText("每月月供减少（等额本息下恒为0）");
    less_mon.move(0,400);
    l3.setParent(this);
    l3.move(200,400);
    l3.setText("                         ");

    borrow.setParent(this);
    borrow.setText("借款总额");
    borrow.move(0,430);
    l4.setParent(this);
    l4.move(100,430);
    l4.setText("                         ");
    tax.setParent(this);
    tax.setText("支付利息");
    tax.move(0,460);
    l5.setParent(this);
    l5.move(100,460);
    l5.setText("                         ");

    pay.setParent(this);
    pay.setText("还款总额");
    pay.move(0,490);
    l6.setParent(this);
    l6.move(100,490);
    l6.setText("                         ");

    tax_11.setParent(this);
    tax_11.setText("商业贷款利率：                      %");
    tax_11.move(20,230);

    tax_21.setParent(this);
    tax_21.setText("公积金贷款利率                      %");
    tax_21.hide();

    price_11.setParent(this);
    price_11.setText("商业贷款总额：                      万元");
    price_11.hide();

    price_21.setParent(this);
    price_21.setText("公积金贷款总额                      万元");
    price_21.hide();

    area1.setParent(this);
    area1.setText("房屋面积：                          平方米");
    area1.move(20,140);

    s_price1.setParent(this);
    s_price1.setText("房屋单价：                          元/平方米");
    s_price1.move(20,110);

    type1.setParent(this);
    type1.setText("贷款类别：");
    type1.move(20,50);

    way1.setParent(this);
    way1.setText("计算方式：");
    way1.move(20,80);

    percent1.setParent(this);
    percent1.setText("按揭成数：");
    percent1.move(20,170);


    years1.setParent(this);
    years1.setText("按揭年数：");
    years1.move(20,200);

    how_to_pay1.setParent(this);
    how_to_pay1.setText("还款方式：");
    how_to_pay1.move(20,260);
    //所有组件生成完毕，进行界面初始化
    //初始界面需要隐藏的有 tax_2,price_1,price_2
    tax_2.hide();
    price_1.hide();
    price_2.hide();

    //调整控件位置
    type.move(100,50);
    way.move(100,80);
    s_price.move(100,110);
    area.move(100,140);
    percent.move(100,170);
    years.move(100,200);
    tax_1.move(100,230);
    how_to_pay.move(100,260);
    calculation.move(100,310);
    reset.move(200,310);

    //设置控件：“贷款类别”
    // connect(&b(控件地址),&QPushButton::clicked（监测信号）,this（反馈控件地址）,&SubWidget::sendSlot（执行函数）);
    connect(&type,SIGNAL(currentIndexChanged(int)),this,SLOT(change_type()));

    //设置控件：“计算方式”
    connect(&way,SIGNAL(currentIndexChanged(int)),this,SLOT(change_way()));


    //设置控件：“计算结果”
    connect(&calculation,SIGNAL(clicked(bool)),this,SLOT(circulation_choose()));//回头记得添加警告

    //设置控件：“清空所有”
    connect(&reset,SIGNAL(clicked(bool)),this,SLOT(clean_all()));



}
void Widget::clean_all()
{
    tax_1.clear();
    tax_2.clear();
    price_1.clear();
    price_2.clear();
    s_price.clear();
    area.clear();
}

void Widget::change_way()//计算方式的选择带来的控件变化
{
    switch (way.currentIndex()) {
    case 0:
        price_1.hide();
        price_2.hide();
        price_11.hide();
        price_21.hide();
        area.show();
        area.move(100,140);
        area1.show();
        area1.move(20,140);
        s_price.show();
        s_price.move(100,110);
        s_price1.show();
        s_price1.move(20,110);

        break;
    case 1:
        area.hide();
        area1.hide();
        s_price.hide();
        s_price1.hide();
        if(type.currentIndex()==0)
        {
            price_1.show();
            price_1.move(100,110);
            price_11.show();
            price_11.move(20,110);
        }
           else if (type.currentIndex()==1)
        {
            price_2.show();
            price_2.move(100,110);
            price_21.show();
            price_21.move(20,110);
        }

        break;
    }
}
void Widget::hide_all()//隐藏除贷款类别以外的全部控件
{
   /* QPushButton calculation,reset;
    QLineEdit tax_1,tax_2,price_1,price_2,area,s_price;
    QComboBox type,way,percent,years,how_to_pay;*/
    calculation.hide();
    reset.hide();
    tax_1.hide();
    tax_11.hide();

    tax_2.hide();
    tax_21.hide();
    price_1.hide();
    price_11.hide();

    price_2.hide();
    price_21.hide();
    area.hide();
    area1.hide();
    s_price.hide();
    s_price1.hide();
    way.hide();
    way1.hide();
    percent.hide();
    percent1.hide();
    years.hide();
    years1.hide();
    how_to_pay.hide();
    how_to_pay1.hide();
}

void Widget::change_type()//改变贷款方式时，所执行的函数
{
    switch (type.currentIndex()) {
    case 0://商业贷款
    hide_all();
    way.show();
    way.move(100,80);
    way1.show();
    way1.move(20,80);
    change_way();//用change_way函数保证计算方式改变时控件正确显示
    percent.show();
    percent.move(100,170);
    percent1.show();
    percent1.move(20,170);
    years.show();
    years.move(100,200);
    years1.show();
    years1.move(20,200);
    tax_1.show();
    tax_1.move(100,230);
    tax_11.show();
    tax_11.move(20,230);
    how_to_pay.show();
    how_to_pay.move(100,260);
    how_to_pay1.show();
    how_to_pay1.move(20,250);
    calculation.show();
    calculation.move(100,310);
    reset.show();
    reset.move(200,310);
        break;
    case 1://公积金贷款
        hide_all();
        way.show();
        way.move(100,80);
        way1.show();
        way1.move(20,80);
        change_way();
        percent.show();
        percent.move(100,170);
        percent1.show();
        percent1.move(20,170);
        years.show();
        years.move(100,200);
        years1.show();
        years1.move(20,200);
        tax_2.show();
        tax_2.move(100,230);
        tax_21.show();
        tax_21.move(20,230);
        how_to_pay.show();
        how_to_pay.move(100,260);
        how_to_pay1.show();
        how_to_pay1.move(20,260);
        calculation.show();
        calculation.move(100,310);
        reset.show();
        reset.move(200,310);

        break;

    case 2://组合型贷款
        hide_all();
        price_1.show();
        price_1.move(100,80);
        price_11.show();
        price_11.move(20,80);
        tax_1.show();
        tax_1.move(100,110);
        tax_11.show();
        tax_11.move(20,110);
        price_2.show();
        price_2.move(100,140);
        price_21.show();
        price_21.move(20,140);
        tax_2.show();
        tax_2.move(100,170);
        tax_21.show();
        tax_21.move(20,170);
        years.show();
        years.move(100,200);
        years1.show();
        years1.move(20,200);
        how_to_pay.show();
        how_to_pay.move(100,230);
        how_to_pay1.show();
        how_to_pay1.move(20,230);
        calculation.show();
        calculation.move(100,280);
        reset.show();
        reset.move(200,280);
        break;



    }
}

void Widget::circulation_choose()//贷款方式不同，选择不同函数
{
    //qDebug()<<"wot";
    if(type.currentIndex()==2) mix_calculation_result();
    else calculation_result();
}

void Widget::mix_calculation_result()
{
    //此函数用于混合贷款

    double pay_money_1=0,pay_money_2=0,pay_tax_1=0,pay_tax_2=0,house_money_1=0,house_money_2=0,month_money_1=0,month_money_2=0,rate_1=0,rate_2=0,less_money_1=0,less_money_2=0;
    int year=0;

    year=years.currentIndex()+1;
    //需要获取house_money,rate

         house_money_1=price_1.text().toInt()*10000;
         house_money_2=price_2.text().toInt()*10000;


        rate_1= tax_1.text().toDouble()/1200;
        rate_2= tax_2.text().toDouble()/1200;

    if(how_to_pay.currentIndex()==0)
    {
/*每月还本付息金额 =[ 本金 x 月利率 x(1+月利率)贷款月数 ] / [(1+月利率)还款月数 - 1]
还款总利息=贷款额*贷款月数*月利率*（1+月利率）贷款月数/【（1+月利率）还款月数 - 1】-贷款额
还款总额=还款月数*贷款额*月利率*（1+月利率）贷款月数/【（1+月利率）还款月数 - 1】*/
    month_money_1=(house_money_1*rate_1*pow((1+rate_1),year*12))/(pow((1+rate_1),year*12)-1);
    //month_money=(house_money*rate*pow((1+rate),year*12))/(pow((1+rate),year*12)-1);
    pay_tax_1=house_money_1*year*12*rate_1*pow((1+rate_1),year*12)/(pow((1+rate_1),year*12)-1)-house_money_1;
    pay_money_1=pay_tax_1+house_money_1;

    month_money_2=(house_money_2*rate_2*pow((1+rate_2),year*12))/(pow((1+rate_2),year*12)-1);
    pay_tax_2=house_money_2*year*12*rate_2*pow((1+rate_2),year*12)/(pow((1+rate_2),year*12)-1)-house_money_2;
    pay_money_2=pay_tax_2+house_money_2;




    }
    /*每月还本付息金额=(本金/还款月数)+(本金-累计已还本金)×月利率

每月本金=总本金/还款月数

每月利息=(本金-累计已还本金)×月利率

  还款总利息=（还款月数+1）*贷款额*月利率/2

还款总额=(还款月数+1)*贷款额*月利率/2+贷款额 tax
*/
    else
    {
        month_money_1=(house_money_1/(year*12))+(house_money_1)*rate_1;//此处并非每月还款，为首月还款
        less_money_1=house_money_1/(year*12)*rate_1;
        pay_tax_1=(year*12+1)*rate_1*house_money_1/2;
        pay_money_1=pay_tax_1+house_money_1;

        month_money_2=(house_money_2/(year*12))+(house_money_2)*rate_2;//此处并非每月还款，为首月还款
        //month_money=(house_money/(year*12))+(house_money)*rate;
        less_money_2=house_money_2/(year*12)*rate_2;
        pay_tax_2=(year*12+1)*rate_2*house_money_2/2;
        pay_money_2=pay_tax_2+house_money_2;
    }

    /*mon_pay.setText("首月月供："+QString::number(month_money_1+month_money_2));
    less_mon.setText("每月月供减少（等额本息下恒为0）:"+QString::number(less_money_1+less_money_2));
    borrow.setText("借款总额："+QString::number(house_money_1+house_money_2));
    tax.setText("支付利息："+QString::number(pay_tax_1+pay_tax_2));
    pay.setText("还款总额:"+QString::number(pay_money_1+pay_money_2));
    month.setText("还款月数："+QString::number(year*12));*/
    l2.setText(QString::number(month_money_1+month_money_2));
    l3.setText(QString::number(less_money_1+less_money_2));
    l4.setText(QString::number(house_money_1+house_money_2));
    l5.setText(QString::number(pay_tax_1+pay_tax_2));
    l6.setText(QString::number(pay_money_1+pay_money_2));
    l1.setText(QString::number(year*12));
}


void Widget::calculation_result()
{
    //此函数用于非混合贷款

    double pay_money=0,pay_tax=0,house_money=0,month_money=0,rate=0,less_money=0;
    int year=0;

    year=years.currentIndex()+1;
    qDebug()<<year;
    //需要获取house_money,rate
    if(way.currentIndex()==0)
    {
        house_money=s_price.text().toInt()*area.text().toInt()*(double)(2+0.5*percent.currentIndex())/10;
        qDebug()<<house_money;
    }
    else
    {
        if(type.currentIndex()==0)
        {
            house_money=price_1.text().toInt()*10000;
        }
        else
        {
            house_money=price_2.text().toInt()*10000;
        }
    }
    if(type.currentIndex()==0)
    {
        rate= tax_1.text().toDouble()/1200;
        //qDebug()<<rate;
    }
    else rate=tax_2.text().toDouble()/1200;


    if(how_to_pay.currentIndex()==0)
    {
/*每月还本付息金额 =[ 本金 x 月利率 x(1+月利率)^贷款月数 ] / [(1+月利率)^还款月数 - 1]
还款总利息=贷款额*贷款月数*月利率*（1+月利率）贷款月数/【（1+月利率）还款月数 - 1】-贷款额
还款总额=还款月数*贷款额*月利率*（1+月利率）贷款月数/【（1+月利率）还款月数 - 1】*/
    month_money=(house_money*rate*pow((1+rate),year*12))/(pow((1+rate),year*12)-1);
    qDebug()<<month_money;
    pay_tax=house_money*year*12*rate*pow((1+rate),year*12)/(pow((1+rate),year*12)-1)-house_money;
    pay_money=pay_tax+house_money;


    }
    /*每月还本付息金额=(本金/还款月数)+(本金-累计已还本金)×月利率

每月本金=总本金/还款月数

每月利息=(本金-累计已还本金)×月利率

  还款总利息=（还款月数+1）*贷款额*月利率/2

还款总额=(还款月数+1)*贷款额*月利率/2+贷款额 tax
*/
    else
    {
        month_money=(house_money/(year*12))+(house_money)*rate;//此处并非每月还款，为首月还款
        less_money=house_money/(year*12)*rate;
        pay_tax=(year*12+1)*rate*house_money/2;
        pay_money=pay_tax+house_money;

    }

//mon_pay,less_mon,borrow,tax,pay,month,
    l2.setText(QString::number(month_money));
    l3.setText(QString::number(less_money));
    l4.setText(QString::number(house_money));
    l5.setText(QString::number(pay_tax));
    l6.setText(QString::number(pay_money));
    l1.setText(QString::number(year*12));

}
Widget::~Widget()
{

}
