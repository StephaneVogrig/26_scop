/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:10:12 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 14:03:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Window_HPP
# define Window_HPP

#include <GLFW/glfw3.h>
#include "GlfwContext.hpp"
#include "Input.hpp"

class Window
{
    public:
        Window(GlfwContext&, Input& input, int width, int height, const char* title);
        Window(const Window& other) = delete;
        Window& operator=(const Window& other) = delete;
        ~Window();

        bool shouldClose() const;
        void swapBuffers() const;
        void pollEvents() const;
        void requestClose() const;

    private:
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        GLFWwindow* _window = nullptr;
        Input& _input;
};

#endif
