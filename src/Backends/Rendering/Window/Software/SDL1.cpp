#include "../Software.h"

#include <stddef.h>
#include <stdlib.h>
#include <string>

#include "SDL.h"

#include "../../../Misc.h"

static Uint32 window_flags = SDL_HWSURFACE | SDL_DOUBLEBUF;

static SDL_Surface *window_sdlsurface;
static SDL_Surface *framebuffer_sdlsurface;

bool WindowBackend_Software_CreateWindow(const char *window_title, int screen_width, int screen_height, bool fullscreen)
{
	if (fullscreen)
		window_flags |= SDL_FULLSCREEN;
	else
		window_flags &= ~SDL_FULLSCREEN;

	window_sdlsurface = SDL_SetVideoMode(screen_width, screen_height, 24, window_flags);
	if (window_sdlsurface != NULL)
	{
		SDL_WM_SetCaption(window_title, NULL);
		framebuffer_sdlsurface = SDL_CreateRGBSurface(SDL_SWSURFACE, window_sdlsurface->w, window_sdlsurface->h, 24, 0x0000FF, 0x00FF00, 0xFF0000, 0);

		if (framebuffer_sdlsurface != NULL)
		{
			Backend_PostWindowCreation();

			return true;
		}
		else
		{
			std::string error_message = std::string("Couldn't create framebuffer surface: ") + SDL_GetError();
			Backend_ShowMessageBox("Fatal error (software rendering backend)", error_message.c_str());
		}
	}
	else
	{
		std::string error_message = std::string("Couldn't create window: ") + SDL_GetError();
		Backend_ShowMessageBox("Fatal error (software rendering backend)", error_message.c_str());
	}

	return false;
}

void WindowBackend_Software_DestroyWindow(void)
{
	SDL_FreeSurface(framebuffer_sdlsurface);
}

unsigned char* WindowBackend_Software_GetFramebuffer(size_t *pitch)
{
	*pitch = framebuffer_sdlsurface->pitch;

	return (unsigned char*)framebuffer_sdlsurface->pixels;
}

void WindowBackend_Software_Display(void)
{
	if (SDL_BlitSurface(framebuffer_sdlsurface, NULL, window_sdlsurface, NULL) < 0)
		Backend_PrintError("Couldn't blit framebuffer surface to window surface: %s", SDL_GetError());

	if (SDL_Flip(window_sdlsurface) < 0)
		Backend_PrintError("Couldn't copy window surface to the screen: %s", SDL_GetError());
}

void WindowBackend_Software_HandleWindowResize(unsigned int width, unsigned int height)
{
	window_sdlsurface = SDL_SetVideoMode(width, height, 24, window_flags);
	if (window_sdlsurface == NULL)
		Backend_PrintError("Couldn't get SDL surface associated with window: %s", SDL_GetError());
}
