int countRev(string s)
{
  int open = 0, close = 0;
  if (s.length() % 2 != 0)
    return -1;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '{')
      open++;
    else
    {
      if (open == 0)
        close++; // case: }}}}...
      else
        open--;
    }
  }
  if (open == 0)
    return close / 2; // case: }}}}...
  if (close == 0)
    return open / 2;                       // case: {{{{...
  return (open + 1) / 2 + (close + 1) / 2; // case: }}}}...{{{{...
}