/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:19:16 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/24 17:41:43 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScopWindow.hpp"

#define FG_RED			"\033[31m"
#define FG_DEFAULT		"\033[39m"

int main(void) {
    try {
        std::cout << "Scop start" << std::endl;
        ScopWindow window(1024, 768, "scop");
        while (!glfwWindowShouldClose(window.get()))
        {
            glfwSwapBuffers(window.get());
        }
        return (EXIT_SUCCESS);
    }
    catch (const std::runtime_error& e) {
        std::cerr << FG_RED << e.what() << FG_DEFAULT << std::endl;
        return (EXIT_FAILURE);
    }
}
