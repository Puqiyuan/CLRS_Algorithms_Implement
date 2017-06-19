int init_stack(Stack *S)
{
  S->top = 0;

  S->stack[0] = -1;

  return 1;
}


int push(Stack *S, int x)
{
  S->top = S->top + 1;
  S->stack[S->top] = x;

  return 1;
}


bool stack_empty(Stack S)
{
  if (S.top == 0)
    return true;

  return false;	 
}


int pop(Stack *S)
{
  if (stack_empty(*S))
    return 0;

  else
    S->top = S->top - 1;
  
  return S->stack[S->top + 1];
}


int disply(Stack S)
{
  int i;

  printf("The top of the stack: %d\n", S.top);
  
  for (i = S.top; i >= 1; i--)
    printf("%d ", S.stack[i]);

  printf("\n");

  return 0;
}
