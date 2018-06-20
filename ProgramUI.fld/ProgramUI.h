// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef ProgramUI_h
#define ProgramUI_h
#include <FL/Fl.H>
/**
 necessary for the warnning messages
*/
#include <FL/fl_ask.H>
#include <FL/Fl_Double_Window.H>
extern void WinQuit_cb(Fl_Double_Window*, void*);
#include <FL/Fl_Menu_Bar.H>
extern void CreateAcc_cb(Fl_Menu_*, void*);
extern void SaveAcc_cb(Fl_Menu_*, void*);
extern void Help_cb(Fl_Menu_*, void*);
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
extern void CButton1_cb(Fl_Button*, void*);
#include <FL/Fl_Text_Display.H>
extern void TDAdd_cb(Fl_Button*, void*);
extern void TDEdit_cb(Fl_Button*, void*);
extern void TDDelete_cb(Fl_Button*, void*);
#include <FL/Fl_Value_Input.H>
extern void FButton3_cb(Fl_Button*, void*);

class MainWindow {
public:
  /**
   Declaring text buffer in global scope, 
   static in source file only, dont know why, 
   but just work like this.
  */
  Fl_Text_Buffer *buff; 
  void hide();
  void show();
  Fl_Double_Window* make();
  Fl_Double_Window *mainwindow;
  static Fl_Menu_Item menu_[];
  Fl_Text_Display *Display;
  Fl_Value_Input *ToDoNumber;
};
#include <FL/Fl_Input.H>
#include <FL/Fl_Check_Button.H>
extern void CheckButton_cb(Fl_Check_Button*, void*);
#include <FL/Fl_Return_Button.H>
extern void CAButtonOK_cb(Fl_Return_Button*, void*);

class CreateAccountWindow {
public:
  /**
   Declaring text buffer in global scope, 
   static in source file only, dont know why, 
   but just work like this.
  */
  Fl_Text_Buffer *buff; 
  void hide();
  void show();
  Fl_Double_Window* make();
  Fl_Double_Window *createaccountwindow;
  Fl_Text_Display *Display;
  Fl_Input *NameIn;
  Fl_Input *BirthdayIn;
  Fl_Input *PasswordIn;
  Fl_Value_Input *MoneyIn;
  Fl_Value_Input *FinanceHorizonIn;
  Fl_Check_Button *FinancesCB;
  Fl_Check_Button *ToDoListCB;
  Fl_Check_Button *CalendarCB;
  Fl_Return_Button *Ok;
};
extern void TDWButtonOK_cb(Fl_Return_Button*, void*);
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Input_Choice.H>
extern void PWButtonOK_cb(Fl_Return_Button*, void*);
extern void CreateAcc_cb(Fl_Button*, void*);

class ToDoWindow {
public:
  /**
   Declaring text buffer in global scope, 
   static in source file only, dont know why, 
   but just work like this.
  */
  Fl_Text_Buffer *buff; 
  void hide();
  void show();
  Fl_Double_Window* make();
  Fl_Double_Window *ToDoWindow;
  Fl_Return_Button *Ok;
  Fl_Input *Date;
  Fl_Text_Editor *Display;
  Fl_Check_Button *StatusCB;
  Fl_Input *Name;
  Fl_Input_Choice *Importance;
  Fl_Input *Tag;
  Fl_Input_Choice *Periocity;

class PasswordWindow {
public:
  /**
   Declaring text buffer in global scope, 
   static in source file only, dont know why, 
   but just work like this.
  */
  Fl_Text_Buffer *buff; 
  void hide();
  void show();
  Fl_Double_Window* make();
  Fl_Double_Window *PassordWindow;
  Fl_Return_Button *Ok;
  Fl_Input_Choice *NameChoice;
  Fl_Input *PasswordInput;
  Fl_Button *CreateUserButton;
};
};
#endif