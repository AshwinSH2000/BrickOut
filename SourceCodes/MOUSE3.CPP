mouse.cpp

//Declaration for  i/o Registers
union REGS i,o ;


// INITIALISES MOUSE
interrupt initmouse()
{
  i.x.ax = 0 ;
  int86(0x33, &i, &o) ;
  return ( o.x.ax == 0 ? -1:0 ) ;

}


//DISPLAY MOUSE POINTER
showmouseptr()
{
  i.x.ax = 1 ;
  int86( 0x33, &i, &o );
}


//DISPLAY MOUSE POINTER
hidemouseptr()
{
  i.x.ax = 2 ;              
  //if i.x.ax=2 mouse pointer will be hidden.
  int86( 0x33, &i, &o );
}


//RESTRICTS MOUSE POINTER
restrictmouseptr(int x1, int y1, int x2, int y2 )
{
  i.x.ax = 7 ;
  i.x.cx = x1  ;
  i.x.dx = x2 ;//max cursor point
  int86(0x33, &i, &o ) ;
  i.x.ax = 8 ;
  i.x.cx = y1 ;
  i.x.dx = y2 ;
  int86(0x33, &i, &o) ;
}


//GETS MOUSE COORDINATES AND BUTTON STATUS
getmousepos(int *button, int *x, int *y )
{
  i.x.ax = 3 ;
  int86(0x33, &i, &o ) ;

  *button = o.x.bx ;
  *x = o.x.cx ;
  *y = o.x.dx ;
}

