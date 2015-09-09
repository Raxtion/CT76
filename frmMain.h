//---------------------------------------------------------------------------

#ifndef frmMainH
#define frmMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ScktComp.hpp>

struct Data
{
    AnsiString Custromer;
    AnsiString Supplier;
    AnsiString PN;
    AnsiString LOT;
    AnsiString XX;
    AnsiString DWG;
    AnsiString MFGdate;
    AnsiString EXPdate;
};
//---------------------------------------------------------------------------
class TfmMain : public TForm
{
__published:	// IDE-managed Components
    TListBox *listHistory;
    TBitBtn *btnStart;
    TClientSocket *ClientSocket1;
    TEdit *editCustromer;
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *editSupplier;
    TLabel *Label3;
    TEdit *editPN;
    TLabel *Label4;
    TEdit *editLOT;
    TLabel *Label5;
    TEdit *editXX;
    TLabel *Label6;
    TEdit *editDWG;
    TLabel *Label8;
    TEdit *editMFGdate;
    TLabel *Label7;
    TEdit *editEXPdate;
    TEdit *editIP;
    TEdit *editPort;
    TLabel *Label9;
    TLabel *Label10;

    void __fastcall btnStartClick(TObject *Sender);
    void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
    Data __fastcall TfmMain::strMsgSplit(AnsiString strMessage);
    void __fastcall TfmMain::SplitString(AnsiString Original, AnsiString
      Delim, TStrings *List);
    void __fastcall TfmMain::ReplaceString(AnsiString *Original, AnsiString
      OldStr, AnsiString NewStr);
public:		// User declarations
    __fastcall TfmMain(TComponent* Owner);
    void __fastcall TfmMain::AddList(AnsiString strMessage, bool bIsSplit);
    void __fastcall TfmMain::AddLog(char *pRx,int nSize);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
