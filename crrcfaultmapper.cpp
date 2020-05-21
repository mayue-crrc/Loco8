#include "crrcfaultmapper.h"
#include "qdebug.h"
#include "qvariant.h"
#include "QTime"
#include "global.h"
//#define FAULT_WINDOWS_MODE
#include "qtextcodec.h"
CrrcFaultMapper::CrrcFaultMapper(QString databaseFaultTypeName, QString databaseHistoryFaultName)
    :databaseFaultTypeName(databaseFaultTypeName),databaseHistoryFaultName(databaseHistoryFaultName)
{

}

bool CrrcFaultMapper::InsertHistoryFault(QHash<quint32,FaultBean>& inserthash)
{
#ifndef FAULT_WINDOWS_MODE

    QTime timeStart(QTime::currentTime());
    char *zErrMsg = 0;
    int rc = sqlite3_exec(databaseHistoryFault,"begin",0,0,&zErrMsg);
    foreach(unsigned short int key,inserthash.keys() )
    {

        QString ssm;
        ssm="insert into fault_history (History_ID,ID,start_time,end_time,confirm,Speed,Voltage,Current,Direction,Grade)" "values ("+QString::number(key)+","
                                                                                               +QString::number(inserthash[key].ID)+",'"
                                                                                               +inserthash[key].StartTime+"','"
                                                                                               +inserthash[key].EndTime+"','"
                                                                                               +QString::number(inserthash[key].IsConfirm)+"','"
                                                                                                +QString::number(inserthash[key].Speed,10,1)+"','"
                                                                                                +QString::number(inserthash[key].Voltage,10,1)+"','"
                                                                                                +QString::number(inserthash[key].Current,10,1)+"','"
                                                                                                +inserthash[key].Direction+"','"
                                                                                                +QString::number(inserthash[key].Grade,10,1)+"')";
#ifdef QT_VERSION_5_6
        sqlite3_exec(databaseHistoryFault,ssm.toLatin1().data(),0,0,&zErrMsg);
#else
        sqlite3_exec(databaseHistoryFault,ssm.toAscii().data(),0,0,&zErrMsg);

#endif
    }
    rc = sqlite3_exec(databaseHistoryFault,"commit;",0,0,&zErrMsg);

    if(rc != SQLITE_OK)
    {
        qDebug()<<"InsertHistoryFault error: "<<zErrMsg  << __FILE__ << __LINE__;
        return false;
    }
    //qDebug()<<"insert history fault time out: "<<timeStart.msecsTo(QTime::currentTime());

    return true;
#endif
}
bool CrrcFaultMapper::UpdateHistoryFault(QHash<quint32,FaultBean>& updatehash)
{
#ifndef FAULT_WINDOWS_MODE

    QTime timeStart(QTime::currentTime());

    char *zErrMsg = 0;
    int rc = sqlite3_exec(databaseHistoryFault,"begin",0,0,&zErrMsg);

    foreach(unsigned short int key,updatehash.keys() )
    {
        QString ssm;
        ssm = "update fault_history set end_time = '"+ updatehash[key].EndTime +"' where History_ID = "+QString::number(key);
#ifdef QT_VERSION_5_6
        sqlite3_exec(databaseHistoryFault,ssm.toLatin1().data(),0,0,&zErrMsg);
#else
        sqlite3_exec(databaseHistoryFault,ssm.toAscii().data(),0,0,&zErrMsg);
#endif
    }
    rc = sqlite3_exec(databaseHistoryFault,"commit;",0,0,&zErrMsg);

    if(rc != SQLITE_OK)
    {
        qDebug()<<"UpdateHistoryFault error: "<<zErrMsg << __FILE__ << __LINE__;
        return false;
    }
    //qDebug()<<"update history fault time out: "<<timeStart.msecsTo(QTime::currentTime());

    return true;

#endif

}

bool CrrcFaultMapper::GetNextHistoryFaultID(int &res)
{
#ifndef FAULT_WINDOWS_MODE

    int res_HistoryID = 0;
    char **dbResult  = NULL;
    char *sql = "select MAX(History_ID) from fault_history";
    char * errmsg = NULL;
    int nRow, nColumn;
    int resd = sqlite3_get_table(databaseHistoryFault, sql,&dbResult, &nRow, &nColumn, &errmsg );
    if(resd == SQLITE_OK)
    {
        res_HistoryID = QString(QLatin1String(dbResult[nColumn])).toInt();
    }else
    {
        qDebug()<<"GetNextHistoryFaultID error: "<<errmsg << __FILE__ << __LINE__;
        return false;
    }
    sqlite3_free_table(dbResult);
    res = res_HistoryID+1;
    return true;
#endif
}
void CrrcFaultMapper::GetFaultTypeHash(QHash<quint32,FaultTypeBean>& hash )
{
#ifndef FAULT_WINDOWS_MODE

    QTime stime(QTime::currentTime());
    char *sql = "select * from fault_type";
    sqlite3_stmt * stmt = NULL;
    sqlite3_exec(databaseFaultType, "BEGIN", 0, 0, NULL);
    int rc = sqlite3_prepare_v2(databaseFaultType, sql, strlen(sql), &stmt, 0);

    if(rc == SQLITE_OK)
    {
        while(sqlite3_step(stmt) != SQLITE_DONE)
        {
            FaultTypeBean faultTypeBean;
#ifdef QT_VERSION_5_6
            faultTypeBean.ID = sqlite3_column_int(stmt,0);
            //faultTypeBean.FaultName = QString::fromLatin1(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            faultTypeBean.FaultName = (reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            faultTypeBean.FaultPosition = QString::fromLatin1(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            faultTypeBean.FaultDevice = QString::fromLatin1(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
            faultTypeBean.FaultCode = QString::fromLatin1(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
            faultTypeBean.PortAddress = QString::fromLatin1(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))).toInt(NULL,16);
            faultTypeBean.ByteoffAddress = sqlite3_column_int(stmt,6);
            faultTypeBean.BitoffAddress = sqlite3_column_int(stmt,7);
            faultTypeBean.FaultDescription = (reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)));
            faultTypeBean.FaultTips = (reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9)));
            faultTypeBean.FaultValid = QString::fromLatin1(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10))) == "1" ? true : false;
            faultTypeBean.FaultLevel = sqlite3_column_int(stmt,11);
#else
            faultTypeBean.ID = sqlite3_column_int(stmt,0);
            faultTypeBean.FaultName = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            faultTypeBean.FaultPosition = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            faultTypeBean.FaultDevice = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
            faultTypeBean.FaultCode = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
            faultTypeBean.PortAddress = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))).toInt(NULL,16);
            faultTypeBean.ByteoffAddress = sqlite3_column_int(stmt,6);
            faultTypeBean.BitoffAddress = sqlite3_column_int(stmt,7);
            faultTypeBean.FaultDescription = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)));
            faultTypeBean.FaultTips = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9)));
            faultTypeBean.FaultValid = QString::fromAscii(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10))) == "1" ? true : false;
            faultTypeBean.FaultLevel = sqlite3_column_int(stmt,11);
#endif

            hash.insert(faultTypeBean.ID,faultTypeBean);

        }
    }else
    {
        qDebug()<<"GetFaultTypeHash error: "<<sqlite3_errmsg(databaseHistoryFault);

    }
    sqlite3_finalize(stmt);
    sqlite3_exec(databaseFaultType,"commit;", 0, 0, NULL);
    //qDebug()<<"get fault_type time out : "<<stime.msecsTo(QTime::currentTime())<< __FILE__ << __LINE__;;
#endif
}

bool CrrcFaultMapper::GetHistoryFault(QList<FaultBean>& historylist)
{
#ifndef FAULT_WINDOWS_MODE

    QTime stime(QTime::currentTime());
    char * errmsg = NULL;
    char *sql = "select * from fault_history  order by History_ID desc limit 3000";
    sqlite3_stmt * stmt = NULL;
    sqlite3_exec(databaseHistoryFault, "BEGIN", 0, 0, &errmsg);

    int rc = sqlite3_prepare_v2(databaseHistoryFault, sql, strlen(sql), &stmt, 0);

    if(rc == SQLITE_OK)
    {
        while(sqlite3_step(stmt) != SQLITE_DONE)
        {
            FaultBean faultBean;
            faultBean.HistoryID = sqlite3_column_int(stmt,0);
            faultBean.ID = sqlite3_column_int(stmt,1);
            faultBean.StartTime = QString(QLatin1String((char*)sqlite3_column_text(stmt,2)));
            faultBean.EndTime = QString(QLatin1String((char*)sqlite3_column_text(stmt,3)));
            faultBean.IsConfirm = QString(QLatin1String((char*)sqlite3_column_text(stmt,4))) == "1" ? true : false;
            faultBean.Speed = QString(QLatin1String((char*)sqlite3_column_text(stmt,5))).toFloat();
            faultBean.Voltage = QString(QLatin1String((char*)sqlite3_column_text(stmt,6))).toFloat();
            faultBean.Current = QString(QLatin1String((char*)sqlite3_column_text(stmt,7))).toFloat();
            faultBean.Direction = getdirections((char*)sqlite3_column_text(stmt,8));
            faultBean.Grade = QString(QLatin1String((char*)sqlite3_column_text(stmt,9))).toFloat();

            historylist.push_back(faultBean);

        }

    }else
    {
        qDebug()<<"GetHistoryFault error: "<<sqlite3_errmsg(databaseHistoryFault)<< __FILE__ << __LINE__;;
        return false;
    }

    sqlite3_finalize(stmt);
    sqlite3_exec(databaseHistoryFault,"commit;", 0, 0, NULL);
    return true;
    //qDebug()<<"get history fault time out: "<<stime.msecsTo(QTime::currentTime());

#endif
}


bool CrrcFaultMapper::GetCurrentFault(QList<FaultBean> &currentlist,QHash<quint32,FaultBean>& currenthash)
{
#ifndef FAULT_WINDOWS_MODE

        QTime stime(QTime::currentTime());
        char * errmsg = NULL;
        char *sql = "select * from fault_current";
        sqlite3_stmt * stmt = NULL;
        sqlite3_exec(databaseHistoryFault, "BEGIN", 0, 0, &errmsg);

        int rc = sqlite3_prepare_v2(databaseHistoryFault, sql, strlen(sql), &stmt, 0);

        if(rc == SQLITE_OK)
        {
            while(sqlite3_step(stmt) != SQLITE_DONE)
            {
                FaultBean faultBean;
                faultBean.HistoryID = sqlite3_column_int(stmt,0);
                faultBean.ID = sqlite3_column_int(stmt,1);
                faultBean.StartTime = QString(QLatin1String((char*)sqlite3_column_text(stmt,2)));
                faultBean.EndTime = QString(QLatin1String((char*)sqlite3_column_text(stmt,3)));
                faultBean.IsConfirm = QString(QLatin1String((char*)sqlite3_column_text(stmt,4))) == "1" ? true : false;
                faultBean.Speed = QString(QLatin1String((char*)sqlite3_column_text(stmt,5))).toFloat();
                faultBean.Voltage = QString(QLatin1String((char*)sqlite3_column_text(stmt,6))).toFloat();
                faultBean.Current = QString(QLatin1String((char*)sqlite3_column_text(stmt,7))).toFloat();
                faultBean.Direction = getdirections((char*)sqlite3_column_text(stmt,8));

                faultBean.Grade = QString(QLatin1String((char*)sqlite3_column_text(stmt,9))).toFloat();

                currentlist.push_front(faultBean);
                currenthash.insert(faultBean.ID,faultBean);
            }

        }else
        {
            qDebug()<<"GetCurrentFault error: "<<sqlite3_errmsg(databaseHistoryFault)<< __FILE__ << __LINE__;;
            return false;
        }

        sqlite3_finalize(stmt);
        sqlite3_exec(databaseHistoryFault,"commit;", 0, 0, NULL);
        //qDebug()<<"get current fault time out: "<<stime.msecsTo(QTime::currentTime());
        return true;

#endif
}

void CrrcFaultMapper::GetUnconfirmFault(QList<FaultBean> &unconfirmlist)
{
#ifndef FAULT_WINDOWS_MODE
    QTime stime(QTime::currentTime());
    char * errmsg = NULL;
    char *sql = "select * from fault_unconfirm order by History_ID";
    sqlite3_stmt * stmt = NULL;
    sqlite3_exec(databaseHistoryFault, "BEGIN", 0, 0, &errmsg);

    int rc = sqlite3_prepare_v2(databaseHistoryFault, sql, strlen(sql), &stmt, 0);

    if(rc == SQLITE_OK)
    {
        while(sqlite3_step(stmt) != SQLITE_DONE)
        {
            FaultBean faultBean;
            faultBean.HistoryID = sqlite3_column_int(stmt,0);
            faultBean.ID = sqlite3_column_int(stmt,1);
            faultBean.StartTime = QString(QLatin1String((char*)sqlite3_column_text(stmt,2)));
            faultBean.EndTime = QString(QLatin1String((char*)sqlite3_column_text(stmt,3)));
            faultBean.IsConfirm = QString(QLatin1String((char*)sqlite3_column_text(stmt,4))) == "1" ? true : false;
            faultBean.Speed = QString(QLatin1String((char*)sqlite3_column_text(stmt,5))).toFloat();
            faultBean.Voltage = QString(QLatin1String((char*)sqlite3_column_text(stmt,6))).toFloat();
            faultBean.Current = QString(QLatin1String((char*)sqlite3_column_text(stmt,7))).toFloat();
            faultBean.Direction = getdirections((char*)sqlite3_column_text(stmt,8));
            faultBean.Grade = QString(QLatin1String((char*)sqlite3_column_text(stmt,9))).toFloat();

            unconfirmlist.push_front(faultBean);
        }

    }else
    {
        qDebug()<<"GetUnconfirmFault error: "<<sqlite3_errmsg(databaseHistoryFault)<< __FILE__ << __LINE__;;
    }

    sqlite3_finalize(stmt);
    sqlite3_exec(databaseHistoryFault,"commit;", 0, 0, NULL);
    //qDebug()<<"get unconfirm fault time out: "<<stime.msecsTo(QTime::currentTime());

#endif
}

bool CrrcFaultMapper::UpdateUnconfirmFault(quint32 historyID)
{
#ifndef FAULT_WINDOWS_MODE

    QTime timeStart(QTime::currentTime());

    char *zErrMsg = 0;
    int rc = sqlite3_exec(databaseHistoryFault,"begin",0,0,&zErrMsg);

    QString ssm = "update fault_history set confirm = 1 where History_ID="+QString::number(historyID);
#ifdef QT_VERSION_5_6
    sqlite3_exec(databaseHistoryFault,ssm.toLatin1().data(),0,0,&zErrMsg);
#else
    sqlite3_exec(databaseHistoryFault,ssm.toAscii().data(),0,0,&zErrMsg);
#endif

    rc = sqlite3_exec(databaseHistoryFault,"commit;",0,0,&zErrMsg);

    if(rc != SQLITE_OK)
    {
        qDebug()<<"UpdateUnconfirmFault error: "<<zErrMsg << __FILE__ << __LINE__;
        return false;
    }
    //qDebug()<<"update unconfirm fault time out: "<<timeStart.msecsTo(QTime::currentTime());

    return true;

#endif
}
bool CrrcFaultMapper::openDatabase()
{
#ifndef FAULT_WINDOWS_MODE
    bool res = true;
#ifdef QT_VERSION_5_6
    int type_rc = sqlite3_open(databaseFaultTypeName.toLatin1().data(),&databaseFaultType);
#else
    int type_rc = sqlite3_open(databaseFaultTypeName.toAscii().data(),&databaseFaultType);
#endif
    if(type_rc)
    {
        qDebug()<< "can't open databaseFaultType: "<<sqlite3_errmsg(databaseFaultType);
        res = false;
    }
#ifdef QT_VERSION_5_6
    int history_rc = sqlite3_open(databaseHistoryFaultName.toLatin1().data(),&databaseHistoryFault);
#else
    int history_rc = sqlite3_open(databaseHistoryFaultName.toAscii().data(),&databaseHistoryFault);
#endif
    if(history_rc)
    {
        qDebug()<< "can't open databaseHistoryFault: "<<sqlite3_errmsg(databaseHistoryFault);
        res = false;
    }
    return res;
#endif
}

void CrrcFaultMapper::closeDatabase()
{
#ifndef FAULT_WINDOWS_MODE
    sqlite3_close(databaseFaultType);

    sqlite3_close(databaseHistoryFault);
#endif
}
QString CrrcFaultMapper::GetTypeDBInfo()
{
    QString Version = NULL;//,m_Timestamp,m_Description;

#ifndef FAULT_WINDOWS_MODE

    char **dbResult  = NULL;
    char *sql = "select Version from fault_version order by Version desc limit 1";
    char * errmsg = NULL;
    int nRow, nColumn;
    int res = sqlite3_get_table(databaseFaultType, sql,&dbResult, &nRow, &nColumn, &errmsg );
    if(res == SQLITE_OK)
    {
        Version = QString(QLatin1String(dbResult[nColumn]));
    }else
    {
        qDebug()<<"GetFaultTypeVersion error: "<<errmsg << __FILE__ << __LINE__;
    }
    sqlite3_free_table(dbResult);
#endif
    return Version;

}
Directions CrrcFaultMapper::getdirections(char* c)
{

    if (c == NULL)
    {
        return nullp;
    }

    Directions t_dir;
    switch (*c)
    {
    case 1:
        t_dir = forward;
        break;
    case 2:
        t_dir = backword;
        break;
    case 3:
        t_dir = zero;
        break;
    case 4:
        t_dir = nullp;
        break;
    }
    return t_dir;
}
