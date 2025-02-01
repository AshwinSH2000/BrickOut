Highscor.cpp

char score1[30], score2[30], score3[30];
char name1[30], name2[30], name3[30];

void update_score();

void check_score(char pas_name[30], char pas_score[30])
{ 
  fstream file;
  file.open("C:\\XI\\HIGH_SCORE.TXT",ios::in);

  // read the scores
  file.getline(name1, 30, '.');
  file.getline(score1, 30, '.');
  file.getline(name2, 30, '.');
  file.getline(score2, 30, '.');
  file.getline(name3, 30, '.');
  file.getline(score3, 30, '.');
  
  if(strcmpi(pas_score,score1)>0 )
  {
    strcpy(name3, name2);
    strcpy(name2, name1);
    strcpy(name1, pas_name);
    strcpy(score3, score2);
    strcpy(score2, score1);
    strcpy(score1, pas_score);
    update_score();
  }
 
  else if(strcmpi(pas_score,score2)>0)
  {
    strcpy(name3, name2);
    strcpy(name2, pas_name);
    strcpy(score3, score2);
    strcpy(score2, pas_score);
    update_score();
  }
 
  else if(strcmpi(pas_score,score3)>0)
  {
    strcpy(name3, pas_name);
    strcpy(score3, pas_score);
    update_score();
  }
}

void update_score()
{
  fstream file;
  file.open("C:\\XI\\HIGH_SCORE.TXT",ios::out);
  file<<name1<<score1<<name2<<score2<<name3<<score3;
}
void display_score()
{ 
  fstream file;
  file.open("C:\\XI\\HIGH_SCORE.TXT",ios::in);

  //--- first score ---//
  file.getline(name1, 30, '.');
  cout<<"\n\n\n\t\t"<<name1;
  file.getline(score1, 30, '.');
  cout<<"\t\t\t\t"<<score1;
  
  //--- second score ---//
  file.getline(name2, 30, '.');
  cout<<"\n\t\t"<<name2;
  file.getline(score2, 30, '.');
  cout<<"\t\t\t\t"<<score2;

  //--- third score ---//
  file.getline(name3, 30, '.');
  cout<<"\n\t\t"<<name3;
  file.getline(score3, 30, '.');
  cout<<"\t\t\t\t"<<score3;

}
void hallofame()
{  
  int op;
  settextstyle(5,0,5);
  setcolor(3);
  do
  {
    clrscr();
    cleardevice();
    outtextxy(150,10,"HALL OF FAME");
    cout<<"\n\n\t1) AMATEUR";
    cout<<"\n\t2) PRO";
    cout<<"\n\t3) EXIT";
    cout<<"\n\n\tENTER YOUR CHOICE:";
    cin>>op;
    switch(op)
    {
      case 1:cleardevice();
	     settextstyle(5,0,5);
	     setcolor(3);
	     outtextxy(150,10,"HALL OF FAME");
       	     cout<<"\n\t\tHigh scores of AMATEUR level";
	     cout<<"\n\n\t\tNAME"<<"\t\t\t\t"<<"SCORES";
	     display_score();
	     cout<<"\n\t-----------------------------";
	     cout<<"------------------------";
	     getch();
	     break;
      case 2:cleardevice();
	     settextstyle(5,0,5);
	     setcolor(3);
	     outtextxy(150,10,"HALL OF FAME");
	     cout<<"\n\t\t\tHigh scores of PRO level";
	     cout<<"\n\n\t\tNAME"<<"\t\t\t\t"<<"SCORES";
	     display_score();
	     cout<<"\n\t-----------------------------";
	     getch();
	     break;

      case 3:cleardevice();
	     return;

    }
  }
  while(op!=4);
  getch();
}