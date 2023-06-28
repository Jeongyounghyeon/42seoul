#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define TRUE	1
#define False	0
#define ERROR	-1

char	paper[300][300];
int		width;
int		height;
FILE	*pfile;

int		open_file(char *file_name);
int		init_paper();
int		drawing();
void	print_paper();

int	main(int argc, char **argv)
{
	if (argc != 2) {
		write(1, "Error: argument\n", 17);
		return (1);
	}
	if (open_file(argv[1]) == ERROR
		|| init_paper() == ERROR
		|| drawing() == ERROR)
	{
		write(1, "Error: Operation file corrupted\n", 33);
		return (1);
	}
	print_paper();
	fclose(pfile);
	return (0);
}

int	open_file(char *file)
{
	pfile = fopen(file, "r");
	if (!pfile)
		return (ERROR);
	return (0);
}

int	init_paper()
{
	char	c;

	if (fscanf(pfile, "%d %d %c\n", &width, &height, &c) != 3)
		return (ERROR);
	if (width <= 0 || width > 300 || height <= 0 || height > 300)
		return (ERROR);
	memset(paper[0], c, 300 * 300);
	return (0);
}

int	drawing()
{
	char	Cc, c;
	float	x, y, r;
	int		rtn_fscanf;

	while ((rtn_fscanf = fscanf(pfile, "%c %f %f %f %c\n", &Cc, &x, &y, &r, &c)) == 5) {
		if (r <= 0 || (Cc != 'c' && Cc != 'C'))
			return (ERROR);
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				float	sum_squre = (x - j) * (x - j) + (y - i) * (y - i);
				if (sum_squre > r * r)
					continue;
				if (Cc == 'c' && (sqrtf(sum_squre) < r - 1))
					continue;
				paper[i][j] = c;
			}
		}
	}
	if (rtn_fscanf != EOF)
		return (ERROR);
	return (0);
}

void	print_paper()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) 
			write(1, &(paper[i][j]), 1);
		write(1, "\n", 1);
	}
}
