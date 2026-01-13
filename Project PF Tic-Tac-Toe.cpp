#include<iostream>
using namespace std;

char board[3][3]={{'1', '2', '3'},{'4', '5', '6'}, {'7', '8', '9'}};
int row, cols;
char turn = 'X';
bool draw=false; //false ka matlab abhi nai hui draw game 
int again;

void gameBoard(){ //for showing game board!
	system("cls");
	cout<<"\t T I C - T A C - T O E - G A M E"<<endl;
	cout<<endl<<"player[1] = X     Player[2] = O"<<endl<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<board[i][j]<<" ";
			if(j<2)
			cout<<"|";
		}
		cout<<endl;
		if(i<2)
		cout<<"_______"<<endl;
	}
	cout<<endl;
}
	
void playerTurn(){
	
	int choice;
	if(turn == 'X'){
	cout<<"Player1 [X]: ";	
	}
	if(turn == 'O'){
	cout<<"Player2 [O]: ";
	}
	cin>>choice;
	
	switch(choice){
		case 1: row=0; cols=0; break;
		case 2: row=0; cols=1; break;
		case 3: row=0; cols=2; break;
		case 4: row=1; cols=0; break;
		case 5: row=1; cols=1; break;
		case 6: row=1; cols=2; break;
		case 7: row=2; cols=0; break;
		case 8: row=2; cols=1; break;
		case 9: row=2; cols=2; break;
		
			default:
			cout<<"Invalid choice"<<endl; 
			playerTurn();		
	}
	if( turn == 'X' && board[row][cols]!='X' && board[row][cols]!='O' ){
		board[row][cols]='X';
		turn ='O';
	}
	else if( turn == 'O' && board[row][cols]!='X' && board[row][cols]!='O' ){
		board[row][cols]='O';
		turn = 'X';
	}
	else{
		cout<<"Box already filled. Try Again! "<<endl;
		playerTurn();
}
	}

bool gameOver(){
	for(int i=0; i<3; i++){		//for check win!
		if(board[i][0]==board[i][1] && board[i][0]==board[i][2] ){ // for identical rows 
			return false;
		}
		if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){	//for identical colums
			return false;
			}
		}
				// for digonals checking
		if(board[0][0]==board[1][1] && board[0][0]==board[2][2] ){
			return false;
		}
		if(board[0][2]==board[1][1] && board[0][2]==board[2][0] ){
			return false;
	}
	//for checking any empty box left!
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j]!='X' && board[i][j]!='O'){
				return true; //true matlab main function ma while ka  loop abhi chalay ga!!
			}
		}
	}
	//check draw
	draw = true;
	return false;
	
}

void resetBoard(){
	
	char num='1';
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j]=num+1;
		}
	}
	turn='X';
	draw=false;
}

int main(){	
	
	cout << "Welcome To Tic Tac Toe Game! By AbdullahXcode" << endl;
	cout << "----------------------------------------" << endl;
		do{
		while(gameOver()){
			gameBoard();
			playerTurn();
			gameBoard();
			gameOver();
		}
		
		if(turn =='X' && draw==false){
			cout<<"Player[2] is winner!!. Congratulation"<<endl;
		}
		else if(turn =='O'  && draw==false){
			cout<<"Player[1] is winner!!. Congratulations"<<endl;
		}
		else{
			cout<<"Game Draw!!"<<endl;
		}
	cout << "----------------------------------------" << endl;
	
	}while(again==1);

		cout<<"Game ended !"<<endl;
		return 0;
	
	return 0;
}
