//---------------------------------------------------------------------------

#include <vcl.h>
#include "time.h"
#include <stdio>
#include <dir.h>
#include <stdlib>
#include "GlobalFunction.h"
#include "IniFile.h"
#pragma hdrstop

#include "frmMain.h"
#define BOOST_FILESYSTEM_VERSION 3
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmMain *fmMain;

extern CIniFile g_IniFile;
//---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TfmMain::btnStartClick(TObject *Sender)
{
    if (ClientSocket1->Active == false) btnStart->Caption = "Stop";
    else btnStart->Caption = "Start";
    ClientSocket1->Active=!ClientSocket1->Active;

    ClientSocket1->Host = g_IniFile.m_sReaderIP;
    ClientSocket1->Port = g_IniFile.m_nReaderPort;

    if (!FileExists("C:\\Product Data\\")) _mkdir("C:\\Product Data\\");
    bool bRead = false;
    DDX_String(bRead, g_IniFile.m_sReaderIP, this->editIP);
    DDX_String(bRead, g_IniFile.m_nReaderPort, this->editPort);
    g_IniFile.MachineFile(false);
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::AddLog(char *pRx,int nSize)
{
    AnsiString strTime;
    time_t timer;
    struct tm *tblock;

    timer = time(NULL);
    tblock = localtime(&timer);
    try
    {
        FILE *pFile;
        if (!FileExists("C:\\C76_Log\\")) _mkdir("C:\\C76_Log\\");
        strTime.sprintf("C:\\C76_Log\\%04d_%02d_%02d.txt",tblock->tm_year+1900,tblock->tm_mon+1,tblock->tm_mday);
        pFile=fopen(strTime.c_str(),"a+");
        if(pFile!=NULL)
        {
            fprintf(pFile,"\n[%2d:%02d:%02d]\n",tblock->tm_hour,tblock->tm_min, tblock->tm_sec);
            int nIndex=0;
            while(nIndex<nSize)
            {
                fprintf(pFile,"%c",pRx[nIndex]);
                nIndex++;
            }
            fclose(pFile);
        }
    }
    catch(const EAccessViolation &e)
    {
                //Application->MessageBox(e.Message.c_str(), "AddLog Exception",MB_OK);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::AddList(AnsiString strMessage, bool bIsSplit)
{
    AnsiString strMsg;
    time_t timer;
    struct tm *tblock;

    /* gets time of day */
    timer = time(NULL);
    /* converts date/time to a structure */
    tblock = localtime(&timer);

    AnsiString temptime = asctime(tblock);
    ReplaceString(&temptime, "\n", "");
    AnsiString tempstrMsg = strMessage;
    ReplaceString(&tempstrMsg, "\r", "");

    strMsg.sprintf("%s==>%s",temptime,tempstrMsg);
    //strMsg.sprintf("%s==>%s",asctime(tblock),strMessage);

    if (bIsSplit == true)
    {
        struct Data stucData = strMsgSplit(strMsg);
        listHistory->AddItem(strMsg,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    Custromer = "+stucData.Custromer,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    Supplier  = "+stucData.Supplier,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    PN        = "+stucData.PN,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    LOT       = "+stucData.LOT,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    XX        = "+stucData.XX,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    DWG       = "+stucData.DWG,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    MFGdate   = "+stucData.MFGdate,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
        listHistory->AddItem("    EXPdate   = "+stucData.EXPdate,NULL);
        listHistory->ItemIndex=listHistory->Count-1;

        editCustromer->Text = stucData.Custromer;
        editSupplier->Text = stucData.Supplier;
        editPN->Text = stucData.PN;
        editLOT->Text = stucData.LOT;
        editXX->Text = stucData.XX;
        editDWG->Text = stucData.DWG;
        editMFGdate->Text = stucData.MFGdate;
        editEXPdate->Text = stucData.EXPdate;
    }
    else
    {
        listHistory->AddItem(strMsg,NULL);
        listHistory->ItemIndex=listHistory->Count-1;
    }

    AddLog(strMessage.c_str(),strMessage.Length());
}
//---------------------------------------------------------------------------
Data __fastcall TfmMain::strMsgSplit(AnsiString strMessage)
{
    //AnsiString strMsg;
    TStringList *Tokens1 = new TStringList;
    TStringList *Tokens2 = new TStringList;
    SplitString(strMessage, ":", Tokens1);
    strMessage = Tokens1->operator [](Tokens1->Count-1);
    SplitString(strMessage, "/", Tokens2);
    struct Data TempData;
    TempData.Custromer = Tokens2->operator [](0);
    TempData.Supplier = Tokens2->operator [](1);
    TempData.PN = Tokens2->operator [](2);
    TempData.LOT = Tokens2->operator [](3);
    TempData.XX = Tokens2->operator [](4);
    TempData.DWG = Tokens2->operator [](5);
    TempData.MFGdate = Tokens2->operator [](6);
    TempData.EXPdate = Tokens2->operator [](7);

    delete Tokens1;
    delete Tokens2;
    return TempData;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SplitString(AnsiString Original, AnsiString Delim, TStrings *List)
{
    int iPos = 0;
    while( true )
    {
        iPos = Original.Pos(Delim);
        if( iPos == 0 )
            break;

        List->Append(Original.SubString(1, iPos-1));
        Original.Delete(1, iPos + Delim.Length()-1);
    }
    if( !Original.IsEmpty() )
    List->Append(Original);
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::ReplaceString(AnsiString *Original, AnsiString OldStr, AnsiString NewStr)
{
    int iPos = 0;
    while( true )
    {
        iPos = Original->Pos(OldStr);
        if( iPos == 0 )
            break;
        Original->Delete(iPos, OldStr.Length());
        Original->Insert(NewStr,iPos);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AddList("ReaderIP:"+Socket->RemoteAddress, false);
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    char xData[200]={0};
    Socket->ReceiveBuf(xData,200);

    AnsiString strMsg;
    strMsg.sprintf("����2DCode:%s ",xData);
    try
    {
        if (strMsg.Length()<20) AddList(strMsg, false);
        else AddList(strMsg, true);
    }
    catch (...)
    {
        AddList(strMsg, false);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::FormCreate(TObject *Sender)
{
    bool bRead = true;
    g_IniFile.MachineFile(bRead);
    DDX_String(bRead, g_IniFile.m_sReaderIP, this->editIP);
    DDX_String(bRead, g_IniFile.m_nReaderPort, this->editPort);

    ClientSocket1->Host = g_IniFile.m_sReaderIP;
    ClientSocket1->Port = g_IniFile.m_nReaderPort;
}
//---------------------------------------------------------------------------

