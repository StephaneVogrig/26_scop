/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScopWindow.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:23:18 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/24 19:40:27 by stephane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScopWindow.hpp"

ScopWindow::ScopWindow(GlfwContext&, int width, int height, const char* title)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (_window == NULL) {
        throw(std::runtime_error("Failed to open GLFW window!"));
    }
    glfwMakeContextCurrent(_window);
}

ScopWindow::~ScopWindow()
{
    glfwDestroyWindow(_window);
}

bool ScopWindow::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void ScopWindow::swapBuffers() {
    glfwSwapBuffers(_window);
}
