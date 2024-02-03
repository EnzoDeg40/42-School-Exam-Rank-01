int	number_above(int *tab, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > n)
			return (tab[i]);
		i++;
	}
	return (0);
}
