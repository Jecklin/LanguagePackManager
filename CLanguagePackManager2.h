#ifndef CLANGUAGEPACKMANAGER2_H
#define CLANGUAGEPACKMANAGER2_H

#include <QHash>

////// *****************   visition 2: QHash<QString, QStringList>         ***************///

class CLanguagePackManager2
{
public:
    CLanguagePackManager2();
    ~CLanguagePackManager2();
    
    enum ELanguage
    {
        English     ,
        Chinese     ,
        Japanese    ,
        Spanish
    };
    
    void            SwitchLanguage(ELanguage language);
    QStringList     GetValue(QString key);
    
    //test
    void            Test();
    
private:
    bool            ReadJson(ELanguage language);
    
    
    
    

    
private:
    QHash<QString, QStringList> m_hash;
};



#endif // CLANGUAGEPACKMANAGER2_H


////// *****************   visition 2: QHash<QString, QStringList>         ***************///
////// *****************  save : QHash<QString, QStringList>               ***************///
////// *****************  json :                                           ***************///
//{"CUCaseDialog":
//[
//    "病例列表",
//    "打开"
//],
//"CUCombinedOrCover":
//[
//    "复合",
//    "覆盖"
//],}
/// 
/// 
/// 
/// 
