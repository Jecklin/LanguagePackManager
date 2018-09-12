#ifndef CLANGUAGEPACKMANAGER_H
#define CLANGUAGEPACKMANAGER_H

#include <QHash>


class CLanguagePackManager
{
public:
    CLanguagePackManager();         //The default language pack is English
    ~CLanguagePackManager();
    
    enum ELanguage
    {
        English     ,
        Chinese     ,
        Japanese    ,
        Spanish
    };
    
public:
    ///
    /// \brief SwitchLanguage : This function is used to switch languages
    /// \param language       : This parameter specifies the language you want to switch
    /// \return               : Successful toggle returns true
    ///
    bool            SwitchLanguage(ELanguage language);
    ///
    /// \brief GetValue       : This function is used to get values based on the key
    /// \param key            : This parameter is used to specify the key
    /// \return               : Returns the value corresponding to the key
    ///
    QString         GetValue(QString key);
    
    
    
    //test
    void            Test();
    
private:
    bool            ReadJson(ELanguage language);
    

    
private:
    QHash<QString, QString> m_hash;
};


#endif // CLANGUAGEPACKMANAGER_H

////// *****************   visition 1: QHash<QString, QString>             ***************///
////// *****************  save : QHash<QString, QStringList>               ***************///
////// *****************  json :                                           ***************///
//Chinese.json
//{
//    "1": "确定",
//    "2":"取消"
//}


//English".json
//{
//    "1": "确定",
//    "2":"取消"
//}	

/// 

