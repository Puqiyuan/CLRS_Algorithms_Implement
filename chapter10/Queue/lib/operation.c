int init_queue(Queue *Q)
{
  Q -> tail = Q -> head = 1;

  Q -> queue[0] = -1;

  return 1;
}


int en_queue(Queue *Q, int x)
{
  if  (Q -> tail == MAX_SIZE)
    Q -> tail = 1;
  
  if (Q -> head == Q -> tail + 1)
    {
      printf("OVERFLOW\n");
      return 0;
    }

  Q -> queue[Q -> tail] = x;

  if  (Q -> tail == MAX_SIZE)
    Q -> tail = 1;

  else
    Q -> tail += 1;

  return 1;
}


int de_queue(Queue *Q)
{
  if (Q -> tail == Q -> head)
    {
      printf("UNDERFLOW\n");
      return 0;
    }
  
  int x = Q -> queue[Q -> head];

  if (Q -> head == MAX_SIZE)
    Q -> head = 1;

  else
    Q -> head += 1;

  return x;
}


int display(Queue Q)
{  
  while (Q.head != Q.tail)
    {
      printf("%d ", Q.queue[Q.head]);
      
      if (Q.head == MAX_SIZE)
	Q.head = 1;

      else
	Q.head += 1;
    }

  printf("\n");
  
  return 1;
}
