void  ft_putchar(char c);

int   top_line(int x, int y, int i)
{
  //x나 y가 1이상 이어야 코드가 실행되게 하고 아니면 {} 끝에서 리턴0로 끝.
  if (x >= 1 && y >= 1)
  // 1,1 이상이면 이 안으로 들어오고 
  {
    ft_putchar('o');
    //코드에 들어왔으니 o을 찍음
    //if문은 예외케이스 만든거
    if (x == 1)
    // 만약 x가 1이라면 
    {
      ft_putchar('\n');
      // 개행 처리. x인 가로축을 1을 줘버리면 그 아래는 행렬이 만들어 질수 없으니 개행처리해주고 종료
      return (0);
    }
    while (i > 0)
    // i는 '-'의 숫자. i < 0 일수도 있었지만 그러면 ++ 해주면 되고 아니니까 --로 0까지 돌림
    {
      ft_putchar('-');
      // x를 5로 가정
      // '-'를 출력 그니까 이미 'o' 를 찍은상태에서 '-'이값이 (5-2 = 3)될때 까지 '-'를 돌린다. 
      // '-' 이건 2번째 부터 찍히니까 항상 왜냐하면 x가 1일때는 1,1 자리에 'o'를 찍으니.
      --i;
      // i 즉 '-'이거를 줄이면서 while문을 돌아가게 한다. 
    }
    ft_putchar('o');
    // while문 끝났으니 다시 꼭짓점에 'o'를 출력하면 
    // 첫번째 줄은 당연히 o---o가 됨  
    ft_putchar('\n');
    // 첫번째 줄은 끝났으니 개행처리 \n
  }
  return (0);
  //이 return은 x 혹은 y 가 1보다 크지 않을때 즉 0이거나 - 일때 0으로 코드를 끝내려고하기 위한. 
}

int   mid_line(int x, int y, int i, int j)
              //x 가로 y 세로 i 'o' j '|'
{
  if (y >= 3)
  //세로가 3이상이면
  {
    while (j > 0)
    // 특수 케이스
    // '|' 이게 0이거나 0보다 작으려면 y값은 2가 되어야 한다. j = y - 2 이니까
    // y 인 세로 값이 2보다 크면 이 while문에 안들어옴
    {
      ft_putchar('|');
      // while문에 들어왔다면 '|' 이걸 찍어준다. 
      while (i > 0)
      // i 즉 'o'이게 0보다 크면 
      // 0보다 크려면 i = x - 2 이니까 x가 2보다 커야한다.
      {
        ft_putchar(' ');
        //그러면 공백을 해주려고 공백처리
        --i;
        // 공백을 찍고 다음으로 넘어가기 위해 -- 처리
      }
      i = x - 2;
      // i = x - 2를 void rush()함수에서 선언을 했지만 위에 while문에서 i를 줄였으니 다시 선언
      if (x != 1)
      // x 즉 가로가 1이 아니라면 이 아래 실행 뭐 즉 2라면
      {
        ft_putchar('|');
        // 그러면 '|' 이걸 끝에 찍는다. 왜냐면 위에 코드가 돌아가면서 | 공백공백공백 | 이렇게 된다.
      }
      ft_putchar('\n');
      // 다음줄을 위해서 다시 개행처리
      --j;
    }
  }
  return (0);
}

int   bottom_line(int x, int y, int i)
            // x 는 가로 y 는 세로 i 는 '-' 의 숫자 
{
  if (y > 1)
  // 세로가 1보다 크다면.
  {
    ft_putchar('o');
    //그러면 제일 마지막줄에 'o'를 찍는다. 하나 찍는다. 반복문 없으니까
    if (x == 1)
    // 만약 x가 1이라면.
    {
      ft_putchar('\n');
      //그러면 x인 가로가 필요없으니 y축을 출력하기 위해 개행처리 해준다.
      return (0);
    }
    while (i > 0)
    // i 가 0보다 크려면 최소 1이라는 소리.
    // i 가 최소 1이려면 i = x - 2이니까 x인 가로가 3이어야 한다. 
    // x 가 못해도 3이어야 중간에 '-'이게 들어간다. 가로라인에.
    {
      ft_putchar('-');
      // x 가 3이어야 이게 실행되는데 
      // 3보다 크면 가로가 당연히 o-o이렇게 된다.
      --i;
      //하나찍으면서 진행되어야 하니 --한다.
    }
    ft_putchar('o');
    // while문을 돌았으면 가로줄 끝에 'o'를 붙여준다. 
    ft_putchar('\n');
    //그러고 개행처리 이건 뭐 솔직히 필요없을수도.
  }
  return (0);
}

void  rush(int x, int y)
{
  int i;
  //b의 숫자, -  
  int j;
  // |의 숫자
  i = x - 2;
  j = y - 2;
  top_line(x, y, i);
  mid_line(x, y, i, j);
  bottom_line(x, y, i);
}
