#ifndef CLANGUAGEPACKMANAGER3_H
#define CLANGUAGEPACKMANAGER3_H

#include <QHash>

////// *****************   visition 3: 单例模式            ***************///

class CLanguagePackManager
{
public:
    
    enum ELanguage
    {
        English     ,
        Chinese     ,
        Japanese    ,
        Spanish
    };
    
    ///
    /// \brief getInstance
    /// \return 
    ///
    static CLanguagePackManager* getInstance();
    
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
    CLanguagePackManager();         //The default language pack is English
    ~CLanguagePackManager(); 
    

    bool            ReadJson(ELanguage language);
    void            InitLanguage();
    
    
    
private:
    QHash<QString, QString>         m_hash;
    static CLanguagePackManager     m_manager;
};


#endif // CLANGUAGEPACKMANAGER3_H
