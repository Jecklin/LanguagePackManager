#include <QCoreApplication>
#include "CLanguagePackManager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    CLanguagePackManager manger;
    manger.SwitchLanguage(CLanguagePackManager::Chinese);
    manger.Test();
    
    qDebug() << "GetValue():";
    QStringList list = manger.GetValue("CUDlgToothInfo");
    QStringList::const_iterator iter = list.constBegin();
    while (iter != list.constEnd())
    {
        qDebug() << *iter;
        ++iter;
    }
    
    return a.exec();
}
