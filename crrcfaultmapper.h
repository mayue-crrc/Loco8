#ifndef CRRCFAULTMAPPER_H
#define CRRCFAULTMAPPER_H

#include "faultbean.h"
#include "faulttypebean.h"
#include "qhash.h"
#include "qlist.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <sqlite3.h>

class CrrcFaultMapper
{
public:
    CrrcFaultMapper(QString databaseFaultTypeName, QString databaseHistoryFaultName);
    bool InsertHistoryFault(QHash<quint32,FaultBean>& inserthash);
    bool UpdateHistoryFault(QHash<quint32,FaultBean>& updatehash);
    bool GetNextHistoryFaultID(int &res);
    bool GetHistoryFault(QList<FaultBean>& historylist);
    bool GetCurrentFault(QList<FaultBean>& currentlist,QHash<quint32,FaultBean>& currenthash); //<fault_ID,bean>
    void GetFaultTypeHash(QHash<quint32,FaultTypeBean>& hash);     //<fault_ID,bean>
    bool UpdateUnconfirmFault(quint32 historyID);
    void GetUnconfirmFault(QList<FaultBean> &unconfirmlist);
    QString GetTypeDBInfo();

    bool openDatabase();
    void closeDatabase();



private:
    //QSqlDatabase databaseFaultType,databaseHistoryFault;
    const QString databaseFaultTypeName,databaseHistoryFaultName;
    sqlite3* databaseFaultType;
    sqlite3* databaseHistoryFault;

    Directions getdirections(char* c);

};

#endif // CRRCFAULTMAPPER_H
