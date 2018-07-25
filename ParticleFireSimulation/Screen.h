#pragma once
#include <SDL.h>

class Screen
{
public:

	const static int WIDTH = 800;
	const static int HEIGHT = 600;

private:
	SDL_Window * m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	SDL_Texture*  m_texture = nullptr;
	Uint32*		m_buffer = nullptr;

public:
	bool Init();
	bool ProcessEvents();
	void Close();
	void Update();
	void SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void SetBackgroundColor(Uint8 red, Uint8 green, Uint8 blue);
	void Clear();
};


