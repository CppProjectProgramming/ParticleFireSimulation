#include "stdafx.h"
#include "Screen.h"

#undef main


bool Screen::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Simulation",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN); // TODO parametrize the title

	if (!m_window) { SDL_Quit(); return false; }

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
		WIDTH, HEIGHT);

	m_buffer1 = new Uint32[WIDTH * HEIGHT];
	m_buffer2 = new Uint32[WIDTH * HEIGHT];

	//http://www.cplusplus.com/reference/cstring/memset/
	memset(m_buffer1, 0, WIDTH*HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, WIDTH*HEIGHT * sizeof(Uint32));


	for (int i = 0; i < WIDTH * HEIGHT; i++)
	{
		m_buffer1[i] = 0xffff00ff;
	}

	if (!m_renderer)
	{
		Close();
		return false;
	}

	if (!m_texture)
	{
		Close();
		return false;
	}

	return true;
}

bool Screen::ProcessEvents()
{
	SDL_Event Event;

	while (SDL_PollEvent(&Event))
	{
		if (Event.type == SDL_QUIT)
		{
			return false;
		}
	}

	return true;
}



void Screen::Update()
{
	SDL_UpdateTexture(m_texture, nullptr, m_buffer1, WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
	SDL_RenderPresent(m_renderer);
}

void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	// Check if the pixel is in range of the screen so we can plot it correctly.
	if (x < 0 || x >= Screen::WIDTH || y < 0 || y >= Screen::HEIGHT)
	{
		return;
	}

	Uint32 color = 0;
	
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer1[(y * WIDTH) + x] = color;
}

void Screen::Clear()
{
	memset(m_buffer1, 0, WIDTH* HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, WIDTH* HEIGHT * sizeof(Uint32));

}


void Screen::BoxBlur()
{
	// Swap the buffers so pixel info in buffer 2 and we are drawing to buffer 1
	Uint32 *temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int row = -1; row <= 1; row++)
			{
				for (int col = -1; col <= 1; col++)
				{
					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && currentX < WIDTH && currentY >= 0 && currentY < HEIGHT)
					{
						Uint32 color = m_buffer2[currentY * WIDTH + currentX];
						
						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}
			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;
			SetPixel(x, y, red, green, blue);
		}
	}
}


void Screen::SetBackgroundColor(Uint8 red, Uint8 green, Uint8 blue)
{
	for (int y = 0; y < Screen::HEIGHT; y++)
	{
		for (int x = 0; x < Screen::WIDTH; x++)
		{
			SetPixel(x, y, red, green, blue);
		}
	}
}


void Screen::Close()
{
	delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

