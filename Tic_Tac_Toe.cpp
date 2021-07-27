#include<iostream>
using namespace std;

//grid is a 2D array that holds all the moves
char grid[3][3];


//declaration of functions
int inp();			//takes the input position from user
void display();			//displays the current state of grid
void tie(char);			//completes the game if a TIE is inevitable
bool empty(int);		//checks if a cell is empty
void fill(int, char);		//fills a cell with given character
void firstSolve();		//function for game when Computer plays first
void secondSolve();		//function for game when Human plays first


int main()
{
	char ch;

	//initialize the grid with ' '
	for(int i=0;i<3;i++) { for(int j=0;j<3;j++) grid[i][j] = ' '; }
	cout<<"\n\n";
	cout<<"  1 | 2 | 3 \n"; cout<<" -----------\n";
    	cout<<"  4 | 5 | 6 \n"; cout<<" -----------\n";
    	cout<<"  7 | 8 | 9 \n"; cout<<"\n\n";


	cout<<"Want to Play first? [Y/N]: ";
	cin>>ch;
	if(ch!='Y' && ch!= 'y' && ch!='N' && ch!='n')
	{
		do{
			cout<<"\nPlease Enter correct choice [Y/N]: ";
			cin>>ch;
		}while(ch!='Y' && ch!= 'y' && ch!='N' && ch!='n');
	}

	//The first person always starts with 'X'
	if(ch=='Y' || ch=='y')
	{
		cout<<"\nYou play with X\n";
		secondSolve();
	}
	else
	{
		cout<<"\nYou play with O\n";
		firstSolve();
	}


	return 0;
}


//display function for grid
void display()
{
	cout<<"\n\n";
	cout<<"  "<<grid[0][0]<<" | "<<grid[0][1]<<" | "<<grid[0][2]<<"\n";
	cout<<" -----------\n";
	cout<<"  "<<grid[1][0]<<" | "<<grid[1][1]<<" | "<<grid[1][2]<<"\n";
	cout<<" -----------\n";
	cout<<"  "<<grid[2][0]<<" | "<<grid[2][1]<<" | "<<grid[2][2]<<"\n";
	cout<<"\n\n";
}

//fills the cell of grid with given character
void fill(int pos, char c)
{
	if(pos==1) grid[0][0] = c;
	else if(pos==2) grid[0][1] = c;
	else if(pos==3) grid[0][2] = c;
	else if(pos==4) grid[1][0] = c;
	else if(pos==5) grid[1][1] = c;
	else if(pos==6) grid[1][2] = c;
	else if(pos==7) grid[2][0] = c;
	else if(pos==8) grid[2][1] = c;
	else if(pos==9) grid[2][2] = c;
}

//checks if the cell of grid is empty
bool empty(int pos)
{
	if(pos>0 && pos<10)
	{
		if(pos==1)
		{ if(grid[0][0]==' ') return true;
		  else return false; }
		else if(pos==2)
		{ if(grid[0][1]==' ') return true;
		  else return false; }
		else if(pos==3)
		{ if(grid[0][2]==' ') return true;
		  else return false; }
		else if(pos==4)
		{ if(grid[1][0]==' ') return true;
		  else return false; }
		else if(pos==5)
		{ if(grid[1][1]==' ') return true;
		  else return false; }
		else if(pos==6)
		{ if(grid[1][2]==' ') return true;
		  else return false; }
		else if(pos==7)
		{ if(grid[2][0]==' ') return true;
		  else return false; }
		else if(pos==8)
		{ if(grid[2][1]==' ') return true;
		  else return false; }
		else if(pos==9)
		{ if(grid[2][2]==' ') return true;
		  else return false; }
	}
	return false;
}

//tie function completes the game after a TIE is sure to happen
void tie(char c)
{
	int i,j,cnt = 0,pos;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(grid[i][j]==' ')
				cnt++;
		}
	}
	if(c=='O') cnt = (cnt+1)/2;
	else cnt = cnt/2;
	while(cnt--)
	{
		if(c=='O') { pos = inp(); fill(pos, 'O'); display(); c = 'X'; }
		for(i=0;i<3 && c=='X';i++)
		{
			for(j=0;j<3 && c=='X';j++)
			{ if(grid[i][j]==' ') { grid[i][j] = 'X'; display(); c = 'O'; } }
		}
	}
}

//takes input position from user
int inp()
{
	int pos;
	cout<<"Choose a position: ";
	cin>>pos;
	if(pos>=1 && pos<=9 && empty(pos)) return pos;
	do{
		cout<<"\nPlease Choose an empty position: ";
		cin>>pos;
	}while((pos<1 || pos>9) || !empty(pos));
	return pos;
}

//function for game when Computer plays first
void firstSolve()
{
	int pos;

	//Computer always starts at 7th position
	grid[2][0] = 'X'; display();
	pos = inp(); fill(pos, 'O'); display();

	//I have covered all possible subcases
	if(pos==9)
	{
		grid[0][0] = 'X'; display();
		pos = inp(); fill(pos, 'O'); display();
		if(pos==4)
		{
			grid[0][2] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==5) { grid[0][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			else if(pos==2) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			else { grid[0][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
		else { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
	}
	else if(pos==8)
	{
		grid[2][2] = 'X'; display();
		pos = inp(); fill(pos, 'O'); display();
		if(pos==5)
			{
			grid[0][2] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==6)
			{
				grid[0][0] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==2) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==4) { grid[0][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[0][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
			else{ grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
		else
		{
			if(pos==3)
			{
				grid[0][1] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==4) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==5) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==1)
			{
				grid[0][2] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==6) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==5) { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
			else	//1, 3 and 5 are free
			{
				if(pos==4)
				{
					grid[0][1] = 'X'; display();
					pos = inp(); fill(pos, 'O'); display();
					if(pos==6) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
					else if(pos==5) { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
					else { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==6)
				{
					grid[0][1] = 'X'; display();
					pos = inp(); fill(pos, 'O'); display();
					if(pos==4) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
					else if(pos==5) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
					else { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==2)
				{
					grid[0][1] = 'X'; display();
					pos = inp(); fill(pos, 'O'); display();
					if(pos==4) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
					else if(pos==5) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
					else { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				}
			}
		}
	}

	//It covers the when user fills center cell
	else if(pos==5)
	{
		grid[0][2] = 'X'; display();
		pos = inp(); fill(pos, 'O'); display();
		if(pos==9)
		{
			grid[0][0] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==2) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			else if(pos==4) { grid[0][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			else { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
		else if(pos==1)
		{
			grid[2][2] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==6) { grid[2][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			else if(pos==8) { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			else { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
		else if(pos==2)
		{
			grid[2][1] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==9)
			{
				grid[0][0] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==6) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][2] = 'X'; display(); cout<<"Game TIE\n\n"; }
			}
			else{ grid[2][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
		else if(pos==8)
		{
			grid[0][1] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==1)
			{
				grid[2][2] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==4) { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][0] = 'X'; display(); cout<<"Game TIE\n\n"; }
			}
			else{ grid[0][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
		else if(pos==4)
		{
			grid[1][2] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==9)
			{
				grid[0][0] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==8) { grid[0][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[2][1] = 'X'; display(); cout<<"Game TIE\n\n"; }
			}
			else{ grid[2][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
		else if(pos==6)
		{
			grid[1][0] = 'X'; display();
			pos = inp(); fill(pos, 'O'); display();
			if(pos==1)
			{
				grid[2][2] = 'X'; display(); 
				pos = inp(); fill(pos, 'O'); display();
				if(pos==2) { grid[2][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[0][1] = 'X'; display(); cout<<"Game TIE\n\n"; }
			}
			else{ grid[0][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
		}
	}
	else	//5, 8 and 9 are free
	{
		grid[2][2] = 'X'; display();
		pos = inp(); fill(pos, 'O'); display();
		if(pos==8)
		{
			if(grid[0][0]=='O')
			{
				grid[0][2] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==5) { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==6) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(grid[0][1]=='O')
			{
				grid[0][2] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==5) { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==6) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(grid[0][2]=='O')
			{
				grid[0][0] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==5) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==4) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(grid[1][0]=='O')
			{
				grid[0][2] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==5) { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==6) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][2] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(grid[1][2]=='O')
			{
				grid[0][0] = 'X'; display();
				pos = inp(); fill(pos, 'O'); display();
				if(pos==5) { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else if(pos==4) { grid[1][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
				else { grid[1][0] = 'X'; display(); cout<<"Computer Wins\n\n"; }
			}
		}
		else { grid[2][1] = 'X'; display(); cout<<"Computer Wins\n\n"; }
	}
}

//function for game when Human plays first
void secondSolve()
{
	int pos;
	pos = inp(); fill(pos, 'X'); display();
	if(pos==2 || pos==4 || pos==6 || pos==8)	//human selects an edge cell
	{
		//the center cell is free, so computer captures it
		if(pos==2)
		{
			grid[1][1] = 'O'; display();
			pos = inp(); fill(pos, 'X'); display();
			if(pos==1)
			{
				grid[0][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==7)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==6) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==3)
			{
				grid[0][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==9)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==4) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==4)
			{
				grid[0][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==9)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==6)
			{
				grid[0][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==7)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==7)
			{
				grid[0][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==1)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==6) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==4)
				{
					grid[0][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9)
					{
						grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==6) { grid[2][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==8) { grid[1][2] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==6)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==4) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==8) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==8)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==9)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==6) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==4) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==9)
			{
				grid[0][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==3)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==4) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==6)
				{
					grid[0][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7)
					{
						grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==4) { grid[2][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==8) { grid[1][0] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==4)
				{
					grid[2][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==6) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==8) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==8)
				{
					grid[2][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==7)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==4) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==6) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==8)
			{
				grid[1][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==4)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
		}
		else if(pos==4)
		{
			grid[1][1] = 'O'; display();
			pos = inp(); fill(pos, 'X'); display();
			if(pos==1)
			{
				grid[2][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==3)
				{
					grid[1][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==7)
			{
				grid[0][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==9)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==2)
			{
				grid[0][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==9)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==8)
			{
				grid[2][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==3)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==3)
			{
				grid[2][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==1)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==2)
				{
					grid[0][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9)
					{
						grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==8) { grid[1][2] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==6) { grid[2][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==8)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==2) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==6) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==6)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==9)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==1) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==2) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==9)
			{
				grid[0][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==7)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==8)
				{
					grid[2][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3)
					{
						grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==2) { grid[1][2] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==6) { grid[0][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==2)
				{
					grid[0][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==8) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==6) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==6)
				{
					grid[0][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==3)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==8) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==7) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==6)
			{
				grid[2][1] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==2)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
		}
		else if(pos==6)
		{
			grid[1][1] = 'O'; display();
			pos = inp(); fill(pos, 'X'); display();
			if(pos==3)
			{
				grid[2][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==1)
				{
					grid[1][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==9)
			{
				grid[0][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==7)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==2)
			{
				grid[0][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==7)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==8)
			{
				grid[2][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==1)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==1)
			{
				grid[2][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==3)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==2)
				{
					grid[0][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7)
					{
						grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==8) { grid[1][0] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==4) { grid[2][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==8)
				{
					grid[2][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==2) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==4) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==4)
				{
					grid[2][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==7)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==2) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==7)
			{
				grid[0][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==9)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==8)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1)
					{
						grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==2) { grid[1][0] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==4) { grid[0][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==2)
				{
					grid[0][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==8) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==4) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==4)
				{
					grid[0][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==1)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==4) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==1) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==4)
			{
				grid[2][1] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==2)
				{
					grid[2][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
		}
		else if(pos==8)
		{
			grid[1][1] = 'O'; display();
			pos = inp(); fill(pos, 'X'); display();
			if(pos==7)
			{
				grid[2][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==1)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==6) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==9)
			{
				grid[2][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==3)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==4) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==4)
			{
				grid[2][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==3)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==6)
			{
				grid[2][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==1)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else if(pos==1)
			{
				grid[2][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==7)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==6) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==4)
				{
					grid[2][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3)
					{
						grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==6) { grid[0][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==2) { grid[1][2] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==6)
				{
					grid[0][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==4) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==2) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==2)
				{
					grid[0][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==3)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==6) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==4) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==3)
			{
				grid[2][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==9)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==4) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==6)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==1)
					{
						grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display();
						if(pos==4) { grid[0][1] = 'O'; display(); cout<<"Game TIE\n\n"; }
						else if(pos==2) { grid[1][0] = 'O'; display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==4)
				{
					grid[0][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==6) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==2) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==2)
				{
					grid[0][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==1)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==4) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==6) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
			}
			else if(pos==2)
			{
				grid[1][2] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==4)
				{
					grid[0][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
		}
	}
	else
	{
		if(pos==5)		//human selects the center cell
		{
			grid[2][0] = 'O'; display();
			pos = inp(); fill(pos, 'X'); display();
			if(pos==3)
			{
				grid[0][0] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==4)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==9) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
			}
			else
			{
				if(pos==1)
				{
					grid[2][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8)
					{
						grid[0][1] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==2)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==9)
					{
						grid[0][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else if(pos==4)
				{
					grid[1][2] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==1) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==9) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==6)
				{
					grid[1][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==1) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					else if(pos==9) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
				}
				else if(pos==8)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==3)
					{
						grid[1][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==1) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else
					{
						if(pos==1)
						{
							grid[2][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==4)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==1) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==9) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==6)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==1) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==9) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==9)
						{
							grid[0][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
					}
				}
				else if(pos==9)
				{
					grid[0][0] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==4)
					{
						grid[1][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
					}
					else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
			}
		}
		else			//human selects a corner cell
		{
			if(pos==1)
			{
				grid[1][1] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==9)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2)
					{
						grid[0][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else
				{
					if(pos==8)
					{
						grid[2][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==7)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==6)
						{
							grid[0][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==4)
						{
							grid[2][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==3)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==2)
						{
							grid[0][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==7)
					{
						grid[1][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==6)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==6)
					{
						grid[2][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==3)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==8)
						{
							grid[2][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==2)
						{
							grid[0][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==7) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==7)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==4)
						{
							grid[2][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==4)
					{
						grid[2][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==3)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else if(pos==3)
					{
						grid[0][1] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==8)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==2)
					{
						grid[0][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==7)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
				}
			}
			else if(pos==3)
			{
				grid[1][1] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==7)
				{
					grid[2][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==2)
					{
						grid[0][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else
				{
					if(pos==8)
					{
						grid[2][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==9)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==4)
						{
							grid[0][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==6)
						{
							grid[2][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==1)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==2)
						{
							grid[0][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==9)
					{
						grid[1][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==4)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==4)
					{
						grid[2][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==1)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==8)
						{
							grid[2][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==1) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==2)
						{
							grid[0][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==9) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==9)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==1) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==6)
						{
							grid[2][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==6)
					{
						grid[2][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==1)
						{
							grid[0][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==8) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else if(pos==1)
					{
						grid[0][1] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==8)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==2)
					{
						grid[0][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==9)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
				}
			}
			else if(pos==7)
			{
				grid[1][1] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==3)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8)
					{
						grid[2][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else
				{
					if(pos==2)
					{
						grid[0][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==1)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[2][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==6)
						{
							grid[2][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==4)
						{
							grid[0][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==9) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==9)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==1) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==8)
						{
							grid[2][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==1)
					{
						grid[1][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==6)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==6)
					{
						grid[0][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==9)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==2)
						{
							grid[0][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==9) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==8)
						{
							grid[2][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==1) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==1)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==9) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==4)
						{
							grid[0][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==4)
					{
						grid[0][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==9)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[2][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else if(pos==9)
					{
						grid[2][1] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==2)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==8)
					{
						grid[2][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==1)
						{
							grid[1][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==6) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[0][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
				}
			}
			else if(pos==9)
			{
				grid[1][1] = 'O'; display();
				pos = inp(); fill(pos, 'X'); display();
				if(pos==1)
				{
					grid[0][1] = 'O'; display();
					pos = inp(); fill(pos, 'X'); display();
					if(pos==8)
					{
						grid[2][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else { grid[2][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
				}
				else
				{
					if(pos==2)
					{
						grid[0][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==3)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[2][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==4)
						{
							grid[2][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==6)
						{
							grid[0][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==7) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==7)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==3) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==6) { grid[1][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==8)
						{
							grid[2][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[1][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==3)
					{
						grid[1][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==4)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==4)
					{
						grid[0][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==7)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[0][2] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==2)
						{
							grid[0][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==7) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==8)
						{
							grid[2][0] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==3) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else if(pos==3)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==7) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else if(pos==8) { grid[0][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
						}
						else if(pos==6)
						{
							grid[0][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[2][1] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
					}
					else if(pos==6)
					{
						grid[0][2] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==7)
						{
							grid[2][1] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==2) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[2][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
					else if(pos==7)
					{
						grid[2][1] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==2)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[0][1] = 'O'; display(); cout<<"Computer Wins\n\n";}
					}
					else if(pos==8)
					{
						grid[2][0] = 'O'; display();
						pos = inp(); fill(pos, 'X'); display();
						if(pos==3)
						{
							grid[1][2] = 'O'; display();
							pos = inp(); fill(pos, 'X'); display();
							if(pos==4) { grid[0][0] = 'O'; display(); pos = inp(); fill(pos, 'X'); display(); cout<<"Game TIE\n\n"; }
							else { grid[1][0] = 'O'; display(); cout<<"Computer Wins\n\n"; }
						}
						else { grid[0][2] = 'O'; display(); cout<<"Computer Wins\n\n"; }
					}
				}
			}
		}
	}
}