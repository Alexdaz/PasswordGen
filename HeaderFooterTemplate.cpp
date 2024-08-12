//---------------------------------------------------------------------------
#include <random>

#include <fmx.h>

#ifdef __ANDROID__
#include <FMX.Helpers.Android.hpp>
#include <Androidapi.JNIBridge.hpp>
#include <Androidapi.JNI.Os.hpp>
#include <Androidapi.JNI.JavaTypes.hpp>
#include <Androidapi.JNI.GraphicsContentViewText.hpp>
#include <Androidapi.JNI.Util.hpp>
#include <Androidapi.JNI.App.hpp>
#include <Androidapi.JNI.Embarcadero.hpp>
#include <Androidapi.Jni.hpp>
#endif

#pragma hdrstop

#include "HeaderFooterTemplate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.SmXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.Moto360.fmx", _PLAT_ANDROID)
#pragma resource ("*.SSW3.fmx", _PLAT_ANDROID)
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.XLgXhdpiTb.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiTb.fmx", _PLAT_ANDROID)

THeaderFooterForm *HeaderFooterForm;

//---------------------------------------------------------------------------
std::string RandomPassword(uint Chars, std::string pass)
{
    if (pass.empty())
    {
    	ShowMessage("Por favor selecciona que propiedas tiene la contraseña.");
        return EMPTY;
    }

    std::string result = EMPTY;

    std::random_device rd;
    std::mt19937 randNumberGen(rd());
    
    while (result.length() < Chars)
    {
        result += pass[randNumberGen() % pass.length()];
    }
    pass.clear();

    return result;
}
//---------------------------------------------------------------------------

__fastcall THeaderFooterForm::THeaderFooterForm(TComponent* Owner)
	: TForm(Owner)
{
    #ifdef __ANDROID__
    TAndroidHelper::Activity->getWindow()->setStatusBarColor(COLORBAR);
    #endif
}
//---------------------------------------------------------------------------

void __fastcall THeaderFooterForm::btnCopyClick(TObject *Sender)
{
    edtPassword->SelectAll();
    edtPassword->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall THeaderFooterForm::btnDeleteClick(TObject *Sender)
{
    edtPassword->Text = EMPTY;
    nbValue->Value = MINVALUE;
}
//---------------------------------------------------------------------------

void __fastcall THeaderFooterForm::btnGenPasswordClick(TObject *Sender)
{
    if (nbValue->Value < MINVALUE)
    {
        edtPassword->Text = EMPTY;
        nbValue->Value = MINVALUE;
        ShowMessage((UnicodeString)"No se pueden ingresar valores menores a " + MINVALUE + (UnicodeString)".");
    }
    else
    {
    	std::string tpass = EMPTY;

        //Password options.
        if (swChars->IsChecked)   { tpass.append("!#%+{}[]()<>:=?@");           }
        if (swNumbers->IsChecked) { tpass.append("1234567890");                 }
        if (swUpper->IsChecked)   { tpass.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ"); }
        if (swLower->IsChecked)   { tpass.append("abcdefghijklmnopqrstuvwxyz"); }

        edtPassword->Text = RandomPassword(nbValue->Value, tpass).c_str();
    }
}
//---------------------------------------------------------------------------

