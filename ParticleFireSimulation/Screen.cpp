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

	m_buffer = new Uint32[WIDTH * HEIGHT];

	//http://www.cplusplus.com/reference/cstring/memset/
	memset(m_buffer, 0, WIDTH*HEIGHT * sizeof(Uint32));


	for (int i = 0; i < WIDTH * HEIGHT; i++)
	{
		m_buffer[i] = 0xffff00ff;
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
	SDL_UpdateTexture(m_texture, nullptr, m_buffer, WIDTH * sizeof(Uint32));
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

	m_buffer[(y * WIDTH) + x] = color;
}

void Screen::Clear()
{
	memset(m_buffer, 0, WIDTH* HEIGHT * sizeof(Uint32));
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
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

