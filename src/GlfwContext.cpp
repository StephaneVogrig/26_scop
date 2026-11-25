/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlfwContext.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:04:58 by stephane          #+#    #+#             */
/*   Updated: 2026/11/25 17:42:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include "loaderGL.hpp"
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
