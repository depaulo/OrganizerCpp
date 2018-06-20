#include <iostream>
#include <stdio.h>
#include <cstdint>
#include "UserData/UserData.cpp"
#include "ProgramUI.fld/ProgramUI.cpp"
#include <sstream>
using std::string;

//create the appUser initailized with empty values.
    User appUser;
/*It is necessary to beginDatabase in the begining and endDatabase in the end.
    it create the database and initialize all the tables, it is a friend of the user class,
    but isnt a member.
    endDatabase needs to be in the closing section, it is also necessary to create the user,
    it isnt done by this function.
*/
//create the main window for the program
    MainWindow mainWin;
    CreateAccountWindow createWin;
    ToDoWindow todoWin;

int main(int argc, char **argv) {
    Fl::visual(FL_DOUBLE|FL_INDEX);//forgot why, but is usefull
    mainWin.make();

    /*make the window, and show it on the screen.
    show is already included in the make function in the programui file.*/
    return Fl::run();//make the fltk run.
}


 static int callback(void *datas, int argc, char **argv, char **azColName) {
			int i;
		for(i=0; i<argc; i++){
			todoWin.buff->append("\n");
			todoWin.buff->append(azColName[i]);
			todoWin.buff->append(" \t\t: ");
			todoWin.buff->append(argv[i]);
		}
	return 0;
}
//*************************************************************************
//ProgramUI functions

//mainWin Callbacks

void CButton1_cb(Fl_Button*,void*){
    mainWin.buff->text("testing button1");
}

void TDAdd_cb(Fl_Button*,void*){
    todoWin.make();
}

void TDEdit_cb(Fl_Button*,void*){
    todoWin.make();
}

void TDDelete_cb(Fl_Button*,void*){
    todoWin.make();
}

void FButton3_cb(Fl_Button*,void*){
    mainWin.buff->append("\ntesting button3");
}

void CreateAcc_cb(Fl_Menu_*,void*){
    createWin.make();
}

void SaveAcc_cb(Fl_Menu_*,void*){
    createWin.make();
}

void LoadAcc_cb(Fl_Menu_*,void*){
    createWin.make();
}

void Help_cb(Fl_Menu_*,void*){
    fl_message("Well\nThis is a work in progress \n"
    "When i finish, i will be capable to manage my life with this program\n"
    "my calendar, todo list and finances.");
}

/*
procedure for closing the window, ask if you really need to close it,
and offer the option to save, need flask, included in programui.
*/
void WinQuit_cb(Fl_Double_Window*,void* userdata) {
		int hotspot = fl_message_hotspot();//create the small window
		fl_message_hotspot(1);
		fl_message_title("Quitting?");
		//text in the message, and buttons names.
		int rep = fl_choice("Are you sure you want to quit?","Cancel","Quit","Save");
		fl_message_hotspot(hotspot);
	if (rep==1){//quit, the database is closed at the destructor
		exit(0);
		}
	if (rep==2)//save, if add more things, remember to open brackets
		fl_message("hmmm, didnt make this option yet, sorry )))).");
	}
//***************************************************************************
//Passord Manager callback
void PWButtonOK_cb(Fl_Return_Button*, void*){

}
//***************************************************************************
//createWin Callbacks

void CAButtonOK_cb(Fl_Return_Button*,void*){
    appUser.editUserData(createWin.NameIn->value(), createWin.PasswordIn->value(),createWin.MoneyIn->value(), createWin.BirthdayIn->value(), createWin.FinanceHorizonIn->value());
    createWin.hide();
}
//****************************************************************************
//todoWin Callbacks
void CheckButton_cb(Fl_Check_Button*,void* userData){
int choice=uintptr_t(userData);
//1=finances, 2=todolist, 3=calendar, 4=completed
switch (choice){
    case 1:{
        //appUser.set_finances(CreateAccountWindow.FinancesCB->value());
        //comment
        //comment2
        //coment3
        
    }
        break;
    case 2:{
    }
        break;
    case 3:{
    }
        break;
    case 4:{
    }
        break;
    default:{
    }
        break;
}
}
void TDWButtonOK_cb(Fl_Return_Button*,void*){
    appUser.saveToDo(1, todoWin.Date->value(), appUser.get_completed(), todoWin.buff->text(),todoWin.Periocity->value(), todoWin.Tag->value(), todoWin.Name->value(), todoWin.Importance->value());
}


//********************************************************************************
