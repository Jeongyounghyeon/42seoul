#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE	1
#define False	0
#define ERROR	-1

char	**paper;
int		width;
int		height;
FILE	*pfile;

int		open_file(char *file);
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

	if (fscanf(pfile, "%d %d %c\n", &width, &height, &c) == EOF)
		return (ERROR);
	if (width <= 0 || width > 300 || height <= 0 || height > 300)
		return (ERROR);
	paper = (char **)malloc(height * sizeof(char *));
	if (!paper)
		return (ERROR);
	for (int i = 0; i < height; i++) {
		paper[i] = (char *)malloc(width * sizeof(char));
		if (!paper[i])
			return (ERROR);
		memset(paper[i], c, width);
	}
	return (0);
}

int	drawing()
{
	char	rR, c;
	float	X, Y, w, h;
	int		x_, _x, y_, _y;
	int		res_fscanf;

	while ((res_fscanf = fscanf(pfile, "%c %f %f %f %f %c\n", &rR, &X, &Y, &w, &h, &c)) == 6)
	{
		if ((X + w < 0) || (Y + h) < 0)
			continue;
		if (X < 0) x_ = -1;
		else if ((float)(int)X == X) x_ = (int)X; else x_ = (int)X + 1;
		if (Y < 0) y_ = -1;
		else if ((float)(int)Y == Y) y_ = (int)Y; else y_ = (int)Y + 1;
		if ((X + w) >= width + 1) _x = width;
		else _x = (int)(X + w);
		if ((Y + h) >= height + 1) _y = height;
		else _y = (int)(Y + h);
		printf("%d %d %d %d\n", x_, _x, y_, _y);
		for (int i  = y_; i <= _y; i++) {
			if (i < 0 || i >= height)
				continue;
			for (int j = x_; j <= _x; j++) {
				if (j < 0 || j >= width)
					continue;
				if (rR == 'r' && ((i != y_ && i != _y) && (j != x_ && j != _x)))
					continue;
				paper[i][j] = c;
			}
		}
	}
	if (res_fscanf != EOF)
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