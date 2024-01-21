#include<iostream>
#include<windows.h>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};
void drawboard(){
	system("cls");
	cout<<"\n******************* TIC TAC TOE ***************************** \n\n";
	cout<<"********** PLAYER 1: [X]  PLAYER 2: [O] ********************* \n\n";
    cout<<"                     "<<"     |     |     "<<endl;
    cout<<"                     "<<"  "<< board[0]<< "  |  "<<board[1]<< "  |  "<<board[2]<<endl;
    cout<<"                     "<<"_____|_____|_____" << endl;
    cout<<"                     "<<"     |     |     " << endl;
    cout<<"                     "<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<endl;
    cout<<"                     "<<"_____|_____|_____"<<endl;
    cout<<"                     "<<"     |     |     "<<endl;
    cout<<"                     "<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<< endl;
    cout<<"                     "<<"     |     |     "<<endl<<endl;
}
int winnerCheck(){
	if((board[0] == board[1]) && (board[0] == board[2]))
		return 1;
	else if((board[3] == board[4]) && (board[3] == board[5]))
		return 1;
	else if((board[6] == board[7]) && (board[6] == board[8]))
		return 1;
	else if((board[0] == board[3]) && (board[0] == board[6]))
		return 1;
	else if((board[1] == board[4]) && (board[1] == board[7]))
		return 1;
	else if((board[2] == board[5]) && (board[2] == board[8]))
		return 1;
	else if((board[2] == board[4]) && (board[2] == board[6]))
		return 1;
	else if((board[0] == board[4]) && (board[0] == board[8]))
		return 1;
	else if(board[0]!='1' && board[1]!='2' && board[2]!='3' && board[3]!='4' && board[4]!='5' && board[5]!='6' && board[6]!='7' && board[7]!='8' && board[8]!='9')
		return 0;
	else
		return -1;									
}
void play(){
	HANDLE state_color;
	state_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int player = 1, state, choice;
	char mark;
	do{
		drawboard();
		player = (player%2) ? 1:2;
		cout<<"TURN: Player - "<<player<<"\n";
		cout<<"Enter Any Number(1-9): ";
		cin>>choice;
		mark = (player == 1) ? 'X':'O';
		
		if(choice == 1 && board[0] == '1')
			board[0] = mark;
		else if(choice == 2 && board[1] == '2')
			board[1] = mark;
		else if(choice == 3 && board[2] == '3')
			board[2] = mark;
		else if(choice == 4 && board[3] == '4')
			board[3] = mark;
		else if(choice == 5 && board[4] == '5')
			board[4] = mark;
		else if(choice == 6 && board[5] == '6')
			board[5] = mark;
		else if(choice == 7 && board[6] == '7')
			board[6] = mark;
		else if(choice == 8 && board[7] == '8')
			board[7] = mark;
		else if(choice == 9 && board[8] == '9')
			board[8] = mark;
		else{
			cout<<"INVALID MOVE!";
			player--;
			cin.ignore();
			cin.get();
		}
		state = winnerCheck();
		player++;													
	}while(state==-1);
	
	//Draw Board in a different color and declare winner
	SetConsoleTextAttribute(state_color, FOREGROUND_INTENSITY | 47);
	drawboard();
	if(state==1)
		cout<<"==> PLAYER "<<--player<<" WINS ";
	else
		cout<<"==> DRAW!";
}
int main(){ 	
//		Using HANDLE to manage the console output(Changing its text Attribute!)
	HANDLE base_color; 
	base_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(base_color, FOREGROUND_INTENSITY | 30); 
	play();
	return 0;
}