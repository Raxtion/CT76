//---------------------------------------------------------------------------


#pragma hdrstop

#include "IniFile.h"
#include <IniFiles.hpp>
#include "time.h"

#include <dir.h>
#include <stdio.h>

#define ErrorMessage_Dir "Error Message\\"
#define ErrorMessageFileName "C76ErrorMessage.ini"
#define ErrorMessageEngFileName "C76ErrorMessageEng.ini"
#define UserName "User.sis"
#define MachineFileName "C76Machine.sis"

CIniFile g_IniFile; 
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall CIniFile::CIniFile()
{

}
//---------------------------------------------------------------------------

void __fastcall CIniFile::MachineFile(bool bRead)
{
  AnsiString strFile;
  TIniFile *pIniFile;
                    
  strFile.sprintf("%s%s",IniFile_Dir,MachineFileName);
  pIniFile = new TIniFile(strFile);

 //System
  DDXFile_Int(bRead,pIniFile,System_Section,"Language",m_nLanguageMode);
  DDXFile_Int(bRead,pIniFile,System_Section,"Priviledge",m_nPriviledge);
  DDXFile_String(bRead,pIniFile,System_Section,"ARTPassword",m_strARTPassword,"CLARE");
  DDXFile_String(bRead,pIniFile,System_Section,"ENGPassword",m_strENGPassword,"123");
  //DDXFile_String(bRead,pIniFile,System_Section,"LastFileName",m_strLastFileName,"C:\\Product Data\\Default.ini");

  //Machine
  DDXFile_String(bRead,pIniFile,System_Section,"m_sReaderIP",m_sReaderIP,"192.168.100.10");
  DDXFile_Int(bRead,pIniFile,System_Section,"m_nReaderPort",m_nReaderPort,9004);

  delete pIniFile;
}
//---------------------------------------------------------------------------
void __fastcall CIniFile::ProductFile(char *strFileName,bool bRead)
{
  AnsiString strName;
  TIniFile *pIniFile;
  pIniFile = new TIniFile(strFileName);
  delete pIniFile;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CIniFile::GetErrorString(char *SectionName,int nCode)
{
  AnsiString strFileName,strErrMsg,strErrMsg1,strCode,strErrName;
  TIniFile *pIniFile;

  if(m_nLanguageMode==0) strErrName=ErrorMessageFileName;
  else strErrName=ErrorMessageEngFileName;

  strFileName.sprintf("%s%s%s",IniFile_Dir,ErrorMessage_Dir,strErrName);
  pIniFile = new TIniFile(strFileName);

  strCode.sprintf("E%04d",nCode);
  if(m_nLanguageMode==0) strErrMsg=pIniFile->ReadString(SectionName,strCode,"¥¼©w¸q¿ù»~½X!!");
  else strErrMsg=pIniFile->ReadString(SectionName,strCode,"Not Defined Error Code!!!");
  strErrMsg1.sprintf("[%s] %s=%s",SectionName,strCode,strErrMsg);
  delete pIniFile;

  return strErrMsg1+"\n";
}

