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
    
    //test
    void    Test();
    
private:
    bool    ReadJson(ELanguage language);
    

    
private:
    QHash<QString, QString> m_hash;
};

#endif // CLANGUAGEPACKMANAGER_H
