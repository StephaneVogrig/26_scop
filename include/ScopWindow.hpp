/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScopWindow.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:10:12 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/24 19:40:50 by stephane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPWINDOW_HPP
# define SCOPWINDOW_HPP

#include <stdexcept>
#include <GLFW/glfw3.h>
#include "GlfwContext.hpp"

class ScopWindow
{
    public:
        ScopWindow(GlfwContext&, int width, int height, const char* title);
        ScopWindow(const ScopWindow& other) = delete;
        ScopWindow& operator=(const ScopWindow& other) = delete;
        ~ScopWindow();

        bool shouldClose();
        void swapBuffers();

    private:
        GLFWwindow* _window = nullptr;
};

#endif
