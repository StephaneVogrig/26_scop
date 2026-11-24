/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScopWindow.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:10:12 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/24 17:34:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPWINDOW
# define SCOPWINDOW

#include <stdexcept>
#include "GLFW/glfw3.h"

class ScopWindow
{
    public:
        ScopWindow(int width, int height, const char* title);
        ScopWindow(const ScopWindow& other) = delete;
        ScopWindow& operator=(const ScopWindow& other) = delete;
        ~ScopWindow();
        GLFWwindow* get();

    private:
        GLFWwindow* _window = nullptr;
};

#endif
