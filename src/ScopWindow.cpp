/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScopWindow.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:23:18 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/24 17:37:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScopWindow.hpp"

ScopWindow::ScopWindow(int width, int height, const char* title)
{
    if (!glfwInit()) {
        throw(std::runtime_error("GLFW initialisation failed!"));
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (_window == NULL) {
        glfwTerminate();
        throw(std::runtime_error("Failed to open GLFW window!"));
    }
    glfwMakeContextCurrent(_window);
}

ScopWindow::~ScopWindow()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

GLFWwindow* ScopWindow::get() {
    return _window;
}
