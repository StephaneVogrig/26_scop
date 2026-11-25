/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:23:18 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 14:05:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include "Window.hpp"

Window::Window(GlfwContext&, Input& input, int width, int height, const char* title)
    : _input(input)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (_window == nullptr)
    {
        throw std::runtime_error("Failed to open GLFW window!");
    }
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);
    glfwSetWindowUserPointer(_window, this);
    glfwSetKeyCallback(_window, keyCallback);
}

Window::~Window()
{
    glfwDestroyWindow(_window);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(_window) != 0;
}

void Window::swapBuffers() const
{
    glfwSwapBuffers(_window);
}

void Window::pollEvents() const
{
    glfwPollEvents();
}

void Window::requestClose() const
{
    glfwSetWindowShouldClose(_window, GLFW_TRUE);
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height);
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    (void)scancode;
    (void)mods;
    auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if (self != nullptr)
    {
        self->_input.onKeyEvent(key, action);
    }
}
