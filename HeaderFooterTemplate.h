//---------------------------------------------------------------------------

#ifndef HeaderFooterTemplateH
#define HeaderFooterTemplateH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.EditBox.hpp>
#include <FMX.NumberBox.hpp>

#define EMPTY ""
#define COLORBAR -16346689
#define MINVALUE 8
//---------------------------------------------------------------------------
class THeaderFooterForm : public TForm
{
__published:	// IDE-managed Components
	TToolBar *Header;
	TToolBar *Footer;
	TLabel *HeaderLabel;
	TButton *btnDelete;
	TButton *btnCopy;
	TEdit *edtPassword;
	TNumberBox *nbValue;
	TButton *btnGenPassword;
	TLayout *ParentLayout;
	TLayout *Length;
	TLabel *lblLength;
	TLayout *GB1;
	TLayout *Uppercase;
	TLabel *lblUpper;
	TLayout *GB2;
	TLayout *Lowercase;
	TLayout *Password;
	TLabel *lblLower;
	TSwitch *swLower;
	TSwitch *swUpper;
	TLayout *Numbers;
	TLabel *lblNumbers;
	TSwitch *swNumbers;
	TLayout *SpecialChars;
	TLabel *lblSpecialChars;
	TSwitch *swChars;
	void __fastcall btnCopyClick(TObject *Sender);
	void __fastcall btnDeleteClick(TObject *Sender);
	void __fastcall btnGenPasswordClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THeaderFooterForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THeaderFooterForm *HeaderFooterForm;
//---------------------------------------------------------------------------
#endif
