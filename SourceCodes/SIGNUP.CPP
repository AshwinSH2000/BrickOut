Signup.cpp

class SignUp
{
  char UserName[30];
  char PassWord[30];

public:

  SignUp( )
  {
    strcpy(UserName, "\0");
    strcpy(PassWord, "\0");
  }

  void AssignRegistry( char UName[30], char PWord[30] )
  {
    strcpy(UserName, UName );
    strcpy(PassWord, PWord );
  }

  void Display()
  {
    cout<<UserName<<endl;
    cout<<PassWord<<endl;
  }
};


void Sign( char UName[30], char PWord[30] )
{
  SignUp Register ;
  Register.AssignRegistry(UName,PWord) ;

  fstream File;
  File.open("C:\\XI\\SignUp.Txt" ,ios :: app |ios::binary );
  File.write((char*)&Register,sizeof(Register)) ;
  File.close();

  File.open("C:\\XI\\SignUp.Txt" ,ios :: in |ios::binary);
  File.read( (char*)&Register, sizeof(Register) );
  while( !File.eof() )
  {
    Register.Display();
    File.read( (char*)&Register, sizeof(Register) );
  }
  File.close();
  getch();
}