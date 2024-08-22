void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
	{
		free (p);
		return (p);
	}
	while (size)
	{
		*p = 0;
		p++;
		size--;
	}
	return (p);
}