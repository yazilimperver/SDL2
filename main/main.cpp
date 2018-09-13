#include <SDL.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <SDL_opengl.h>

#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include <string>

extern "C"
{
    AAssetManager* Android_JNI_GetAssetManager(void);
    JNIEnv* Android_JNI_GetEnv(void);
    const char* GetPackageName();
}
int main(int argc, char** argsv)
{
    const char* packageName = GetPackageName();
	//put your SDL / game code here

	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2


    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);


    // Turn on double buffering with a 24bit Z buffer.
    // May need to change this to 16 or 32
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

    // Create an application window with the following settings:
	window = SDL_CreateWindow(
		"An SDL 2.0.8",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

    // Create our opengl contex t and attach it to our window
    SDL_GL_CreateContext(window);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    //Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (true)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(255, 0, 0, 255);

        SDL_GL_SwapWindow(window);
    }


	SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();


	return 0;
}