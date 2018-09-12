#ifndef CLANGUAGEPACKMANGER2_H
#define CLANGUAGEPACKMANGER2_H

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
    
    void            SwitchLanguage(ELanguage language);
    QStringList     GetValue(QString key);
    
    //test
    void            Test();
    
private:
    bool            ReadJson(ELanguage language);
    

    
private:
    QHash<QString, QStringList> m_hash;
};



#endif // CLANGUAGEPACKMANGER2_H


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
