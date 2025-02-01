Signin.cpp

class SignIn
{
  char Username[30];
  char Password[30];

public:

  SignIn()
  {
    strcpy(Username, "\0");
    strcpy(Password, "\0");
  }

  void AssignValues( char UNamE[30], char PWorD[30] )
  {
    strcpy(Username, UNamE );
    strcpy(Password, PWorD );
  }

  int Check_Match(SignIn UserValue)
  {
   int result=0;
   if(!( strcmp(UserValue.Username,Username)))
   {
     if(!( strcmp(UserValue.Password,Password)))
     {
       return 1;
     }
   }
   return 0;
  }
};

int Check( char UnamE[30] , char PworD[30] )
{
  SignIn UserValue;
  UserValue.AssignValues(UnamE,PworD);
  fstream file;
  file.open("C:\\XI\\SignUp.Txt", ios::in | ios::binary );
  SignIn Register;

  file.read ( ( char*)&Register, sizeof(Register) );
  while( !file.eof() )
  {
     if( Register.Check_Match(UserValue) )
       return 1;
     file.read((char*)&Register, sizeof(Register));
  }
}
