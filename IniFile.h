//---------------------------------------------------------------------------

#ifndef IniFileH
#define IniFileH

#include "vcl.h"
#include <vector>
#include <list>
#include "GlobalFunction.h"


#define System_Section "System"
#define Machine_Section "Machine"
#define Product_Section "Product"


#define IniFile_Dir "C:\\Product Data\\"
#define MAX_GLUE_WITDH 100


//---------------------------------------------------------------------------
class CIniFile
{
//Variable
public:
    __fastcall CIniFile();
  //System
  int m_nLanguageMode;    //0=Chinese 1=English
  int m_nPriviledge;
  AnsiString m_strARTPassword;
  AnsiString m_strENGPassword;
  AnsiString m_strLastFileName;
  double m_dCycleTimeOut;

  //-----------------Machine
  AnsiString m_sReaderIP;
  int m_nReaderPort;

  //-----------------Product----------------- 

//Function
public:
  void __fastcall MachineFile(bool bRead);
  void __fastcall ProductFile(char *strFileName,bool bRead);
  AnsiString __fastcall GetErrorString(char *SectionName,int nCode);

};
#endif
