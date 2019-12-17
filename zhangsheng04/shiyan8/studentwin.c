#include "myWeiget.h"
#include "studentinfo.h"
#include "studentwin.h"
#include "dbawin.h"
#include "tushuku.h"
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>

stdwin::stdwin(QWidget *parent)
    :QWidget(parent),std1(QObject::tr("请输入书名"),this),
      std2(QObject::tr("请输入书号"),this),std3(QObject::tr("请输入书的出版社"),this),
      stdfbno(this),stdfbname(this),stdfbpublication(this),fbbegin(QObject::tr("查询"),this)
{
    std1.setGeometry(40,30,110,30);
    std2.setGeometry(40,90,110,30);
    std3.setGeometry(40,150,140,30);

    QFont font("Aharoni",26);
    QFont font2("Aharoni",19);
    stdfbname.setFont(font2);
    stdfbno.setFont(font2);
    stdfbpublication.setFont(font2);

    fbbegin.setGeometry(QRect(150,200,100,40));
    stdfbname.setGeometry(QRect(180,30,160,30));
    stdfbno.setGeometry(QRect(180,90,160,30));
    stdfbpublication.setGeometry(QRect(180,150,160,30));
    connect(&fbbegin,SIGNAL(clicked(void)),this,SLOT(lookfor_slots(void)));
}
void stdwin::lookfor_slots()
{
    QString bno=stdfbno.text().trimmed();
    QString bpubl=stdfbpublication.text().trimmed();
    QString bname = stdfbname.text();

if(bno.isEmpty())
{
    if((!bname.isEmpty())&&(!bpubl.isEmpty()))
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM book WHERE 书名=:bname AND 出版社=:bpubl");
        query.bindValue(":bname",bname);
        query.bindValue(":bpubl",bpubl);
        query.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);
        QTableView *view = new QTableView;
        view->setModel(model);
        view->show();}
    if(bname.isEmpty()&&(!bpubl.isEmpty()))
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM book WHERE 出版社=:bpubl");
        query.bindValue(":bpubl",bpubl);
        query.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);
        QTableView *view = new QTableView;
        view->setModel(model);
        view->show();}
    if((!bname.isEmpty())&&bpubl.isEmpty())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM book WHERE 书名=:bname");
        query.bindValue(":bname",bname);
        query.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);
        QTableView *view = new QTableView;
        view->setModel(model);
        view->show();}
}
else
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM book WHERE 书号=:bno ");
        query.bindValue(":bno",bno);
        query.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);
        QTableView *view = new QTableView;
        view->setModel(model);
        view->show();
    }
}
