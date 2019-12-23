#ifndef STUDENTWIN_H
#define STUDENTWIN_H
#include<QtGui>
class stdwin:public QWidget
{
    Q_OBJECT
public slots:
    void lookfor_slots(void);
public:
    stdwin(QWidget *parent=0);
public:
    QLabel std1,std2,std3;
    QPushButton fbbegin;
    QLineEdit stdfbno,stdfbname,stdfbpublication;
};


#endif // STUDENTWIN_H

