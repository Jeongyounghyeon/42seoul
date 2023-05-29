#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char	**paper;
int		width;
int		height;
FILE	*pfile;

int		main(int argc, char **argv);
void	open_file(char *argv);
void	init_paper();
void	drawings();
void	print_paper();

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	open_file(argv[1]);
	init_paper();
	drawings();
	fclose(pfile);
	print_paper();
	exit (0);
}

void	open_file(char *argv)
{
	pfile = fopen(argv, "r");
	if (pfile == 0)
		exit(1);
}

void	init_paper()
{
	char c;

	if (fscanf(pfile, "%d %d %c\n", &width, &height, &c) == EOF) exit(1);
	if (!(paper = (char **)malloc(height * sizeof(char *)))) exit(1);
	for (int i = 0; i < height; i++) {
		if (!(paper[i] = (char *)malloc(width * sizeof(char)))) exit(1);
		memset(paper[i], c, width * sizeof(char));
	}
}

void	drawings()
{
	char	rR, c;
	float	x, y, w, h;
	int		x_, _x, y_, _y;

	while (fscanf(pfile, "%c %f %f %f %f %c\n", &rR, &x, &y, &w, &h, &c) != EOF)
	{
		if (rR != 'r' && rR != 'R') exit(1);
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
	}
}

void	print_paper()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) 
			write(1, &(paper[i][j]), 1);
		write(1, "\n", 1);
	}
}