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
