/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlfwContext.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:04:58 by stephane          #+#    #+#             */
/*   Updated: 2026/11/24 21:10:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <GLFW/glfw3.h>
#include "GlfwContext.hpp"

GlfwContext::GlfwContext()
{
    if (!glfwInit())
    {
        throw(std::runtime_error("GLFW initialisation failed!"));
    }
}

GlfwContext::~GlfwContext()
{
    glfwTerminate();
}
