#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (*str++)
		res++;
	return (res);
}

char	*strjoin_sep(char *str0, char *str1, char sep)
{
	char	*res;
	char	*pres;
	int		resl;
	int		str_len[2];

	res = 0;
	str_len[0] = ft_strlen(str0);
	str_len[1] = ft_strlen(str1);
	resl = str_len[0] + str_len[1];
	if ((str_len[0] > 0) && (str_len[1] > 0))
		resl++;
	res = (char *)malloc((resl + 1) * sizeof(char));
	if (!res)
		return (0);
	pres = res;
	if (str0)
		while (*str0)
			*pres++ = *str0++;
	if ((str_len[0] > 0) && (str_len[1] > 0))
		*pres++ = sep;
	if (str1)
		while (*str1)
			*pres++ = *str1++;
	*pres = 0;
	return (res);
}

char	*strarr_join(char **strs_in)
{
	char	*res;
	char	*pstr;
	char	**pinstr;

	if (!strs_in)
		return (0);
	res = 0;
	pinstr = strs_in;
	while (*pinstr)
	{
		res = strjoin_sep(res, *pinstr, ' ');
		if (!res)
		{
			free(res);
			return (0);
		}
		pinstr++;
	}
	return (res);
}

int main(int argc, char **argv)
{	
	printf("%s|<- END WALL\n", strarr_join(argv + 1));

	return (0);
}