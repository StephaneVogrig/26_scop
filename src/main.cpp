/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:19:16 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 20:49:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "GlfwContext.hpp"
#include "Window.hpp"
#include "loaderGL.hpp"

#define FG_RED      "\033[31m"
#define FG_DEFAULT  "\033[39m"

void processInput(Window& window, Input& input)
{
    if (input.isKeyDown(GLFW_KEY_ESCAPE))
    {
        window.requestClose();
    }
}

int main(void)
{
    std::cout << "Scop start" << std::endl;

    try
    {
        GlfwContext glfw;
        Input input;
        Window window(glfw, input, 1024, 768, "scop");
        loadGLextensions();

        while (!window.shouldClose())
        {
            processInput(window, input);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            window.swapBuffers();
            window.pollEvents();
            input.endFrame();
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << FG_RED << e.what() << FG_DEFAULT << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
