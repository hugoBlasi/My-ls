void my_putchar(char c);
void my_putstr(char *str);

void my_putnbr(int n)
{
  int i;
  i = 1;
  if (n == -2147483648)
    my_putstr("-2147483678");
  if (n < 0)
  {
    my_putchar('-');
    n = -n;
  }
  while ((n / i) >= 10)
    i *= 10;
  while (i > 0)
  {
    my_putchar((n / i) % 10 + 48);
    i /= 10;
  }
}