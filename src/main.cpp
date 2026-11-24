/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:19:16 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/24 21:15:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "GlfwContext.hpp"
#include "ScopWindow.hpp"

#define FG_RED      "\033[31m"
#define FG_DEFAULT  "\033[39m"

int main(void)
{
    try
    {
        std::cout << "Scop start" << std::endl;

        GlfwContext glfw;
        ScopWindow window(glfw, 1024, 768, "scop");
        while (!window.shouldClose())
        {
            window.swapBuffers();
            window.pollEvents();
        }
        return EXIT_SUCCESS;
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << FG_RED << e.what() << FG_DEFAULT << std::endl;
        return EXIT_FAILURE;
    }
}
