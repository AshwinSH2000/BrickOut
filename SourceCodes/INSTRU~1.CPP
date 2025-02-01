Instru~1.cpp

int instru()
{
  clrscr();
  cleardevice();
  cout<<"\n\n\n";
  outtextxy(25,30,"INSTRUCTIONS");
  cout<<"\n";
  cout<<setw(45)<<"************";
  cout<<"\n\n";
  cout<<setw(25)<<"Basic Rules of the game:";
  cout<<"\n";
  cout<<setw(25)<<"************************";
  cout<<"\n\n\n";
  int resp;
  cout<<" 1.The colour of the brick which is destroyed"
      <<" decides the points that \n the player gets."
      <<"\n\n 2.Red-6 points, Blue-5 points, Brown-4"
      <<" points, Yellow-3points, Green-2 points, "
      <<" Cyan-1 point."
      <<"\n\n 3.Initially, the player is given 3 lives and "
      <<" he/she loses one life each time \n the ball strikes "
      <<" the lower wall of the screen."
      <<"\n\n 4.So in order to keep the ball in action, "
      <<" the player will be provided with a \n movable paddle "
      <<" at the bottom of the screen. He/she can move the paddle"
      <<" only \n horizontally. Vertical or diagonal movement of "
      <<" the paddle is not allowed."
      <<"\n\n 5.The speed of the ball increases slightly at "
      <<" specific intervals: After 20 \n hits, after 40 hits and so on.";
      getch();

      clrscr();
      cleardevice();
      cout<<"\n\n 6.When a new ball is given to the player,"
          <<"it will start moving with the same \n speed as it"
          <<"was moving when the game initially started. Again "
          <<"after 20 hits\n its speed increases. After 40 hits "
          <<"it further increases.";
      cout<<"\n\n 7.The scores will be kept track of and it will"
          << be displayed on the top of the   screen."
          <<"\n\n 8.There will be a specific time limit, say of "
          <<"5 minutes. If a player finishes \n the game before "
          <<"the specified limit, then the remaining time (in seconds)"
          <<"will  be added up to the total points secured by the player."
          <<"If one is \n unable to complete it within the given time, "
          <<"then the extra time (in seconds) \n that one takes will be "
          <<"subtracted from the total points.";
      getch();
      clrscr();
      cleardevice();
      cout<<"\n\n9.There will be two levels in the game: Amateur and Pro."
          <<"\n\nIn the Amateur level, there will be a single ball moving"
          <<" and a specified length of the paddle."
          <<"\n\nIn the Pro level, the bricks will be half destroyed "
          <<" when the ball bounces on them once. "
          <<" To completely destroy the brick, the ball must be made "
          <<"to bounce on them once again."
          <<"\n\n10.The game will be completed if all the bricks "
          <<" are destroyed by the player. If his/her score is a high score,"
          <<" then it will be registered into the Hall of Fame."
          <<" If the player loses all his lives, then the game "
          <<" will be terminated. And if his score is a high score,"
          <<" that too will be entered into the Hall of Fame."
          <<"However,\nat any moment the player can end the game.";
  getch();
  return 1;
}




