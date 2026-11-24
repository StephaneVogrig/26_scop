/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScopWindow.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:10:12 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 00:10:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPWINDOW_HPP
# define SCOPWINDOW_HPP

#include <GLFW/glfw3.h>
#include "GlfwContext.hpp"

class ScopWindow
{
    public:
        ScopWindow(GlfwContext&, int width, int height, const char* title);
        ScopWindow(const ScopWindow& other) = delete;
        ScopWindow& operator=(const ScopWindow& other) = delete;
        ~ScopWindow();

        bool shouldClose() const;
        void swapBuffers() const;
        void pollEvents() const;

    private:
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        GLFWwindow* _window = nullptr;
};

#endif
