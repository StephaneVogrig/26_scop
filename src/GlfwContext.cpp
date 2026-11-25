/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlfwContext.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:04:58 by stephane          #+#    #+#             */
/*   Updated: 2026/11/25 12:49:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <GLFW/glfw3.h>
#include "GlfwContext.hpp"

GlfwContext::GlfwContext()
{
    if (!glfwInit())
    {
        throw std::runtime_error("GLFW initialisation failed!");
    }
}

GlfwContext::~GlfwContext()
{
    glfwTerminate();
}
