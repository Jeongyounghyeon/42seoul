#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char	**paper;
int		width;
int		height;
FILE	*pfile;

int		main(int argc, char **argv);
int		open_file(char *argv);
int	init_paper();
int	drawings();
void	print_paper();

int main(int argc, char **argv)
{
	if (argc != 2) {
		write(1, "Error: argument\n", 17);
		return (1);
	}

	if (open_file(argv[1]) == 1)
		return (1);
	if (init_paper() == 1 || drawings() == 1) {
		write(1, "Operation file corrupted\n", 26);
		return (1);
	}
	fclose(pfile);
	print_paper();
	return (0);
}

int	open_file(char *argv)
{
	pfile = fopen(argv, "r");
	if (pfile == 0)
		return (1);
	return (0);
}

int	init_paper()
{
	char c;

	if (fscanf(pfile, "%d %d %c\n", &width, &height, &c) == EOF) 
		return (1);
	if (!(paper = (char **)malloc(height * sizeof(char *)))) 
		return (1);
	for (int i = 0; i < height; i++) {
		if (!(paper[i] = (char *)malloc(width * sizeof(char))))
			return (1);
		memset(paper[i], c, width * sizeof(char));
	}
	if (!(width <= 300 && height <= 300))
		return (1);
	return (0);
}

int	drawings()
{
	char	rR, c;
	float	x, y, w, h;
	int		x_, _x, y_, _y;
	int		res_scanf;

	res_scanf = fscanf(pfile, "%c %f %f %f %f %c\n", &rR, &x, &y, &w, &h, &c);
	while (res_scanf != EOF)
	{
		if ((rR != 'r' && rR != 'R')
			|| w <= 0 || h <= 0) 
			return (1);
		_x = (int)(x + w);
		_y = (int)(y + h);
		x_ = (int)x;
		y_ = (int)y;
		if (x != x_) x_++;
		if (y != y_) y_++;
		for (int i = y_; i <= _y; i++) {
			if (i < 0) continue;
			if (i >= height) break;
			for (int j = x_; j <= _x; j++) {
				if (j < 0) continue;
				if (j >= width) break;
				if (rR == 'r' && ((i != y_ && i != _y) && (j != x_ && j != _x)))
					continue;
				paper[i][j] = c;
			}
		}
		res_scanf = fscanf(pfile, "%c %f %f %f %f %c\n", &rR, &x, &y, &w, &h, &c);
	}
	if (res_scanf != EOF)
		return (1);
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