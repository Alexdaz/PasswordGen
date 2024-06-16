//---------------------------------------------------------------------------
#include <cstdlib>
#include <string>

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

#define EMPTY ""
#define COLORBAR -16346689
#define MINVALUE 8

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

typedef unsigned int uint;

//---------------------------------------------------------------------------
std::string RandomPassword(uint Chars, std::string pass)
{
    std::string result = EMPTY;

    while (result.length() < Chars)
    {
        result += pass[rand() % pass.length()];
    }
    pass = EMPTY;

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
        auto numChars = nbValue->Text.ToInt();

    	std::string str = EMPTY;

        //Password options.
        if (swUpper->IsChecked && swLower->IsChecked && swNumbers->IsChecked && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        }
        else if (swUpper->IsChecked && swLower->IsChecked && swNumbers->IsChecked && !(swChars->IsChecked)) {
            str = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        }
        else if (swUpper->IsChecked && swLower->IsChecked && !(swNumbers->IsChecked) && !(swChars->IsChecked)) {
            str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        }
        else if (!(swUpper->IsChecked) && swLower->IsChecked && !(swNumbers->IsChecked) && !(swChars->IsChecked)) {
            str = "abcdefghijklmnopqrstuvwxyz";
        }
        else if (swUpper->IsChecked && swLower->IsChecked && !(swNumbers->IsChecked) && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        }
        else if (swUpper->IsChecked && !(swLower->IsChecked) && !(swNumbers->IsChecked) && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }
        else if (!(swUpper->IsChecked) && swLower->IsChecked && !(swNumbers->IsChecked) && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@abcdefghijklmnopqrstuvwxyz";
        }
        else if (!(swUpper->IsChecked) && !(swLower->IsChecked) && swNumbers->IsChecked && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@1234567890";
        }
        else if (!(swUpper->IsChecked) && !(swLower->IsChecked) && !(swNumbers->IsChecked) && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@";
        }
        else if (swUpper->IsChecked && !(swLower->IsChecked) && swNumbers->IsChecked && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }
        else if (swUpper->IsChecked && swLower->IsChecked && !(swNumbers->IsChecked) && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@1234567890abcdefghijklmnopqrstuvwxyz";
        }
        else if (!(swUpper->IsChecked) && swLower->IsChecked && swNumbers->IsChecked && !(swChars->IsChecked)) {
            str = "1234567890abcdefghijklmnopqrstuvwxyz";
        }
        else if (swUpper->IsChecked && !(swLower->IsChecked) && swNumbers->IsChecked && !(swChars->IsChecked)) {
            str = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }
        else if (!(swUpper->IsChecked) && swLower->IsChecked && swNumbers->IsChecked && swChars->IsChecked) {
            str = "!#%+{}[]()<>:=?@1234567890abcdefghijklmnopqrstuvwxyz";
        }
        else if (!(swUpper->IsChecked) && !(swLower->IsChecked) && swNumbers->IsChecked && !(swChars->IsChecked)) {
            str = "1234567890";
        }
        else if (swUpper->IsChecked && !(swLower->IsChecked) && !(swNumbers->IsChecked) && !(swChars->IsChecked)) {
            str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }
        else {
           ShowMessage("Por favor selecciona que propiedas tiene la contraseña.");
            str = "*";
        }

        edtPassword->Text = RandomPassword(numChars, str).c_str();
    }
}
//---------------------------------------------------------------------------

