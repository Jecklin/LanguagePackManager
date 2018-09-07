#ifndef CLANGUAGEPACKMANAGER_H
#define CLANGUAGEPACKMANAGER_H

#include <QHash>


class CLanguagePackManager
{
public:
    CLanguagePackManager();
    ~CLanguagePackManager();
    
    enum ELanguage
    {
        English     ,
        Chinese     ,
        Japanese    ,
        Spanish
    };
    
    void    SwitchLanguage(ELanguage language);
    QString GetValue(QString key);
    
private:
    bool    ReadJson(ELanguage language);
    //test
    void    Test();
    
private:
    QHash<QString, QString> m_hash;
};

#endif // CLANGUAGEPACKMANAGER_H
