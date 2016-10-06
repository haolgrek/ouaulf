
#include <math.h>
#define mapwidth 24
#define mapheight 24

int worldmap[mapwidth][mapheight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


int main(int argc, char *argv[])
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	camerax;
	int		w;
	int		h;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	oldplanex;
	double	olddirx;
	double	oldplaney;
	double	olddiry;
	double	frametime;
	double	movespeed;
	double	rotspeed;
	int		x;
	int		color;

	w= 1280;
	h = 1024;
	posx = 22;
	posy = 12;  //x and y start position
	dirx = -1;
	diry = 0; //initial direction vector
	planex = 0;
	planey = 0.66; //the 2d raycaster version of camera plane
	time = 0; //time of current frame
	oldtime = 0; //time of previous frame

	while (1)
	{
		x = 0;
		while (x < w)
		{
			//calculate ray position and direction
			camerax = 2 * x / (double)w - 1; //x-coordinate in camera space
			rayposx = posx;
			rayposy = posy;
			raydirx = dirx + planex * camerax;
			raydiry = diry + planey * camerax;
			//which box of the map we're in
			mapx = (int)rayposx;
			mapy = (int)rayposy;
			//length of ray from current position to next x or y-side
			//length of ray from one x or y-side to next x or y-side
			deltadistx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
			deltadisty = sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
			//what direction to step in x or y-direction (either +1 or -1)
			hit = 0; //was there a wall hit?
			//was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if (raydirx < 0)
			{
				stepx = -1;
				sidedistx = (rayposx - mapx) * deltadistx;
			}
			else
			{
				stepx = 1;
				sidedistx = (mapx + 1.0 - rayposx) * deltadistx;
			}
			if (raydiry < 0)
			{
				stepy = -1;
				sidedisty = (rayposy - mapy) * deltadisty;
			}
			else
			{
				stepy = 1;
				sidedisty = (mapy + 1.0 - rayposy) * deltadisty;
			}
			while (hit == 0)
			{
				//jump to next map square, or in x-direction, or in y-direction
				if (sidedistx < sidedisty)
				{
					sidedistx += deltadistx;
					mapx += stepx;
					side = 0;
				}
				else
				{
					sidedisty += deltadisty;
					mapy += stepy;
					side = 1;
				}
				//Check if ray has hit a wall
				if (worldmap[mapx][mapy] > 0)
					hit = 1;
			}
			//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
			if (side == 0)
				perpwalldist = (mapx - rayposx + (1 - stepx) / 2) / raydirx;
			else
				perpwalldist = (mapy - rayposy + (1 - stepy) / 2) / raydiry;
			//Calculate height of line to draw on screen
			lineheight = (int)(h / perpwalldist);
			//calculate lowest and highest pixel to fill in current stripe
			drawstart = -lineheight / 2 + h / 2;
			if(drawstart < 0)
				drawstart = 0;
			drawend = lineheight / 2 + h / 2;
			if(drawend >= h)
				drawend = h;
			//choose wall color
			while (mapy < drawend)
			{
				color = 0x00ff00;
				if (side == 0)
					color = 0x00f0f0;
				if (side == 1 && raydiry < 0)
					color = 0xff0000;
				if (side == 0 && raydirx > 0)
					color = 0x0000ff;
				worldmap[mapy][mapx] = color;
				mapy++;
			}
		}
		x++;
		readKeys();
	//move forward if no wall in front of you
	//
		if (keydown(SDLK_UP))
		{
			if(worldmap[(int)(posx + dirx * movespeed)][(int)posy] == false)
				posx += dirx * movespeed;
			if(worldmap[(int)posx][(int)(posy + diry * movespeed)] == false)
				posy += diry * movespeed;
		}
		//move backwards if no wall behind you
		if (keydown(SDLK_DOWN))
		{
			if(worldmap[(int)(posx - dirx * movespeed)][(int)posy] == false)
				posx -= dirx * movespeed;
			if(worldmap[(int)posx][(int)(posy - diry * movespeed)] == false)
				posy -= diry * movespeed;
		}
		//rotate to the right
		if (keydown(SDLK_RIGHT))
		{
		//both camera direction and camera plane must be rotated
			olddirx = dirx;
			dirx = dirx * cos(-rotspeed) - diry * sin(-rotspeed);
			diry = olddirx * sin(-rotspeed) + diry * cos(-rotspeed);
			oldplanex = planex;
			planex = planex * cos(-rotspeed) - planey * sin(-rotspeed);
			planey = oldplanex * sin(-rotspeed) + planey * cos(-rotspeed);
		}
		//rotate to the left
		if (keydown(SDLK_LEFT))
		{
		//both camera direction and camera plane must be rotated
			olddirx = dirx;
			dirx = dirx * cos(rotspeed) - diry * sin(rotspeed);
			diry = olddirx * sin(rotspeed) + diry * cos(rotspeed);
			oldplanex = planex;
			planex = planex * cos(rotspeed) - planey * sin(rotspeed);
			planey = oldplanex * sin(rotspeed) + planey * cos(rotspeed);
		}
	}
	loop end;
}
