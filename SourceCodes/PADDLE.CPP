Paddle.cpp

void paddle()
{
   int x, y, button ;
   initmouse();
   showmouseptr();
   getmousepos( &button,&x, &y);
   setfillstyle( 1, RED );
   bar(x+20,440, x+100, 460 );      
   delay(5);
   setfillstyle( 2,BLACK );
   bar(x,440, x+100, 460 );
}